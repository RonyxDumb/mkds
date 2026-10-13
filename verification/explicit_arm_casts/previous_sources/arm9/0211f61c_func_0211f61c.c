/* Decompiled C draft; module arm9; ROM address 0211f61c. No matching claim. */
#include "types.h"
#include "deps/0211f61c_func_0211f61c.h"

void func_0211f61c(void)

{
  undefined4 uVar1;
  int local_10;
  int local_c [3];
  
  local_10 = 0;
  local_c[0] = 0;
  uVar1 = find_buf_fn_from_thumb(*puRam0211f698);
  func_020b48b4(*piRam0211f69c,uVar1);
  uVar1 = find_buf_fn_from_thumb(*puRam0211f6a0);
  Gfx_ReadCharGraphicsRelative(&local_10,uVar1);
  uVar1 = find_buf_fn_from_thumb(*puRam0211f6a4);
  Gfx_ReadPaletteRelative(local_c,uVar1);
  uVar1 = find_buf_fn_from_thumb(*puRam0211f6a8);
  *(undefined4 *)(*piRam0211f69c + 4) = uVar1;
  uVar1 = find_buf_fn_from_thumb(*puRam0211f6ac);
  *(undefined4 *)(*piRam0211f69c + 0xc) = uVar1;
  AllocateReserveTEQSub(0x23,0,*(undefined4 *)(local_10 + 0x14),*(undefined4 *)(local_10 + 0x10));
  AllocateReserveTEQSub(0x1e,0,*(undefined4 *)(local_c[0] + 0xc),*(undefined4 *)(local_c[0] + 8));
  return;
}

