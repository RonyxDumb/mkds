/* Decompiled C draft; module arm9; ROM address 0202a734. No matching claim. */
#include "types.h"
#include "deps/0202a734_Maybe_WiFi_VS_course_select_s_b.h"

void Maybe_WiFi_VS_course_select_s_b(void)

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
  uVar1 = find_buf_fn_from_thumb(uRam0202a7f0);
  Gfx_ReadCharGraphicsV2(&local_18,uVar1);
  uVar1 = find_buf_fn_from_thumb(uRam0202a7f4);
  Gfx_ReadCharGraphicsV2(&local_18,uVar1);
  uVar1 = find_buf_fn_from_thumb(uRam0202a7f8);
  Gfx_ReadCharGraphics(&local_18,uVar1);
  uVar1 = find_buf_fn_from_thumb(uRam0202a7fc);
  Gfx_ReadCharGraphics(&local_18,uVar1);
  uVar1 = find_buf_fn_from_thumb(uRam0202a800);
  LoadCellBankFrom(&local_10,uVar1);
  uVar1 = find_buf_fn_from_thumb(uRam0202a804);
  LoadCellBankFrom(&local_10,uVar1);
  uVar1 = find_buf_fn_from_thumb(uRam0202a808);
  Gfx_ReadPalette(&local_14,uVar1);
  uVar1 = find_buf_fn_from_thumb(uRam0202a80c);
  Gfx_ReadPalette(&local_14,uVar1);
  uVar1 = find_buf_fn_from_thumb(uRam0202a810);
  Gfx_ReadPalette(&local_14,uVar1);
  uVar1 = find_buf_fn_from_thumb(uRam0202a814);
  Gfx_ReadPalette(&local_14,uVar1);
  uVar1 = find_buf_fn_from_thumb(uRam0202a818);
  MaybeReadScreenBlock_0(local_c,uVar1);
  uVar1 = find_buf_fn_from_thumb(uRam0202a81c);
  MaybeReadScreenBlock_0(local_c,uVar1);
  return;
}

