/*���̵߳�ͬ���ͻ�����ʵ��"������-������"����.*/
/*
* �������߶������߶໺���� �����ߺ������߲���ͬʱ����
* ���룺gcc -o produce-consume-1 produce-consume-1.c -lpthread
* ���У�./produce-consume-1
*/

#include <stdio.h>
#include <stdlib.h>
//#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

//������
void *product(void *arg)
{
printf("This is the ������ thread!\n" );
    return(NULL);
}

//������
void *consumer(void *arg)
{
printf("This is the ������ thread!\n" );
    return(NULL);
}

main()
{ 
    pthread_t tid_product, tid_consumer;
    printf(" This is the parent process !\n" );
    
    printf("create������\n");
    pthread_create(&tid_product,NULL,product,NULL);

    printf("create������\n");
    pthread_create(&tid_consumer,NULL,consumer,NULL);

    sleep(1);
    return;
}

