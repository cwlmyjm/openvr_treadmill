#pragma once
#include <openvr_driver.h>
#include <easylogging++.h>
#include "CDeviceDriver.h"

using namespace vr;

class CServerProvider
	: public IServerTrackedDeviceProvider
{
public:
	CServerProvider();
	~CServerProvider();

public:
	virtual EVRInitError Init(IVRDriverContext *pDriverContext);
	virtual void Cleanup();
	virtual const char * const *GetInterfaceVersions();
	virtual void RunFrame();
	virtual bool ShouldBlockStandbyMode();
	virtual void EnterStandby();
	virtual void LeaveStandby();

private:
	CDeviceDriver * controller;
};

