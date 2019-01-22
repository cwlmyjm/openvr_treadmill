#pragma once
#include <openvr_driver.h>

class ControllerWarpper
{
private:
	uint32_t m_unObjectId = 0;
	vr::PropertyContainerHandle_t m_handle = vr::k_ulInvalidPropertyContainer;
public:
	ControllerWarpper(uint32_t unObjectId);
	~ControllerWarpper();
	const uint32_t GetControllerId() { return m_unObjectId; };
	void CreateAllInputComponent();
private:
	vr::VRInputComponentHandle_t m_InputTrackpadTouch = vr::k_ulInvalidInputComponentHandle;
	vr::VRInputComponentHandle_t m_InputTrackpadClick = vr::k_ulInvalidInputComponentHandle;
	vr::VRInputComponentHandle_t m_InputTrackpadX = vr::k_ulInvalidInputComponentHandle;
	vr::VRInputComponentHandle_t m_InputTrackpadY = vr::k_ulInvalidInputComponentHandle;
	vr::VRInputComponentHandle_t m_InputTriggerTouch = vr::k_ulInvalidInputComponentHandle;
	vr::VRInputComponentHandle_t m_InputTriggerClick = vr::k_ulInvalidInputComponentHandle;
	vr::VRInputComponentHandle_t m_InputTriggerValue = vr::k_ulInvalidInputComponentHandle;
	vr::VRInputComponentHandle_t m_InputJoystickX = vr::k_ulInvalidInputComponentHandle;
	vr::VRInputComponentHandle_t m_InputJoystickY = vr::k_ulInvalidInputComponentHandle;
	vr::VRInputComponentHandle_t m_InputJoystickClick = vr::k_ulInvalidInputComponentHandle;
	vr::VRInputComponentHandle_t m_InputJoystickTouch = vr::k_ulInvalidInputComponentHandle;
	vr::VRInputComponentHandle_t m_InputGripValue = vr::k_ulInvalidInputComponentHandle;
	vr::VRInputComponentHandle_t m_InputSystemClick = vr::k_ulInvalidInputComponentHandle;
public:
	void UpdateInputTrackpadTouch(bool value, float offset = 0);
	void UpdateInputTrackpadClick(bool value, float offset = 0);
	void UpdateInputTrackpadX(float value, float offset = 0);
	void UpdateInputTrackpadY(float value, float offset = 0);
	void UpdateInputTriggerTouch(bool value, float offset = 0);
	void UpdateInputTriggerClick(bool value, float offset = 0);
	void UpdateInputTriggerValue(float value, float offset = 0);
	void UpdateInputJoystickX(float value, float offset = 0);
	void UpdateInputJoystickY(float value, float offset = 0);
	void UpdateInputJoystickClick(bool value, float offset = 0);
	void UpdateInputJoystickTouch(bool value, float offset = 0);
	void UpdateInputGripValue(float value, float offset = 0);
	void UpdateInputSystemClick(bool value, float offset = 0);
};

