#include "00/code_0218acb0.h"
#include "00/code_0218a000.h"
#include "00/code_0218ae5c.h"
#include "00/code_0218b000.h"
#include "00/code_0218c000.h"
#include "00/code_021a3000.h"
#include "00/code_0218aea4.h"
#include "00/code_0218e2dc.h"

void SBQueryEngineSetPublicIP(MatchingServerList *matchingServerList, u32 publicIp) {
    matchingServerList->mEngine.mMyPublicIp = publicIp;
}

void SBEngineHaltUpdates(MatchingServerList *matchingServerList) {
    FIFOClear(&matchingServerList->mEngine.mPendingList);
    FIFOClear(&matchingServerList->mEngine.mQueryList);
}

void SBEngineCleanup(MatchingServerList *matchingServerList) {
    closesocket(matchingServerList->mEngine.mQuerySock);
    matchingServerList->mEngine.mQuerySock = 0xffffffff;
    FIFOClear(&matchingServerList->mEngine.mPendingList);
    FIFOClear(&matchingServerList->mEngine.mQueryList);
}
