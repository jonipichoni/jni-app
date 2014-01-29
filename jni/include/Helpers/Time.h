/*
 * Time.h
 *
 *  Created on: 28 Jan 2014
 *      Author: rogelio
 */

#ifndef TIME_H_
#define TIME_H_

#include "boost/timer.hpp"

class Time {
public:
	Time(float p_timeScale = 1.0);
	virtual ~Time();
	float elapsedTime() const;
	float deltaTime() const;
	float levelTime() const;
	void setTimeScale(float p_timeScale);
	float getTimeScale() const;
	//would probably have to implement a scene change observer
	void resetSceneTime();
private:
	float m_timeScale;
	float m_deltaTime;
	boost::timer m_timer;
	boost::timer m_sceneTime;
};

#endif /* TIME_H_ */
