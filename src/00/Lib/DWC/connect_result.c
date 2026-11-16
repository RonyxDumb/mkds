#include "00/Lib/DWC/connect_result.h"
#include "00/Lib/DWC/access_point_state.h"
#include "00/Lib/DWC/access_point_close.h"
#include "00/Lib/DWC/no_internet_error.h"
#include "00/Lib/DWC/no_access_point_error.h"
#include "00/Lib/DWC/program_error.h"

u8 DWCi_AC_Error(void) {
    ACHOLD *hold;
    int status;
    hold = DWCi_AC_GetMemPtr(AC_MEM_HOLD);
    status = DWCi_AC_CloseNetwork(&hold->mErrorPhase);
    if (status == 1) {
        return 0x12;
    }
    return 0x11;
}

u32 DWCi_AC_GetResult(void) {
    ACHOLD *hold;
    int error;
    hold = DWCi_AC_GetMemPtr(AC_MEM_HOLD);
    error = DWCi_AC_GetError();
    if (error < 4) {
        return GetProgramaError(error);
    }
    if (error < 5) {
        return GetIrregularError();
    }
    if (error == 5) {
        return GetNotFoundAP(hold);
    }
    return GetNotFoundInet(hold);
}
