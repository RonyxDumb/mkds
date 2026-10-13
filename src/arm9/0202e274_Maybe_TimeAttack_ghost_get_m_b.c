/* Decompiled C draft; module arm9; ROM address 0202e274. No matching claim. */
#include "types.h"
#include "deps/0202e274_Maybe_TimeAttack_ghost_get_m_b.h"

void Maybe_TimeAttack_ghost_get_m_b(void)

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
  uVar1 = find_buf_fn_from_thumb(uRam0202e3dc);
  Gfx_ReadCharGraphicsV2(&local_18,uVar1);
  uVar1 = find_buf_fn_from_thumb(uRam0202e3e0);
  Gfx_ReadCharGraphicsV2(&local_18,uVar1);
  uVar1 = find_buf_fn_from_thumb(uRam0202e3e4);
  Gfx_ReadCharGraphicsV2(&local_18,uVar1);
  uVar1 = find_buf_fn_from_thumb(uRam0202e3e8);
  Gfx_ReadCharGraphicsV2(&local_18,uVar1);
  uVar1 = find_buf_fn_from_thumb(uRam0202e3ec);
  Gfx_ReadCharGraphics(&local_18,uVar1);
  uVar1 = find_buf_fn_from_thumb(uRam0202e3f0);
  Gfx_ReadCharGraphics(&local_18,uVar1);
  uVar1 = find_buf_fn_from_thumb(uRam0202e3f4);
  Gfx_ReadCharGraphics(&local_18,uVar1);
  uVar1 = find_buf_fn_from_thumb(uRam0202e3f8);
  Gfx_ReadCharGraphics(&local_18,uVar1);
  uVar1 = find_buf_fn_from_thumb(uRam0202e3fc);
  LoadCellBankFrom(&local_10,uVar1);
  uVar1 = find_buf_fn_from_thumb(uRam0202e400);
  LoadCellBankFrom(&local_10,uVar1);
  uVar1 = find_buf_fn_from_thumb(uRam0202e404);
  LoadCellBankFrom(&local_10,uVar1);
  uVar1 = find_buf_fn_from_thumb(uRam0202e408);
  LoadCellBankFrom(&local_10,uVar1);
  uVar1 = find_buf_fn_from_thumb(uRam0202e40c);
  Gfx_ReadPalette(&local_14,uVar1);
  uVar1 = find_buf_fn_from_thumb(uRam0202e410);
  Gfx_ReadPalette(&local_14,uVar1);
  uVar1 = find_buf_fn_from_thumb(uRam0202e414);
  Gfx_ReadPalette(&local_14,uVar1);
  uVar1 = find_buf_fn_from_thumb(uRam0202e418);
  Gfx_ReadPalette(&local_14,uVar1);
  uVar1 = find_buf_fn_from_thumb(uRam0202e41c);
  Gfx_ReadPalette(&local_14,uVar1);
  uVar1 = find_buf_fn_from_thumb(uRam0202e420);
  Gfx_ReadPalette(&local_14,uVar1);
  uVar1 = find_buf_fn_from_thumb(uRam0202e424);
  Gfx_ReadPalette(&local_14,uVar1);
  uVar1 = find_buf_fn_from_thumb(uRam0202e428);
  Gfx_ReadPalette(&local_14,uVar1);
  uVar1 = find_buf_fn_from_thumb(uRam0202e42c);
  MaybeReadScreenBlock_0(local_c,uVar1);
  uVar1 = find_buf_fn_from_thumb(uRam0202e430);
  MaybeReadScreenBlock_0(local_c,uVar1);
  uVar1 = find_buf_fn_from_thumb(uRam0202e434);
  MaybeReadScreenBlock_0(local_c,uVar1);
  uVar1 = find_buf_fn_from_thumb(uRam0202e438);
  MaybeReadScreenBlock_0(local_c,uVar1);
  func_02117388();
  return;
}

