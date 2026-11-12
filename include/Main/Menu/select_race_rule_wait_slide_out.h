#pragma once

#include "types.h"
#include "Main/Menu/data_0217d000.h"

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

extern char *gSelectRaceRuleWaitNcerName;
extern char *gSelectRaceRuleWaitBnclName;
extern char *gSelectRaceRuleWaitNclrName;
extern char *gSelectRaceRuleWaitBnllName;
extern char *gSelectRaceRuleWaitNcgrName;
extern struct SelectRaceRuleWait *gSelectRaceRuleWait;
