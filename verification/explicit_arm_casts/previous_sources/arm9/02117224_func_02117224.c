/* Decompiled C draft; module arm9; ROM address 02117224. No matching claim. */
#include "types.h"
#include "deps/02117224_func_02117224.h"

void func_02117224(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  
  iVar2 = Mem_AllocateHeap(param_1,0x18);
  *piRam02117294 = iVar2;
  uVar3 = find_buf_fn_from_thumb(*puRam02117298);
  Gfx_ReadCharGraphicsRelative(*piRam02117294,uVar3);
  uVar3 = find_buf_fn_from_thumb(*puRam0211729c);
  func_020b48b4(*piRam02117294 + 4,uVar3);
  piVar1 = piRam02117294;
  iVar5 = 0;
  iVar2 = 0;
  puVar4 = puRam021172a0;
  do {
    uVar3 = find_buf_fn_from_thumb(*puVar4);
    Gfx_ReadPaletteRelative(*piVar1 + 8 + iVar2,uVar3);
    puVar4 = puVar4 + 1;
    iVar2 = iVar2 + 4;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 3);
  uVar3 = find_buf_fn_from_thumb(*puRam021172a4);
  *(undefined4 *)(*piRam02117294 + 0x14) = uVar3;
  return;
}

