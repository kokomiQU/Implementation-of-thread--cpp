#include <stdio.h>
#include "ThreadPool.h"
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>


void taskFunc(void* arg)
{
    int num = *(int*)arg;
    printf("thread %ld is working ,number =%d\n", pthread_self(), num);
    sleep(1);
}

int main()
{
    //�����̳߳�
    ThreadPool pool(3, 10);
    for (int i = 0; i < 100; ++i)
    {
        int* num = new int(i+100);
        pool.addTask(Task(taskFunc,num));
    }

    sleep(20);


    return 0;
}