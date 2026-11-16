#include "Main/Unknown/code_02036588.h"

void proc_init(HeapCall *call, u32 func) {
    call->field0 = 0;
    call->mFunc = func;
    call->mAfterFunc = 0;
    call->mParent = NULL;
    call->mHeap = NULL;
}

void proc_setMainFunc(HeapCall *call, u32 func) {
    call->mFunc = func;
}
