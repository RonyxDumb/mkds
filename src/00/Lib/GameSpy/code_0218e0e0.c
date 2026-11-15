#include "00/Lib/GameSpy/code_0218e0e0.h"
#include "00/Lib/DWC/connection_error_strings.h"
#include "code_02134398.h"
#include "00/Lib/DWC/dwc_memfunc.h"
#include "00/Lib/GameSpy/code_0218dd8c.h"

void *TableNew(u32 elemSize, u32 nBuckets, void *hashFn, void *compFn, void *freeFn) {
    return HashtableCreate(elemSize, nBuckets, 4, (s32(*)(void *, s32))(hashFn), (ElementCompareFunc *) (compFn),
                           (void (*)(void *))(freeFn));
}
