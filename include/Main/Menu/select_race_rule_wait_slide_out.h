#pragma once

#include "types.h"
#include "Main/Menu/menu_screens_work.h"

void SlideOutSelectRaceRuleWait(void);

void PlaceSelectRaceRuleWait(void);

void AdvanceSelectRaceRuleWaitSlideIn(void);
void AdvanceSelectRaceRuleWaitSlideOut(void);
void AdvanceSelectRaceRuleWait(void);
void SlideInSelectRaceRuleWait(void);

void ClearSelectRaceRuleWaitPointer(void);

void RequestSelectRaceRuleWaitSlideIn(void);
void RequestSelectRaceRuleWaitRest(void);
void RequestSelectRaceRuleWaitSlideOut(void);
void InitSelectRaceRuleWait(void *heap, void *oamList);

void LocateAndQueueSelectRaceRuleWait(void);

extern char *gSelectRaceRuleWaitNcerName;
extern char *gSelectRaceRuleWaitBnclName;
extern char *gSelectRaceRuleWaitNclrName;
extern char *gSelectRaceRuleWaitBnllName;
extern char *gSelectRaceRuleWaitNcgrName;
extern struct SelectRaceRuleWait *gSelectRaceRuleWait;
