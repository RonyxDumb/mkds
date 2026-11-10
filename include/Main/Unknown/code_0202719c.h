#pragma once

#include "types.h"

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
