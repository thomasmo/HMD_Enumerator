// hmdenum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "openvr/headers/openvr.h"

int main()
{
    std::cout << "HMD_Enumerator\n"; 
	printf("vr::VR_IsRuntimeInstalled -- %u\n", ::vr::VR_IsRuntimeInstalled());
	printf("vr::VR_IsHmdPresent -- %u\n", ::vr::VR_IsHmdPresent());
	vr::HmdError eError;
	
	::vr::IVRSystem* mVRSystemU = ::vr::VR_Init(&eError, ::vr::VRApplication_Utility);
	if (mVRSystemU != nullptr)
	{
		bool isConnectedU = mVRSystemU->IsTrackedDeviceConnected(::vr::k_unTrackedDeviceIndex_Hmd);
		printf("vr::IVRSystem::IsTrackedDeviceConnected -- %u\n", isConnectedU);
	}
	else
	{
		std::cout << "Failed to create Utility";
	}

	::vr::IVRSystem* mVRSystemS = ::vr::VR_Init(&eError, ::vr::VRApplication_Scene);
	if (mVRSystemS != nullptr)
	{
		bool isConnectedS = mVRSystemS->IsTrackedDeviceConnected(::vr::k_unTrackedDeviceIndex_Hmd);
		printf("vr::IVRSystem::IsTrackedDeviceConnected -- %u\n", isConnectedS);
	}
	else
	{
		std::cout << "Failed to create Scene";
	}
}
