#include "ITCM/code_01ff9320.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9598.h"
#include "code_02010c84.h"
#include "code_02147cd8.h"

#pragma opt_arithtransformation off

// The table below is initialized data kept in .text ahead of the code (the original has it at 0x01ff9300, right
// before NNSi_G3dSendTexSRTMaya); 1.2 puts initialized non-const data in the section a `#pragma section` names.
#pragma define_section ITCM ".text"                                                                                    \
                            ".bss" abs32 RWX
#pragma section ITCM begin

Unk01ff9320_Fn calcTexMtx_[8] = {
    (Unk01ff9320_Fn) texmtxCalc_flag_, (Unk01ff9320_Fn) texmtxCalc_flagS_, (Unk01ff9320_Fn) texmtxCalc_flagR_,
    (Unk01ff9320_Fn) texmtxCalc_flagRS_, (Unk01ff9320_Fn) texmtxCalc_flagT_, (Unk01ff9320_Fn) texmtxCalc_flagTS_,
    (Unk01ff9320_Fn) texmtxCalc_flagTR_, (Unk01ff9320_Fn) texmtxCalc_flagTRS_,
};

#pragma section ITCM end

void texmtxCalc_flagTS_(s32 *o, const NNSG3dMatAnmResult *v1) {
    s32 a;
    s32 b;
    s32 t;

    a = v1->field2C << 12;
    b = v1->field2E << 12;
    FX_DivAsync(b, a);
    o[0] = v1->field20[1];
    o[5] = v1->field20[1];
    o[1] = (-v1->field20[0] * FX_GetDivResult()) >> 12;
    FX_DivAsync(a, b);
    t = -(v1->field20[0] + v1->field20[1]);
    o[12] = (v1->field2C * (t + 0x1000)) << 3;
    o[13] = (v1->field2E * (v1->field20[0] - v1->field20[1] + 0x1000)) << 3;
    o[4] = (v1->field20[0] * FX_GetDivResult()) >> 12;
}

void texmtxCalc_flagTR_(s32 *o, const NNSG3dMatAnmResult *v1) {
    s32 t;

    o[0] = v1->field18[0];
    o[5] = v1->field18[1];
    o[1] = 0;
    o[12] = 0;
    t = -(v1->field18[1] << 1);
    o[13] = (v1->field2E * (t + 0x2000)) << 3;
    o[4] = 0;
}

void texmtxCalc_flagTRS_(s32 *o) {
    o[0] = 0x1000;
    o[1] = 0;
    o[4] = 0;
    o[5] = 0x1000;
    o[12] = 0;
    o[13] = 0;
}

void NNSi_G3dSendTexSRTMaya(NNSG3dMatAnmResult *p) {
    Unk01ff9320_buf b;

    if (p->field0 & 8) {
        b.field0 = 0x101610;
    } else {
        b.field0 = 0x101810;
    }
    b.field4 = 3;
    b.field48 = 2;
    b.field8[14] = 0;
    b.field8[11] = 0;
    b.field8[10] = 0;
    b.field8[9] = 0;
    b.field8[8] = 0;
    b.field8[7] = 0;
    b.field8[6] = 0;
    b.field8[3] = 0;
    b.field8[2] = 0;
    b.field8[15] = 0x1000;
    calcTexMtx_[p->field0 & 7](b.field8, p);
    if (p->field30 != 0x1000) {
        b.field8[0] = ((s64) p->field30 * b.field8[0]) >> 12;
        b.field8[1] = ((s64) p->field30 * b.field8[1]) >> 12;
        b.field8[12] = ((s64) p->field30 * b.field8[12]) >> 12;
    }
    if (p->field34 != 0x1000) {
        b.field8[4] = ((s64) p->field34 * b.field8[4]) >> 12;
        b.field8[5] = ((s64) p->field34 * b.field8[5]) >> 12;
        b.field8[13] = ((s64) p->field34 * b.field8[13]) >> 12;
    }
    NNS_G3dGeBufferOP_N(b.field0, (u32 *) &b + 1, 0x12);
}
