#pragma once

#include "types.h"
#include "Main/Menu/second_menu_scene.h" // StateCallbacks

extern StateCallbacks g_E7FnList0[12];

void Logo_StateHandler_NotifyWiFiHelp_Second(void *stateObject);
void Logo_StateHandler_NotifyWiFiHelp_First(void *stateObject);
void Logo_StateHandler_NotifyWiFiIdIssue_Second(void *stateObject);
void Logo_StateHandler_NotifyWiFiIdIssue_First(void *stateObject);
void Logo_StateHandler_CheckWiFiStatus_Second(void *stateObject);
