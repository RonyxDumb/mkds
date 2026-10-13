/* Decompiled C draft; module arm9; ROM address 0211732c. No matching claim. */
#include "types.h"
#include "deps/0211732c_VerifyKartIconFiles_from_thumb.h"

void VerifyKartIconFiles_from_thumb(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18 [2];
  
  local_20 = 0;
  local_1c = 0;
  local_18[0] = 0;
  uVar1 = find_buf_fn_from_thumb(*puRam0211737c);
  Gfx_ReadCharGraphicsV2(&local_20,uVar1);
  uVar1 = find_buf_fn_from_thumb(*puRam02117380);
  LoadCellBankFrom(&local_1c,uVar1);
  iVar3 = 0;
  puVar2 = puRam02117384;
  do {
    uVar1 = find_buf_fn_from_thumb(*puVar2);
    Gfx_ReadPalette(local_18,uVar1);
    puVar2 = puVar2 + 1;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 3);
  return;
}

