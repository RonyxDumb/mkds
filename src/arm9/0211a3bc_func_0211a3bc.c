/* Decompiled C draft; module arm9; ROM address 0211a3bc. No matching claim. */
#include "types.h"
#include "deps/0211a3bc_func_0211a3bc.h"

void func_0211a3bc(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  if (*psRam0211a64c == 2) {
    uVar2 = find_buf_fn_from_thumb(*puRam0211a650);
    *(undefined4 *)(*piRam0211a654 + 0x14) = uVar2;
    return;
  }
  if (*(int *)(*piRam0211a654 + 0x40) == 0) {
    uVar2 = find_buf_fn_from_thumb(*puRam0211a658);
    MaybeReadCharBlock_1(&local_20,uVar2);
    uVar2 = find_buf_fn_from_thumb(*puRam0211a65c);
    Gfx_ReadPaletteRelative(&local_18,uVar2);
    uVar2 = find_buf_fn_from_thumb(*puRam0211a660);
    MaybeReadScreenBlock(&local_1c,uVar2);
  }
  else {
    uVar2 = find_buf_fn_from_thumb(*puRam0211a664);
    MaybeReadCharBlock_1(&local_20,uVar2);
    uVar2 = find_buf_fn_from_thumb(*puRam0211a668);
    Gfx_ReadPaletteRelative(&local_18,uVar2);
    uVar2 = find_buf_fn_from_thumb(*puRam0211a66c);
    MaybeReadScreenBlock(&local_1c,uVar2);
  }
  uVar2 = find_buf_fn_from_thumb(*puRam0211a670);
  MaybeReadCharBlock_1(&local_14,uVar2);
  uVar2 = find_buf_fn_from_thumb(*puRam0211a674);
  Gfx_ReadPaletteRelative(&local_c,uVar2);
  uVar2 = find_buf_fn_from_thumb(*puRam0211a678);
  MaybeReadScreenBlock(&local_10,uVar2);
  uVar2 = Mem_AllocateHeap(*(undefined4 *)(*piRam0211a654 + 0x30),uRam0211a67c);
  piVar1 = piRam0211a654;
  *(undefined4 *)(*piRam0211a654 + 0x24) = uVar2;
  if (*(int *)(*piVar1 + 0x40) == 0) {
    uVar2 = find_buf_fn_from_thumb(*puRam0211a680);
    *(undefined4 *)(*piRam0211a654 + 4) = uVar2;
    uVar2 = find_buf_fn_from_thumb(*puRam0211a684);
    *(undefined4 *)(*piRam0211a654 + 8) = uVar2;
  }
  else {
    uVar2 = find_buf_fn_from_thumb(*puRam0211a688);
    *(undefined4 *)(*piRam0211a654 + 4) = uVar2;
    uVar2 = find_buf_fn_from_thumb(*puRam0211a68c);
    *(undefined4 *)(*piRam0211a654 + 8) = uVar2;
  }
  uVar2 = find_buf_fn_from_thumb(*puRam0211a690);
  Gfx_ReadCharGraphicsRelative(&local_30,uVar2);
  uVar2 = find_buf_fn_from_thumb(*puRam0211a694);
  func_020b48b4((int *)(uintptr_t)(*piRam0211a654),uVar2);
  uVar2 = find_buf_fn_from_thumb(*puRam0211a698);
  Gfx_ReadPaletteRelative(&local_2c,uVar2);
  uVar2 = find_buf_fn_from_thumb(*puRam0211a69c);
  *(undefined4 *)(*piRam0211a654 + 0x10) = uVar2;
  uVar2 = find_buf_fn_from_thumb(*puRam0211a650);
  *(undefined4 *)(*piRam0211a654 + 0x14) = uVar2;
  uVar2 = find_buf_fn_from_thumb(*puRam0211a6a0);
  *(undefined4 *)(*piRam0211a654 + 0x18) = uVar2;
  uVar2 = find_buf_fn_from_thumb(*puRam0211a6a4);
  Gfx_ReadCharGraphicsRelative(&local_28,uVar2);
  uVar2 = find_buf_fn_from_thumb(*puRam0211a6a8);
  func_020b48b4((int *)(uintptr_t)(*piRam0211a654 + 0xc),uVar2);
  uVar2 = find_buf_fn_from_thumb(*puRam0211a6ac);
  Gfx_ReadPaletteRelative(&local_24,uVar2);
  iVar4 = *(int *)(local_2c + 0xc);
  AllocateReserveTEQSub(4,0,*(undefined4 *)(local_20 + 0x14),*(undefined4 *)(local_20 + 0x10));
  AllocateReserveTEQSub(0xf,0,*(undefined4 *)(local_18 + 0xc),uRam0211a6b0);
  AllocateReserveTEQSub(8,0,local_1c + 0xc,*(undefined4 *)(local_1c + 8));
  AllocateReserveTEQSub(8,uRam0211a67c,*(undefined4 *)(*piRam0211a654 + 0x24),uRam0211a67c);
  iVar3 = func_020cccb4();
  if ((iVar3 != 0x18) && (iVar3 = func_020cccb4(), iVar3 != 0xc)) {
    AllocateReserveTEQSub(0x17,0,*(undefined4 *)(local_14 + 0x14),*(undefined4 *)(local_14 + 0x10));
    AllocateReserveTEQSub(0x1f,0,*(undefined4 *)(local_c + 0xc),uRam0211a6b0);
    AllocateReserveTEQSub(0x1b,0,local_10 + 0xc,*(undefined4 *)(local_10 + 8));
    AllocateReserveTEQSub(0x1b,uRam0211a67c,*(undefined4 *)(*piRam0211a654 + 0x24),uRam0211a67c);
  }
  AllocateReserveTEQSub(0x13,0,*(undefined4 *)(local_30 + 0x14),*(undefined4 *)(local_30 + 0x10));
  AllocateReserveTEQSub(0xe,0,*(undefined4 *)(local_2c + 0xc),uRam0211a6b4);
  AllocateReserveTEQSub(0xe,iRam0211a6b8,iVar4 + iRam0211a6b8,0x40);
  AllocateReserveTEQSub(0x23,0,*(undefined4 *)(local_28 + 0x14),*(undefined4 *)(local_28 + 0x10));
  AllocateReserveTEQSub(0x1e,0,*(undefined4 *)(local_24 + 0xc),*(undefined4 *)(local_24 + 8));
  return;
}

