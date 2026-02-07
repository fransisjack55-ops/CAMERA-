// MFSource.h

#ifndef MFSOURCE_H
#define MFSOURCE_H

#include <mfapi.h> // Media Foundation API
#include <mfobjects.h> // Media Foundation Objects

class StealthCamMFSource
{
public:
    StealthCamMFSource();
    ~StealthCamMFSource();
    HRESULT Initialize();
    HRESULT Start();
    HRESULT Stop();
    // Other necessary methods...
};

class StealthCamStream
{
public:
    StealthCamStream();
    ~StealthCamStream();
    HRESULT StartStreaming();
    HRESULT StopStreaming();
    // Other necessary methods...
};

#endif // MFSOURCE_H