#include "00/Lib/DWC/connect_test_create.h"
#include "00/Lib/DWC/network_check_control.h"
#include "00/Lib/DWC/access_point_state.h"

u32 ConnectTestCreate(void) {
    int result;
    result = DWC_Netcheck_Create(DWCi_AC_GetMemPtr(AC_MEM_NETCHECK));
    if (result != 0) {
        DWCi_AC_SetError(3);
        return 0x11;
    }
    return 0xe;
}
