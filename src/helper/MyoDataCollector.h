#pragma once

#include "ofMain.h"

#include <myo.hpp>

struct MyoFrameOrientationData
{
	uint64_t timestamp;
	ofQuaternion quaternion;

	float euler_roll;
	float euler_pitch;
	float euler_yaw;
};

struct MyoFramePoseData
{
	uint64_t timestamp;
	myo::Pose pose;
};

class MyoDataCollector : public myo::DeviceListener {
public:
    MyoDataCollector();

    // onOrientationData() is called whenever the Myo device provides its current orientation, which is represented
    // as a unit quaternion.
    void onOrientationData(myo::Myo* myo, uint64_t timestamp, const myo::Quaternion<float>& quat);

    // onPose() is called whenever the Myo detects that the person wearing it has changed their pose, for example,
    // making a fist, or not making a fist anymore.
    void onPose(myo::Myo* myo, uint64_t timestamp, myo::Pose pose);

    // There are other virtual functions in DeviceListener that we could override here, like onAccelerometerData().
    // For this example, the functions overridden above are sufficient.

    // We define this function to print the current values that were updated by the on...() functions above.
    void printDebug();

    // These values are set by onOrientationData() and onPose() above.
    int roll_w, pitch_w, yaw_w;
    myo::Pose currentPose;
};