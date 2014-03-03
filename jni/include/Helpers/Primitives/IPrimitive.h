/*
 * Primitives.h
 *
 *  Created on: 28 Jan 2014
 *      Author: rogelio
 */

#ifndef PRIMITIVES_H_
#define PRIMITIVES_H_




class Primitive {
public:
	Primitive();
	///virtual ~Primitive() = 0;
	virtual ~Primitive();
//TODO: not cool, anyone could mess with the arrays, but cant acces if protected
protected :
	/*GLfloat* _vertices;
	GLfloat* _texCoords;
	GLfloat* _elements;*/

protected:


};
#endif /* PRIMITIVES_H_ */
