#include "00/Lib/DWC/dwc_memfunc.h"
#include "00/unk_021b5000.h"
#include "03/Net/essid_wcm.h"
#include "code_0214d018.h"

u8 gAllocFunc[4];
u8 gFreeFunc[4];

u32 DWC_SetMemFunc(void *(*alloc)(u32, u32, s32), void (*free)(u32, void *)) {
    u32 value0 = (u32) alloc;
    u32 value1 = (u32) free;
    u32 value2;
    value2 = (u32) &gAllocFunc;
    *(u32 *) ((value2) + 0u) = value0;
    value0 = (u32) &gFreeFunc;
    *(u32 *) ((value0) + 0u) = value1;
    return value0;
}

void *DWC_Alloc(u32 name, u32 size) {
    return (*(void *(**) (u32, u32, u32)) & gAllocFunc)(name, size, 0x20);
}

void *DWC_AllocEx(u32 name, u32 size, u32 align) {
    u32 v2 = ((u32) (&gAllocFunc));
    u32 v3 = (*(u32 *) ((v2) + (0)));
    u32 v4 = ((u32(*)(u32, u32, u32))(v3))(name, size, align);
    return (void *) v4;
}

void DWC_Free(u32 name, u32 ptr, u32 size) {
    u32 v2 = ((u32) (&gFreeFunc));
    u32 v3 = (*(u32 *) ((v2) + (0)));
    u32 v4 = ((u32(*)(u32, u32, u32))(v3))(name, ptr, size);
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
    u32 value0 = (u32) ptr;
    u32 value1;
    u32 value2;
    u32 value3;
    value1 = (value0) + (0u);
    value0 = 5u;
    value2 = 0u;
    DWC_Free(value0, value1, value2);
}
