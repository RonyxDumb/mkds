#include "00/Lib/DWC/dwc_memfunc.h"
#include "00/unk_021b5000.h"
#include "03/Net/essid_packet_steps.h"
#include "code_0214d018.h"

u8 gAllocFunc[4];
u8 gFreeFunc[4];

u32 DWC_SetMemFunc(void *(*alloc)(u32, u32, s32), void (*free)(u32, void *)) {
    u32 allocFunction = (u32) alloc;
    u32 freeFunction = (u32) free;
    u32 allocSlotAddress;
    u32 freeSlotAddress;
    allocSlotAddress = (u32) &gAllocFunc;
    *(u32 *) ((allocSlotAddress) + 0u) = allocFunction;
    freeSlotAddress = (u32) &gFreeFunc;
    *(u32 *) ((freeSlotAddress) + 0u) = freeFunction;
    return freeSlotAddress;
}

void *DWC_Alloc(u32 name, u32 size) {
    return (*(void *(**) (u32, u32, u32)) & gAllocFunc)(name, size, 0x20);
}

void *DWC_AllocEx(u32 name, u32 size, u32 align) {
    u32 allocSlotAddress = ((u32) (&gAllocFunc));
    u32 allocFunction = (*(u32 *) ((allocSlotAddress) + (0)));
    u32 allocatedMemory = ((u32(*)(u32, u32, u32))(allocFunction))(name, size, align);
    return (void *) allocatedMemory;
}

void DWC_Free(u32 name, u32 ptr, u32 size) {
    u32 freeSlotAddress = ((u32) (&gFreeFunc));
    u32 freeFunction = (*(u32 *) ((freeSlotAddress) + (0)));
    u32 freeResult = ((u32(*)(u32, u32, u32))(freeFunction))(name, ptr, size);
}

void *DWC_Realloc(u32 name, void *ptr, u32 oldsize, u32 newsize) {
    return DWC_ReallocEx(name, ptr, oldsize, newsize, 0x20);
}

void *DWC_ReallocEx(u32 name, void *ptr, u32 heldSize, u32 wantedSize, u32 align) {
    void *moved;
    moved = (*(void *(**) (u32, u32, u32)) & gAllocFunc)(name, wantedSize, align);
    if (moved == NULL) {
        return NULL;
    }
    if (ptr != NULL) {
        MI_CpuCopy8(ptr, moved, wantedSize);
        (*(UnkWordFunc *) (*(u32 *) &gFreeFunc))(name, ptr, heldSize);
    }
    return moved;
}

void *DWCi_GsMalloc(u32 size) {
    return DWC_Alloc(5, size);
}

void *DWCi_GsRealloc(void *ptr, u32 size) {
    return DWC_Realloc(5, ptr, size, size);
}

void DWCi_GsFree(void *ptr) {
    u32 pointerValue = (u32) ptr;
    u32 freePointer;
    u32 freeSize;
    u32 unusedValue;
    freePointer = (pointerValue) + (0u);
    pointerValue = 5u;
    freeSize = 0u;
    DWC_Free(pointerValue, freePointer, freeSize);
}
