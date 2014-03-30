#include "GLESApplication.h"
#include "Helpers/Time.h"

#include "ThreadPool.h"

//////////// STATIC

int GLESApplication::init(int w, int h)
{

    LOGI("+++++++++++++++++++++++++++++++++++++++++++++++");
    printGLString("Version", GL_VERSION);
    printGLString("Vendor", GL_VENDOR);
    printGLString("Renderer", GL_RENDERER);
    printGLString("Extensions", GL_EXTENSIONS);
    LOGI("+++++++++++++++++++++++++++++++++++++++++++++++");

    this->width = w;
    this->height = h;
    
    positInit();
    
    /////////////////

    ThreadPool* myPool = new ThreadPool(5);

	//time_t t1=time(NULL);

	//Lets start bullying ThreadPool with tonnes of work !!!
	for(unsigned int i=0;i<200;i++){
		WorkerThread* myThread = new WorkerThread(i);
		myPool->setWork(myThread);
	}

    ////////////////

    return 0;
}


double GLESApplication::getCurrentTime()
{
    static struct timeval start;
    
    gettimeofday(&start, NULL);
    return ((start.tv_sec * 1000) + (start.tv_usec / 1000.0));
}


