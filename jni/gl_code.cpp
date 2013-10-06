// OpenGL ES 2.0 code

#include <jni.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "gl_utils.h"
#include "my_log.h"
#include "tests/RenderTriangle.h"


extern "C" {
    JNIEXPORT void JNICALL Java_com_android_gl2jni_GL2JNILib_init(JNIEnv * env, jobject obj,  jint width, jint height);
    JNIEXPORT void JNICALL Java_com_android_gl2jni_GL2JNILib_step(JNIEnv * env, jobject obj);
};

JNIEXPORT void JNICALL Java_com_android_gl2jni_GL2JNILib_init(JNIEnv * env, jobject obj,  jint width, jint height)
{
	TTRIANGLE::setupGraphics(width, height);
}

JNIEXPORT void JNICALL Java_com_android_gl2jni_GL2JNILib_step(JNIEnv * env, jobject obj)
{
	TTRIANGLE::renderFrame();
}
