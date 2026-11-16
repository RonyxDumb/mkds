#include "Main/Unknown/code_020f8d9c.h"
#include "Main/Unknown/code_020e0650.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/code_02109110.h"

#pragma thumb on

void InitItemObject(ItemObject *a, u32 b, int c) {
    a->field48 = b;
    sub_20E0650((u32 *) &a->field104);
    InitSoundSource(&a->mSoundSource, it_sItemParams[c].fieldA0, &a->mPos);
    sub_2109054(&a->mSoundSource);
}

#pragma thumb off
