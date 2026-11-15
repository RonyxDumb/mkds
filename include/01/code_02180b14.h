#pragma once

#include "types.h"

void TestSceneSetSubBg1Cnt(u32 cntVal14, u32 cntVal7, u32 cntVal8, u32 cntVal2, u32 cntVal13);
void WriteSubBg1CntMosaic(u32 bit6Value);
void WriteSubBg1CntBits(u32 bits);
void WriteSubBg1Offset(u32 offsetX, u32 offsetY);
void SetSubBg0Cnt(u32 cntVal14, u32 cntVal7, u32 cntVal8, u32 cntVal2, u32 cntVal13);
void WriteSubBg0CntMosaic(u32 bit6Value);
void WriteSubBg0CntBits(u32 bits);
void WriteSubBg0Offset(u32 offsetX, u32 offsetY);
void TestSceneGXS_SetVisiblePlane(u32 bits);
