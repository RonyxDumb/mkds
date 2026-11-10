#pragma once

#include "types.h"

// Argument of AdvanceTimeAttackGhostSend: a halfword is set at 4.
typedef struct Unk0202cdf4 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ u16 mUnk_04;
} Unk0202cdf4;

void WriteTimeAttackGhostSendRegisters(void);
void ReleaseTimeAttackGhostSend(void);
s32 AdvanceTimeAttackGhostSend(Unk0202cdf4 *advanceArg);
void InitTimeAttackGhostSend(void *parentHeap, void *mainOam, void *subOam);
void SetGhostSendCellsOffsetY(void);
void StartReadSelectedGhost(void);
void SetupGhostSendSubTextWithName(s32 messageIndex, s32 withButton);
void SetupGhostSendMainText(void);
void PrintSelectedGhostSendRecord(void);
void PrintGhostSendCounts(void);
void SetupGhostSendState8Text(void);
void RefreshGhostListRows(s32 action, s32 slot, s32 row, s32 selectedSlot);
