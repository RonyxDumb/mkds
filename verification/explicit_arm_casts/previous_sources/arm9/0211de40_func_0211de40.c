/* Decompiled C draft; module arm9; ROM address 0211de40. No matching claim. */
#include "types.h"
#include "deps/0211de40_func_0211de40.h"

void func_0211de40(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Mem_AllocateHeap(param_1,0xc);
  *piRam0211de88 = iVar1;
  uVar2 = find_buf_fn_from_thumb(*puRam0211de8c);
  Gfx_ReadCharGraphicsRelative(*piRam0211de88,uVar2);
  uVar2 = find_buf_fn_from_thumb(*puRam0211de90);
  func_020b48b4(*piRam0211de88 + 4,uVar2);
  uVar2 = find_buf_fn_from_thumb(*puRam0211de94);
  *(undefined4 *)(*piRam0211de88 + 8) = uVar2;
  return;
}

