#include<stdio.h>
void main()
{
        int i,p1,p2;
        while((p1=fork())==-1);
        if(p1==0)
                for(i=1; i<=50; i++)
                        printf("son%d",i);
        else
        {   
                while((p2=fork())==-1);
                if(p2==0)
                        for(i=1; i<=50; i++)
                                printf("dauther%d",i);
                else
                        for(i=1; i<=50; i++)
                                printf("father%d",i);
        }   
}
