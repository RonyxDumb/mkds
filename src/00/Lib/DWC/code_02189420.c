#include "00/Lib/DWC/code_02189420.h"
#include "00/Lib/DWC/code_021884d8.h"

u32 GetIrregularError(void) {
    return 0xfffffffa;
}

u32 GetNotFoundAP(ACHOLD *hold) {
    if (hold->mBeaconReceived == 0) {
        return (0xffff3c4du);
    }
    return (0xffff3865u);
}
