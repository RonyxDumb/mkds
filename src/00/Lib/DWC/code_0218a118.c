#include "00/Lib/DWC/code_0218a118.h"
#include "00/Lib/DWC/code_02188ec0.h"
#include "00/Lib/DWC/code_021884d8.h"

s32 ConnectTestEnd(const ACWORK *work) {
    SetAcHoldApType(work->mConnectApType);
    return 0x10;
}
