/* Decompiled C draft; module arm9; ROM address 0211a6bc. No matching claim. */
#include "types.h"
#include "deps/0211a6bc_VerifySelectCupCourseFiles_from_thumb.h"

void VerifySelectCupCourseFiles_from_thumb(void)

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
  if (*psRam0211a76c != 2) {
    uVar1 = find_buf_fn_from_thumb(*puRam0211a770);
    Gfx_ReadCharGraphicsV2(&local_14,uVar1);
    uVar1 = find_buf_fn_from_thumb(*puRam0211a774);
    Gfx_ReadPalette(local_c,uVar1);
    uVar1 = find_buf_fn_from_thumb(*puRam0211a778);
    MaybeReadScreenBlock_0(&local_10,uVar1);
    uVar1 = find_buf_fn_from_thumb(*puRam0211a77c);
    Gfx_ReadCharGraphicsV2(&local_14,uVar1);
    uVar1 = find_buf_fn_from_thumb(*puRam0211a780);
    Gfx_ReadPalette(local_c,uVar1);
    uVar1 = find_buf_fn_from_thumb(*puRam0211a784);
    MaybeReadScreenBlock_0(&local_10,uVar1);
    uVar1 = find_buf_fn_from_thumb(*puRam0211a788);
    Gfx_ReadCharGraphics(&local_20,uVar1);
    uVar1 = find_buf_fn_from_thumb(*puRam0211a78c);
    LoadCellBankFrom(&local_1c,uVar1);
    uVar1 = find_buf_fn_from_thumb(*puRam0211a790);
    Gfx_ReadPalette(&local_18,uVar1);
  }
  return;
}

