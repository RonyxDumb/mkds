#include "Main/Kart/kart_appear.h"
#include "Main/System/heap.h"
#include "Main/System/result_archive_path.h"
#include "Main/Unknown/unk_02165000.h"

#pragma thumb on

KartAppear *CreateKartAppear(void *heap) {
    KartAppear *kartAppear;
    kartAppear = HeapAlloc(heap, 4);
    kartAppear->mFileData = FindFileInLoadedArchives(gKartAppearFileName);
    return kartAppear;
}

#pragma thumb off
