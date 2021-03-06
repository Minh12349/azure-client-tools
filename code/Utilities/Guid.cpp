// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#include "stdafx.h"
#include "Guid.h"
#include "DMException.h"
#include <Rpc.h>

using namespace std;

namespace Microsoft { namespace Azure { namespace DeviceManagement { namespace Utils {

wstring Guid::NewGuid()
{
    UUID uuid;
    RPC_STATUS ret_val = ::UuidCreate(&uuid);
    if (ret_val == RPC_S_OK)
    {
        // convert UUID to LPWSTR
        WCHAR* wszUuid = NULL;
        ret_val = ::UuidToStringW(&uuid, (RPC_WSTR*)&wszUuid);
        if (wszUuid != NULL)
        {
            std::wstring guid(wszUuid);
            ::RpcStringFreeW((RPC_WSTR*)&wszUuid);
            return guid;
        }
        else
        {
            throw DMException(DMSubsystem::Windows, ret_val, "Failed to convert Uuid to string");
        }
    }
    else
    {
        throw DMException(DMSubsystem::Windows, ret_val, "Failed to create new Uuid");
    }
}
}}}}
