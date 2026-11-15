#include "00/Lib/DWC/code_0219c384.h"

#include "00/unk_021b5000.h"

s32 stDwcErrorCode;
s32 stDwcLastError;

s32 DWC_GetLastError(s32 *errorCode) {
    if (errorCode != NULL) {
        *errorCode = stDwcErrorCode;
    }
    return stDwcLastError;
}

void DWC_ClearError(void) {
    if (stDwcLastError != 11) {
        stDwcLastError = 0;
        stDwcErrorCode = 0;
    }
}

u32 DWCi_IsError(void) {
    if (stDwcLastError != 0) {
        return 1;
    }
    return 0;
}

void DWCi_SetError(s32 error, s32 errorCode) {
    if (stDwcLastError != 11) {
        stDwcLastError = error;
        stDwcErrorCode = errorCode;
    }
}
