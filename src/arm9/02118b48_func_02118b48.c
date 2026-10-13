/* Decompiled C draft; module arm9; ROM address 02118b48. No matching claim. */
#include "types.h"
#include "deps/02118b48_func_02118b48.h"

void func_02118b48(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10 [2];
  
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_10[0] = 0;
  if (*psRam02118cf8 == 2) {
    uVar1 = find_buf_fn_from_thumb(*puRam02118cfc);
    *(undefined4 *)(*piRam02118d00 + 0x14) = uVar1;
    return;
  }
  uVar1 = find_buf_fn_from_thumb(*puRam02118d04);
  MaybeReadCharBlock_1(&local_18,uVar1);
  uVar1 = find_buf_fn_from_thumb(*puRam02118d08);
  Gfx_ReadPaletteRelative(local_10,uVar1);
  uVar1 = find_buf_fn_from_thumb(*puRam02118d0c);
  MaybeReadScreenBlock(&local_14,uVar1);
  uVar1 = Mem_AllocateHeap(*(undefined4 *)(*piRam02118d00 + 0x2c),uRam02118d10);
  *(undefined4 *)(*piRam02118d00 + 0x20) = uVar1;
  uVar1 = find_buf_fn_from_thumb(*puRam02118d14);
  *(undefined4 *)(*piRam02118d00 + 4) = uVar1;
  uVar1 = find_buf_fn_from_thumb(*puRam02118d18);
  *(undefined4 *)(*piRam02118d00 + 8) = uVar1;
  uVar1 = find_buf_fn_from_thumb(*puRam02118d1c);
  Gfx_ReadCharGraphicsRelative(&local_28,uVar1);
  uVar1 = find_buf_fn_from_thumb(*puRam02118d20);
  func_020b48b4((int *)(uintptr_t)(*piRam02118d00),uVar1);
  uVar1 = find_buf_fn_from_thumb(*puRam02118d24);
  Gfx_ReadPaletteRelative(&local_24,uVar1);
  uVar1 = find_buf_fn_from_thumb(*puRam02118d28);
  *(undefined4 *)(*piRam02118d00 + 0x10) = uVar1;
  uVar1 = find_buf_fn_from_thumb(*puRam02118cfc);
  *(undefined4 *)(*piRam02118d00 + 0x14) = uVar1;
  uVar1 = find_buf_fn_from_thumb(*puRam02118d2c);
  Gfx_ReadCharGraphicsRelative(&local_20,uVar1);
  uVar1 = find_buf_fn_from_thumb(*puRam02118d30);
  func_020b48b4((int *)(uintptr_t)(*piRam02118d00 + 0xc),uVar1);
  uVar1 = find_buf_fn_from_thumb(*puRam02118d34);
  Gfx_ReadPaletteRelative(&local_1c,uVar1);
  iVar3 = *(int *)(local_24 + 0xc);
  iVar2 = func_020cccb4();
  if ((iVar2 != 0x18) && (iVar2 = func_020cccb4(), iVar2 != 0xc)) {
    AllocateReserveTEQSub(4,0,*(undefined4 *)(local_18 + 0x14),*(undefined4 *)(local_18 + 0x10));
    AllocateReserveTEQSub(0xf,0,*(undefined4 *)(local_10[0] + 0xc),uRam02118d38);
    AllocateReserveTEQSub(8,0,local_14 + 0xc,*(undefined4 *)(local_14 + 8));
    AllocateReserveTEQSub(8,uRam02118d10,*(undefined4 *)(*piRam02118d00 + 0x20),uRam02118d10);
  }
  AllocateReserveTEQSub(0x13,0,*(undefined4 *)(local_28 + 0x14),*(undefined4 *)(local_28 + 0x10));
  AllocateReserveTEQSub(0xe,0,*(undefined4 *)(local_24 + 0xc),uRam02118d3c);
  AllocateReserveTEQSub(0xe,iRam02118d40,iVar3 + iRam02118d40,0x40);
  AllocateReserveTEQSub(0x23,0,*(undefined4 *)(local_20 + 0x14),*(undefined4 *)(local_20 + 0x10));
  AllocateReserveTEQSub(0x1e,0,*(undefined4 *)(local_1c + 0xc),*(undefined4 *)(local_1c + 8));
  return;
}

