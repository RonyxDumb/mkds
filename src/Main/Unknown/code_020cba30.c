#include "Main/Unknown/code_020cba30.h"
#include "registers.h"
#include "00/code_02181f98.h"
#include "code_0214a390.h"

void func_020cbabc(u32 value) {
    gStruct217B488->mUnk_08 = value;
}

void func_020cbaa8(u32 value) {
    gStruct217B488->mUnk_10 = value;
}

void menu_G2_SetBlendAlpha(u32 plane1, u32 plane2, u32 ev1, u32 ev2) {
    G2x_SetBlendAlpha_(&reg_G2_BLDCNT, plane1, plane2, ev1, ev2);
}

void menu_G2S_SetBlendAlpha(u32 plane1, u32 plane2, u32 ev1, u32 ev2) {
    G2x_SetBlendAlpha_(&reg_G2S_DB_BLDCNT, plane1, plane2, ev1, ev2);
}
