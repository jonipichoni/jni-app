/*
 * Mesh.h
 *
 *  Created on: 28 Jan 2014
 *      Author: rogelio
 */

#ifndef MESH_H_
#define MESH_H_
#include <GLES2/gl2.h>
#include "boost/shared_ptr.hpp"

class Mesh {
public:
	typedef boost::shared_ptr<Mesh> MeshPtr;
	Mesh();
	virtual ~Mesh();

private:
	void bindVertices(const GLfloat* p_vertices);
	void bindTexCoord(const GLfloat* p_texCoords);
	void bindElements(const GLushort* p_elements);
	GLuint mVbo_vertices, mVbo_texcoords;
	GLuint mIbo_elements;
	GLsizei mVertices_size, mTexcoords_size ;
	GLsizei mElements_size;
};


#endif /* MESH_H_ */
