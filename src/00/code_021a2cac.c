#include "00/code_021a2cac.h"
#include "00/code_0219eaf4.h"
#include "00/code_021a2950.h"

u32 DWC_CancelMatching(void) {
    int valid;
    valid = DWC_IsValidCancelMatching();
    if (valid != 0) {
        DWCi_DoCancelMatching();
        return 1;
    }
    return 0;
}
