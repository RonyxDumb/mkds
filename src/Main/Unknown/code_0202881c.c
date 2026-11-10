#include "Main/Unknown/code_0202881c.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217a000.h"

u32 GetConnectionState(void) {
    return (gConnectionWork->mState);
}

void SetDataSharingSendByteInState8(u8 sendByte) {
    if (GetConnectionState() == 8) {
        gConnectionWork->mDataSharingSendByte = sendByte;
    }
}

u32 SelectKartGetPairHasPair(InputSlotPair *inputSlotPair) {
    return inputSlotPair->mHasPair;
}
