#ifndef CUBE_H
#define CUBE_H

#include <GLES2/gl2.h>
#include "glm/glm.hpp"
#include "ShaderProgram.h"

class Cube 
{
    
public:
    Cube();
    virtual ~Cube() 
    {
    }
    
    void draw(ShaderProgram *shaderProgram);

private:
    void initGeometry();
    GLuint vbo_cube_vertices, vbo_cube_texcoords;
    GLuint ibo_cube_elements;
    
};

#endif // CUBE_H
