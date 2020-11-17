#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#define M 10 	// ��������С�����軺������СΪ10
#define N1 5	// ������������������5��������	
#define N2 3	// ������������������3��������

sem_t empty_sem;	// ����ͬ���ź����� ������������ʱ��ֹ�����߷Ų�Ʒ
sem_t full_sem;		// ����ͬ���ź����� ��������û��Ʒʱ��ֹ����������

pthread_mutex_t mutex; 	// ���廥���ź�����һ��ֻ��һ���̷߳��ʻ�����
int producer_id = 0;   	// ������id
int consumer_id = 0; 	// ������id
int in = 0;   	// �����߷��ò�Ʒ��λ��
int out = 0; 	// ������ȡ��Ʒ��λ��
int buff[M] = {0}; 		// �����ʼ��ȫ��Ϊ0����Ϊ��ʼʱû�в�Ʒ�������������λ���в�Ʒ����buff[�±�]��ֵ��Ϊ1
int M_num = 0;	// �������Ĳ�Ʒ��������ʼʱΪ0
int producer_num = 0; 	// �����������Ĳ�Ʒ����
int consumer_num = 0; 	// ���������ѵĲ�Ʒ����

//�������߳�
void *producer(void *arg)
{
	int id = ++producer_id;	// Ϊÿ���������̶߳���һ������
	while(1)
	{
		sleep(1);
		pthread_mutex_lock(&mutex);		// ���ϻ�����
		sem_wait(&empty_sem);	// �൱��Pԭ����ø÷���ʱ���ź���empty_sem�Զ���1�����empty_sem<0���߳������ȴ���
		in = in % M;  // Ϊ���ܹ�ѭ�����ʻ������������������һ��λֵ�󣬻�ص���һ��λ��
		producer_num++;	// �����Ĳ�Ʒ������1
		M_num++;	// ����֮�󽫲�Ʒ���뻺�������������Ĳ�Ʒ������1
		buff[in] = 1;	// �������в�Ʒ����ֵ��Ϊ1
		in++;	// Ϊ�������ŵ�λ�ô�1��ʼ�������ȼ�1��
		printf("%d��������������һ����Ʒ������ڵ�%d��λ�ã���������Ϊ%d��������ʣ��%d����Ʒ\n", id, in, producer_num, M_num);
		pthread_mutex_unlock(&mutex);	// ���������
		sem_post(&full_sem);	// �൱��Vԭ����ø÷���ʱ���ź���full_sem�Զ���1�����full_sem<=0����ỽ���̡߳�
	}
}

//�������߳�
void *consumer(void *arg)
{
	int id = ++consumer_id;
	while(1)
	{
		sleep(1);
		pthread_mutex_lock(&mutex);
		sem_wait(&full_sem);
		out = out % M;
		consumer_num++;
		M_num--;	//�ӻ���������֮�󣬻������Ĳ�Ʒ������1
		buff[out] = 0;
		out++;
		printf("%d��������������һ������ڵ�%d��λ���ϲ�Ʒ����������Ϊ%d��������ʣ��%d����Ʒ\n", id, out, consumer_num, M_num);
		pthread_mutex_unlock(&mutex);
		sem_post(&empty_sem);
	}
}

void main()
{
	int i;

	//��ʼ���ź���
	sem_init(&empty_sem, 0, M); // ���ڶ�������Ϊ0ʱ���ź������������ڵ��̹߳���
	sem_init(&full_sem, 0, 0);
	
	//�����������̺߳��������̵߳�ID
	pthread_t producer_tid[N1], consumer_tid[N2];
	
	//����N1���������߳�
	for(i = 0; i < N1; i++)
		pthread_create(&producer_tid[i], NULL, producer, NULL);
	
	//����N2���������߳�
	for(i = 0; i < N2; i++)
		pthread_create(&consumer_tid[i], NULL, consumer, NULL);

	//����N1���������߳�
	for(i = 0; i < N1; i++)
		pthread_join(producer_tid[i], NULL);

	//����N2���������߳�
	for(i = 0; i < N2; i++)
		pthread_join(consumer_tid[i], NULL);
}
