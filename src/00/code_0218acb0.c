#include "00/code_0218acb0.h"
#include "00/code_0218a000.h"
#include "00/code_0218ae5c.h"
#include "00/code_0218b000.h"
#include "00/code_0218c000.h"
#include "00/code_021a3000.h"
#include "00/code_0218aea4.h"
#include "00/code_0218e2dc.h"

void SBQueryEngineSetPublicIP(MatchingServerList *matchingServerList, u32 publicIp) {
    matchingServerList->mUnk_000.mMyPublicIp = publicIp;
}

void SBEngineHaltUpdates(MatchingServerList *matchingServerList) {
    FIFOClear(&matchingServerList->mUnk_000.mPendingList);
    FIFOClear(&matchingServerList->mUnk_000.mQueryList);
}

void SBEngineCleanup(MatchingServerList *matchingServerList) {
    func_ov000_0218e53c(matchingServerList->mUnk_000.mQuerySock);
    matchingServerList->mUnk_000.mQuerySock = 0xffffffff;
    FIFOClear(&matchingServerList->mUnk_000.mPendingList);
    FIFOClear(&matchingServerList->mUnk_000.mQueryList);
}
