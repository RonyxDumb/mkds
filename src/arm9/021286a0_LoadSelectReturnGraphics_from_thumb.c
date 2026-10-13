/* Decompiled C draft; module arm9; ROM address 021286a0. No matching claim. */
#include "types.h"
#include "deps/021286a0_LoadSelectReturnGraphics_from_thumb.h"

int LoadSelectReturnGraphics_from_thumb(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_2c;
  int local_24;
  int local_20;
  int local_1c [2];
  
  uVar2 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam02128764);
  MaybeReadCharBlock_1(&local_24,uVar2);
  uVar2 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam02128768);
  MaybeReadScreenBlock(&local_20,uVar2);
  uVar2 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam0212876c);
  Gfx_ReadPaletteRelative(local_1c,uVar2);
  param_1 = param_1 - *(int *)(local_24 + 0x10);
  Arm_FlushRange(*(undefined4 *)(local_24 + 0x14));
  CopyBgData_Bg2_Bottom(*(undefined4 *)(local_24 + 0x14),param_1,*(undefined4 *)(local_24 + 0x10));
  piVar1 = piRam02128770;
  iVar3 = 0;
  local_2c = 0;
  do {
    iVar4 = 0;
    iVar5 = iVar4;
    do {
      *(short *)(iVar4 + iVar3 * 2 + *piVar1 + 0x10) =
           (short)(param_1 >> 5) + *(short *)(iVar3 * 2 + local_20 + iVar4 + 0xc);
      iVar4 = iVar4 + 2;
      iVar5 = iVar5 + 1;
    } while (iVar5 < 0x20);
    iVar3 = iVar3 + 0x20;
    local_2c = local_2c + 1;
  } while (local_2c < 0x20);
  Arm_FlushRange(*piVar1 + 0x10,*(undefined4 *)(local_20 + 8));
  TEQSub_Fn26Impl_Fn28Impl(*piRam02128770 + 0x10,0,*(undefined4 *)(local_20 + 8));
  Arm_FlushRange(*(undefined4 *)(local_1c[0] + 0xc),iRam02128774);
  CopyPaletteBottom(*(int *)(local_1c[0] + 0xc) + iRam02128774,iRam02128774,0x40);
  return param_1;
}

