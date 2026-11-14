#include "Main/Unknown/code_02056444.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/unk_02165000.h"

#pragma thumb on

KartAppear *CreateKartAppear(void *heap) {
    KartAppear *kartAppear;
    kartAppear = HeapAlloc(heap, 4);
    kartAppear->mFileData = FindFileInLoadedArchives(gKartAppearFileName);
    return kartAppear;
}

#pragma thumb off
