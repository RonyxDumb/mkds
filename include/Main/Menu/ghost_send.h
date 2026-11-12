#pragma once

#include "types.h"

typedef struct SceneNumbers SceneNumbers;

void WriteTimeAttackGhostSendRegisters(void);
void ReleaseTimeAttackGhostSend(void);
s32 AdvanceTimeAttackGhostSend(SceneNumbers *advanceArg);
void InitTimeAttackGhostSend(void *parentHeap, void *mainOam, void *subOam);
void SetGhostSendCellsOffsetY(void);
void StartReadSelectedGhost(void);
void SetupGhostSendSubTextWithName(s32 messageIndex, s32 withButton);
void SetupGhostSendMainText(void);
void PrintSelectedGhostSendRecord(void);
void PrintGhostSendCounts(void);
void SetupGhostSendState8Text(void);
void RefreshGhostListRows(s32 action, s32 slot, s32 row, s32 selectedSlot);
