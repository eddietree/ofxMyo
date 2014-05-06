#pragma once

#include "helper/MyoDataCollector.h"

#include "ofxMyoDefines.h"

class ofxMyo
{

public:

	// call this during initalization
	void setup();

	// call everyframe to fetch Myo frame data
	void update();

	// grab data
	MyoFrameOrientationData getCurrFrameOrientionData() const;
	MyoFramePoseData getCurrFramePoseData() const;

public:

	ofxMyo();
	~ofxMyo();

private:

	void release();

private:

	myo::Hub *m_hub;
	MyoDataCollector m_collector;

};