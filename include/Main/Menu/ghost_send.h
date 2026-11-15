#pragma once

#include "types.h"
#include "Main/Menu/data_02174000.h"

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
void SetupGhostSendEndConnectionText(void);
void RefreshGhostListRows(s32 action, s32 slot, s32 row, s32 selectedSlot);

// Rows of four halfwords.
extern const s16 gTimeAttackGhostSendMLabelTextRows[3][4];
extern GhostSceneCallbacks gTimeAttackGhostSendCallbacks;
extern s16 gTimeAttackGhostSendSLabelTextRows[18][4];
extern struct TimeAttackGhostSend *gTimeAttackGhostSend;
