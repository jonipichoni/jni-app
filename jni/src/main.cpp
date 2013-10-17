#include <jni.h>
#include <errno.h>
#include "GLESDemo.h"

void android_main(struct android_app* state) 
{
	// Make sure glue is not stripped
	app_dummy();

    GLESDemo glesApp(state);

    glesApp.run();
}
//END_INCLUDE(all)
