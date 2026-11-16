#include "Main/Unknown/code_0204b418.h"
#include "Main/Unknown/code_0204b458.h"
#include "01/code_021956dc.h"

#pragma thumb on

void savc_writeWithBackup(u32 firstAddress, u32 secondAddress, u32 *source, u32 byteCount,
                               void (*callback)(u32, u32), s32 hasPrefix) {
    gSaveCore->mSecondPassAddress = secondAddress;
    savc_write(firstAddress, source, byteCount, (void (*)(u32 *, u32)) callback, 1, hasPrefix);
}

void savc_writeBlock(u32 address, void *source, u32 byteCount, u32 callback) {
    u32 started = savc_write(address, source, byteCount, (void (*)(u32 *, u32))(callback), 0x0u, 0x0u);
}

#pragma thumb off
