#include "00/Lib/CPS/code_021a91b4.h"
#include "00/unk_021b6000.h"
#include "03/Net/essid_packet_steps.h"
#include "code_0214d018.h"
#include "00/Lib/CPS/code_021a9228.h"
#include "00/types_021ab5e4.h"

void CPSi_SslPeriodical(s32 now) {
    s32 sessionIndex;
    HttpsEntry *session;
    sessionIndex = 0;
    session = gHttpsEntries;
    for (; sessionIndex < 4; sessionIndex++) {
        if (session->mInUse != 0 && now - session->mLastUseTime > 0xef) {
            session->mInUse = 0;
        }
        session++;
    }
}

void CPSi_SslCleanup(void) {
    u32 table;
    u32 fillByte;
    u32 byteCount;
    u32 unusedScratch;
    table = (u32) &gHttpsEntries;
    fillByte = 0u;
    byteCount = 0x170u;
    MI_CpuFill8((void *) table, fillByte, byteCount);
}
