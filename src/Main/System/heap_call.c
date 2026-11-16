#include "Main/System/heap_call.h"
#include "Main/System/startup.h"
#include "Main/System/heap.h"
#include "Main/Menu/select_kart_ghost_work.h"
#include "Main/System/interpolation_value.h"
#include "font_glyph_layout.h"
#include "Main/Graphics/cell_file_set.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Menu/multi_select_member_group.h"
#include "touch_panel_sampling.h"
#include "Main/Save/buddy_record_time.h"
#include "cell_transfer_state.h"

HeapCall *g_ActiveExecutionContext;
s32 g_DwcStatus;
StartupMemory g_GlobalGG;
u8 gDwcInitWork[0x700];

void ExecutionContext_Create(HeapCall *call, u32 func) {
    call->mName = NULL;
    call->mFunc = func;
    call->mAfterFunc = 0;
    call->mParent = NULL;
    call->mHeap = NULL;
}

void ExecutionContext_SetFunction(HeapCall *call, u32 func) {
    call->mFunc = func;
}

u32 ExecutionContext_Execute(HeapCall *call, u32 argument) {
    u32 result;
    void *outerHeap;
    call->mParent = g_ActiveExecutionContext;
    if (call->mParent != NULL) {
        outerHeap = call->mParent->mHeap;
    } else {
        outerHeap = GetGlobalHeapHandle();
    }
    call->mHeap = Mem_CreateChildExpHeap(outerHeap);
    g_ActiveExecutionContext = call;
    result = ((u32(*)(u32)) call->mFunc)(argument);
    if (call->mAfterFunc != 0) {
        ((void (*)(void)) call->mAfterFunc)();
    }
    g_ActiveExecutionContext = call->mParent;
    Mem_DestroyHeap(call->mHeap);
    call->mHeap = NULL;
    return result;
}

void *GetActiveExecutionContext(void) {
    return g_ActiveExecutionContext;
}

void *ExecutionContext_GetHeapHandle(HeapCall *call) {
    return call->mHeap;
}
