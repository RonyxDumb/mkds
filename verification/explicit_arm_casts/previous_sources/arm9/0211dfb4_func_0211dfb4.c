/* Decompiled C draft; module arm9; ROM address 0211dfb4. No matching claim. */
#include "types.h"
#include "deps/0211dfb4_func_0211dfb4.h"

void func_0211dfb4(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Mem_AllocateHeap(param_1,0x10);
  *piRam0211e010 = iVar1;
  uVar2 = find_buf_fn_from_thumb(*puRam0211e014);
  Gfx_ReadCharGraphicsRelative(*piRam0211e010,uVar2);
  uVar2 = find_buf_fn_from_thumb(*puRam0211e018);
  func_020b48b4(*piRam0211e010 + 4,uVar2);
  uVar2 = find_buf_fn_from_thumb(*puRam0211e01c);
  Gfx_ReadPaletteRelative(*piRam0211e010 + 8,uVar2);
  uVar2 = find_buf_fn_from_thumb(*puRam0211e020);
  *(undefined4 *)(*piRam0211e010 + 0xc) = uVar2;
  return;
}

