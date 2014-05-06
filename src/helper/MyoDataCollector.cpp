#include "MyoDataCollector.h"

#define _USE_MATH_DEFINES
#include <math.h>

MyoDataCollector::MyoDataCollector()
{
	memset( &m_orientation_data, 0, sizeof(m_orientation_data) );

	memset( &m_pose_data, 0, sizeof(m_pose_data) );
	m_pose_data.pose = myo::Pose();
}

void MyoDataCollector::onOrientationData(myo::Myo* myo, uint64_t timestamp, const myo::Quaternion<float>& quat)
{
    using std::atan2;
    using std::asin;
    using std::sqrt;

    // Calculate Euler angles (roll, pitch, and yaw) from the unit quaternion.
    float roll = atan2(2.0f * (quat.w() * quat.x() + quat.y() * quat.z()),
                        1.0f - 2.0f * (quat.x() * quat.x() + quat.y() * quat.y()));
    float pitch = asin(2.0f * (quat.w() * quat.y() - quat.z() * quat.x()));
    float yaw = atan2(2.0f * (quat.w() * quat.z() + quat.x() * quat.y()),
                    1.0f - 2.0f * (quat.y() * quat.y() + quat.z() * quat.z()));

	MyoFrameOrientationData & orient_data = m_orientation_data;
	orient_data.timestamp = timestamp;
	orient_data.quaternion = ofQuaternion( quat.x(), quat.y(), quat.z(), quat.w() );

    // Convert the floating point angles in radians to a scale from 0 to 20.
    orient_data.euler_roll = static_cast<int>((roll + (float)M_PI)/(M_PI * 2.0f) * 18);
    orient_data.euler_pitch = static_cast<int>((pitch + (float)M_PI/2.0f)/M_PI * 18);
	orient_data.euler_yaw = static_cast<int>((yaw + (float)M_PI)/(M_PI * 2.0f) * 18);
}

void MyoDataCollector::onPose(myo::Myo* myo, uint64_t timestamp, myo::Pose pose)
{
	MyoFramePoseData & pose_data = m_pose_data;
	pose_data.timestamp = timestamp;

	pose_data.pose = pose;

    // Vibrate the Myo whenever we've detected that the user has made a fist.
    if (pose == myo::Pose::fist) 
	{
        myo->vibrate(myo::Myo::VibrationMedium);
    }
}

void MyoDataCollector::printDebug()
{
	// orientation
	printf("Orientation (roll,pitch,yaw) : [%f,%f,%f])\n", m_orientation_data.euler_roll, m_orientation_data.euler_pitch, m_orientation_data.euler_yaw );

	// pose
    std::string poseString = m_pose_data.pose.toString();
	std::cout << "Pose at time " << m_pose_data.timestamp << ": " << poseString << std::endl;
}