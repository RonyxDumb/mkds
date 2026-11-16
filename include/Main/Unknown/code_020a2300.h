#pragma once

#include "types.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020a3fa8.h" // KartBalloons

void mgcnt_setApplyForceToDriverBalloonsFunc(void (*callback)(s32, s32));
void mgcnt_setOnEndFunc(void (*callback)(void));
void mgcnt_setOnKillFunc(void (*callback)(u16 a));
void mgcnt_setOnDamageFunc(s32 (*callback)(u16 a, u16 b));
void mgcnt_setField384(void (*callback)(s32, s32));
void mgcnt_setTryStealBalloonFunc(s32 (*callback)(s32, s32));
// Returns Standings.mKartBalloons, the pointer stored by mgcnt_setBlncntDriverEntries.
KartBalloons *mgcnt_getBlncntDriverEntries(void);
// Stores the pointer to the KartBalloons array of the balloon object in Standings.mKartBalloons.
void mgcnt_setBlncntDriverEntries(KartBalloons *kartBalloons);
