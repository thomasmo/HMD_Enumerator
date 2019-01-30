// hmdenum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "openvr/headers/openvr.h"

int main()
{
    std::cout << "HMD_Enumerator\n"; 
	printf("vr::VR_IsRuntimeInstalled -- %u\n", ::vr::VR_IsRuntimeInstalled());
	vr::HmdError eError;
	::vr::IVRSystem* mVRSystem = ::vr::VR_Init(&eError, ::vr::VRApplication_Scene);
	bool isConnected = mVRSystem->IsTrackedDeviceConnected(::vr::k_unTrackedDeviceIndex_Hmd);
	printf("vr::IVRSystem::IsTrackedDeviceConnected -- %u\n", isConnected);
}
