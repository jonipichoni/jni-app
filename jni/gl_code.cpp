#include <jni.h>

#include <android/log.h>
#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <assert.h>

#include "GLESDemo.h"
#include "my_log.h"
#include "opengl.h"

GLESDemo glesApp;
AAssetManager* p_asset_mgr;

float start = 0.0;
int frames = 0;

extern "C" {

    JNIEXPORT void JNICALL Java_com_android_gl2jni_GL2JNILib_init(JNIEnv * env, jobject obj, jint width, jint height);
    JNIEXPORT void JNICALL Java_com_android_gl2jni_GL2JNILib_step(JNIEnv * env, jobject obj, jfloat fElapsedTime );
    JNIEXPORT void JNICALL Java_com_android_gl2jni_GL2JNILib_createAssetManager( JNIEnv* env, jobject obj, jobject assetManager );
};

JNIEXPORT void JNICALL Java_com_android_gl2jni_GL2JNILib_init(JNIEnv * env,
																jobject obj,
																jint width,
																jint height)
{
	glesApp.init(width, height);
}

JNIEXPORT void JNICALL Java_com_android_gl2jni_GL2JNILib_step(JNIEnv * env, jobject obj, jfloat fElapsedTime )
{
	glesApp.drawOneFrame(fElapsedTime);

	frames++;
	if(start >= 1.0) {
		LOGI("FPS: %d", frames);
		frames = 0;
		start = 0;
	}
	start += fElapsedTime;
}

JNIEXPORT void JNICALL Java_com_android_gl2jni_GL2JNILib_createAssetManager( JNIEnv* env, jobject obj, jobject assetManager )
{
	p_asset_mgr = AAssetManager_fromJava( env, assetManager );
    assert( p_asset_mgr );
}
