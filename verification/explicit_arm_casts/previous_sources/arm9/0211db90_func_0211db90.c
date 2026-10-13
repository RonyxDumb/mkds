/* Decompiled C draft; module arm9; ROM address 0211db90. No matching claim. */
#include "types.h"
#include "deps/0211db90_func_0211db90.h"

void func_0211db90(void)

{
  undefined4 uVar1;
  int local_10;
  int local_c;
  int local_8 [2];
  
  local_10 = 0;
  local_c = 0;
  local_8[0] = 0;
  if (*(int *)(*piRam0211dd04 + 0x2c) == 3) {
    uVar1 = find_buf_fn_from_thumb(*puRam0211dd08);
    MaybeReadCharBlock_1(&local_c,uVar1);
    uVar1 = find_buf_fn_from_thumb(*puRam0211dd0c);
    MaybeReadScreenBlock(*piRam0211dd04 + 0x20,uVar1);
    uVar1 = find_buf_fn_from_thumb(*puRam0211dd10);
    *(undefined4 *)(*piRam0211dd04 + 4) = uVar1;
    uVar1 = find_buf_fn_from_thumb(*puRam0211dd14);
    *(undefined4 *)(*piRam0211dd04 + 8) = uVar1;
    uVar1 = find_buf_fn_from_thumb(*puRam0211dd18);
    *(undefined4 *)(*piRam0211dd04 + 0xc) = uVar1;
  }
  else {
    uVar1 = find_buf_fn_from_thumb(*puRam0211dd1c);
    MaybeReadCharBlock_1(&local_c,uVar1);
    uVar1 = find_buf_fn_from_thumb(*puRam0211dd20);
    MaybeReadScreenBlock(*piRam0211dd04 + 0x20,uVar1);
    uVar1 = find_buf_fn_from_thumb(*puRam0211dd24);
    *(undefined4 *)(*piRam0211dd04 + 4) = uVar1;
    uVar1 = find_buf_fn_from_thumb(*puRam0211dd28);
    *(undefined4 *)(*piRam0211dd04 + 8) = uVar1;
    uVar1 = find_buf_fn_from_thumb(*puRam0211dd2c);
    *(undefined4 *)(*piRam0211dd04 + 0xc) = uVar1;
  }
  uVar1 = find_buf_fn_from_thumb(*puRam0211dd30);
  Gfx_ReadPaletteRelative(local_8,uVar1);
  uVar1 = Mem_AllocateHeap(*(undefined4 *)(*piRam0211dd04 + 0x28),uRam0211dd34);
  *(undefined4 *)(*piRam0211dd04 + 0x24) = uVar1;
  uVar1 = find_buf_fn_from_thumb(*puRam0211dd38);
  Gfx_ReadCharGraphicsRelative(&local_10,uVar1);
  uVar1 = find_buf_fn_from_thumb(*puRam0211dd3c);
  func_020b48b4(*piRam0211dd04,uVar1);
  uVar1 = find_buf_fn_from_thumb(*puRam0211dd40);
  Gfx_ReadPaletteRelative(*piRam0211dd04 + 0x10,uVar1);
  AllocateReserveTEQSub(0x14,0,*(undefined4 *)(local_c + 0x14),*(undefined4 *)(local_c + 0x10));
  AllocateReserveTEQSub
            (0x1b,0,*(int *)(*piRam0211dd04 + 0x20) + 0xc,
             *(undefined4 *)(*(int *)(*piRam0211dd04 + 0x20) + 8));
  AllocateReserveTEQSub(0x1b,uRam0211dd34,*(undefined4 *)(*piRam0211dd04 + 0x24),uRam0211dd34);
  AllocateReserveTEQSub(0x1f,0,*(undefined4 *)(local_8[0] + 0xc),0x80);
  AllocateReserveTEQSub(0x23,0,*(undefined4 *)(local_10 + 0x14),*(undefined4 *)(local_10 + 0x10));
  AllocateReserveTEQSub
            (0x1e,0,*(undefined4 *)(*(int *)(*piRam0211dd04 + 0x10) + 0xc),
             *(undefined4 *)(*(int *)(*piRam0211dd04 + 0x10) + 8));
  return;
}

