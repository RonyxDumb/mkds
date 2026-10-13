/* Decompiled C draft; module arm9; ROM address 0211dd44. No matching claim. */
#include "types.h"
#include "deps/0211dd44_VerifyCommonSelectRaceRuleFiles_from_thumb.h"

void VerifyCommonSelectRaceRuleFiles_from_thumb(void)

{
  undefined4 uVar1;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c [3];
  
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c[0] = 0;
  uVar1 = find_buf_fn_from_thumb(*puRam0211dde0);
  Gfx_ReadCharGraphicsV2(&local_14,uVar1);
  uVar1 = find_buf_fn_from_thumb(*puRam0211dde4);
  MaybeReadScreenBlock_0(&local_10,uVar1);
  uVar1 = find_buf_fn_from_thumb(*puRam0211dde8);
  Gfx_ReadPalette(local_c,uVar1);
  uVar1 = find_buf_fn_from_thumb(*puRam0211ddec);
  Gfx_ReadCharGraphicsV2(&local_14,uVar1);
  uVar1 = find_buf_fn_from_thumb(*puRam0211ddf0);
  MaybeReadScreenBlock_0(&local_10,uVar1);
  uVar1 = find_buf_fn_from_thumb(*puRam0211ddf4);
  Gfx_ReadCharGraphics(&local_20,uVar1);
  uVar1 = find_buf_fn_from_thumb(*puRam0211ddf8);
  LoadCellBankFrom(&local_1c,uVar1);
  uVar1 = find_buf_fn_from_thumb(*puRam0211ddfc);
  Gfx_ReadPalette(&local_18,uVar1);
  VerifyCommonWaitFiles_from_thumb();
  return;
}

