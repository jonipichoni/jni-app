/*
 * RenderTriangle.h
 *
 *  Created on: 6 Oct 2013
 *      Author: jaime
 */

#ifndef RENDERTRIANGLE_H_
#define RENDERTRIANGLE_H_

#include "gl_utils.h"
#include "my_log.h"

namespace TTRIANGLE {

static const char gVertexShader[] =
    "attribute vec4 vPosition;\n"
    "void main() {\n"
    "  gl_Position = vPosition;\n"
    "}\n";

static const char gFragmentShader[] =
    "precision mediump float;\n"
    "void main() {\n"
    "  gl_FragColor = vec4(1.0, 0.0, 1.0, 1.0);\n"
    "}\n";


GLuint gProgram;
GLuint gvPositionHandle;

bool setupGraphics(int w, int h) {
	GL::printGLString("Version", GL_VERSION);
	GL::printGLString("Vendor", GL_VENDOR);
	GL::printGLString("Renderer", GL_RENDERER);
	GL::printGLString("Extensions", GL_EXTENSIONS);

    LOGI("setupGraphics(%d, %d)", w, h);
    gProgram = GL::createProgram(gVertexShader, gFragmentShader);
    if (!gProgram) {
        LOGE("Could not create program.");
        return false;
    }
    gvPositionHandle = glGetAttribLocation(gProgram, "vPosition");
    GL::checkGlError("glGetAttribLocation");
    LOGI("glGetAttribLocation(\"vPosition\") = %d\n",
            gvPositionHandle);

    glViewport(0, 0, w, h);
    GL::checkGlError("glViewport");
    return true;
}

const GLfloat gTriangleVertices[] = { 0.0f, 0.5f, -0.5f, -0.5f,
        0.5f, -0.5f };

void renderFrame() {
    static float grey;
    grey += 0.01f;
    if (grey > 1.0f) {
        grey = 0.0f;
    }
    glClearColor(grey, grey, grey, 1.0f);
    GL::checkGlError("glClearColor");
    glClear( GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    GL::checkGlError("glClear");

    glUseProgram(gProgram);
    GL::checkGlError("glUseProgram");

    glVertexAttribPointer(gvPositionHandle, 2, GL_FLOAT, GL_FALSE, 0, gTriangleVertices);
    GL::checkGlError("glVertexAttribPointer");
    glEnableVertexAttribArray(gvPositionHandle);
    GL::checkGlError("glEnableVertexAttribArray");
    glDrawArrays(GL_TRIANGLES, 0, 3);
    GL::checkGlError("glDrawArrays");
}

}


#endif /* RENDERTRIANGLE_H_ */
