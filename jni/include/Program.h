#ifndef PROGRAM_H
#define PROGRAM_H

#include <GLES2/gl2.h>
#include <boost/shared_ptr.hpp>
#include <map>
#include <string>

using namespace std;

class Program
{

public:

	Program(GLuint vertexShader, GLuint fragmentShader):
    	mVertexShader(vertexShader),
    	mFragmentShader(fragmentShader),
    	mProgramId(glCreateProgram()) {};

    virtual ~Program() {};

    GLint getAttributeLocation(string attributeName) {
    	return mAttributes[attributeName];
    }
    GLint getUniformLocation(string uniformName) {
    	return mUniforms[uniformName];
    }
    void setAttributeLocation(string attributeName,
    		GLint location) {
		mAttributes[attributeName] = location;
	}
	void setUniformLocation(string uniformName,
			GLint location) {
		mUniforms[uniformName] = location;
	}
    virtual GLuint getProgramId() const {
    	return mProgramId;
    }
    virtual GLuint getVertexShader() const {
		return mVertexShader;
	}
    virtual GLuint getFragmentShader() const {
    	return mFragmentShader;
    }


private:
    const GLuint mVertexShader;
    const GLuint mFragmentShader;
    const GLuint mProgramId;

    map<string, GLuint> mAttributes;
    map<string, GLint> mUniforms;

};

typedef boost::shared_ptr<Program> ProgramPtr;

#endif // PROGRAM_H
