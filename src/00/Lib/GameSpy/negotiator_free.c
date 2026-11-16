#include "00/Lib/GameSpy/negotiator_free.h"
#include "00/Lib/GameSpy/socket_calls.h"

void NegotiatorFree(NatTraversalEntry *negotiator) {
    if (negotiator->mDescriptor != -1) {
        closesocket(negotiator->mDescriptor);
    }
    negotiator->mDescriptor = -1;
    negotiator->mState = NAT_NEGOTIATION_CANCELED;
}
