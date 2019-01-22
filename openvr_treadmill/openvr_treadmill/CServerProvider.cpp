#include "stdafx.h"
#include "CServerProvider.h"


CServerProvider::CServerProvider()
{
	el::Configurations conf("log.conf");
	el::Loggers::reconfigureAllLoggers(conf);
	LOG(INFO) << "CServerProvider::CServerProvider";
}

CServerProvider::~CServerProvider()
{
}

EVRInitError CServerProvider::Init(IVRDriverContext *pDriverContext)
{
	LOG(INFO) << "CServerProvider::Init";
	VR_INIT_SERVER_DRIVER_CONTEXT(pDriverContext);

	// init drivers and add it to vr host
	controller = new CDeviceDriver();
	vr::VRServerDriverHost()->TrackedDeviceAdded("openvr_treadmill", vr::TrackedDeviceClass_Controller, controller);

	return EVRInitError::VRInitError_None;
}

void CServerProvider::Cleanup()
{
	// clean drivers and remove it from vr host
	LOG(INFO) << "CServerProvider::Cleanup";
}

const char * const * CServerProvider::GetInterfaceVersions()
{
	LOG(INFO) << "CServerProvider::GetInterfaceVersions";
	return k_InterfaceVersions;
}

void CServerProvider::RunFrame()
{
	// call SingleLoop in drivers per frame
	LOG(INFO) << "CServerProvider::RunFrame";
	controller->SingleLoop();
}

bool CServerProvider::ShouldBlockStandbyMode()
{
	LOG(INFO) << "CServerProvider::ShouldBlockStandbyMode";
	return false;
}

void CServerProvider::EnterStandby()
{
	LOG(INFO) << "CServerProvider::EnterStandby";
}

void CServerProvider::LeaveStandby()
{
	LOG(INFO) << "CServerProvider::LeaveStandby";
}
