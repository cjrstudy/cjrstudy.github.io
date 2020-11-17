#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#define M 10 	// 缓冲区大小，假设缓冲区大小为10
#define N1 5	// 生产者数量，假设有5个生产者	
#define N2 3	// 消费者数量，假设有3个消费者

sem_t empty_sem;	// 定义同步信号量， 当缓冲区满了时阻止生产者放产品
sem_t full_sem;		// 定义同步信号量， 当缓冲区没产品时阻止消费者消费

pthread_mutex_t mutex; 	// 定义互斥信号量，一次只有一个线程访问缓冲区
int producer_id = 0;   	// 生产者id
int consumer_id = 0; 	// 消费者id
int in = 0;   	// 生产者放置产品的位置
int out = 0; 	// 消费者取产品的位置
int buff[M] = {0}; 		// 缓冲初始化全部为0，因为开始时没有产品；如果缓冲区的位置有产品，则将buff[下标]的值变为1
int M_num = 0;	// 缓冲区的产品数量，开始时为0
int producer_num = 0; 	// 生产者生产的产品数量
int consumer_num = 0; 	// 消费者消费的产品数量

//生产者线程
void *producer(void *arg)
{
	int id = ++producer_id;	// 为每个生产者线程定义一个名称
	while(1)
	{
		sleep(1);
		pthread_mutex_lock(&mutex);		// 加上互斥锁
		sem_wait(&empty_sem);	// 相当于P原语，调用该方法时，信号量empty_sem自动减1，如果empty_sem<0，线程则发生等待。
		in = in % M;  // 为了能够循环访问缓冲区：当访问了最后一个位值后，会回到第一个位置
		producer_num++;	// 生产的产品数量加1
		M_num++;	// 生产之后将产品放入缓冲区，缓冲区的产品数量加1
		buff[in] = 1;	// 缓冲区有产品，将值置为1
		in++;	// 为了输出存放的位置从1开始，所以先加1。
		printf("%d号生产者生产了一个产品，存放在第%d个位置，总生产量为%d，缓冲区剩余%d个产品\n", id, in, producer_num, M_num);
		pthread_mutex_unlock(&mutex);	// 解除互斥锁
		sem_post(&full_sem);	// 相当于V原语，调用该方法时，信号量full_sem自动加1，如果full_sem<=0，则会唤醒线程。
	}
}

//消费者线程
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
		M_num--;	//从缓冲区消费之后，缓冲区的产品数量减1
		buff[out] = 0;
		out++;
		printf("%d号消费者消费了一个存放在第%d个位置上产品，总消费量为%d，缓冲区剩余%d个产品\n", id, out, consumer_num, M_num);
		pthread_mutex_unlock(&mutex);
		sem_post(&empty_sem);
	}
}

void main()
{
	int i;

	//初始化信号量
	sem_init(&empty_sem, 0, M); // 当第二个参数为0时，信号量将被进程内的线程共享
	sem_init(&full_sem, 0, 0);
	
	//声明生产者线程和消费者线程的ID
	pthread_t producer_tid[N1], consumer_tid[N2];
	
	//创建N1个生产者线程
	for(i = 0; i < N1; i++)
		pthread_create(&producer_tid[i], NULL, producer, NULL);
	
	//创建N2个消费者线程
	for(i = 0; i < N2; i++)
		pthread_create(&consumer_tid[i], NULL, consumer, NULL);

	//销毁N1个生产者线程
	for(i = 0; i < N1; i++)
		pthread_join(producer_tid[i], NULL);

	//销毁N2个消费者线程
	for(i = 0; i < N2; i++)
		pthread_join(consumer_tid[i], NULL);
}
