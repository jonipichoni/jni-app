/*
 * Time.cpp
 *
 *  Created on: 28 Jan 2014
 *      Author: rogelio
 */

#include "Helpers/Time.h"
//todo::if class is not gonna grow any further could be implemented in the h file as inline functions.
Time::Time(float p_timeScale = 1f) {
	m_timeScale = p_timeScale;
}

Time::~Time() {
	// TODO Auto-generated destructor stub
}
float Time::elapsedTime() const{
	return m_timer.elapsed();
}

float Time::deltaTime() const{
	return m_timer.elapsed()*m_timeScale;
}

float Time::levelTime() const{
	return m_sceneTime.elapsed();
}

void Time::setTimeScale(float p_timeScale) {
	m_timeScale = p_timeScale;
}

float Time::getTimeScale() const {
	return m_timeScale;
}

//would probably have to implement a scene change observer
void Time::resetSceneTime() {
	m_sceneTime.restart();
}

