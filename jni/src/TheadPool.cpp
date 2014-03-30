#include <stdlib.h>
#include "ThreadPool.h"

#include "my_log.h"

using namespace std;

pthread_mutex_t ThreadPool::mMutexSync = PTHREAD_MUTEX_INITIALIZER;

ThreadPool::ThreadPool()
{
        ThreadPool(2);
}

ThreadPool::ThreadPool(unsigned maxThreads)
{
   if (maxThreads < 1)   maxThreads = 1;
   if (maxThreads > NUMTHRDS)   maxThreads = NUMTHRDS;

   mMmaxThreads = maxThreads;

   // Lock Block
   pthread_mutex_lock(&mMutexSync);

   // Init semaphores
   // availableWork - How many tasks are in the queue?
   // availableThreads - Selfexpl
   sem_init(&mAvailableWork, 0, 0);
   sem_init(&mAvailableThreads, 0, mMmaxThreads);

   // Unlock Block
   pthread_mutex_unlock(&mMutexSync);

   /* @TODO - JOINABLE IF WE ARE GONNA DESTROY THEM, BUT always alive?
   	pthread_attr_t attr;
   	pthread_attr_init(&attr);
   	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
   	*/

   	for(unsigned int i = 0; i<mMmaxThreads; ++i)
   	{
   		//pthread_t tempThread;
   		pthread_create(&mCallThd[i], NULL, &ThreadPool::exec, (void *) this );

   	}
}

ThreadPool::~ThreadPool()
{
	// @todo Clear Queues

	/*@TODO WAIT FOR THREAD, but are we gonna destroy them?*/

	sem_destroy(&mAvailableWork);
	sem_destroy(&mAvailableThreads);
	pthread_mutex_destroy(&mMutexSync);

}

bool ThreadPool::setWork(WorkerThread *workerThread)
{
	// Sync Block
	pthread_mutex_lock(&mMutexSync);
		mWorkerQueue.push(workerThread);
		sem_post(&mAvailableWork);
	pthread_mutex_unlock(&mMutexSync);

	return true;
}

bool ThreadPool::getWork(WorkerThread **workerArg)
{
	LOGI("_TH WAITING WORK %d",(int)pthread_self());
	// Sleep until works available
	sem_wait(&mAvailableWork);

	// Sync Block
	pthread_mutex_lock(&mMutexSync);
		// Get FIFO work
		WorkerThread * workerThread = mWorkerQueue.front();
		mWorkerQueue.pop();
		*workerArg = workerThread;

	// Unlock Block
	pthread_mutex_unlock(&mMutexSync);
    return true;
}

void *ThreadPool::exec(void *param)
{
	LOGI("_TH THREAD STARTED %d",(int)pthread_self());
	while(true) {

        WorkerThread *worker = NULL;

        while(((ThreadPool *)param)->getWork(&worker))
        {
			if(worker)
			{
				LOGI("_TH START WORK %d - %d",(int)pthread_self(),worker->id);
				worker->executeThis();
				LOGI("_TH END WORK %d - %d",(int)pthread_self(),worker->id);
				delete worker;
				worker = NULL;
			}
			sem_post(&((ThreadPool *)param)->mAvailableThreads);
        }
	}

	return 0;
}
