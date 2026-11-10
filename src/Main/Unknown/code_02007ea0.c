#include "Main/Unknown/code_02007ea0.h"
#include "Main/Unknown/unk_0216f000.h"
#include "code_0200fc8c.h"
#include "Main/Unknown/code_02007148.h"

#pragma thumb on

void SetCallback(UnkFunc *p0) {
    u32 enabled = (OS_DisableInterrupts());
    u32 v7;
    mbc->mCallback = p0;
    v7 = (OS_RestoreInterrupts(enabled));
}

#pragma thumb off
