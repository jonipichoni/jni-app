#ifndef GLES_APPLICATION_H
#define GLES_APPLICATION_H


#include <EGL/egl.h>
#include <GLES2/gl2.h>

#include <android/sensor.h>
#include <android/asset_manager.h>
#include <android/native_activity.h>
#include <android_native_app_glue.h>

#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#include "my_log.h"
#include "stdlib.h"

/**
 * Our saved state data.
 */
struct saved_state {
};

/**
 * Shared state for our app.
 */
struct engine {
	//This is the interface for the standard glue code of a threaded application.
    struct android_app* app;

    // External
    ASensorManager* sensorManager;
    const ASensor* accelerometerSensor;
    ASensorEventQueue* sensorEventQueue;

    // @TODO - Keep State?
    int animating;

    // Internals of EGL
    EGLDisplay display;
    EGLSurface surface;
    EGLContext context;

    // Screen info
    int32_t width;
    int32_t height;

    // Our App Saved Data
    struct saved_state state;
};

class GLESApplication
{
    public:
        GLESApplication(android_app *context)
        {
            this->display = EGL_NO_DISPLAY;
            this->surface = EGL_NO_SURFACE;
            this->context = EGL_NO_CONTEXT;
            this->width = 0;
            this->height = 0;
            this->androidContext = context;
        }
        
        virtual ~GLESApplication() {}

        /**
         * Method call by APP_CMD_INIT_WINDOW. The window is being show.
         */
        int initWindow(android_app *app);

        /**
         * Method call by APP_CMD_TERM_WINDOW.
         */
        void terminateWindow(android_app *app) {}
        void tearDownEGLContext();
        virtual int32_t handleInput(struct android_app* app, AInputEvent* event);
        void handleCommand(struct android_app* app, int32_t cmd);
        double getCuttentTime();
        void run();
    
protected:
        virtual void saveState(android_app *app) {}
        virtual void gainedFocus(android_app *app) {}
        virtual void lostFocus(android_app *app) {}
        virtual void _drawOneFrame(double ellapsedTime);
        virtual void drawOneFrame(double ellapsedTime)  = 0;
        virtual void onStart(android_app* app) {}
        virtual void initShaders() = 0;
        virtual void positInit() = 0;
        GLuint compileShader(const char *path, GLenum shaderType);
        char *loadShaderFromFile(const char *path);
        

    
protected:
        EGLDisplay display;
        EGLSurface surface;
        EGLContext context;
        android_app *androidContext;
        int width;
        int height;
        GLuint shaderProgramObject;

        struct engine engine;
};
#endif // GLES_APPLICATION_H
