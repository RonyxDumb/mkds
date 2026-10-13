/* Decompiled C draft; module arm9; ROM address 02127f14. No matching claim. */
#include "types.h"
#include "deps/02127f14_SelectChoisesContext_LoadGraphics_from_thumb.h"

int SelectChoisesContext_LoadGraphics_from_thumb(int param_1)

{
  byte bVar1;
  byte bVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_2c;
  int local_24;
  int local_20;
  int local_1c [2];
  
  uVar4 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam02128008);
  MaybeReadCharBlock_1(&local_24,uVar4);
  uVar4 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam0212800c);
  MaybeReadScreenBlock(&local_20,uVar4);
  uVar4 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam02128010);
  Gfx_ReadPaletteRelative(local_1c,uVar4);
  param_1 = param_1 - *(int *)(local_24 + 0x10);
  *(int *)(*piRam02128014 + iRam02128018) = param_1 >> 5;
  Arm_FlushRange(*(undefined4 *)(local_24 + 0x14),*(undefined4 *)(local_24 + 0x10));
  CopyBgData_Bg0_Bottom(*(undefined4 *)(local_24 + 0x14),param_1,*(undefined4 *)(local_24 + 0x10));
  piVar3 = piRam02128014;
  iVar5 = 0;
  local_2c = 0;
  do {
    iVar6 = 0;
    iVar7 = iVar6;
    do {
      *(short *)(iVar6 + iVar5 * 2 + *piVar3 + 0x2c) =
           (short)(param_1 >> 5) + *(short *)(iVar5 * 2 + local_20 + iVar6 + 0xc);
      iVar6 = iVar6 + 2;
      iVar7 = iVar7 + 1;
    } while (iVar7 < 0x20);
    iVar5 = iVar5 + 0x20;
    local_2c = local_2c + 1;
  } while (local_2c < 0x20);
  Arm_FlushRange(*piVar3 + 0x2c,*(undefined4 *)(local_20 + 8));
  TEQSub_Fn24Impl(*piRam02128014 + 0x2c,0,*(undefined4 *)(local_20 + 8));
  iVar5 = iRam02128018;
  piVar3 = piRam02128014;
  bVar1 = pbRam0212801c[2];
  bVar2 = *pbRam0212801c;
  *(uint *)(*piRam02128014 + iRam02128020) =
       *(int *)(*piRam02128014 + iRam02128018) + (uint)bVar2 + (uint)bVar1 * 0x20;
  *(uint *)(*piVar3 + iRam02128024) = *(int *)(*piVar3 + iVar5) + (uint)bVar1 * 0x20 + bVar2 + 3;
  Arm_FlushRange(*(undefined4 *)(local_1c[0] + 0xc),iRam02128028);
  CopyPaletteBottom(*(int *)(local_1c[0] + 0xc) + iRam02128028,iRam02128028,0x40);
  return param_1;
}

