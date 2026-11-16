#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_020a8ed8.h" // IronBall
#include "Main/Unknown/unk_0217b000.h"

void iball_renderBall(void *a, IronBall *ironBall);
void iball_applyBallMaterial(void *a);
void iball_loadBallModel(void *a);
u32 ibal_onDriverCollide(IronBall *ironBall, void *kart, u8 *b, u8 *c);
void ibal_init(IronBall *ironBall);
s32 GetKeyboardChosenKeyValue(void);
s32 GetKeyboardCursorValue(void);
void MoveKeyboardCursorToValue(u16 value);
