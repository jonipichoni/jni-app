/*
 * Camera.h
 *
 *  Created on: 26 Feb 2014
 *      Author: rogelio
 */

#ifndef CAMERA_H_
#define CAMERA_H_

#include "Components/IComponent.h"
#include "glm/glm.hpp"

#include <string>

class Camera :public IComponent {
public:
	typedef boost::shared_ptr<Camera> CameraPtr;
	Camera(const GameObject& p_parent);
	virtual ~Camera();
	glm::mat4 mProjection;
	std::string getComponentType() {
		return std::string("Camera");
	}
	void setPerspective(const float p_fovy, const float p_aspect, const float p_znear, const float p_zfar);
	void setOrtho ( float p_left, float p_right, float p_bottom, float p_top, float p_znear, float p_zfar);
	glm::mat4 getProjection() const  {
		return mProjection;
	}
};

#endif /* CAMERA_H_ */
