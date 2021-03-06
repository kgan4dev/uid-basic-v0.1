/******************************************************************************
 * Copyright (c) 2013-2014, AllSeen Alliance. All rights reserved.
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

#include <alljoyn/controlpanel/Action.h>
#include <alljoyn/controlpanel/ControlPanelService.h>
#include "../BusObjects/ActionBusObject.h"
#include "../ControlPanelConstants.h"
#include <alljoyn/controlpanel/LogModule.h>

namespace ajn {
namespace services {
using namespace cpsConsts;

Action::Action(qcc::String const& name, Widget* rootWidget) : Widget(name, rootWidget, ACTION)
{
}

Action::Action(qcc::String const& name, Widget* rootWidget, ControlPanelDevice* device) :
    Widget(name, rootWidget, device, ACTION)
{

}

Action::~Action()
{
}

WidgetBusObject* Action::createWidgetBusObject(BusAttachment* bus, qcc::String const& objectPath,
                                               uint16_t langIndx, QStatus& status)
{
    return new ActionBusObject(bus, objectPath, langIndx, status, this);
}

QStatus Action::executeAction()
{
    if (m_ControlPanelMode == CONTROLLEE_MODE) {
        QCC_DbgHLPrintf(("Cannot execute Action. Widget is a Controllee widget"));
        return ER_NOT_IMPLEMENTED;
    }

    if (!m_BusObjects.size()) {
        QCC_DbgHLPrintf(("Cannot execute Action. BusObject is not set"));
        return ER_BUS_BUS_NOT_STARTED;
    }

    return ((ActionBusObject*)m_BusObjects[0])->ExecuteAction();
}

bool Action::executeCallBack()
{
    return false;
}

} /* namespace services */
} /* namespace ajn */
