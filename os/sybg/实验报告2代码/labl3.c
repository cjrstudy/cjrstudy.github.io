#include<stdio.h>
#include<pthread.h>
void *ptest(void *arg)
{
        printf("This is the bew thread!");
        return(NULL);
}
main()
{
        pthread_t tid;
        printf("This is the parent process!");
        pthread_create(&tid,NULL,ptest,NULL);
        sleep(1);
        return;
}
