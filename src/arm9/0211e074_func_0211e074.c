/* Decompiled C draft; module arm9; ROM address 0211e074. No matching claim. */
#include "types.h"
#include "deps/0211e074_func_0211e074.h"

void func_0211e074(void)

{
  undefined4 uVar1;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8 [2];
  
  local_10 = 0;
  local_c = 0;
  local_8[0] = 0;
  uVar1 = find_buf_fn_from_thumb(*puRam0211e0b8);
  Gfx_ReadCharGraphicsV2(&local_10,uVar1);
  uVar1 = find_buf_fn_from_thumb(*puRam0211e0bc);
  LoadCellBankFrom(&local_c,uVar1);
  uVar1 = find_buf_fn_from_thumb(*puRam0211e0c0);
  Gfx_ReadPalette(local_8,uVar1);
  return;
}

