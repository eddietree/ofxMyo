#pragma once

#include "ofMain.h"

#include <myo.hpp>

struct MyoFrameOrientationData
{
	uint64_t timestamp;
	ofQuaternion quaternion;

	// in radians
	float euler_roll;
	float euler_pitch;
	float euler_yaw;
};

struct MyoFramePoseData
{
	uint64_t timestamp;
	myo::Pose pose;
};