// dllmain.cpp : Defines the entry point for the DLL application.

#include <windows.h>
#include <comdef.h>
#include "YourComInterface.h"  // Include your COM interface header

// Global variable to hold your COM object
IYourComInterface* pYourComInterface = nullptr;

BOOL APIENTRY DllMain(HMODULE hModule,  
                      DWORD  ul_reason_for_call,  
                      LPVOID lpReserved)  
{ 
    switch (ul_reason_for_call)  
    {  
    case DLL_PROCESS_ATTACH:
        // Initialize COM
        OleInitialize(nullptr);
        break;
    case DLL_PROCESS_DETACH:
        // Clean up COM
        if (pYourComInterface)  
        {  
            pYourComInterface->Release();  
            pYourComInterface = nullptr;  
        }
        OleUninitialize();  
        break;  
    }
    return TRUE;  
}

// DLL registration function
HRESULT RegisterCOM()
{
    // Register your COM object here
    // ...
    return S_OK;
}

HRESULT UnregisterCOM()
{
    // Unregister your COM object here
    // ...
    return S_OK;
}

// Update the friendlyName and hardware ID
const WCHAR* friendlyName = L"Integrated HD Camera";
const WCHAR* hardwareId = L"USB\VID_046D&PID_082D";

