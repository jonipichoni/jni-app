#ifndef GLES_APPLICATION_H
#define GLES_APPLICATION_H


#include <EGL/egl.h>
#include <GLES2/gl2.h>

#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#include "my_log.h"
#include "stdlib.h"
#include "Configuration.h"
#include "ShaderFactory.h"

/**
 * Our saved state data.
 */
struct saved_state {
};


/**
 * Virtual GLES Application.
 */
class GLESApplication
{
    public:
        GLESApplication()
        {
        	// Initialize members
            this->width = 0;
            this->height = 0;
        }
        
        virtual ~GLESApplication() {}

        /**
         * Method call by APP_CMD_INIT_WINDOW. The window is being show.
         */
        int init(int w, int h);

        /**
         * @TODO - move this from here
         */
        double getCuttentTime();

        virtual void drawOneFrame(float ellapsedTime)  = 0;
    
protected:

        // Must implement methods
        virtual void initShaders() = 0;
        virtual void positInit() = 0;
    
protected:

		// Screen info
		int32_t width;
		int32_t height;
};
#endif // GLES_APPLICATION_H
