/*Md Soyaeb Islam
  ID:1705001
  Course Code: CSE 2204
  Course: Operating System and Systems Programing Lab
*/


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>


int arr[101];

int min,max,n;
int avg;

void *average(void *shoaib)
{
    sleep(1);
    int sum=0;
    for(int i=0; i<n; i++)
    {
        sum=sum+arr[i];
    }
    avg=sum/n;
    pthread_exit(0);
}
void *minimum(void *param)
{
    sleep(1);
    min=arr[0];
    for(int i=1; i<n; i++)
    {
        if(arr[i]<min)
            min=arr[i];
    }
    pthread_exit(0);
}
void *maximum(void *param)
{
    sleep(1);
    max=arr[0];
    for(int i=1; i<n; i++)
    {
        if(arr[i]>max)max=arr[i];
    }
    pthread_exit(0);
}
int main()
{
    pthread_t tid[3];

    printf(" Enter The Array size: ");

    scanf("%d",&n);

    printf("\n ****************Enter the array*************\n\n");

    for(int i=0; i<n; i++)
    {
        printf(" Enter Element %d : ",i+1);
        scanf("%d",&arr[i]);

    }

    pthread_create(&tid[0],0,average,0);
    pthread_create(&tid[1],0,minimum,0);
    pthread_create(&tid[2],0,maximum,0);

    for(int i=0; i<3; i++)
    {
        pthread_join(tid[i],NULL);
    }
    printf("\n\nThe average value is %d\n",avg);
    printf("The minimum value is %d\n",min);
    printf("The maximum value is %d\n",max);

    return 0;
}
