/* Decompiled C draft; module arm9; ROM address 0203206c. No matching claim. */
#include "types.h"
#include "deps/0203206c_VerifyCommonSelectGameFiles_from_thumb.h"

void VerifyCommonSelectGameFiles_from_thumb(void)

{
  undefined4 uVar1;
  undefined1 auStack_18 [4];
  undefined1 auStack_14 [4];
  undefined1 auStack_10 [4];
  undefined1 auStack_c [12];
  
  if (*psRam0203210c != 2) {
    uVar1 = find_buf_fn_from_thumb(uRam02032110);
    Gfx_ReadCharGraphicsV2(auStack_18,uVar1);
    uVar1 = find_buf_fn_from_thumb(uRam02032114);
    Gfx_ReadCharGraphics(auStack_18,uVar1);
    uVar1 = find_buf_fn_from_thumb(uRam02032118);
    LoadCellBankFrom(auStack_10,uVar1);
    uVar1 = find_buf_fn_from_thumb(uRam0203211c);
    Gfx_ReadPalette(auStack_14,uVar1);
    uVar1 = find_buf_fn_from_thumb(uRam02032120);
    Gfx_ReadPalette(auStack_14,uVar1);
    uVar1 = find_buf_fn_from_thumb(uRam02032124);
    MaybeReadScreenBlock_0(auStack_c,uVar1);
    uVar1 = find_buf_fn_from_thumb(uRam02032128);
    MaybeReadScreenBlock_0(auStack_c,uVar1);
  }
  uVar1 = find_buf_fn_from_thumb(uRam0203212c);
  Gfx_ReadCharGraphics(auStack_18,uVar1);
  uVar1 = find_buf_fn_from_thumb(uRam02032130);
  LoadCellBankFrom(auStack_10,uVar1);
  uVar1 = find_buf_fn_from_thumb(uRam02032134);
  Gfx_ReadPalette(auStack_14,uVar1);
  return;
}

