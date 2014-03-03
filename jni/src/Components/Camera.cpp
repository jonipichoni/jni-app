/*
 * Camera.cpp
 *
 *  Created on: 26 Feb 2014
 *      Author: rogelio
 */

#include "Components/Camera.h"

#include "glm/ext.hpp"
Camera::Camera(const GameObject& p_parent):IComponent(p_parent) {
	//todo::add to render manager
}

Camera::~Camera() {

}

void Camera::setPerspective(const float p_fovy, const float p_aspect, const float p_znear, const float p_zfar) {
	mProjection = glm::perspective(p_fovy, p_aspect, p_znear, p_zfar);
}
void Camera::setOrtho ( float p_left, float p_right, float p_bottom, float p_top, float p_znear, float p_zfar) {
	mProjection = glm::ortho(p_left, p_right,p_bottom, p_top, p_znear, p_zfar);
}

