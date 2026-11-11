#include "00/code_02189420.h"

u32 GetIrregularError(void) {
    return 0xfffffffa;
}

u32 GetNotFoundAP(int hold) {
    if (*(u8 *) (hold + 0xb) == 0) {
        return (0xffff3c4du);
    }
    return (0xffff3865u);
}
