#include "stdafx.h"
#include "CDeviceDriver.h"



CDeviceDriver::CDeviceDriver()
{
	LOG(INFO) << "CServerProvider::Activate1";
	joystick = new JoyStick();
}


CDeviceDriver::~CDeviceDriver()
{
	LOG(INFO) << "CServerProvider::Activate1";
}

/*
/input/trackpad/x
/input/trackpad/y
/input/trackpad/click
/input/trackpad/touch
*/

EVRInitError CDeviceDriver::Activate(uint32_t unObjectId)
{
	auto properties = vr::VRProperties();
	LOG(INFO) << "CServerProvider::Activate1";

	if (joystick->open() == 0)
	{
		findJoyStick = true;
	}

	LOG(INFO) << "CServerProvider::Activate1";
	handle = vr::VRProperties()->TrackedDeviceToPropertyContainer(unObjectId);
	properties->SetStringProperty(handle, ETrackedDeviceProperty::Prop_InputProfilePath_String, "{openvr_treadmill}/input/openvr_treadmill_controller_profile.json");
	properties->SetBoolProperty(handle, ETrackedDeviceProperty::Prop_NeverTracked_Bool, true);
	properties->SetStringProperty(handle, Prop_ModelNumber_String, "openvr_treadmill_controller");
	properties->SetStringProperty(handle, Prop_RegisteredDeviceType_String, "openvr_treadmill_controller");
	properties->SetInt32Property(handle, vr::Prop_ControllerRoleHint_Int32, TrackedControllerRole_Treadmill);
	
	LOG(INFO) << "CServerProvider::Activate2";
	vr::VRDriverInput()->CreateBooleanComponent(handle, "/input/trackpad/touch", &trackpad_touch);
	vr::VRDriverInput()->CreateBooleanComponent(handle, "/input/trackpad/click", &trackpad_click);
	vr::VRDriverInput()->CreateScalarComponent(handle, "/input/trackpad/x", &trackpad_x, EVRScalarType::VRScalarType_Absolute, EVRScalarUnits::VRScalarUnits_NormalizedTwoSided);
	vr::VRDriverInput()->CreateScalarComponent(handle, "/input/trackpad/y", &trackpad_y, EVRScalarType::VRScalarType_Absolute, EVRScalarUnits::VRScalarUnits_NormalizedTwoSided);
	LOG(INFO) << "CServerProvider::Activate3";

	return EVRInitError::VRInitError_None;
}

void CDeviceDriver::Deactivate()
{
	LOG(INFO) << "CServerProvider::Deactivate";
}

void CDeviceDriver::EnterStandby()
{
	LOG(INFO) << "CServerProvider::EnterStandby";
}

void* CDeviceDriver::GetComponent(const char *pchComponentNameAndVersion)
{
	LOG(INFO) << "CServerProvider::GetComponent";
	return nullptr;
}

void CDeviceDriver::DebugRequest(const char *pchRequest, char *pchResponseBuffer, uint32_t unResponseBufferSize)
{
	LOG(INFO) << "CServerProvider::DebugRequest";
}

DriverPose_t CDeviceDriver::GetPose()
{
	LOG(INFO) << "CServerProvider::GetPose";
	DriverPose_t temp = { 0 };
	return temp;
}

void CDeviceDriver::SingleLoop()
{
	if (!findJoyStick)
	{
		if (joystick->open() != 0)
		{
			return;
		}
		findJoyStick = true;
	}

	JoyStickStatus jss;
	joystick->read(&jss);

	vr::VRDriverInput()->UpdateBooleanComponent(trackpad_touch, jss.lbu == 1, 0);
	vr::VRDriverInput()->UpdateBooleanComponent(trackpad_click, jss.lbd == 1, 0);

	if (jss.lbd == 1 || jss.lbu == 1)
	{
		float x = (float)jss.lx / 128.0f - 1;
		float y = (float)jss.ly / 128.0f - 1;
		vr::VRDriverInput()->UpdateScalarComponent(trackpad_x, x, 0);
		vr::VRDriverInput()->UpdateScalarComponent(trackpad_y, y, 0);
	}
}
