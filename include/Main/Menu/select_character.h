#pragma once

#include "types.h"

typedef struct Interpolation Interpolation;

int AdvanceSelectCharacter(void);
void InitSelectCharacter(void *parentHeap, s32 mode, void *mainOam, void *subOam);

extern char data_usa_02161b3c[];
extern char data_usa_02161b5c[];
extern char data_usa_02161b7c[];
extern char data_usa_02161b9c[];
extern char data_usa_02161bb8[];
extern char data_usa_02161bd4[];
extern char data_usa_02161bf0[];
extern char data_usa_02161c14[];
extern char data_usa_02161c38[];
extern char data_usa_02161c60[];

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
