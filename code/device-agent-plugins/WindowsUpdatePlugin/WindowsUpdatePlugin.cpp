// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

// WindowsUpdatePlugin.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "device-agent/common/plugins/PluginConstants.h"
#include "device-agent/common/plugins/PluginJsonConstants.h"
#include "device-agent/plugin-common/PluginStub.h"
#include "PluginJsonConstants.h"
#include "WindowsUpdateHandler.h"

using namespace std;
using namespace DMUtils;
using namespace DMCommon;

using namespace Microsoft::Azure::DeviceManagement::Plugin::Common;
using namespace Microsoft::Azure::DeviceManagement::WindowsUpdatePlugin;

PluginStub gPluginStub;
std::shared_ptr<IRawHandler> gWindowsUpdate;

std::shared_ptr<IRawHandler> CreateWindowsUpdateHandler()
{
    if (gWindowsUpdate == nullptr)
    {
        gWindowsUpdate = make_shared<WindowsUpdateHandler>();
    }
    return gWindowsUpdate;
}

int __stdcall PluginCreate()
{
    gPluginStub.Initialize();
    gPluginStub.RegisterRawHandler(WindowsUpdateHandlerId, CreateWindowsUpdateHandler);
    return DM_ERROR_SUCCESS;
}

#include "device-agent/plugin-common/PluginExports.h"
