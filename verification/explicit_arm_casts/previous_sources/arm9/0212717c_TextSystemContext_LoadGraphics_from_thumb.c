/* Decompiled C draft; module arm9; ROM address 0212717c. No matching claim. */
#include "types.h"
#include "deps/0212717c_TextSystemContext_LoadGraphics_from_thumb.h"

int TextSystemContext_LoadGraphics_from_thumb(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int local_1c;
  int local_18;
  int local_14 [2];
  
  if (*psRam021273c8 == 2) {
    uVar2 = find_buf_fn_from_thumb(uRam021273cc);
    MaybeReadCharBlock_1(&local_1c,uVar2);
    uVar2 = find_buf_fn_from_thumb(uRam021273d0);
    MaybeReadScreenBlock(*piRam021273d4 + iRam021273d8,uVar2);
    uVar2 = find_buf_fn_from_thumb(uRam021273dc);
    Gfx_ReadPaletteRelative(local_14,uVar2);
  }
  else {
    uVar2 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam021273e0);
    MaybeReadCharBlock_1(&local_1c,uVar2);
    uVar2 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam021273e4);
    MaybeReadCharBlock_1(&local_18,uVar2);
    uVar2 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam021273e8);
    MaybeReadScreenBlock(*piRam021273d4 + iRam021273d8,uVar2);
    uVar2 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam021273ec);
    MaybeReadScreenBlock(*piRam021273d4 + iRam021273f0,uVar2);
    uVar2 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam021273f4);
    MaybeReadScreenBlock(*piRam021273d4 + iRam021273f8,uVar2);
    uVar2 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam021273fc);
    MaybeReadScreenBlock(*piRam021273d4 + iRam02127400,uVar2);
    uVar2 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam02127404);
    MaybeReadScreenBlock(*piRam021273d4 + iRam02127408,uVar2);
    uVar2 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam0212740c);
    MaybeReadScreenBlock(*piRam021273d4 + iRam02127410,uVar2);
    uVar2 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam02127414);
    MaybeReadScreenBlock(*piRam021273d4 + iRam02127418,uVar2);
    uVar2 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam0212741c);
    Gfx_ReadPaletteRelative(local_14,uVar2);
  }
  *(undefined4 *)(*piRam021273d4 + iRam02127420) = 0;
  Arm_FlushRange(*(undefined4 *)(local_1c + 0x14),*(undefined4 *)(local_1c + 0x10));
  CopyBgData_Bg2_Top(*(undefined4 *)(local_1c + 0x14),0,*(undefined4 *)(local_1c + 0x10));
  if (*(int *)(*piRam021273d4 + 0x48) != 0) {
    param_1 = param_1 - *(int *)(local_1c + 0x10);
    *(int *)(*piRam021273d4 + iRam02127424) = param_1 >> 5;
    Arm_FlushRange(*(undefined4 *)(local_1c + 0x14),*(undefined4 *)(local_1c + 0x10));
    CopyBgData_Bg0_Bottom(*(undefined4 *)(local_1c + 0x14),param_1,*(undefined4 *)(local_1c + 0x10))
    ;
  }
  if (*psRam021273c8 != 2) {
    if (*(int *)(*piRam021273d4 + 0x44) != 0) {
      *(undefined4 *)(*piRam021273d4 + iRam02127428) = 0;
    }
    *(uint *)(*piRam021273d4 + iRam0212742c) = *(uint *)(local_1c + 0x10) >> 5;
    Arm_FlushRange(*(undefined4 *)(local_18 + 0x14),*(undefined4 *)(local_18 + 0x10));
    CopyBgData_Bg2_Top(*(undefined4 *)(local_18 + 0x14),*(int *)(*piRam021273d4 + iRam0212742c) << 5
                       ,*(undefined4 *)(local_18 + 0x10));
    iVar3 = *piRam021273d4;
    if (*(int *)(iVar3 + 0x4c) != 0) {
      *(undefined4 *)(iVar3 + iRam02127430) = *(undefined4 *)(iVar3 + iRam02127424);
    }
    piVar1 = piRam021273d4;
    param_1 = param_1 - *(int *)(local_18 + 0x10);
    iVar3 = param_1 >> 5;
    *(int *)(*piRam021273d4 + iRam02127434) = iVar3;
    *(int *)(*piVar1 + iRam02127438) = iVar3;
    *(int *)(*piVar1 + iRam0212743c) = iVar3;
    *(int *)(*piVar1 + iRam02127440) = iVar3;
    Arm_FlushRange(*(undefined4 *)(local_18 + 0x14),*(undefined4 *)(local_18 + 0x10));
    CopyBgData_Bg0_Bottom(*(undefined4 *)(local_18 + 0x14),param_1,*(undefined4 *)(local_18 + 0x10))
    ;
  }
  Arm_FlushRange(*(undefined4 *)(local_14[0] + 0xc),iRam02127444);
  CopyPaletteTop(*(int *)(local_14[0] + 0xc) + iRam02127444,iRam02127444,0x40);
  CopyPaletteBottom(*(int *)(local_14[0] + 0xc) + iRam02127444,iRam02127444,0x40);
  piVar1 = piRam021273d4;
  *(undefined2 *)(*piRam021273d4 + iRam0212744c) =
       *(undefined2 *)(*(int *)(local_14[0] + 0xc) + iRam02127448);
  *(undefined2 *)(*piVar1 + iRam02127454) =
       *(undefined2 *)(*(int *)(local_14[0] + 0xc) + iRam02127450);
  uVar2 = func_0214a214();
  local_14[1] = 0;
  Mem_CpuFastMemorySet(0,uVar2,uRam02127458);
  uVar4 = *(uint *)(*piRam021273d4 + iRam02127434);
  uVar2 = GetAnotherSubEngineBGOffset();
  Mem_CpuFill16(uVar4 & 0xffff,uVar2,uRam02127458);
  return param_1;
}

