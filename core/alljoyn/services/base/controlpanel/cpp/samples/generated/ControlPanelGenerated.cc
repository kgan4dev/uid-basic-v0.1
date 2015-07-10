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

#include "ControlPanelGenerated.h"
#include <alljoyn/controlpanel/LanguageSets.h>
#include <alljoyn/controlpanel/Label.h>
#include "ControlPanelProvided.h"

using namespace ajn;
using namespace services;

bool ControlPanelGenerated::languageSetsDone = false;
ControlPanelControlleeUnit* ControlPanelGenerated::myDeviceUnit = 0;
ControlPanel* ControlPanelGenerated::myDeviceRootContainerControlPanel = 0;
Container* ControlPanelGenerated::myDeviceRootContainer = 0;
Label* ControlPanelGenerated::myDeviceCurrentTemp = 0;
MyDeviceHeatProperty* ControlPanelGenerated::myDeviceHeatProperty = 0;
MyDeviceOvenAction* ControlPanelGenerated::myDeviceOvenAction = 0;
ActionWithDialog* ControlPanelGenerated::myDeviceLightAction = 0;
MyDeviceLightConfirm* ControlPanelGenerated::myDeviceLightConfirm = 0;
NotificationAction* ControlPanelGenerated::myDeviceAreYouSureNotificationAction = 0;
MyDeviceAreYouSure* ControlPanelGenerated::myDeviceAreYouSure = 0;


ActionWithDialog* ControlPanelGenerated::myDeviceNextLightAction = 0;
MyDeviceNextLightConfirm* ControlPanelGenerated::myDeviceNextLightConfirm = 0;

ActionWithDialog* ControlPanelGenerated::myDeviceYellowLightAction = 0;
MyDeviceYellowLightConfirm* ControlPanelGenerated::myDeviceYellowLightConfirm = 0;

ActionWithDialog* ControlPanelGenerated::myDeviceNextYellowLightAction = 0;
MyDeviceNextYellowLightConfirm* ControlPanelGenerated::myDeviceNextYellowLightConfirm = 0;

ActionWithDialog* ControlPanelGenerated::myDeviceGreenLightAction = 0;
MyDeviceGreenLightConfirm* ControlPanelGenerated::myDeviceGreenLightConfirm = 0;

ActionWithDialog* ControlPanelGenerated::myDeviceNextGreenLightAction = 0;
MyDeviceNextGreenLightConfirm* ControlPanelGenerated::myDeviceNextGreenLightConfirm = 0;

#define CHECK(x) if ((status = x) != ER_OK) { return status; }

void ControlPanelGenerated::PrepareLanguageSets()
{
    if (languageSetsDone) {
        return;
    }

    LanguageSet myDeviceMyLanguages("myDeviceMyLanguages");
    myDeviceMyLanguages.addLanguage("en");
    myDeviceMyLanguages.addLanguage("de_AT");
    myDeviceMyLanguages.addLanguage("zh_Hans_CN");
    LanguageSets::add(myDeviceMyLanguages.getLanguageSetName(), myDeviceMyLanguages);

    languageSetsDone = true;
}

