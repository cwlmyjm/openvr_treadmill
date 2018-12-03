#pragma once
#include <openvr_driver.h>
#include <easylogging++.h>
#include "JoyStick.h"

using namespace vr;

class CDeviceDriver
	: public ITrackedDeviceServerDriver
{
public:
	CDeviceDriver();
	~CDeviceDriver();
public:
	virtual EVRInitError Activate(uint32_t unObjectId) override;
	virtual void Deactivate() override;
	virtual void EnterStandby() override;
	virtual void *GetComponent(const char *pchComponentNameAndVersion) override;
	virtual void DebugRequest(const char *pchRequest, char *pchResponseBuffer, uint32_t unResponseBufferSize) override;
	virtual DriverPose_t GetPose() override;

	virtual void SingleLoop();

private:
	PropertyContainerHandle_t handle;
	JoyStick * joystick;

	VRInputComponentHandle_t trackpad_touch = vr::k_ulInvalidInputComponentHandle;
	VRInputComponentHandle_t trackpad_click = vr::k_ulInvalidInputComponentHandle;
	VRInputComponentHandle_t trackpad_x = vr::k_ulInvalidInputComponentHandle;
	VRInputComponentHandle_t trackpad_y = vr::k_ulInvalidInputComponentHandle;

	bool findJoyStick = false;
};

