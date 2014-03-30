/*
 * ThreadPool.h
 *
 *  Created on: 30 Mar 2014
 *      Author: jaime
 */

#include <pthread.h>
#include <semaphore.h>
#include <iostream>
#include <queue>

using namespace std;

#define NUMTHRDS 10



/*
WorkerThread class
This class needs to be sobclassed by the user.
*/
class WorkerThread{
public:
    int id;

    unsigned virtual executeThis()
	{
    	sleep(5);
    	return(0);
	}

    WorkerThread(int id) : id(id) {}
    virtual ~WorkerThread(){}
};

/*
ThreadPool class manages all the ThreadPool related activities.
This includes keeping track of idle threads and synchronizations between all threads.
*/
class ThreadPool{

public:
	// Default Constructor
    ThreadPool();
    // Consatructor
    ThreadPool(unsigned int maxThreads);

    // Destructor
    virtual ~ThreadPool();

    // Wait and destroy threads, Poll Secs needed if JOINABLE? Dont think so
    void destroyTP(int maxPollSecs);

    //
    bool setWork(WorkerThread *worker);
    bool getWork(WorkerThread **worker);

    static void *exec(void *param);


private:

    unsigned int mMmaxThreads;

    static pthread_mutex_t mMutexSync;
	sem_t mAvailableWork;
	sem_t mAvailableThreads;

	// NUMTHRDS max num threads
	pthread_t mCallThd[NUMTHRDS];

    queue<WorkerThread *> mWorkerQueue;
};
