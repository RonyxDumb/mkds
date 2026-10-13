/* Decompiled C draft; module arm9; ROM address 02078f18. No matching claim. */
#include "types.h"
#include "deps/02078f18_StructCESub_Initialize_from_thumb.h"

void StructCESub_Initialize_from_thumb(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  StructAD00Sub_Initialize_from_thumb(param_2);
  *(undefined4 *)(param_2 + 0xb0) = *(undefined4 *)*puRam02078f74;
  *(undefined4 *)(param_2 + 0xb4) = 0;
  uVar1 = Mem_AllocateHeap(param_1,0x6c);
  *(undefined4 *)(param_2 + 0x10) = uVar1;
  uVar1 = Mem_AllocateHeap(param_1,0x6c);
  *(undefined4 *)(param_2 + 0x14) = uVar1;
  uVar1 = Mem_AllocateHeap(param_1,0x6c);
  *(undefined4 *)(param_2 + 0x18) = uVar1;
  uVar1 = Mem_AllocateHeap(param_1,0x74);
  *(undefined4 *)(param_2 + 0x1c) = uVar1;
  uVar1 = Mem_AllocateHeap(param_1,0x38);
  *(undefined4 *)(param_2 + 8) = uVar1;
  return;
}