QStatus ControlPanelGenerated::PrepareWidgets(ControlPanelControllee*& controlPanelControllee)
{
    if (controlPanelControllee) {
        return ER_BAD_ARG_1;
    }

    PrepareLanguageSets();

    QStatus status = ER_OK;
    controlPanelControllee = new ControlPanelControllee();

    myDeviceUnit = new ControlPanelControlleeUnit("MyDevice");
    CHECK(controlPanelControllee->addControlPanelUnit(myDeviceUnit));

    myDeviceRootContainerControlPanel = ControlPanel::createControlPanel(LanguageSets::get("myDeviceMyLanguages"));
    if (!myDeviceRootContainerControlPanel) {
        return ER_FAIL;
    }
    CHECK(myDeviceUnit->addControlPanel(myDeviceRootContainerControlPanel));

    myDeviceRootContainer = new Container("rootContainer", NULL);
    CHECK(myDeviceRootContainerControlPanel->setRootWidget(myDeviceRootContainer));

    myDeviceRootContainer->setEnabled(true);
    myDeviceRootContainer->setIsSecured(false);
    myDeviceRootContainer->setBgColor(0x200);

    std::vector<qcc::String> myDeviceRootContainerlabelVec;
    myDeviceRootContainerlabelVec.push_back("Berry Clip LEDs Controller");
    myDeviceRootContainerlabelVec.push_back("Container Etikett");
    myDeviceRootContainerlabelVec.push_back(UNICODE_MY_LABEL_CONTAINER);
    myDeviceRootContainer->setLabels(myDeviceRootContainerlabelVec);

    std::vector<uint16_t> myDeviceRootContainerHintsVec;
    myDeviceRootContainerHintsVec.push_back(VERTICAL_LINEAR);
    myDeviceRootContainerHintsVec.push_back(HORIZONTAL_LINEAR);
    myDeviceRootContainer->setHints(myDeviceRootContainerHintsVec);
/*
    myDeviceCurrentTemp = new Label("CurrentTemp", myDeviceRootContainer);
    CHECK(myDeviceRootContainer->addChildWidget(myDeviceCurrentTemp));

    myDeviceCurrentTemp->setEnabled(true);
    myDeviceCurrentTemp->setBgColor(0x98765);

    std::vector<qcc::String> myDeviceCurrentTemplabelVec;
    myDeviceCurrentTemplabelVec.push_back("Current Temperature:");
    myDeviceCurrentTemplabelVec.push_back("Aktuelle Temperatur:");
    myDeviceCurrentTemplabelVec.push_back(UNICODE_CURENT_TEMPERATURE);
    myDeviceCurrentTemp->setLabels(myDeviceCurrentTemplabelVec);

    std::vector<uint16_t> myDeviceCurrentTempHintsVec;
    myDeviceCurrentTempHintsVec.push_back(TEXTLABEL);
    myDeviceCurrentTemp->setHints(myDeviceCurrentTempHintsVec);

    myDeviceHeatProperty = new MyDeviceHeatProperty("heatProperty", myDeviceRootContainer, UINT16_PROPERTY);
    CHECK(myDeviceRootContainer->addChildWidget(myDeviceHeatProperty));

    myDeviceHeatProperty->setEnabled(true);
    myDeviceHeatProperty->setIsSecured(false);
    myDeviceHeatProperty->setWritable(true);
    CHECK(myDeviceHeatProperty->setGetValue(getuint16Var));
    myDeviceHeatProperty->setBgColor(0x500);

    std::vector<qcc::String> myDeviceHeatPropertylabelVec;
    myDeviceHeatPropertylabelVec.push_back("Oven Temperature");
    myDeviceHeatPropertylabelVec.push_back("Ofentemperatur");
    myDeviceHeatPropertylabelVec.push_back(UNICODE_OVEN_TEMPERATURE);
    myDeviceHeatProperty->setLabels(myDeviceHeatPropertylabelVec);

    std::vector<uint16_t> myDeviceHeatPropertyHintsVec;
    myDeviceHeatPropertyHintsVec.push_back(SPINNER);
    myDeviceHeatProperty->setHints(myDeviceHeatPropertyHintsVec);

    std::vector<qcc::String> myDeviceHeatPropertyunitMeasureVec;
    myDeviceHeatPropertyunitMeasureVec.push_back("Degrees");
    myDeviceHeatPropertyunitMeasureVec.push_back("Grad");
    myDeviceHeatPropertyunitMeasureVec.push_back(UNICODE_DEGREES);
    myDeviceHeatProperty->setUnitOfMeasures(myDeviceHeatPropertyunitMeasureVec);

    std::vector<ConstraintList> myDeviceHeatPropertyConstraintListVec(3);

    std::vector<qcc::String> myDeviceHeatPropertyDisplay1Vec;
    myDeviceHeatPropertyDisplay1Vec.push_back("Regular");
    myDeviceHeatPropertyDisplay1Vec.push_back("Normal");
    myDeviceHeatPropertyDisplay1Vec.push_back(UNICODE_REGULAR);
    myDeviceHeatPropertyConstraintListVec[0].setDisplays(myDeviceHeatPropertyDisplay1Vec);
    myDeviceHeatPropertyConstraintListVec[0].setConstraintValue((uint16_t)175);

    std::vector<qcc::String> myDeviceHeatPropertyDisplay2Vec;
    myDeviceHeatPropertyDisplay2Vec.push_back("Hot");
    myDeviceHeatPropertyDisplay2Vec.push_back("Heiss");
    myDeviceHeatPropertyDisplay2Vec.push_back(UNICODE_HOT);
    myDeviceHeatPropertyConstraintListVec[1].setDisplays(myDeviceHeatPropertyDisplay2Vec);
    myDeviceHeatPropertyConstraintListVec[1].setConstraintValue((uint16_t)200);

    std::vector<qcc::String> myDeviceHeatPropertyDisplay3Vec;
    myDeviceHeatPropertyDisplay3Vec.push_back("Very Hot");
    myDeviceHeatPropertyDisplay3Vec.push_back("Sehr Heiss");
    myDeviceHeatPropertyDisplay3Vec.push_back(UNICODE_VERY_HOT);
    myDeviceHeatPropertyConstraintListVec[2].setDisplays(myDeviceHeatPropertyDisplay3Vec);
    myDeviceHeatPropertyConstraintListVec[2].setConstraintValue((uint16_t)225);

    myDeviceHeatProperty->setConstraintList(myDeviceHeatPropertyConstraintListVec);

    myDeviceOvenAction = new MyDeviceOvenAction("ovenAction", myDeviceRootContainer);
    CHECK(myDeviceRootContainer->addChildWidget(myDeviceOvenAction));

    myDeviceOvenAction->setEnabled(true);
    myDeviceOvenAction->setIsSecured(false);
    myDeviceOvenAction->setBgColor(0x400);

    std::vector<qcc::String> myDeviceOvenActionlabelVec;
    myDeviceOvenActionlabelVec.push_back("Start Oven");
    myDeviceOvenActionlabelVec.push_back("Ofen started");
    myDeviceOvenActionlabelVec.push_back(UNICODE_START_OVEN);
    myDeviceOvenAction->setLabels(myDeviceOvenActionlabelVec);

    std::vector<uint16_t> myDeviceOvenActionHintsVec;
    myDeviceOvenActionHintsVec.push_back(ACTIONBUTTON);
    myDeviceOvenAction->setHints(myDeviceOvenActionHintsVec);
*/
    myDeviceLightAction = new ActionWithDialog("lightAction", myDeviceRootContainer);
    CHECK(myDeviceRootContainer->addChildWidget(myDeviceLightAction));

    myDeviceLightAction->setEnabled(true);
    myDeviceLightAction->setIsSecured(false);
    myDeviceLightAction->setBgColor(0x400);

    std::vector<qcc::String> myDeviceLightActionlabelVec;
    myDeviceLightActionlabelVec.push_back("RED LED 1");
    myDeviceLightActionlabelVec.push_back("Ofenlicht anschalten");
    myDeviceLightActionlabelVec.push_back(UNICODE_TURN_ON_OVEN_LIGHT);
    myDeviceLightAction->setLabels(myDeviceLightActionlabelVec);

    std::vector<uint16_t> myDeviceLightActionHintsVec;
    myDeviceLightActionHintsVec.push_back(ACTIONBUTTON);
    myDeviceLightAction->setHints(myDeviceLightActionHintsVec);

    myDeviceLightConfirm = new MyDeviceLightConfirm("LightConfirm", NULL);
    CHECK(myDeviceLightAction->addChildDialog(myDeviceLightConfirm));

    myDeviceLightConfirm->setEnabled(true);
    myDeviceLightConfirm->setIsSecured(false);

    std::vector<qcc::String> myDeviceLightConfirmmessageVec;
    myDeviceLightConfirmmessageVec.push_back("Change the state of RED LED 1");
    myDeviceLightConfirmmessageVec.push_back("Are you sure you want to turn on the light");
    myDeviceLightConfirmmessageVec.push_back(UNICODE_ARE_YOU_SURE_YOU_WANT_TO_TURN_OFF_THE_LIGHT);
    myDeviceLightConfirm->setMessages(myDeviceLightConfirmmessageVec);
    myDeviceLightConfirm->setNumActions(2);
    myDeviceLightConfirm->setBgColor(0x789);

    std::vector<qcc::String> myDeviceLightConfirmlabelVec;
    myDeviceLightConfirmlabelVec.push_back("Are you sure?");
    myDeviceLightConfirmlabelVec.push_back("Sind sie sicher?");
    myDeviceLightConfirmlabelVec.push_back(UNICODE_ARE_YOU_SURE);
    myDeviceLightConfirm->setLabels(myDeviceLightConfirmlabelVec);

    std::vector<uint16_t> myDeviceLightConfirmHintsVec;
    myDeviceLightConfirmHintsVec.push_back(ALERTDIALOG);
    myDeviceLightConfirm->setHints(myDeviceLightConfirmHintsVec);

    std::vector<qcc::String> myDeviceLightConfirmLabelAction1Vec;
    myDeviceLightConfirmLabelAction1Vec.push_back("TURN ON");
    myDeviceLightConfirmLabelAction1Vec.push_back("Ja");
    myDeviceLightConfirmLabelAction1Vec.push_back(UNICODE_YES);
    myDeviceLightConfirm->setLabelsAction1(myDeviceLightConfirmLabelAction1Vec);

    std::vector<qcc::String> myDeviceLightConfirmLabelAction2Vec;
    myDeviceLightConfirmLabelAction2Vec.push_back("TURN OFF");
    myDeviceLightConfirmLabelAction2Vec.push_back("Nein");
    myDeviceLightConfirmLabelAction2Vec.push_back(UNICODE_NO);
    myDeviceLightConfirm->setLabelsAction2(myDeviceLightConfirmLabelAction2Vec);

    myDeviceNextLightAction = new ActionWithDialog("nextlightAction", myDeviceRootContainer);
    CHECK(myDeviceRootContainer->addChildWidget(myDeviceNextLightAction));

    myDeviceNextLightAction->setEnabled(true);
    myDeviceNextLightAction->setIsSecured(false);
    myDeviceNextLightAction->setBgColor(0x400);

    std::vector<qcc::String> myDeviceNextLightActionlabelVec;
    myDeviceNextLightActionlabelVec.push_back("RED LED 2");
    myDeviceNextLightActionlabelVec.push_back("Ofenlicht anschalten");
    myDeviceNextLightActionlabelVec.push_back(UNICODE_TURN_ON_OVEN_LIGHT);
    myDeviceNextLightAction->setLabels(myDeviceNextLightActionlabelVec);

    std::vector<uint16_t> myDeviceNextLightActionHintsVec;
    myDeviceNextLightActionHintsVec.push_back(ACTIONBUTTON);
    myDeviceNextLightAction->setHints(myDeviceNextLightActionHintsVec);

    myDeviceNextLightConfirm = new MyDeviceNextLightConfirm("LightConfirm", NULL);
    CHECK(myDeviceNextLightAction->addChildDialog(myDeviceNextLightConfirm));

    myDeviceNextLightConfirm->setEnabled(true);
    myDeviceNextLightConfirm->setIsSecured(false);

    std::vector<qcc::String> myDeviceNextLightConfirmmessageVec;
    myDeviceNextLightConfirmmessageVec.push_back("Change the state of RED LED 2 ");
    myDeviceNextLightConfirmmessageVec.push_back("Are you sure you want to turn on the light");
    myDeviceNextLightConfirmmessageVec.push_back(UNICODE_ARE_YOU_SURE_YOU_WANT_TO_TURN_OFF_THE_LIGHT);
    myDeviceNextLightConfirm->setMessages(myDeviceNextLightConfirmmessageVec);
    myDeviceNextLightConfirm->setNumActions(2);
    myDeviceNextLightConfirm->setBgColor(0x789);

    std::vector<qcc::String> myDeviceNextLightConfirmlabelVec;
    myDeviceNextLightConfirmlabelVec.push_back("Are you sure?");
    myDeviceNextLightConfirmlabelVec.push_back("Sind sie sicher?");
    myDeviceNextLightConfirmlabelVec.push_back(UNICODE_ARE_YOU_SURE);
    myDeviceNextLightConfirm->setLabels(myDeviceNextLightConfirmlabelVec);

    std::vector<uint16_t> myDeviceNextLightConfirmHintsVec;
    myDeviceNextLightConfirmHintsVec.push_back(ALERTDIALOG);
    myDeviceNextLightConfirm->setHints(myDeviceNextLightConfirmHintsVec);

    std::vector<qcc::String> myDeviceNextLightConfirmLabelAction1Vec;
    myDeviceNextLightConfirmLabelAction1Vec.push_back("TURN ON");
    myDeviceNextLightConfirmLabelAction1Vec.push_back("Ja");
    myDeviceNextLightConfirmLabelAction1Vec.push_back(UNICODE_YES);
    myDeviceNextLightConfirm->setLabelsAction1(myDeviceNextLightConfirmLabelAction1Vec);

    std::vector<qcc::String> myDeviceNextLightConfirmLabelAction2Vec;
    myDeviceNextLightConfirmLabelAction2Vec.push_back("TURN OFF");
    myDeviceNextLightConfirmLabelAction2Vec.push_back("Nein");
    myDeviceNextLightConfirmLabelAction2Vec.push_back(UNICODE_NO);
    myDeviceNextLightConfirm->setLabelsAction2(myDeviceNextLightConfirmLabelAction2Vec);

    myDeviceYellowLightAction = new ActionWithDialog("yellowLightAction", myDeviceRootContainer);
    CHECK(myDeviceRootContainer->addChildWidget(myDeviceYellowLightAction));

    myDeviceYellowLightAction->setEnabled(true);
    myDeviceYellowLightAction->setIsSecured(false);
    myDeviceYellowLightAction->setBgColor(0x400);

    std::vector<qcc::String> myDeviceYellowLightActionlabelVec;
    myDeviceYellowLightActionlabelVec.push_back("YELLOW LED 1");
    myDeviceYellowLightActionlabelVec.push_back("Ofenlicht anschalten");
    myDeviceYellowLightActionlabelVec.push_back(UNICODE_TURN_ON_OVEN_LIGHT);
    myDeviceYellowLightAction->setLabels(myDeviceYellowLightActionlabelVec);

    std::vector<uint16_t> myDeviceYellowLightActionHintsVec;
    myDeviceYellowLightActionHintsVec.push_back(ACTIONBUTTON);
    myDeviceYellowLightAction->setHints(myDeviceYellowLightActionHintsVec);

    myDeviceYellowLightConfirm = new MyDeviceYellowLightConfirm("LightConfirm", NULL);
    CHECK(myDeviceYellowLightAction->addChildDialog(myDeviceYellowLightConfirm));

    myDeviceYellowLightConfirm->setEnabled(true);
    myDeviceYellowLightConfirm->setIsSecured(false);

    std::vector<qcc::String> myDeviceYellowLightConfirmmessageVec;
    myDeviceYellowLightConfirmmessageVec.push_back("Change the state of YELLOW LED 1");
    myDeviceYellowLightConfirmmessageVec.push_back("Are you sure you want to turn on the light");
    myDeviceYellowLightConfirmmessageVec.push_back(UNICODE_ARE_YOU_SURE_YOU_WANT_TO_TURN_OFF_THE_LIGHT);
    myDeviceYellowLightConfirm->setMessages(myDeviceYellowLightConfirmmessageVec);
    myDeviceYellowLightConfirm->setNumActions(2);
    myDeviceYellowLightConfirm->setBgColor(0x789);

    std::vector<qcc::String> myDeviceYellowLightConfirmlabelVec;
    myDeviceYellowLightConfirmlabelVec.push_back("Are you sure?");
    myDeviceYellowLightConfirmlabelVec.push_back("Sind sie sicher?");
    myDeviceYellowLightConfirmlabelVec.push_back(UNICODE_ARE_YOU_SURE);
    myDeviceYellowLightConfirm->setLabels(myDeviceYellowLightConfirmlabelVec);

    std::vector<uint16_t> myDeviceYellowLightConfirmHintsVec;
    myDeviceYellowLightConfirmHintsVec.push_back(ALERTDIALOG);
    myDeviceYellowLightConfirm->setHints(myDeviceYellowLightConfirmHintsVec);

    std::vector<qcc::String> myDeviceYellowLightConfirmLabelAction1Vec;
    myDeviceYellowLightConfirmLabelAction1Vec.push_back("TURN ON");
    myDeviceYellowLightConfirmLabelAction1Vec.push_back("Ja");
    myDeviceYellowLightConfirmLabelAction1Vec.push_back(UNICODE_YES);
    myDeviceYellowLightConfirm->setLabelsAction1(myDeviceYellowLightConfirmLabelAction1Vec);

    std::vector<qcc::String> myDeviceYellowLightConfirmLabelAction2Vec;
    myDeviceYellowLightConfirmLabelAction2Vec.push_back("TURN OFF");
    myDeviceYellowLightConfirmLabelAction2Vec.push_back("Nein");
    myDeviceYellowLightConfirmLabelAction2Vec.push_back(UNICODE_NO);
    myDeviceYellowLightConfirm->setLabelsAction2(myDeviceYellowLightConfirmLabelAction2Vec);

    myDeviceNextYellowLightAction = new ActionWithDialog("nextYellowLightAction", myDeviceRootContainer);
    CHECK(myDeviceRootContainer->addChildWidget(myDeviceNextYellowLightAction));

    myDeviceNextYellowLightAction->setEnabled(true);
    myDeviceNextYellowLightAction->setIsSecured(false);
    myDeviceNextYellowLightAction->setBgColor(0x400);

    std::vector<qcc::String> myDeviceNextYellowLightActionlabelVec;
    myDeviceNextYellowLightActionlabelVec.push_back("YELLOW LED 2");
    myDeviceNextYellowLightActionlabelVec.push_back("Ofenlicht anschalten");
    myDeviceNextYellowLightActionlabelVec.push_back(UNICODE_TURN_ON_OVEN_LIGHT);
    myDeviceNextYellowLightAction->setLabels(myDeviceNextYellowLightActionlabelVec);

    std::vector<uint16_t> myDeviceNextYellowLightActionHintsVec;
    myDeviceNextYellowLightActionHintsVec.push_back(ACTIONBUTTON);
    myDeviceNextYellowLightAction->setHints(myDeviceNextYellowLightActionHintsVec);

    myDeviceNextYellowLightConfirm = new MyDeviceNextYellowLightConfirm("LightConfirm", NULL);
    CHECK(myDeviceNextYellowLightAction->addChildDialog(myDeviceNextYellowLightConfirm));

    myDeviceNextYellowLightConfirm->setEnabled(true);
    myDeviceNextYellowLightConfirm->setIsSecured(false);

    std::vector<qcc::String> myDeviceNextYellowLightConfirmmessageVec;
    myDeviceNextYellowLightConfirmmessageVec.push_back("Change the state of YELLOW LED 2 ");
    myDeviceNextYellowLightConfirmmessageVec.push_back("Are you sure you want to turn on the light");
    myDeviceNextYellowLightConfirmmessageVec.push_back(UNICODE_ARE_YOU_SURE_YOU_WANT_TO_TURN_OFF_THE_LIGHT);
    myDeviceNextYellowLightConfirm->setMessages(myDeviceNextYellowLightConfirmmessageVec);
    myDeviceNextYellowLightConfirm->setNumActions(2);
    myDeviceNextYellowLightConfirm->setBgColor(0x789);

    std::vector<qcc::String> myDeviceNextYellowLightConfirmlabelVec;
    myDeviceNextYellowLightConfirmlabelVec.push_back("Are you sure?");
    myDeviceNextYellowLightConfirmlabelVec.push_back("Sind sie sicher?");
    myDeviceNextYellowLightConfirmlabelVec.push_back(UNICODE_ARE_YOU_SURE);
    myDeviceNextYellowLightConfirm->setLabels(myDeviceNextYellowLightConfirmlabelVec);

    std::vector<uint16_t> myDeviceNextYellowLightConfirmHintsVec;
    myDeviceNextYellowLightConfirmHintsVec.push_back(ALERTDIALOG);
    myDeviceNextYellowLightConfirm->setHints(myDeviceNextYellowLightConfirmHintsVec);

    std::vector<qcc::String> myDeviceNextYellowLightConfirmLabelAction1Vec;
    myDeviceNextYellowLightConfirmLabelAction1Vec.push_back("TURN ON");
    myDeviceNextYellowLightConfirmLabelAction1Vec.push_back("Ja");
    myDeviceNextYellowLightConfirmLabelAction1Vec.push_back(UNICODE_YES);
    myDeviceNextYellowLightConfirm->setLabelsAction1(myDeviceNextYellowLightConfirmLabelAction1Vec);

    std::vector<qcc::String> myDeviceNextYellowLightConfirmLabelAction2Vec;
    myDeviceNextYellowLightConfirmLabelAction2Vec.push_back("TURN OFF");
    myDeviceNextYellowLightConfirmLabelAction2Vec.push_back("Nein");
    myDeviceNextYellowLightConfirmLabelAction2Vec.push_back(UNICODE_NO);
    myDeviceNextYellowLightConfirm->setLabelsAction2(myDeviceNextYellowLightConfirmLabelAction2Vec);

    myDeviceGreenLightAction = new ActionWithDialog("greenlightAction", myDeviceRootContainer);
    CHECK(myDeviceRootContainer->addChildWidget(myDeviceGreenLightAction));

    myDeviceGreenLightAction->setEnabled(true);
    myDeviceGreenLightAction->setIsSecured(false);
    myDeviceGreenLightAction->setBgColor(0x400);

    std::vector<qcc::String> myDeviceGreenLightActionlabelVec;
    myDeviceGreenLightActionlabelVec.push_back("GREEN LED 1");
    myDeviceGreenLightActionlabelVec.push_back("Ofenlicht anschalten");
    myDeviceGreenLightActionlabelVec.push_back(UNICODE_TURN_ON_OVEN_LIGHT);
    myDeviceGreenLightAction->setLabels(myDeviceGreenLightActionlabelVec);

    std::vector<uint16_t> myDeviceGreenLightActionHintsVec;
    myDeviceGreenLightActionHintsVec.push_back(ACTIONBUTTON);
    myDeviceGreenLightAction->setHints(myDeviceGreenLightActionHintsVec);

    myDeviceGreenLightConfirm = new MyDeviceGreenLightConfirm("LightConfirm", NULL);
    CHECK(myDeviceGreenLightAction->addChildDialog(myDeviceGreenLightConfirm));

    myDeviceGreenLightConfirm->setEnabled(true);
    myDeviceGreenLightConfirm->setIsSecured(false);

    std::vector<qcc::String> myDeviceGreenLightConfirmmessageVec;
    myDeviceGreenLightConfirmmessageVec.push_back("Change the state of GREEN LED 1");
    myDeviceGreenLightConfirmmessageVec.push_back("Are you sure you want to turn on the light");
    myDeviceGreenLightConfirmmessageVec.push_back(UNICODE_ARE_YOU_SURE_YOU_WANT_TO_TURN_OFF_THE_LIGHT);
    myDeviceGreenLightConfirm->setMessages(myDeviceGreenLightConfirmmessageVec);
    myDeviceGreenLightConfirm->setNumActions(2);
    myDeviceGreenLightConfirm->setBgColor(0x789);

    std::vector<qcc::String> myDeviceGreenLightConfirmlabelVec;
    myDeviceGreenLightConfirmlabelVec.push_back("Are you sure?");
    myDeviceGreenLightConfirmlabelVec.push_back("Sind sie sicher?");
    myDeviceGreenLightConfirmlabelVec.push_back(UNICODE_ARE_YOU_SURE);
    myDeviceGreenLightConfirm->setLabels(myDeviceGreenLightConfirmlabelVec);

    std::vector<uint16_t> myDeviceGreenLightConfirmHintsVec;
    myDeviceGreenLightConfirmHintsVec.push_back(ALERTDIALOG);
    myDeviceGreenLightConfirm->setHints(myDeviceGreenLightConfirmHintsVec);

    std::vector<qcc::String> myDeviceGreenLightConfirmLabelAction1Vec;
    myDeviceGreenLightConfirmLabelAction1Vec.push_back("TURN ON");
    myDeviceGreenLightConfirmLabelAction1Vec.push_back("Ja");
    myDeviceGreenLightConfirmLabelAction1Vec.push_back(UNICODE_YES);
    myDeviceGreenLightConfirm->setLabelsAction1(myDeviceGreenLightConfirmLabelAction1Vec);

    std::vector<qcc::String> myDeviceGreenLightConfirmLabelAction2Vec;
    myDeviceGreenLightConfirmLabelAction2Vec.push_back("TURN OFF");
    myDeviceGreenLightConfirmLabelAction2Vec.push_back("Nein");
    myDeviceGreenLightConfirmLabelAction2Vec.push_back(UNICODE_NO);
    myDeviceGreenLightConfirm->setLabelsAction2(myDeviceGreenLightConfirmLabelAction2Vec);

    myDeviceNextGreenLightAction = new ActionWithDialog("nextGreenLightAction", myDeviceRootContainer);
    CHECK(myDeviceRootContainer->addChildWidget(myDeviceNextGreenLightAction));

    myDeviceNextGreenLightAction->setEnabled(true);
    myDeviceNextGreenLightAction->setIsSecured(false);
    myDeviceNextGreenLightAction->setBgColor(0x400);

    std::vector<qcc::String> myDeviceNextGreenLightActionlabelVec;
    myDeviceNextGreenLightActionlabelVec.push_back("GREEN LED 2");
    myDeviceNextGreenLightActionlabelVec.push_back("Ofenlicht anschalten");
    myDeviceNextGreenLightActionlabelVec.push_back(UNICODE_TURN_ON_OVEN_LIGHT);
    myDeviceNextGreenLightAction->setLabels(myDeviceNextLightActionlabelVec);

    std::vector<uint16_t> myDeviceNextGreenLightActionHintsVec;
    myDeviceNextGreenLightActionHintsVec.push_back(ACTIONBUTTON);
    myDeviceNextGreenLightAction->setHints(myDeviceNextLightActionHintsVec);

    myDeviceNextGreenLightConfirm = new MyDeviceNextGreenLightConfirm("LightConfirm", NULL);
    CHECK(myDeviceNextGreenLightAction->addChildDialog(myDeviceNextGreenLightConfirm));

    myDeviceNextGreenLightConfirm->setEnabled(true);
    myDeviceNextGreenLightConfirm->setIsSecured(false);

    std::vector<qcc::String> myDeviceNextGreenLightConfirmmessageVec;
    myDeviceNextGreenLightConfirmmessageVec.push_back("Change the state of GREEN LED 2 ");
    myDeviceNextGreenLightConfirmmessageVec.push_back("Are you sure you want to turn on the light");
    myDeviceNextGreenLightConfirmmessageVec.push_back(UNICODE_ARE_YOU_SURE_YOU_WANT_TO_TURN_OFF_THE_LIGHT);
    myDeviceNextGreenLightConfirm->setMessages(myDeviceNextGreenLightConfirmmessageVec);
    myDeviceNextGreenLightConfirm->setNumActions(2);
    myDeviceNextGreenLightConfirm->setBgColor(0x789);

    std::vector<qcc::String> myDeviceNextGreenLightConfirmlabelVec;
    myDeviceNextGreenLightConfirmlabelVec.push_back("Are you sure?");
    myDeviceNextGreenLightConfirmlabelVec.push_back("Sind sie sicher?");
    myDeviceNextGreenLightConfirmlabelVec.push_back(UNICODE_ARE_YOU_SURE);
    myDeviceNextGreenLightConfirm->setLabels(myDeviceNextGreenLightConfirmlabelVec);

    std::vector<uint16_t> myDeviceNextGreenLightConfirmHintsVec;
    myDeviceNextGreenLightConfirmHintsVec.push_back(ALERTDIALOG);
    myDeviceNextGreenLightConfirm->setHints(myDeviceNextGreenLightConfirmHintsVec);

    std::vector<qcc::String> myDeviceNextGreenLightConfirmLabelAction1Vec;
    myDeviceNextGreenLightConfirmLabelAction1Vec.push_back("TURN ON");
    myDeviceNextGreenLightConfirmLabelAction1Vec.push_back("Ja");
    myDeviceNextGreenLightConfirmLabelAction1Vec.push_back(UNICODE_YES);
    myDeviceNextGreenLightConfirm->setLabelsAction1(myDeviceNextGreenLightConfirmLabelAction1Vec);

    std::vector<qcc::String> myDeviceNextGreenLightConfirmLabelAction2Vec;
    myDeviceNextGreenLightConfirmLabelAction2Vec.push_back("TURN OFF");
    myDeviceNextGreenLightConfirmLabelAction2Vec.push_back("Nein");
    myDeviceNextGreenLightConfirmLabelAction2Vec.push_back(UNICODE_NO);
    myDeviceNextGreenLightConfirm->setLabelsAction2(myDeviceNextGreenLightConfirmLabelAction2Vec);

/*
    std::vector<qcc::String> myDeviceLightConfirmLabelAction3Vec;
    myDeviceLightConfirmLabelAction3Vec.push_back("Cancel");
    myDeviceLightConfirmLabelAction3Vec.push_back("Abrechen");
    myDeviceLightConfirmLabelAction3Vec.push_back(UNICODE_CANCEL);
    myDeviceLightConfirm->setLabelsAction3(myDeviceLightConfirmLabelAction3Vec);
*/
    myDeviceAreYouSureNotificationAction = NotificationAction::createNotificationAction(LanguageSets::get("myDeviceMyLanguages"));
    if (!myDeviceAreYouSureNotificationAction) {
        return ER_FAIL;
    }
    CHECK(myDeviceUnit->addNotificationAction(myDeviceAreYouSureNotificationAction));

    myDeviceAreYouSure = new MyDeviceAreYouSure("areYouSure", NULL);
    CHECK(myDeviceAreYouSureNotificationAction->setRootWidget(myDeviceAreYouSure));

    myDeviceAreYouSure->setEnabled(true);
    myDeviceAreYouSure->setIsSecured(false);

    std::vector<qcc::String> myDeviceAreYouSuremessageVec;
    myDeviceAreYouSuremessageVec.push_back("Are you sure?");
    myDeviceAreYouSuremessageVec.push_back("Sind sie sicher?");
    myDeviceAreYouSuremessageVec.push_back(UNICODE_ARE_YOU_SURE);
    myDeviceAreYouSure->setMessages(myDeviceAreYouSuremessageVec);
    myDeviceAreYouSure->setNumActions(1);
    myDeviceAreYouSure->setBgColor(0x789);

    std::vector<qcc::String> myDeviceAreYouSurelabelVec;
    myDeviceAreYouSurelabelVec.push_back("Are you sure?");
    myDeviceAreYouSurelabelVec.push_back("Sind sie sicher?");
    myDeviceAreYouSurelabelVec.push_back(UNICODE_ARE_YOU_SURE);
    myDeviceAreYouSure->setLabels(myDeviceAreYouSurelabelVec);

    std::vector<qcc::String> myDeviceAreYouSureLabelAction1Vec;
    myDeviceAreYouSureLabelAction1Vec.push_back("Yes");
    myDeviceAreYouSureLabelAction1Vec.push_back("Ja");
    myDeviceAreYouSureLabelAction1Vec.push_back(UNICODE_YES);
    myDeviceAreYouSure->setLabelsAction1(myDeviceAreYouSureLabelAction1Vec);

    return status;
}

