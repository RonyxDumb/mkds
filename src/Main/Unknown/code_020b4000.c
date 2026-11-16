#include "Main/Unknown/code_020b4000.h"

#pragma thumb on
Unk02022aa8 *m2d_getFont(s32 index) {
    u32 value0 = index;
    u32 byteOffset;
    byteOffset = (value0 << 2);
    value0 = (u32) &FontArray;
    value0 = *(const u32 *) ((value0) + (byteOffset));
    return (void *) value0;
}
#pragma thumb off

#pragma thumb on
void *m2d_getPortraitONclr(int index) {
    u32 value0 = index;
    u32 byteOffset;
    byteOffset = (value0 << 2);
    value0 = (u32) &gPlayerCharacterNclr;
    value0 = *(const u32 *) ((value0) + (byteOffset));
    return (void *) value0;
}
#pragma thumb off

#pragma thumb on
Nclr *m2d_getPortraitShyGuyONclr(u32 index) {
    u32 value0 = (u32) index;
    u32 byteOffset;
    byteOffset = (value0 << 2);
    value0 = (u32) &gPlayerCharacterShyguyNclr;
    value0 = *(const u32 *) ((value0) + (byteOffset));
    return (void *) value0;
}
#pragma thumb off

#pragma thumb on
Ncgr *m2d_getPortraitNceNcgr(int index) {
    u32 value0 = index;
    u32 byteOffset;
    byteOffset = (value0 << 2);
    value0 = (u32) &gPlayerCharacterNcgr;
    value0 = *(const u32 *) ((value0) + (byteOffset));
    return (void *) value0;
}
#pragma thumb off

#pragma thumb on
Unk02021dc8 *m2d_getPortraitNceNcer(int index) {
    u32 value0 = index;
    u32 byteOffset;
    byteOffset = (value0 << 2);
    value0 = (u32) &gPlayerCharacterNcer;
    value0 = *(const u32 *) ((value0) + (byteOffset));
    return (void *) value0;
}
#pragma thumb off

#pragma thumb on
void *m2d_getPortraitBncl(int index) {
    u32 value0 = index;
    u32 byteOffset;
    byteOffset = (value0 << 2);
    value0 = (u32) &gPlayerCharacterBncl;
    value0 = *(const u32 *) ((value0) + (byteOffset));
    return (void *) value0;
}
#pragma thumb off
