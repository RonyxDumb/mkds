#pragma once

#include "types.h"
#include "03/unk_021da000.h"

typedef struct Ap {
    /* 00 */ void *mYbBgStep11Ncl;
    /* 04 */ OamRange *mUnk_04[3];
    /* 10 */ OamRange *mUnk_10[3];
    /* 1c */ u8 mUnk_1c;
    /* 1d */ u8 mUnk_1d;
} Ap;

void RequestApSelectionPalette(void);
void UpdateApMessageClose(void);
void UpdateApMessageResult(void);
void SetApSelectedButtonImage(void);
void MoveApSelection(int direction);
void PlaceApSelection(void);
void UpdateApRelease(void);
void UpdateApFadeOut(void);
void StartApClose(void);
void UpdateApResult(void);
void UpdateApNop(void);
void UpdateApInput(void);
void UpdateAp(void);
void UpdateApButtonsIn(void);
void UpdateApFadeIn(void);
void StartApFadeIn(void);
