/* Decompiled C draft; module arm9; ROM address 02118d44. No matching claim. */
#include "types.h"
#include "deps/02118d44_VerifySelectCupFiles_from_thumb.h"

void VerifySelectCupFiles_from_thumb(void)

{
  undefined4 uVar1;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8 [2];
  
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  local_8[0] = 0;
  if (*psRam02118e08 != 2) {
    uVar1 = find_buf_fn_from_thumb(*puRam02118e0c);
    Gfx_ReadCharGraphicsV2(&local_10,uVar1);
    uVar1 = find_buf_fn_from_thumb(*puRam02118e10);
    Gfx_ReadPalette(local_8,uVar1);
    uVar1 = find_buf_fn_from_thumb(*puRam02118e14);
    MaybeReadScreenBlock_0(&local_c,uVar1);
    uVar1 = find_buf_fn_from_thumb(*puRam02118e18);
    Gfx_ReadCharGraphics(&local_28,uVar1);
    uVar1 = find_buf_fn_from_thumb(*puRam02118e1c);
    LoadCellBankFrom(&local_24,uVar1);
    uVar1 = find_buf_fn_from_thumb(*puRam02118e20);
    Gfx_ReadPalette(&local_20,uVar1);
    uVar1 = find_buf_fn_from_thumb(*puRam02118e24);
    Gfx_ReadCharGraphics(&local_1c,uVar1);
    uVar1 = find_buf_fn_from_thumb(*puRam02118e28);
    LoadCellBankFrom(&local_18,uVar1);
    uVar1 = find_buf_fn_from_thumb(*puRam02118e2c);
    Gfx_ReadPalette(&local_14,uVar1);
    VerifySelectCupNameFiles_from_thumb();
    VerifyCupMarkFiles_from_thumb();
    VerifySelectTrophyIconFiles_from_thumb();
  }
  return;
}

