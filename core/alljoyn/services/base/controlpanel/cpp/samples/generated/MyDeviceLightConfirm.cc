/******************************************************************************
 * Copyright (c) 2013, AllSeen Alliance. All rights reserved.
 *
 *    Permission to use, copy, modify, and/or distribute this software for any
 *    purpose with or without fee is hereby granted, provided that the above
 *    copyright notice and this permission notice appear in all copies.
 *
 *    THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 *    WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 *    MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 *    ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 *    WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 *    ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 *    OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 ******************************************************************************/

#include "MyDeviceLightConfirm.h"
#include "ControlPanelProvided.h"


namespace ajn {
namespace services {

MyDeviceLightConfirm::MyDeviceLightConfirm(qcc::String name, Widget* rootWidget) : Dialog(name, rootWidget)
{

}

MyDeviceLightConfirm::~MyDeviceLightConfirm()
{

}

bool MyDeviceLightConfirm::executeAction1CallBack()
{
    AJ_Printf("LED1 ON  : Execute Action1 was called\n");

    //by default return success
    return true;
}

bool MyDeviceLightConfirm::executeAction2CallBack()
{
    AJ_Printf("LED1 OFF : Execute Action2 was called\n");

    //by default return success
    return true;
}

bool MyDeviceLightConfirm::executeAction3CallBack()
{
    AJ_Printf("Execute Action3 was called\n");

    //by default return success
    return true;
}

MyDeviceNextLightConfirm::MyDeviceNextLightConfirm(qcc::String name, Widget* rootWidget) : Dialog(name, rootWidget)
{

}

MyDeviceNextLightConfirm::~MyDeviceNextLightConfirm()
{

}

bool MyDeviceNextLightConfirm::executeAction1CallBack()
{
    AJ_Printf("LED2 ON  : Execute Action1 was called\n");

    //by default return success
    return true;
}

bool MyDeviceNextLightConfirm::executeAction2CallBack()
{
    AJ_Printf("LED2 OFF : Execute Action2 was called\n");

    //by default return success
    return true;
}

bool MyDeviceNextLightConfirm::executeAction3CallBack()
{
    AJ_Printf("Execute Action3 was called\n");

    //by default return success
    return true;
}

MyDeviceYellowLightConfirm::MyDeviceYellowLightConfirm(qcc::String name, Widget* rootWidget) : Dialog(name, rootWidget)
{

}

MyDeviceYellowLightConfirm::~MyDeviceYellowLightConfirm()
{

}

bool MyDeviceYellowLightConfirm::executeAction1CallBack()
{
    AJ_Printf("LED3 ON  : Execute Action1 was called\n");

    //by default return success
    return true;
}

bool MyDeviceYellowLightConfirm::executeAction2CallBack()
{
    AJ_Printf("LED3 OFF : Execute Action2 was called\n");

    //by default return success
    return true;
}

bool MyDeviceYellowLightConfirm::executeAction3CallBack()
{
    AJ_Printf("Execute Action3 was called\n");

    //by default return success
    return true;
}

MyDeviceNextYellowLightConfirm::MyDeviceNextYellowLightConfirm(qcc::String name, Widget* rootWidget) : Dialog(name, rootWidget)
{

}

MyDeviceNextYellowLightConfirm::~MyDeviceNextYellowLightConfirm()
{

}

bool MyDeviceNextYellowLightConfirm::executeAction1CallBack()
{
    AJ_Printf("LED4 ON  : Execute Action1 was called\n");

    //by default return success
    return true;
}

bool MyDeviceNextYellowLightConfirm::executeAction2CallBack()
{
    AJ_Printf("LED4 OFF : Execute Action2 was called\n");

    //by default return success
    return true;
}

bool MyDeviceNextYellowLightConfirm::executeAction3CallBack()
{
    AJ_Printf("Execute Action3 was called\n");

    //by default return success
    return true;
}

MyDeviceGreenLightConfirm::MyDeviceGreenLightConfirm(qcc::String name, Widget* rootWidget) : Dialog(name, rootWidget)
{

}

MyDeviceGreenLightConfirm::~MyDeviceGreenLightConfirm()
{

}

bool MyDeviceGreenLightConfirm::executeAction1CallBack()
{
    AJ_Printf("LED5 ON  : Execute Action1 was called\n");

    //by default return success
    return true;
}

bool MyDeviceGreenLightConfirm::executeAction2CallBack()
{
    AJ_Printf("LED5 OFF : Execute Action2 was called\n");

    //by default return success
    return true;
}

bool MyDeviceGreenLightConfirm::executeAction3CallBack()
{
    AJ_Printf("Execute Action3 was called\n");

    //by default return success
    return true;
}

MyDeviceNextGreenLightConfirm::MyDeviceNextGreenLightConfirm(qcc::String name, Widget* rootWidget) : Dialog(name, rootWidget)
{

}

MyDeviceNextGreenLightConfirm::~MyDeviceNextGreenLightConfirm()
{

}

bool MyDeviceNextGreenLightConfirm::executeAction1CallBack()
{
    AJ_Printf("LED6 ON  : Execute Action1 was called\n");

    //by default return success
    return true;
}

bool MyDeviceNextGreenLightConfirm::executeAction2CallBack()
{
    AJ_Printf("LED6 OFF : Execute Action2 was called\n");

    //by default return success
    return true;
}

bool MyDeviceNextGreenLightConfirm::executeAction3CallBack()
{
    AJ_Printf("Execute Action3 was called\n");

    //by default return success
    return true;
}

} /* namespace services */
} /* namespace ajn */
