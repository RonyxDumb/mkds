#pragma once

#include "types.h"
#include "Main/Menu/select_race_rule_state.h"

void LocateAndQueueSelectRaceRule(void);
void LoadSelectRaceRuleAndWaitData(void);

extern const u16 gSelectRaceRuleStepCellsChanging[5][2];
extern const u16 gSelectRaceRuleStepCellsPlain[5][2];
extern const u32 gSelectRaceRulePreviousRectRows[5];
extern const u32 gSelectRaceRuleEntryInputSlots[8];
extern const SelectRaceRuleNscrRect gSelectRaceRuleSMenuNscrRects[5];
extern const SelectRaceRuleNscrRect gSelectRaceRuleMultiSimpleNscrRects[5];
