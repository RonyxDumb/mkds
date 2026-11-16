#pragma once

#include "types.h"

typedef struct Unk0217aa14_104_68 Unk0217aa14_104_68;

struct MapObjectKindDescriptor;

void ressc_update(u32 arg0);
void ressc_vblank(void);
void ressc_finalize(void);
void ressc_init(void);
u32 overlay_isAddressInOverlay(struct MapObjectKindDescriptor *address);
void overlay_unload(void);
s32 overlay_tryFinishLoad(void);
void overlay_destroyExpHeap(void);
void overlay_createExpHeap(void);
void overlay_finishLoad(void);
void overlay_beginLoad(s32 overlay);
void overlay_reset(void);
void overlay_createFrmHeap(void);
void overlay_init(void *heap);
s32 func_0205a2ac(s32 a);
s32 func_0205a310(s32 a);
void func_0205a350(void);
void func_0205a4b0(Unk0217aa14_104_68 *a, s32 b);
