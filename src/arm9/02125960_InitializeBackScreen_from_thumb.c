/* Decompiled C draft; module arm9; ROM address 02125960. No matching claim. */
#include "types.h"
#include "deps/02125960_InitializeBackScreen_from_thumb.h"

int InitializeBackScreen_from_thumb(int param_1)

{
  byte bVar1;
  byte bVar2;
  int *piVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int local_3c;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  
  iVar6 = *(int *)(*piRam02125b60 + 0xc) * 2;
  uVar4 = (uint)*(byte *)(iRam02125b64 + iVar6);
  uVar7 = (uint)*(byte *)(iRam02125b68 + iVar6);
  bVar1 = *(byte *)(iRam02125b6c + uVar4);
  iVar10 = (uint)bVar1 * 0x20;
  bVar2 = *(byte *)(iRam02125b70 + uVar7);
  iVar6 = (uint)bVar2 * 0x20;
  if (*psRam02125b74 == 2) {
    uVar5 = find_buf_fn_from_thumb(uRam02125b78);
    MaybeReadCharBlock_1(&local_2c,uVar5);
    uVar5 = find_buf_fn_from_thumb(uRam02125b7c);
    MaybeReadScreenBlock_0(&local_28,uVar5);
    uVar5 = find_buf_fn_from_thumb(uRam02125b80);
    Gfx_ReadPaletteRelative(&local_24,uVar5);
    local_20 = local_2c;
    uVar5 = find_buf_fn_from_thumb(uRam02125b84);
    MaybeReadScreenBlock_0(&local_1c,uVar5);
    local_18 = local_24;
  }
  else {
    if (*(char *)(iRam02125b88 + uVar4) == '\0') {
      iVar9 = uVar4 * 4;
      uVar5 = find_buf_fn_from_thumb(*(undefined4 *)(iRam02125b8c + iVar9));
      Gfx_ReadCharGraphicsV2(&local_2c,uVar5);
      uVar5 = find_buf_fn_from_thumb(*(undefined4 *)(iRam02125b90 + iVar9));
      MaybeReadScreenBlock_0(&local_28,uVar5);
      uVar5 = find_buf_fn_from_thumb(*(undefined4 *)(iRam02125b94 + iVar9));
      Gfx_ReadPalette(&local_24,uVar5);
    }
    else {
      iVar9 = uVar4 * 4;
      uVar5 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb
                        (*(undefined4 *)(iRam02125b8c + iVar9));
      Gfx_ReadCharGraphicsV2(&local_2c,uVar5);
      uVar5 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb
                        (*(undefined4 *)(iRam02125b90 + iVar9));
      MaybeReadScreenBlock_0(&local_28,uVar5);
      uVar5 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb
                        (*(undefined4 *)(iRam02125b94 + iVar9));
      Gfx_ReadPalette(&local_24,uVar5);
    }
    if (*(char *)(iRam02125b88 + uVar7) == '\0') {
      iVar9 = uVar7 * 4;
      uVar5 = find_buf_fn_from_thumb(*(undefined4 *)(iRam02125b98 + iVar9));
      Gfx_ReadCharGraphicsV2(&local_20,uVar5);
      uVar5 = find_buf_fn_from_thumb(*(undefined4 *)(iRam02125b9c + iVar9));
      MaybeReadScreenBlock_0(&local_1c,uVar5);
      uVar5 = find_buf_fn_from_thumb(*(undefined4 *)(iRam02125ba0 + iVar9));
      Gfx_ReadPalette(&local_18,uVar5);
    }
    else {
      iVar9 = uVar7 * 4;
      uVar5 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb
                        (*(undefined4 *)(iRam02125b98 + iVar9));
      Gfx_ReadCharGraphicsV2(&local_20,uVar5);
      uVar5 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb
                        (*(undefined4 *)(iRam02125b9c + iVar9));
      MaybeReadScreenBlock_0(&local_1c,uVar5);
      uVar5 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb
                        (*(undefined4 *)(iRam02125ba0 + iVar9));
      Gfx_ReadPalette(&local_18,uVar5);
    }
  }
  AllocateReserveTEQSub(7,0,*(undefined4 *)(local_2c + 0x14),*(undefined4 *)(local_2c + 0x10));
  AllocateReserveTEQSub(0xb,0,local_28 + 0xc,*(undefined4 *)(local_28 + 8));
  AllocateReserveTEQSub(0xf,iVar10,*(int *)(local_24 + 0xc) + iVar10,(0xe - (uint)bVar1) * 0x20);
  param_1 = param_1 - *(int *)(local_20 + 0x10);
  AllocateReserveTEQSub(0x15,param_1,*(undefined4 *)(local_20 + 0x14));
  piVar3 = piRam02125b60;
  iVar10 = 0;
  local_3c = 0;
  do {
    iVar8 = 0;
    iVar9 = iVar8;
    do {
      *(short *)(iVar8 + iVar10 * 2 + *piVar3 + 0x10) =
           (short)(param_1 >> 5) + *(short *)(iVar10 * 2 + local_1c + iVar8 + 0xc);
      iVar8 = iVar8 + 2;
      iVar9 = iVar9 + 1;
    } while (iVar9 < 0x20);
    iVar10 = iVar10 + 0x20;
    local_3c = local_3c + 1;
  } while (local_3c < 0x20);
  AllocateReserveTEQSub(0x19,0,*piVar3 + 0x10,*(undefined4 *)(local_1c + 8));
  AllocateReserveTEQSub(0x1f,iVar6,*(int *)(local_18 + 0xc) + iVar6,(0xc - (uint)bVar2) * 0x20);
  return param_1;
}

