#pragma once

#include "../ofxMyoDefines.h"
#include <myo.hpp>

class MyoDataCollector : public myo::DeviceListener 
{

public:
    MyoDataCollector();

	// overridden function of the listener
    void onOrientationData(myo::Myo* myo, uint64_t timestamp, const myo::Quaternion<float>& quat);
    void onPose(myo::Myo* myo, uint64_t timestamp, myo::Pose pose);

    void printDebug();

	MyoFrameOrientationData getCurrFrameOrientionData() const { return m_orientation_data; }
	MyoFramePoseData getCurrFramePoseData() const { return m_pose_data; }

private:

	MyoFrameOrientationData m_orientation_data;
	MyoFramePoseData m_pose_data;

};