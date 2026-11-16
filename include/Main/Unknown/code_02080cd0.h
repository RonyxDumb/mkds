#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0207ffa4.h"

// LinkCursor followed by a halfword at 0x1c and a byte at 0x1e.
typedef struct Unk02080d34 {
    /* 00 */ LinkCursor mLinkCursor;
    /* 1c */ u16 mKartIndex;
    /* 1e */ u8 mUnk_1e;
} Unk02080d34;

void epoi_2080CD0(LinkCursor *linkCursor, PointLink *pointLink);
void epoi_2080D34(Unk02080d34 *racePointLinkCursor, u16 kartIndex);
BOOL mepo_2080DBC(LinkCursor *linkCursor, Vec3 *position);
BOOL mepo_isPointInMepo(LinkCursor *linkCursor, Vec3 *position);
void func_02080e88(Unk0201ca6c *effect, Kart *kart);
void rptc_stopSlipstreamEffectDirect(Kart *kart);
void rptc_stopSlipstreamEffect(Kart *kart);
void rptc_startSlipstreamEffect(Kart *kart);
void rptc_stopSlipstreamBeginEffectDirect(Kart *kart);
void rptc_stopSlipstreamBeginEffect(Kart *kart);
void rptc_startSlipstreamBeginEffect(Kart *kart);
