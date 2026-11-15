#include "00/Lib/DWC/code_0218a194.h"
#include "00/Lib/DWC/code_02188008.h"
#include "00/Lib/DWC/code_021884d8.h"

u32 ConnectTestCreate(void) {
    int result;
    result = DWC_Netcheck_Create(DWCi_AC_GetMemPtr(AC_MEM_NETCHECK));
    if (result != 0) {
        DWCi_AC_SetError(3);
        return 0x11;
    }
    return 0xe;
}
