#include "00/Lib/GameSpy/code_0218e0e0.h"
#include "00/unk_021b2000.h"
#include "code_02134398.h"
#include "00/Lib/DWC/dwc_memfunc.h"
#include "00/Lib/GameSpy/code_0218dd8c.h"

void *TableNew(u32 elemSize, u32 nBuckets, void *hashFn, void *compFn, void *freeFn) {
    return HashtableCreate(elemSize, nBuckets, 4, (s32(*)(void *, s32))(hashFn), (s32(*)(void *, void *))(compFn),
                           (void (*)(void *))(freeFn));
}
