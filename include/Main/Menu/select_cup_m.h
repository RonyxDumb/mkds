#pragma once

#include "types.h"

void WriteSelectCupMBgOffsets(void);
s32 AdvanceSelectCupM(void);
void AdvanceSelectCupMState1(void);
void AdvanceSelectCupMState0(void);
void ReleaseSelectCupM(void);
void InitSelectCupM(void *parentHeap, void *mainOamList, void *subOamList);
void StartSelectCupMState1(void);
void StartSelectCupMState0(void);
void InitSelectCupMCellsAndRequestCupPicture(void);
void LocateAndQueueSelectCupM(void);
