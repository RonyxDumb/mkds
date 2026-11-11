#include "00/code_0219a3e8.h"
#include "00/code_021a3690.h"

Gt2Connection *gti2CreateConnectionObject(void) {
    u32 value0;
    u32 allocFunction;
    value0 = 160u;
    allocFunction = (u32) &DWCi_GsMalloc;
    value0 = (u32) DWCi_GsMalloc(value0);
    return (Gt2Connection *) value0;
}
