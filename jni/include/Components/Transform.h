/*
 * Transform.h
 *
 *  Created on: 27 Jan 2014
 *      Author: rogelio
 */

#ifndef TRANSFORM_H_
#define TRANSFORM_H_

#include "Components/IComponent.h"
#include "glm/glm.hpp"
#include "glm/gtc/quaternion.hpp"

class Transform : public IComponent {
public:
	glm::vec3 mPos;
	glm::quat mRot;
	Transform(const GameObject& p_parent);
	virtual ~Transform();
	std::string getComponentType() {return std::string("Transform");};
};

#endif /* TRANSFORM_H_ */
