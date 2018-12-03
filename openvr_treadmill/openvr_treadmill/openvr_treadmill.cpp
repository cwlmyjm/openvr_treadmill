// openvr_treadmill.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include <openvr_driver.h>
#include <easylogging++.h>

INITIALIZE_EASYLOGGINGPP

#define HMD_DLL_EXPORT extern "C" __declspec( dllexport )

HMD_DLL_EXPORT void *HmdDriverFactory(const char *pInterfaceName, int *pReturnCode)
{
	if (0 == strcmp(vr::IServerTrackedDeviceProvider_Version, pInterfaceName))
	{
		return NULL;
	}
	else if (0 == strcmp(vr::IVRWatchdogProvider_Version, pInterfaceName))
	{
		return NULL;
	}

	if (pReturnCode)
		*pReturnCode = vr::VRInitError_Init_InterfaceNotFound;

	return NULL;
}