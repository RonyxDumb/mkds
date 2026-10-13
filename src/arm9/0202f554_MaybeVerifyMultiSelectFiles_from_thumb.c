/* Decompiled C draft; module arm9; ROM address 0202f554. No matching claim. */
#include "types.h"
#include "deps/0202f554_MaybeVerifyMultiSelectFiles_from_thumb.h"

void MaybeVerifyMultiSelectFiles_from_thumb(void)

{
  undefined4 uVar1;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c [3];
  
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c[0] = 0;
  uVar1 = find_buf_fn_from_thumb(uRam0202f648);
  Gfx_ReadCharGraphicsV2(&local_18,uVar1);
  uVar1 = find_buf_fn_from_thumb(uRam0202f64c);
  Gfx_ReadCharGraphics(&local_18,uVar1);
  uVar1 = find_buf_fn_from_thumb(uRam0202f650);
  Gfx_ReadCharGraphics(&local_18,uVar1);
  uVar1 = find_buf_fn_from_thumb(uRam0202f654);
  Gfx_ReadCharGraphics(&local_18,uVar1);
  uVar1 = find_buf_fn_from_thumb(uRam0202f658);
  Gfx_ReadCharGraphics(&local_18,uVar1);
  uVar1 = find_buf_fn_from_thumb(uRam0202f65c);
  LoadCellBankFrom(&local_10,uVar1);
  uVar1 = find_buf_fn_from_thumb(uRam0202f660);
  LoadCellBankFrom(&local_10,uVar1);
  uVar1 = find_buf_fn_from_thumb(uRam0202f664);
  LoadCellBankFrom(&local_10,uVar1);
  uVar1 = find_buf_fn_from_thumb(uRam0202f668);
  LoadCellBankFrom(&local_10,uVar1);
  uVar1 = find_buf_fn_from_thumb(uRam0202f66c);
  Gfx_ReadPalette(&local_14,uVar1);
  uVar1 = find_buf_fn_from_thumb(uRam0202f670);
  Gfx_ReadPalette(&local_14,uVar1);
  uVar1 = find_buf_fn_from_thumb(uRam0202f674);
  Gfx_ReadPalette(&local_14,uVar1);
  uVar1 = find_buf_fn_from_thumb(uRam0202f678);
  Gfx_ReadPalette(&local_14,uVar1);
  uVar1 = find_buf_fn_from_thumb(uRam0202f67c);
  Gfx_ReadPalette(&local_14,uVar1);
  uVar1 = find_buf_fn_from_thumb(uRam0202f680);
  MaybeReadScreenBlock_0(local_c,uVar1);
  uVar1 = find_buf_fn_from_thumb(uRam0202f684);
  MaybeReadScreenBlock_0(local_c,uVar1);
  return;
}

