#pragma once

#include "types.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/MapObjects/pukupuku_init.h"
#include "Main/Unknown/code_020ec000.h"
#include "Main/MapObjects/pushed_motion.h"
#include "Main/Unknown/unk_02158000.h"

u8 CollideKartWithPukupuku(Pukupuku *pukupuku, Kart *kart, u8 *firstResponse, u8 *response);
