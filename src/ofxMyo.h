#pragma once

#include "helper/MyoDataCollector.h"


class ofxMyo
{


public:

	ofxMyo();
	~ofxMyo();

	void setup();
	void update();

private:

	void release();

private:

	myo::Hub *m_hub;
	MyoDataCollector m_collector;

};