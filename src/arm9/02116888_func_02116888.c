/* Decompiled C draft; module arm9; ROM address 02116888. No matching claim. */
#include "types.h"
#include "deps/02116888_func_02116888.h"

void func_02116888(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int local_18;
  int local_14;
  int local_10 [2];
  
  local_18 = 0;
  local_14 = 0;
  local_10[0] = 0;
  uVar2 = find_buf_fn_from_thumb(*puRam02116a04);
  Gfx_ReadCharGraphicsRelative((int *)(uintptr_t)(*piRam02116a08),uVar2);
  uVar2 = find_buf_fn_from_thumb(*puRam02116a0c);
  func_020b48b4((int *)(uintptr_t)(*piRam02116a08 + 4),uVar2);
  uVar2 = find_buf_fn_from_thumb(*puRam02116a10);
  *(undefined4 *)(*piRam02116a08 + 8) = uVar2;
  uVar2 = find_buf_fn_from_thumb(*puRam02116a14);
  *(undefined4 *)(*piRam02116a08 + 0xc) = uVar2;
  uVar2 = find_buf_fn_from_thumb(*puRam02116a18);
  *(undefined4 *)(*piRam02116a08 + 0x18) = uVar2;
  uVar2 = find_buf_fn_from_thumb(*puRam02116a1c);
  *(undefined4 *)(*piRam02116a08 + 0x1c) = uVar2;
  uVar2 = find_buf_fn_from_thumb(*puRam02116a20);
  Gfx_ReadCharGraphicsRelative((int *)(uintptr_t)(*piRam02116a08 + 0x28),uVar2);
  uVar2 = find_buf_fn_from_thumb(*puRam02116a24);
  func_020b48b4((int *)(uintptr_t)(*piRam02116a08 + 0x2c),uVar2);
  uVar2 = find_buf_fn_from_thumb(*puRam02116a28);
  *(undefined4 *)(*piRam02116a08 + 0x30) = uVar2;
  uVar2 = find_buf_fn_from_thumb(*puRam02116a2c);
  *(undefined4 *)(*piRam02116a08 + 0x34) = uVar2;
  uVar2 = find_buf_fn_from_thumb(*puRam02116a30);
  piVar1 = piRam02116a08;
  *(undefined4 *)(*piRam02116a08 + 0x38) = uVar2;
  uVar2 = Mem_AllocateHeap(*(undefined4 *)(*piVar1 + 0x50),uRam02116a34);
  *(undefined4 *)(*piRam02116a08 + 0x4c) = uVar2;
  uVar2 = find_buf_fn_from_thumb(*puRam02116a38);
  MaybeReadCharBlock_1(&local_18,uVar2);
  uVar2 = find_buf_fn_from_thumb(*puRam02116a3c);
  MaybeReadScreenBlock(local_10,uVar2);
  uVar2 = find_buf_fn_from_thumb(*puRam02116a40);
  Gfx_ReadPaletteRelative(&local_14,uVar2);
  uVar2 = find_buf_fn_from_thumb(*puRam02116a44);
  MaybeReadScreenBlock((int *)(uintptr_t)(*piRam02116a08 + 0x10),uVar2);
  uVar2 = find_buf_fn_from_thumb(*puRam02116a48);
  MaybeReadScreenBlock((int *)(uintptr_t)(*piRam02116a08 + 0x20),uVar2);
  iVar3 = GetEmblemPalette_from_thumb();
  AllocateReserveTEQSub(0x17,0,*(undefined4 *)(local_18 + 0x14),*(undefined4 *)(local_18 + 0x10));
  AllocateReserveTEQSub(0x1b,0,local_10[0] + 0xc,*(undefined4 *)(local_10[0] + 8));
  AllocateReserveTEQSub(0x1b,uRam02116a34,*(undefined4 *)(*piRam02116a08 + 0x4c),uRam02116a34);
  AllocateReserveTEQSub(0x1f,0,*(undefined4 *)(local_14 + 0xc),0x40);
  AllocateReserveTEQSub(0xe,0x40,*(undefined4 *)(iVar3 + 0xc),0x20);
  return;
}

