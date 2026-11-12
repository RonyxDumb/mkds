#pragma once

#include "types.h"
#include "Main/Menu/data_02153000.h"
#include "Main/Menu/data_02174000.h"

typedef struct Interpolation Interpolation;

int AdvanceSelectCharacter(void);
void InitSelectCharacter(void *parentHeap, s32 mode, void *mainOam, void *subOam);


void SetupInterpolation(Interpolation *interpolation, s32 state, s32 counterLimit, s16 startValue, s32 endValue);
void LoadSelectCharacterData(void);
void WriteSelectCharacterRegisters(void);
void ReleaseSelectCharacter(void);
void SetSelectCharacterAngleAndScale(void);
u32 IsSelectCharacterModeAndTimerZero(void);
void SetupSelectCharacterRow(s32 previousTableIndex);
void RefreshSelectCharacterRowCells(void);

void SetSelectCharacterBracketsMoving(void);
void MoveSelectCharacterBracketsToRow(void);
void QueueSelectCharacterNameChars(void);
void SetSelectCharacterNameOffsetX(s16 offsetX);
void SetSelectCharacterCellOffsetsY(s16 firstOffsetY, s16 secondOffsetY);
void SetSelectCharacterBracketsResting(void);
void SetSelectCharacterRowCellsVisible(s32 visible);
void StartSelectCharacterReturn(void);
void StartPlayerEntryListKindIfUsed(s32 kind);
void SetSelectCharacterKeyTargets12Rows(void);
void SetSelectCharacterKeyTargets11Rows(void);
void SetSelectCharacterKeyTargets10Rows(void);
void SetSelectCharacterKeyTargets9Rows(void);
void SetSelectCharacterKeyTargets8Rows(void);

extern struct SelectCharacter *gSelectCharacter;
