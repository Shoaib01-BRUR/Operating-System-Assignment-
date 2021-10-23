/*

  A multi-threaded program to generate the Fibonacci sequence

  Md Soyaeb Islam
  ID:1705001
  Course Code: CSE 2204
  Course: Operating System and Systems Programing Lab

*/

#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

long long FIBONACCI;
int n;
void *fib(void *parameter)
{
    sleep(1);

    if(n==0)
        FIBONACCI=0;
    else if(n==1)
        FIBONACCI=1;
    else
    {
        long long f[n+1];
        f[0]=0;
        f[1]=1;
        for(int i=2;i<=n;i++)
            f[i]=f[i-1]+f[i-2];
        FIBONACCI = f[n];
    }
    pthread_exit(0);
}
int main()
{
    pthread_t tid;
    printf("Enter a number: ");
    scanf("%d",&n);
    pthread_create(&tid,0,fib,0);
    pthread_join(tid, NULL);
    printf("%dth fibonacci num is %lld\n",n,FIBONACCI);

    exit(0);
}
