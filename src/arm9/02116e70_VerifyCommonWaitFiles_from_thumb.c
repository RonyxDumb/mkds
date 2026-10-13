/* Decompiled C draft; module arm9; ROM address 02116e70. No matching claim. */
#include "types.h"
#include "deps/02116e70_VerifyCommonWaitFiles_from_thumb.h"

void VerifyCommonWaitFiles_from_thumb(void)

{
  undefined4 uVar1;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8 [2];
  
  local_10 = 0;
  local_c = 0;
  local_8[0] = 0;
  uVar1 = find_buf_fn_from_thumb(*puRam02116eb4);
  LoadCellBankFrom(&local_10,uVar1);
  uVar1 = find_buf_fn_from_thumb(*puRam02116eb8);
  Gfx_ReadCharGraphics(&local_c,uVar1);
  uVar1 = find_buf_fn_from_thumb(*puRam02116ebc);
  Gfx_ReadPalette(local_8,uVar1);
  return;
}

