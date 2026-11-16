#pragma once

#include "types.h"

// The saved coprocessor state: divider operands and mode, square root operand and mode.
typedef struct CPContext {
    /* 00 */ u64 mDivNumer;
    /* 08 */ u64 mDivDenom;
    /* 10 */ u64 mSqrt;
    /* 18 */ u16 mDivMode;
    /* 1a */ u16 mSqrtMode;
} CPContext;

void Arm_MathContext_Load(const CPContext *context);
void Arm_MathContext_Save(CPContext *context);
