/*
 * Mesh.cpp
 *
 *  Created on: 28 Jan 2014
 *      Author: rogelio
 */

#include "AssetComponents/Mesh.h"

Mesh::Mesh() {
	// TODO Auto-generated constructor stub

}

Mesh::~Mesh() {
	glDeleteBuffers(1, &mVbo_vertices);
	glDeleteBuffers(1, &mVbo_texcoords);
	glDeleteBuffers(1, &mIbo_elements);

}

void Mesh::bindVertices(const GLfloat* p_vertices) {
	glGenBuffers(1, &mVbo_vertices);
	glBindBuffer(GL_ARRAY_BUFFER, mVbo_vertices);
	glBufferData(GL_ARRAY_BUFFER, sizeof(p_vertices), p_vertices, GL_STATIC_DRAW);
#ifdef _DEBUG
	GLenum error = glGetError();
	if (error != GL_NO_ERROR) {
		printGLError(error);
	}
#endif
}

void Mesh::bindTexCoord(const GLfloat* p_texCoords) {
	glGenBuffers(1, &mVbo_texcoords);
	glBindBuffer(GL_ARRAY_BUFFER, mVbo_texcoords);
	glBufferData(GL_ARRAY_BUFFER, sizeof(p_texCoords), p_texCoords, GL_STATIC_DRAW);
#ifdef _DEBUG
	GLenum error = glGetError();
	if (error != GL_NO_ERROR) {
		printGLError(error);
	}
#endif
}

void Mesh::bindElements(const GLushort* p_elements) {
	glGenBuffers(1, &mIbo_elements);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIbo_elements);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(p_elements), p_elements, GL_STATIC_DRAW);
#ifdef _DEBUG
	GLenum error = glGetError();
	if (error != GL_NO_ERROR) {
		printGLError(error);
	}
#endif
}
