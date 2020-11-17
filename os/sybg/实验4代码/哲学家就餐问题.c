/*
	ԭ��������ѧ�ҵ�������֧���Ӷ�����ʱ����������������ӽ��͡�
	�ź���������
	�̣߳���ѧ��
*/

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

// �����ź�����5֧����
sem_t chopstick[5];

int a = 0; //����ȫ�ֱ���

// ��ѧ���߳�
void *philosopher(void *arg)
{
	int id = ++a;	// ��߿��ӵı�ţ���ѧ�ұ��
	int left, right;
	while(1)
	{
		sleep(1);
		sem_getvalue(&chopstick[id % 5], &left);		//��ȡ����ź�����ֵ��������left
		sem_getvalue(&chopstick[(id + 1) % 5], &right);	//��ȡ�ұ��ź�����ֵ��������right

		  // ����п���	�ұ��п���
		if(left == 1 && right == 1)
		{
			//������ߵĿ���
			sem_wait(&chopstick[id % 5]);
			//�����ұߵĿ���
			sem_wait(&chopstick[(id + 1) % 5]);

			// �Է�
			printf("%d����ѧ�����ھͲ�\n", id);
		
			// ������ߵĿ���
			sem_post(&chopstick[id % 5]);
			// �����ұߵĿ���
			sem_post(&chopstick[(id + 1) % 5]);
		}
	}
}

void main()
{
	int i;

	//��ʼ���ź���
	for(i = 0; i < 5; i++)
		sem_init(&chopstick[i], 0, 1);

	//�����߳�ID
	pthread_t philosopher_tid[5];

	//����5����ѧ���߳�
	for(i = 0; i < 5; i++)
		pthread_create(&philosopher_tid[i], NULL, philosopher, NULL);

	//�����߳�
	for(i = 0; i < 5; i++)
		pthread_join(philosopher_tid[i], NULL);
	
}