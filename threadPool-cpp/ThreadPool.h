#pragma once
#include"TaskQueue.h"
class ThreadPool
{

public:
	//�����̳߳ز���ʼ��
	ThreadPool(int min, int max);

	//�����̳߳�
	~ThreadPool();

	//���̳߳��������
	void addTask(Task task);

	//��ȡ�̳߳��й������̵߳ĸ���

	int getBusyNum();

	//��ȡ�̳߳��л��ŵ��̵߳ĸ���
	int getAliveNum();


private:
	///////////////////
	//�������̣߳��������̣߳�������
	static void* worker(void* arg);
	//�������߳�������
	static void* manager(void* arg);
	//�����߳��˳�
	void threadExit();



private:
	//�������
	TaskQueue* taskQ;

	pthread_t managerID;   //������ID
	pthread_t* threadIDs;  //�������߳�ID
	int minNum;            //��С�߳�����
	int maxNum;			   //����߳�����
	int busyNum;           //æ�̸߳���
	int liveNum;		   //�����̵߳ĸ���
	int exitNum;		   //Ҫ���ٵ��̸߳���
	pthread_mutex_t mutexPool;   //���������̳߳�
	pthread_cond_t notEmpty;     //��������ǲ��ǿ���
	static const int NUMBER = 2;
	bool shutdown;          //�ǲ���Ҫ�����̳߳�

};

