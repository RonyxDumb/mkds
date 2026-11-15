#include "00/Lib/GameSpy/table_create.h"
#include "00/Lib/DWC/connection_error_strings.h"
#include "print_memory_functions.h"
#include "00/Lib/DWC/dwc_memfunc.h"
#include "00/Lib/GameSpy/hash_table.h"

void *TableNew(u32 elemSize, u32 nBuckets, void *hashFn, void *compFn, void *freeFn) {
    return HashtableCreate(elemSize, nBuckets, 4, (s32(*)(void *, s32))(hashFn), (ElementCompareFunc *) (compFn),
                           (void (*)(void *))(freeFn));
}
