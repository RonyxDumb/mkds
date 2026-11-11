#include "00/code_021a3678.h"
#include "00/code_021a369c.h"

void *DWCi_GsRealloc(void *ptr, u32 size) {
    return DWC_Realloc(5, ptr, size, size);
}
