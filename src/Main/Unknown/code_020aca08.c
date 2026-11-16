#include "Main/Unknown/code_020aca08.h"
#include "Main/Unknown/code_02105e98.h"

#pragma thumb on

u32 title_gotoNicknameVblank(u32 value) {
    return value;
}

void title_gotoNicknameRender(Unk020aca24 *a) {
    if (a != 0) {
        a->mNextScene = 0xb;
        sound_2105E98();
    }
}

#pragma thumb off
