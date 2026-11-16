#include "00/Lib/DWC/memory_allocator.h"
#include "00/Lib/wifi_library_work_objects.h"
#include "03/Net/essid_packet_steps.h"
#include "cpu_copy_fill.h"

void *(*gAllocFunc)(u32, u32, s32);
void (*gFreeFunc)(u32, void *, u32);

u32 DWC_SetMemFunc(void *(*alloc)(u32, u32, s32), void (*free)(u32, void *, u32)) {
    gAllocFunc = alloc;
    gFreeFunc = free;
    return (u32) &gFreeFunc;
}

void *DWC_Alloc(u32 name, u32 size) {
    return gAllocFunc(name, size, 0x20);
}

void *DWC_AllocEx(u32 name, u32 size, u32 align) {
    return gAllocFunc(name, size, align);
}

void DWC_Free(u32 name, void *ptr, u32 size) {
    gFreeFunc(name, ptr, size);
}

void *DWC_Realloc(u32 name, void *ptr, u32 oldsize, u32 newsize) {
    return DWC_ReallocEx(name, ptr, oldsize, newsize, 0x20);
}

void *DWC_ReallocEx(u32 name, void *ptr, u32 heldSize, u32 wantedSize, u32 align) {
    void *moved;
    moved = gAllocFunc(name, wantedSize, align);
    if (moved == NULL) {
        return NULL;
    }
    if (ptr != NULL) {
        Mem_CpuCopy8(ptr, moved, wantedSize);
        gFreeFunc(name, ptr, heldSize);
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
    DWC_Free(5, ptr, 0);
}
