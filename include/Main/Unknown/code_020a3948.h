#pragma once

#include "types.h"
#include "Main/Unknown/code_020a2e4c.h" // Balloon

// Object blln_loadModel sets the word at 0x1c of.
typedef struct Unk020a3eb8 {
    /* 00 */ u8 field0[0x1c];
    /* 1c */ s32 field1C;
} Unk020a3eb8;

void blln_render(void *mapObjectList, Balloon *balloon);
void blln_globalPreRender(void *mapObjectList);
void blln_loadModel(Unk020a3eb8 *a); /* also sets word +0x1c of the group record to 1 */
