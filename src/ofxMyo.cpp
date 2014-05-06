#include "ofxMyo.h"

ofxMyo::ofxMyo() : m_hub(nullptr)
{
}

ofxMyo::~ofxMyo()
{
	release();
}

void ofxMyo::setup()
{
	try
	{
		m_hub = new myo::Hub;

		std::cout << "Attempting to find a Myo..." << std::endl;

		// Next, we try to find a Myo (any Myo) that's nearby and connect to it. waitForAnyMyo() takes a timeout
		// value in milliseconds. In this case we will try to find a Myo for 10 seconds, and if that fails, the function
		// will return a null pointer.
		const int wait_num_ms = 10000;
		myo::Myo* myo = m_hub->waitForAnyMyo(wait_num_ms);

		// If waitForAnyMyo() returned a null pointer, we failed to find a Myo, so exit with an error message.
		if (!myo) 
		{
			throw std::runtime_error("Unable to find a Myo!");
		}

		// We've found a Myo, let's output its MAC address.
		std::cout << "Connected to " << myo->macAddressAsString() << "." << std::endl << std::endl;

		// Check if the Myo has been trained. If it hasn't been trained, it will still function, but it won't generate any
		// pose events.
		if (!myo->isTrained()) 
		{
			throw std::runtime_error("Myo has not been trained. Do you need to run the trainer?");
		}

		// Hub::addListener() takes the address of any object whose class inherits from DeviceListener, and will cause
		// Hub::run() to send events to all registered device listeners.
		m_hub->addListener(&m_collector);
	}

	catch (const std::exception& e) 
	{
		std::cerr << "Error: " << e.what() << std::endl;
		release();
    }
}

void ofxMyo::update()
{
	if ( m_hub )
	{
		const int run_num_ms = 1;
		m_hub->run(1);
	}
}


void ofxMyo::printDebug()
{
	if ( m_hub )
	{
		m_collector.printDebug();
	}
}


void ofxMyo::release()
{
	if ( m_hub ) 
	{
		delete m_hub;
		m_hub = nullptr;
	}
}

MyoFrameOrientationData ofxMyo::getCurrFrameOrientionData() const
{
	return m_collector.getCurrFrameOrientionData();
}

MyoFramePoseData ofxMyo::getCurrFramePoseData() const
{
	return m_collector.getCurrFramePoseData();
}