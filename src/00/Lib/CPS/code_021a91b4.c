#include "00/Lib/CPS/code_021a91b4.h"
#include "00/unk_021b6000.h"
#include "03/Net/essid_packet_steps.h"
#include "code_0214d018.h"
#include "00/Lib/CPS/code_021a9228.h"

void CPSi_SslPeriodical(s32 now) {
    s32 i;
    Unk021a91cc *session;
    i = 0;
    session = (Unk021a91cc *) gHttpsEntries;
    for (; i < 4; i++) {
        if (session->mUnk_5a != 0 && now - session->mUnk_50 > 0xef) {
            session->mUnk_5a = 0;
        }
        session++;
    }
}

void CPSi_SslCleanup(void) {
    u32 table;
    u32 fillByte;
    u32 byteCount;
    u32 value3;
    table = (u32) &gHttpsEntries;
    fillByte = 0u;
    byteCount = 0x170u;
    MI_CpuFill8((void *) table, fillByte, byteCount);
}
