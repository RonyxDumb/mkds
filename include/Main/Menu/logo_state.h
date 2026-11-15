#pragma once

#include "types.h"
#include "Main/Menu/second_menu_scene.h" // StateCallbacks

extern StateCallbacks gLogoStateTable[12];

void UpdateLogoDwcNoticeSecond(void *stateObject);
void EnterLogoDwcNoticeSecond(void *stateObject);
void UpdateLogoDwcNoticeFirst(void *stateObject);
void EnterLogoDwcNoticeFirst(void *stateObject);
void UpdateLogoCheckDwcInit(void *stateObject);
