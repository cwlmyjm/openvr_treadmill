#include "stdafx.h"
#include "ControllerWarpper.h"


ControllerWarpper::ControllerWarpper(uint32_t unObjectId)
{
	m_unObjectId = unObjectId;
	m_handle = vr::VRProperties()->TrackedDeviceToPropertyContainer(m_unObjectId);
}


ControllerWarpper::~ControllerWarpper()
{

}

#define CreateBool(handle, path) {\
	if (handle == vr::k_ulInvalidInputComponentHandle)\
	{\
		vr::VRDriverInput()->CreateBooleanComponent(m_handle, path, &handle);\
	}\
}

#define CreateFloat(handle, path, eType, eUnits) {\
	if (handle == vr::k_ulInvalidInputComponentHandle)\
	{\
		vr::VRDriverInput()->CreateScalarComponent(m_handle, path, &handle, eType, eUnits);\
	}\
}

void ControllerWarpper::CreateAllInputComponent()
{
	CreateBool(m_InputTrackpadTouch, "/input/trackpad/touch");
	CreateBool(m_InputTrackpadClick, "/input/trackpad/click");
	CreateFloat(m_InputTrackpadX, "/input/trackpad/x", vr::EVRScalarType::VRScalarType_Absolute, vr::EVRScalarUnits::VRScalarUnits_NormalizedTwoSided);
	CreateFloat(m_InputTrackpadY, "/input/trackpad/y", vr::EVRScalarType::VRScalarType_Absolute, vr::EVRScalarUnits::VRScalarUnits_NormalizedTwoSided);
	CreateBool(m_InputTriggerTouch, "/input/trigger/touch");
	CreateBool(m_InputTriggerClick, "/input/trigger/click");
	CreateFloat(m_InputTriggerValue, "/input/trigger/value", vr::EVRScalarType::VRScalarType_Absolute, vr::EVRScalarUnits::VRScalarUnits_NormalizedOneSided);
	CreateFloat(m_InputJoystickX, "/input/joystick/x", vr::EVRScalarType::VRScalarType_Absolute, vr::EVRScalarUnits::VRScalarUnits_NormalizedTwoSided);
	CreateFloat(m_InputJoystickY, "/input/joystick/y", vr::EVRScalarType::VRScalarType_Absolute, vr::EVRScalarUnits::VRScalarUnits_NormalizedTwoSided);
	CreateBool(m_InputJoystickClick, "/input/joystick/click");
	CreateBool(m_InputJoystickTouch, "/input/joystick/touch");
	CreateFloat(m_InputGripValue, "/input/grip/value", vr::EVRScalarType::VRScalarType_Absolute, vr::EVRScalarUnits::VRScalarUnits_NormalizedOneSided);
}

#define UpdateBool(handle, path) {\
	if (handle == vr::k_ulInvalidInputComponentHandle)\
	{\
		vr::VRDriverInput()->CreateBooleanComponent(m_handle, path, &handle);\
	}\
	vr::VRDriverInput()->UpdateBooleanComponent(handle, value, offset);\
}

#define UpdateFloat(handle, path, eType, eUnits) {\
	if (handle == vr::k_ulInvalidInputComponentHandle)\
	{\
		vr::VRDriverInput()->CreateScalarComponent(m_handle, path, &handle, eType, eUnits);\
	}\
	vr::VRDriverInput()->UpdateScalarComponent(handle, value, offset);\
}

void ControllerWarpper::UpdateInputTrackpadTouch(bool value, float offset)
{
	UpdateBool(m_InputTrackpadTouch, "/input/trackpad/touch");
}

void ControllerWarpper::UpdateInputTrackpadClick(bool value, float offset)
{
	UpdateBool(m_InputTrackpadClick, "/input/trackpad/click");
}

void ControllerWarpper::UpdateInputTrackpadX(float value, float offset)
{
	UpdateFloat(m_InputTrackpadX, "/input/trackpad/x", vr::EVRScalarType::VRScalarType_Absolute, vr::EVRScalarUnits::VRScalarUnits_NormalizedTwoSided);
}

void ControllerWarpper::UpdateInputTrackpadY(float value, float offset)
{
	UpdateFloat(m_InputTrackpadY, "/input/trackpad/y", vr::EVRScalarType::VRScalarType_Absolute, vr::EVRScalarUnits::VRScalarUnits_NormalizedTwoSided);
}


void ControllerWarpper::UpdateInputTriggerTouch(bool value, float offset)
{
	UpdateBool(m_InputTriggerTouch, "/input/trigger/touch");
}

void ControllerWarpper::UpdateInputTriggerClick(bool value, float offset)
{
	UpdateBool(m_InputTriggerClick, "/input/trigger/click");
}

void ControllerWarpper::UpdateInputTriggerValue(float value, float offset)
{
	UpdateFloat(m_InputTriggerValue, "/input/trigger/value", vr::EVRScalarType::VRScalarType_Absolute, vr::EVRScalarUnits::VRScalarUnits_NormalizedOneSided);
}

void ControllerWarpper::UpdateInputJoystickX(float value, float offset)
{
	UpdateFloat(m_InputJoystickX, "/input/joystick/x", vr::EVRScalarType::VRScalarType_Absolute, vr::EVRScalarUnits::VRScalarUnits_NormalizedTwoSided);
}

void ControllerWarpper::UpdateInputJoystickY(float value, float offset)
{
	UpdateFloat(m_InputJoystickY, "/input/joystick/y", vr::EVRScalarType::VRScalarType_Absolute, vr::EVRScalarUnits::VRScalarUnits_NormalizedTwoSided);
}

void ControllerWarpper::UpdateInputJoystickClick(bool value, float offset)
{
	UpdateBool(m_InputJoystickClick, "/input/joystick/click");
}

void ControllerWarpper::UpdateInputJoystickTouch(bool value, float offset)
{
	UpdateBool(m_InputJoystickTouch, "/input/joystick/touch");
}

void ControllerWarpper::UpdateInputGripValue(float value, float offset)
{
	UpdateFloat(m_InputGripValue, "/input/grip/value", vr::EVRScalarType::VRScalarType_Absolute, vr::EVRScalarUnits::VRScalarUnits_NormalizedOneSided);
}

void ControllerWarpper::UpdateInputSystemClick(bool value, float offset)
{
	UpdateBool(m_InputSystemClick, "/input/system/click");
}
