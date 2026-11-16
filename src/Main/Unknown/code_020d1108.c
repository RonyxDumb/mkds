#include "Main/Unknown/code_020d1108.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_020d0efc.h"
#include "Main/Ui/CupPicture.h"
#include "Main/Unknown/code_020d113c.h"
#include "Main/Unknown/code_020d1158.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma thumb on

void cpic_init(void) {
    int result;
    CupPicture *cupPicture;
    u32 heap;
    result = cpic_MB_IsMultiBootChild_2();
    if (result == 0) {
        heap = cpic_process_getCurrentHeapHandle();
        cupPicture = heap_alloc((void *) heap, (0x0000185cu));
        gCupPicture = cupPicture;
        cupPicture->mCupPictureIndex = 0;
        cpic_loadForCourse(0x14);
    }
}

#pragma thumb off
