#ifndef CUBE_H
#define CUBE_H

#include "opengl.h"
#include "glm/glm.hpp"
#include "Program.h"

class Cube 
{
    
public:
    Cube();
    virtual ~Cube() 
    {
    }
    
    void draw(ProgramPtr program);

private:
    void initGeometry();
    GLuint vbo_cube_vertices, vbo_cube_texcoords;
    GLuint ibo_cube_elements;
    
};

#endif // CUBE_H