void ControlPanelGenerated::Shutdown()
{
    if (myDeviceUnit) {
        delete (myDeviceUnit);
        myDeviceUnit = 0;
    }
    if (myDeviceRootContainerControlPanel) {
        delete (myDeviceRootContainerControlPanel);
        myDeviceRootContainerControlPanel = 0;
    }
    if (myDeviceRootContainer) {
        delete (myDeviceRootContainer);
        myDeviceRootContainer = 0;
    }
    if (myDeviceCurrentTemp) {
        delete (myDeviceCurrentTemp);
        myDeviceCurrentTemp = 0;
    }
    if (myDeviceHeatProperty) {
        delete (myDeviceHeatProperty);
        myDeviceHeatProperty = 0;
    }
    if (myDeviceOvenAction) {
        delete (myDeviceOvenAction);
        myDeviceOvenAction = 0;
    }
    if (myDeviceLightAction) {
        delete (myDeviceLightAction);
        myDeviceLightAction = 0;
    }
    if (myDeviceLightConfirm) {
        delete (myDeviceLightConfirm);
        myDeviceLightConfirm = 0;
    }
    if (myDeviceAreYouSureNotificationAction) {
        delete (myDeviceAreYouSureNotificationAction);
        myDeviceAreYouSureNotificationAction = 0;
    }
    if (myDeviceAreYouSure) {
        delete (myDeviceAreYouSure);
        myDeviceAreYouSure = 0;
    }

}
