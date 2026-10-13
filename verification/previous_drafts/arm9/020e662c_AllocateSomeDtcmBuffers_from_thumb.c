/* Decompiled C draft; module arm9; ROM address 020e662c. No matching claim. */
#include "types.h"
#include "deps/020e662c_AllocateSomeDtcmBuffers_from_thumb.h"

void AllocateSomeDtcmBuffers_from_thumb(void)

{
  undefined4 uVar1;
  
  uVar1 = Mem_AllocateHeap(*(undefined4 *)(*piRam020e66c0 + 0x24),0x30);
  *puRam020e66c4 = uVar1;
  uVar1 = Mem_AllocateHeap(*(undefined4 *)(*piRam020e66c0 + 0x24),0x30);
  *puRam020e66c8 = uVar1;
  uVar1 = Mem_AllocateHeap(*(undefined4 *)(*piRam020e66c0 + 0x24),0x30);
  *puRam020e66cc = uVar1;
  uVar1 = Mem_AllocateHeap(*(undefined4 *)(*piRam020e66c0 + 0x24),0x30);
  *puRam020e66d0 = uVar1;
  uVar1 = Mem_AllocateHeap(*(undefined4 *)(*piRam020e66c0 + 0x24),0x30);
  *puRam020e66d4 = uVar1;
  uVar1 = Mem_AllocateHeap(*(undefined4 *)(*piRam020e66c0 + 0x24),0x30);
  *puRam020e66d8 = uVar1;
  uVar1 = Mem_AllocateHeap(*(undefined4 *)(*piRam020e66c0 + 0x24),0x30);
  *puRam020e66dc = uVar1;
  uVar1 = Mem_AllocateHeap(*(undefined4 *)(*piRam020e66c0 + 0x24),0x24);
  *puRam020e66e0 = uVar1;
  Matrix4x3_Identity((undefined4 *)(uintptr_t)(*puRam020e66d8));
  return;
}

