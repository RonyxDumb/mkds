#include "Main/Unknown/code_020b4000.h"

#pragma thumb on
Unk02022aa8 *GetFontByIndex(s32 index) {
    return gFontTable[index];
}
#pragma thumb off

#pragma thumb on
void *GetPlayerCharacterNclr(int index) {
    return gPlayerCharacterNclr[index];
}
#pragma thumb off

#pragma thumb on
Nclr *GetPlayerCharacterShyguyNclr(u32 index) {
    return gPlayerCharacterShyguyNclr[index];
}
#pragma thumb off

#pragma thumb on
Ncgr *GetPlayerCharacterNcgr(int index) {
    return gPlayerCharacterNcgr[index];
}
#pragma thumb off

#pragma thumb on
Unk02021dc8 *GetPlayerCharacterNcer(int index) {
    return gPlayerCharacterNcer[index];
}
#pragma thumb off

#pragma thumb on
void *GetPlayerCharacterBncl(int index) {
    return gPlayerCharacterBncl[index];
}
#pragma thumb off
