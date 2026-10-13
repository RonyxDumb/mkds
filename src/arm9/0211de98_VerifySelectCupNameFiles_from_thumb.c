/* Decompiled C draft; module arm9; ROM address 0211de98. No matching claim. */
#include "types.h"
#include "deps/0211de98_VerifySelectCupNameFiles_from_thumb.h"

void VerifySelectCupNameFiles_from_thumb(void)

{
  undefined4 uVar1;
  undefined4 local_10;
  undefined4 local_c [3];
  
  local_10 = 0;
  local_c[0] = 0;
  uVar1 = find_buf_fn_from_thumb(*puRam0211dec8);
  Gfx_ReadCharGraphics(&local_10,uVar1);
  uVar1 = find_buf_fn_from_thumb(*puRam0211decc);
  LoadCellBankFrom(local_c,uVar1);
  return;
}

