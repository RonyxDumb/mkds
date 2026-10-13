/* Decompiled C draft; module arm9; ROM address 0211f2b8. No matching claim. */
#include "types.h"
#include "deps/0211f2b8_func_0211f2b8.h"

void func_0211f2b8(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Mem_AllocateHeap(param_1,0x10);
  *piRam0211f314 = iVar1;
  uVar2 = find_buf_fn_from_thumb(*puRam0211f318);
  Gfx_ReadCharGraphicsRelative(*piRam0211f314,uVar2);
  uVar2 = find_buf_fn_from_thumb(*puRam0211f31c);
  func_020b48b4(*piRam0211f314 + 4,uVar2);
  uVar2 = find_buf_fn_from_thumb(*puRam0211f320);
  Gfx_ReadPaletteRelative(*piRam0211f314 + 8,uVar2);
  uVar2 = find_buf_fn_from_thumb(*puRam0211f324);
  *(undefined4 *)(*piRam0211f314 + 0xc) = uVar2;
  return;
}

