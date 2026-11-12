#pragma once

#include "types.h"

void SlideOutSelectRaceRuleWait(void);

void PlaceSelectRaceRuleWait(void);

void AdvanceSelectRaceRuleWaitState0(void);
void AdvanceSelectRaceRuleWaitState2(void);
void AdvanceSelectRaceRuleWait(void);
void SlideInSelectRaceRuleWait(void);

void ClearSelectRaceRuleWaitPointer(void);

void RequestSelectRaceRuleWaitState0(void);
void RequestSelectRaceRuleWaitState1(void);
void RequestSelectRaceRuleWaitState2(void);
void InitSelectRaceRuleWait(void *heap, void *oamList);

void LocateAndQueueSelectRaceRuleWait(void);
