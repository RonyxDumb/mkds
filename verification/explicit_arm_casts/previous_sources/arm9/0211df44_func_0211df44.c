/* Decompiled C draft; module arm9; ROM address 0211df44. No matching claim. */
#include "types.h"
#include "deps/0211df44_func_0211df44.h"

void func_0211df44(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Mem_AllocateHeap(param_1,0x10);
  *piRam0211dfa0 = iVar1;
  uVar2 = find_buf_fn_from_thumb(*puRam0211dfa4);
  Gfx_ReadCharGraphicsRelative(*piRam0211dfa0,uVar2);
  uVar2 = find_buf_fn_from_thumb(*puRam0211dfa8);
  func_020b48b4(*piRam0211dfa0 + 4,uVar2);
  uVar2 = find_buf_fn_from_thumb(*puRam0211dfac);
  Gfx_ReadPaletteRelative(*piRam0211dfa0 + 8,uVar2);
  uVar2 = find_buf_fn_from_thumb(*puRam0211dfb0);
  *(undefined4 *)(*piRam0211dfa0 + 0xc) = uVar2;
  return;
}

