/*用线程的同步和互斥来实现"生产者-消费者"问题.*/
/*
* 多生产者多消费者多缓冲区 生产者和消费者不可同时进行
* 编译：gcc -o produce-consume-1 produce-consume-1.c -lpthread
* 运行：./produce-consume-1
*/

#include <stdio.h>
#include <stdlib.h>
//#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

//生产者
void *product(void *arg)
{
printf("This is the 生产者 thread!\n" );
    return(NULL);
}

//消费者
void *consumer(void *arg)
{
printf("This is the 消费者 thread!\n" );
    return(NULL);
}

main()
{ 
    pthread_t tid_product, tid_consumer;
    printf(" This is the parent process !\n" );
    
    printf("create生产者\n");
    pthread_create(&tid_product,NULL,product,NULL);

    printf("create消费者\n");
    pthread_create(&tid_consumer,NULL,consumer,NULL);

    sleep(1);
    return;
}

