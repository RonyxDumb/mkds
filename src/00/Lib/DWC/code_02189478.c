#include "00/Lib/DWC/code_02189478.h"
#include "00/Lib/DWC/code_021884d8.h"
#include "00/Lib/DWC/code_021892f4.h"
#include "00/Lib/DWC/code_02189350.h"
#include "00/Lib/DWC/code_02189420.h"
#include "00/Lib/DWC/code_02189440.h"

u8 DWCi_AC_Error(void) {
    int status;
    status = DWCi_AC_GetMemPtr(1);
    status = DWCi_AC_CloseNetwork((u8 *) (status + 10));
    if (status == 1) {
        return 0x12;
    }
    return 0x11;
}

u32 DWCi_AC_GetResult(void) {
    u32 hold;
    int error;
    hold = DWCi_AC_GetMemPtr(1);
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
    return GetNotFoundInet((ACHOLD *) hold);
}
