/* Decompiled C draft; module arm9; ROM address 021144c0. No matching claim. */
#include "types.h"
#include "deps/021144c0_Maybe_emblem2.h"

void Maybe_emblem2(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Mem_AllocateHeap(param_1,0x10);
  *piRam021144fc = iVar1;
  uVar2 = Mem_AllocateHeap(param_1,0x78);
  *(undefined4 *)(*piRam021144fc + 4) = uVar2;
  uVar2 = func_0205eda0(param_1);
  *(undefined4 *)(*piRam021144fc + 8) = uVar2;
  uVar2 = find_buf_fn_from_thumb(uRam02114500);
  *(undefined4 *)(*piRam021144fc + 0xc) = uVar2;
  return;
}

