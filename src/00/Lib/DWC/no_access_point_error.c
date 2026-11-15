#include "00/Lib/DWC/no_access_point_error.h"
#include "00/Lib/DWC/access_point_state.h"

u32 GetIrregularError(void) {
    return 0xfffffffa;
}

u32 GetNotFoundAP(ACHOLD *hold) {
    if (hold->mBeaconReceived == 0) {
        return (0xffff3c4du);
    }
    return (0xffff3865u);
}
