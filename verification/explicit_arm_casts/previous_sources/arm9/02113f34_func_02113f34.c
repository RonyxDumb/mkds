/* Decompiled C draft; module arm9; ROM address 02113f34. No matching claim. */
#include "types.h"
#include "deps/02113f34_func_02113f34.h"

void func_02113f34(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  uVar1 = find_buf_fn_from_thumb(*puRam02114104);
  Gfx_ReadCharGraphicsRelative(*piRam02114108,uVar1);
  uVar1 = find_buf_fn_from_thumb(*puRam0211410c);
  func_020b48b4(*piRam02114108 + 4,uVar1);
  uVar1 = find_buf_fn_from_thumb(*puRam02114110);
  Gfx_ReadPaletteRelative(&local_20,uVar1);
  uVar1 = find_buf_fn_from_thumb(*puRam02114114);
  *(undefined4 *)(*piRam02114108 + 8) = uVar1;
  uVar1 = find_buf_fn_from_thumb(*puRam02114118);
  *(undefined4 *)(*piRam02114108 + 0xc) = uVar1;
  uVar1 = find_buf_fn_from_thumb(*puRam0211411c);
  *(undefined4 *)(*piRam02114108 + 0x18) = uVar1;
  uVar1 = find_buf_fn_from_thumb(*puRam02114120);
  *(undefined4 *)(*piRam02114108 + 0x1c) = uVar1;
  uVar1 = find_buf_fn_from_thumb(*puRam02114124);
  Gfx_ReadCharGraphicsRelative(*piRam02114108 + 0x28,uVar1);
  uVar1 = find_buf_fn_from_thumb(*puRam02114128);
  func_020b48b4(*piRam02114108 + 0x2c,uVar1);
  uVar1 = find_buf_fn_from_thumb(*puRam0211412c);
  Gfx_ReadPaletteRelative(&local_10,uVar1);
  uVar1 = find_buf_fn_from_thumb(*puRam02114130);
  *(undefined4 *)(*piRam02114108 + 0x30) = uVar1;
  uVar1 = find_buf_fn_from_thumb(*puRam02114134);
  *(undefined4 *)(*piRam02114108 + 0x34) = uVar1;
  uVar1 = find_buf_fn_from_thumb(*puRam02114138);
  *(undefined4 *)(*piRam02114108 + 0x38) = uVar1;
  iVar2 = GetEmblemPalette_from_thumb();
  uVar1 = find_buf_fn_from_thumb(*puRam0211413c);
  MaybeReadCharBlock_1(&local_1c,uVar1);
  uVar1 = find_buf_fn_from_thumb(*puRam02114140);
  MaybeReadScreenBlock(&local_18,uVar1);
  uVar1 = find_buf_fn_from_thumb(*puRam02114144);
  MaybeReadScreenBlock(*piRam02114108 + 0x10,uVar1);
  uVar1 = find_buf_fn_from_thumb(*puRam02114148);
  MaybeReadScreenBlock(*piRam02114108 + 0x20,uVar1);
  uVar1 = find_buf_fn_from_thumb(*puRam0211414c);
  Gfx_ReadPaletteRelative(&local_14,uVar1);
  iVar3 = *(int *)(local_20 + 0xc);
  AllocateReserveTEQSub
            (0x13,0,*(undefined4 *)(*(int *)*piRam02114108 + 0x14),
             *(undefined4 *)(*(int *)*piRam02114108 + 0x10));
  AllocateReserveTEQSub(0xe,0,*(undefined4 *)(local_20 + 0xc),uRam02114150);
  AllocateReserveTEQSub(0xe,iRam02114154,iVar3 + iRam02114154,0x40);
  AllocateReserveTEQSub
            (0x23,0,*(undefined4 *)(*(int *)(*piRam02114108 + 0x28) + 0x14),
             *(undefined4 *)(*(int *)(*piRam02114108 + 0x28) + 0x10));
  AllocateReserveTEQSub(0x1e,0,*(undefined4 *)(local_10 + 0xc),*(undefined4 *)(local_10 + 8));
  AllocateReserveTEQSub(4,0,*(undefined4 *)(local_1c + 0x14),*(undefined4 *)(local_1c + 0x10));
  AllocateReserveTEQSub(8,0,local_18 + 0xc,*(undefined4 *)(local_18 + 8));
  AllocateReserveTEQSub(0xf,0,*(undefined4 *)(local_14 + 0xc),0x40);
  AllocateReserveTEQSub(0xe,0x40,*(undefined4 *)(iVar2 + 0xc),0x20);
  return;
}

