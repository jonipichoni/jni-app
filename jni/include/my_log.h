/*
 * my_log.h
 *
 *  Created on: 5 Oct 2013
 *      Author: jaime
 */

#ifndef MY_LOG_H_
#define MY_LOG_H_

#include <android/log.h>
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>

/*
 	# Define the log tag

	MY_LOG_TAG := hello-jni

	# Define the default logging level based build type

	ifeq ($(APP_OPTIM),release)
		MY_LOG_LEVEL := MY_LOG_LEVEL_ERROR
	else
		MY_LOG_LEVEL := MY_LOG_LEVEL_VERBOSE
	endif

 */

#define MY_LOG_LEVEL_VERBOSE 1
#define MY_LOG_LEVEL_DEBUG 2
#define MY_LOG_LEVEL_INFO 3
#define MY_LOG_LEVEL_WARNING 4
#define MY_LOG_LEVEL_ERROR 5
#define MY_LOG_LEVEL_FATAL 6
#define MY_LOG_LEVEL_SILENT 7

#ifndef MY_LOG_TAG
#	define MY_LOG_TAG __FILE__
#endif

#ifndef MY_LOG_LEVEL
#	define MY_LOG_LEVEL MY_LOG_LEVEL_VERBOSE
#endif

#define MY_LOG_NOOP (void) 0

#define MY_LOG_PRINT(level,fmt,...) \
		__android_log_print(level, MY_LOG_TAG, "(%s:%u) %s: " fmt, \
				__FILE__, __LINE__, __PRETTY_FUNCTION__, ##__VA_ARGS__)

#if MY_LOG_LEVEL_VERBOSE >= MY_LOG_LEVEL
#	define LOGV(fmt,...) \
		MY_LOG_PRINT(ANDROID_LOG_VERBOSE, fmt, ##__VA_ARGS__)
#else
#	define LOGV(...) MY_LOG_NOOP
#endif

#if MY_LOG_LEVEL_DEBUG >= MY_LOG_LEVEL
#	define LOGD(fmt,...) \
		MY_LOG_PRINT(ANDROID_LOG_DEBUG, fmt, ##__VA_ARGS__)
#else
#	define LOGD(...) MY_LOG_NOOP
#endif

#if MY_LOG_LEVEL_INFO >= MY_LOG_LEVEL
#	define LOGI(fmt,...) \
		MY_LOG_PRINT(ANDROID_LOG_INFO, fmt, ##__VA_ARGS__)
#else
#	define LOGI(...) MY_LOG_NOOP
#endif

#if MY_LOG_LEVEL_WARNING >= MY_LOG_LEVEL
#	define LOGW(fmt,...) \
		MY_LOG_PRINT(ANDROID_LOG_WARN, fmt, ##__VA_ARGS__)
#else
#	define MY_LOG_WARN(...) MY_LOG_NOOP
#endif

#if MY_LOG_LEVEL_ERROR >= MY_LOG_LEVEL
#	define LOGE(fmt,...) \
		MY_LOG_PRINT(ANDROID_LOG_ERROR, fmt, ##__VA_ARGS__)
#else
#	define LOGE(...) MY_LOG_NOOP
#endif

#if MY_LOG_LEVEL_FATAL >= MY_LOG_LEVEL
# define LOGF(fmt,...) \
MY_LOG_PRINT(ANDROID_LOG_FATAL, fmt, ##__VA_ARGS__)
#else
#
define LOGF(...) MY_LOG_NOOP
#endif

#if MY_LOG_LEVEL_FATAL >= MY_LOG_LEVEL
#	define LOGA(expression, fmt, ...) \
		if (!(expression)) \
		{ \
			__android_log_assert(#expression, MY_LOG_TAG, \
					fmt, ##__VA_ARGS__); \
		}
#else
#	define LOGA(...) MY_LOG_NOOP
#endif

static void printGLString(const char *name, GLenum s) {
    const char *v = (const char *) glGetString(s);
    LOGI("GL %s = %s\n", name, v);
}
#endif /* MY_LOG_H_ */
