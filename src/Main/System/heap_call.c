#include "Main/System/heap_call.h"
#include "Main/System/startup.h"
#include "Main/System/heap.h"
#include "Main/Menu/select_kart_ghost_work.h"
#include "Main/System/interpolation_value.h"
#include "code_02022aa8.h"
#include "Main/Graphics/cell_file_set.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Menu/multi_select_member_group.h"
#include "tp.h"
#include "Main/Save/buddy_record_time.h"
#include "g2d_CellTransferManager.h"

HeapCall *gCurrentHeapCall;
s32 gDwcInitResult;
StartupMemory gStartupMemory;
u8 gDwcInitWork[0x700];

void InitHeapCall(HeapCall *call, u32 func) {
    call->mName = NULL;
    call->mFunc = func;
    call->mAfterFunc = 0;
    call->mParent = NULL;
    call->mHeap = NULL;
}

void SetHeapCallFunc(HeapCall *call, u32 func) {
    call->mFunc = func;
}

u32 RunHeapCall(HeapCall *call, u32 argument) {
    u32 result;
    void *outerHeap;
    call->mParent = gCurrentHeapCall;
    if (call->mParent != NULL) {
        outerHeap = call->mParent->mHeap;
    } else {
        outerHeap = GetArenaHeap();
    }
    call->mHeap = CreateExpHeapFromMaxFree(outerHeap);
    gCurrentHeapCall = call;
    result = ((u32(*)(u32)) call->mFunc)(argument);
    if (call->mAfterFunc != 0) {
        ((void (*)(void)) call->mAfterFunc)();
    }
    gCurrentHeapCall = call->mParent;
    HeapDestroy(call->mHeap);
    call->mHeap = NULL;
    return result;
}

void *GetCurrentHeapCall(void) {
    return gCurrentHeapCall;
}

void *GetHeap(HeapCall *call) {
    return call->mHeap;
}
