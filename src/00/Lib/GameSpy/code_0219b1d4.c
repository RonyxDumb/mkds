#include "00/Lib/GameSpy/code_0219b1d4.h"
#include "00/Lib/GameSpy/code_0218e2dc.h"

void NegotiatorFree(NatTraversalEntry *negotiator) {
    if (negotiator->mDescriptor != -1) {
        closesocket(negotiator->mDescriptor);
    }
    negotiator->mDescriptor = -1;
    negotiator->mState = 4;
}
