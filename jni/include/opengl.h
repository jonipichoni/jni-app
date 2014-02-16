/*
 * opengl.h
 *
 *  Created on: 16 Feb 2014
 *      Author: jaime
 */


#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include "my_log.h"

#ifndef OPENGL_H_
#define OPENGL_H_

static void printGLString(const char *name, GLenum s) {
    const char *v = (const char *) glGetString(s);
    LOGI("GL %s = %s\n", name, v);
}


#endif /* OPENGL_H_ */
