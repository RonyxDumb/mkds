/* Decompiled C draft; module arm9; ROM address 021172a8. No matching claim. */
#include "types.h"
#include "deps/021172a8_func_021172a8.h"

void func_021172a8(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  
  iVar2 = Mem_AllocateHeap(param_1,0x18);
  *piRam02117318 = iVar2;
  uVar3 = find_buf_fn_from_thumb(*puRam0211731c);
  Gfx_ReadCharGraphicsRelative(*piRam02117318,uVar3);
  uVar3 = find_buf_fn_from_thumb(*puRam02117320);
  func_020b48b4(*piRam02117318 + 4,uVar3);
  piVar1 = piRam02117318;
  iVar5 = 0;
  iVar2 = 0;
  puVar4 = puRam02117324;
  do {
    uVar3 = find_buf_fn_from_thumb(*puVar4);
    Gfx_ReadPaletteRelative(*piVar1 + 8 + iVar2,uVar3);
    puVar4 = puVar4 + 1;
    iVar2 = iVar2 + 4;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 3);
  uVar3 = find_buf_fn_from_thumb(*puRam02117328);
  *(undefined4 *)(*piRam02117318 + 0x14) = uVar3;
  return;
}

