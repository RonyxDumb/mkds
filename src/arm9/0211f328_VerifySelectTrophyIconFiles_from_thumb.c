/* Decompiled C draft; module arm9; ROM address 0211f328. No matching claim. */
#include "types.h"
#include "deps/0211f328_VerifySelectTrophyIconFiles_from_thumb.h"

void VerifySelectTrophyIconFiles_from_thumb(void)

{
  undefined4 uVar1;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8 [2];
  
  local_10 = 0;
  local_c = 0;
  local_8[0] = 0;
  uVar1 = find_buf_fn_from_thumb(*puRam0211f36c);
  Gfx_ReadCharGraphicsV2(&local_10,uVar1);
  uVar1 = find_buf_fn_from_thumb(*puRam0211f370);
  LoadCellBankFrom(&local_c,uVar1);
  uVar1 = find_buf_fn_from_thumb(*puRam0211f374);
  Gfx_ReadPalette(local_8,uVar1);
  return;
}

