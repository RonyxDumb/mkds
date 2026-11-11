#include "00/code_0218a0f4.h"
#include "00/code_021a8aa8.h"

s32 ConnectTestRetry(void) {
    s32 result = SOC_Cleanup();
    if (result == 0 || result == -39) {
        return 9;
    }
    return 11;
}
