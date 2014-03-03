/*
 * Transform.cpp
 *
 *  Created on: 27 Jan 2014
 *      Author: rogelio
 */

#include "Components/Transform.h"

Transform::Transform(const GameObject& p_parent):IComponent(p_parent)  {
	mPos = glm::vec3(0,0,0);
	mRot = glm::quat(0,0,0,1);
}

Transform::~Transform() {
	// TODO Auto-generated destructor stub
}

