/*
	原理：仅当哲学家的左右两支筷子都可用时，才允许他拿起筷子进餐。
	信号量：筷子
	线程：哲学家
*/

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

// 定义信号量：5支筷子
sem_t chopstick[5];

int a = 0;

// 哲学家线程
void *philosopher(void *arg)
{
	int id = ++a;	// 左边筷子的编号，哲学家编号
	int left, right;
	while(1)
	{
		sleep(1);
		sem_getvalue(&chopstick[id % 5], &left);		//获取左边信号量的值，并赋给left
		sem_getvalue(&chopstick[(id + 1) % 5], &right);	//获取右边信号量的值，并赋给right

		  // 左边有筷子	右边有筷子
		if(left == 1 && right == 1)
		{
			//拿起左边的筷子
			sem_wait(&chopstick[id % 5]);
			//拿起右边的筷子
			sem_wait(&chopstick[(id + 1) % 5]);

			// 吃饭
			printf("%d号哲学家正在就餐\n", id);
		
			// 放下左边的筷子
			sem_post(&chopstick[id % 5]);
			// 放下右边的筷子
			sem_post(&chopstick[(id + 1) % 5]);

		}

		
	}

}

void main()
{
	int i;

	//初始化信号量
	for(i = 0; i < 5; i++)
		sem_init(&chopstick[i], 0, 1);

	//声明线程ID
	pthread_t philosopher_tid[5];

	//创建5个哲学家线程
	for(i = 0; i < 5; i++)
		pthread_create(&philosopher_tid[i], NULL, philosopher, NULL);

	//销毁线程
	for(i = 0; i < 5; i++)
		pthread_join(philosopher_tid[i], NULL);
	
}