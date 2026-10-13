/* Decompiled C draft; module arm9; ROM address 020797d8. No matching claim. */
#include "types.h"
#include "deps/020797d8_InitializeGlobalAD00_from_thumb.h"

void InitializeGlobalAD00_from_thumb(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int local_1c [2];
  
  iVar1 = FindFileBuffer_KME_KM1_KM2_KSB_from_thumb(uRam0207996c);
  SetCurrentlyInKartModelMenu(0);
  *puRam02079970 = 0;
  iVar2 = Mem_AllocateHeap(param_1,uRam02079974);
  *piRam02079978 = iVar2;
  uVar3 = Mem_AllocateHeap(param_1,param_2 * 0xb4);
  *(undefined4 *)*piRam02079978 = uVar3;
  uVar3 = FindFileBufferGeneric_KME_KM1_KM2_KSB_from_thumb(uRam0207997c);
  piVar4 = piRam02079978;
  *(undefined4 *)(*piRam02079978 + 4) = uVar3;
  *(int *)(*piVar4 + 4) = *(int *)(*piVar4 + 4) + *(int *)*piRam02079980 * 8 + -8;
  uVar3 = GetKartAPaletteData_from_thumb();
  piVar4 = piRam02079978;
  *(undefined4 *)(*piRam02079978 + 0x10) = uVar3;
  *(undefined4 *)(*piVar4 + 0x14) = 0;
  FormatCharacterFaceAnimationNsbtpPath();
  uVar3 = FindFileBufferGeneric_KME_KM1_KM2_KSB_from_thumb();
  piVar4 = piRam02079978;
  *(undefined4 *)(*piRam02079978 + 0x28) = uVar3;
  *(short *)(*piVar4 + 8) = (short)param_2;
  *(undefined4 *)(*piVar4 + 0xc) = 0;
  CreateLoadPhysicalParams(param_1,param_2);
  MaybeLoadKartAIData_from_thumb();
  LoadAD00KillerItemModel_from_thumb(param_1);
  uVar7 = 0;
  piVar4 = (int *)*piRam02079978;
  if ((short)piVar4[2] != 0) {
    do {
      iVar9 = *piVar4;
      iVar2 = uVar7 * 0xb4;
      iVar6 = iVar9 + iVar2;
      StructAD00Sub_Initialize_from_thumb(iVar6);
      iVar8 = uVar7 * 0x30;
      *(uint *)(iVar6 + 0xb0) = (uint)*(byte *)(*piRam02079980 + iVar8 + 0x95);
      StructAD00Sub_SomeFn_from_thumb(iVar6);
      *(undefined4 *)(iVar9 + iVar2) = *(undefined4 *)(*piRam02079980 + iVar8 + 0x68);
      *(undefined4 *)(iVar6 + 4) = *(undefined4 *)(*piRam02079980 + iVar8 + 0x6c);
      StructAD00Sub_SetKartIndex_from_thumb(iVar6,*(undefined4 *)(iVar6 + 4));
      uVar3 = Mem_AllocateHeap(param_1,0xe0);
      *(undefined4 *)(iVar6 + 0x20) = uVar3;
      Mem_CpuCopy8(iVar1 + *(int *)(iVar6 + 4) * 0xe0,*(undefined4 *)(iVar6 + 0x20),0xe0);
      CopyKartCharPhysicalParam
                (uVar7,*(uint *)(iVar6 + 4) & 0xffff,*(uint *)(iVar9 + iVar2) & 0xffff);
      uVar7 = uVar7 + 1 & 0xffff;
      piVar4 = (int *)*piRam02079978;
    } while (uVar7 < *(ushort *)(piVar4 + 2));
  }
  func_02079678(param_1,1);
  Dispose_KM1_Mount_KM2_from_thumb();
  func_02079678(param_1,0);
  piVar4 = piRam02079978;
  uVar7 = 0;
  piVar5 = (int *)*piRam02079978;
  if ((short)piVar5[2] != 0) {
    do {
      iVar1 = *piVar5;
      uVar3 = DetermineIsP_from_thumb(uVar7);
      CharacterKart_PatchRobPalette_from_thumb(iVar1 + uVar7 * 0xb4,uVar3);
      uVar7 = uVar7 + 1 & 0xffff;
      piVar5 = (int *)*piVar4;
    } while (uVar7 < *(ushort *)(piVar5 + 2));
  }
  uVar3 = FindFileBufferGeneric_KME_KM1_KM2_KSB_from_thumb(uRam02079984);
  Gfx_ReadPalette(local_1c,uVar3);
  *(undefined4 *)(*piRam02079978 + 0x14) = *(undefined4 *)(local_1c[0] + 0xc);
  return;
}

