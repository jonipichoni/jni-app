#include <jni.h>
#include <errno.h>
#include "GLESDemo.h"

#include "Configuration.h"

/*

#ifdef DEBUG
#	define MY_LOG_LEVEL MY_LOG_LEVEL_ERROR
#endif

*/
void android_main(struct android_app* state) 
{
	// Make sure glue is not stripped
	app_dummy();

    GLESDemo glesApp(state);

    glesApp.run();
}
//END_INCLUDE(all)
