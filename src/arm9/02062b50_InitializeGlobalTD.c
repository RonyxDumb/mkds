/* Decompiled C draft; module arm9; ROM address 02062b50. No matching claim. */
#include "types.h"
#include "deps/02062b50_InitializeGlobalTD.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void InitializeGlobalTD(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined2 uVar4;
  undefined4 *puVar5;
  int *piVar6;
  ushort uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  
  GetActiveExecutionContext();
  uVar8 = ExecutionContext_GetHeapHandle();
  SetCurrentlyInKartModelMenu(0);
  uVar9 = Mem_AllocateHeap(uVar8,0x48);
  *puRam02062e84 = uVar9;
  CreateGlobalTD();
  uVar10 = GX_GetBankForTex();
  uVar11 = uVar10 & 0xffff;
  func_020161b4((uVar10 & 1) +
                ((int)uVar11 >> 1 & 1U) + ((int)uVar11 >> 3 & 1U) + ((int)uVar11 >> 2 & 1U),1);
  func_02016414(0x10000,1);
  InitializeModelResourceList();
  func_02077998();
  SetActiveExecutionContextHeapGroupId_from_thumb(1);
  CreateGlobalAED0_from_thumb();
  InitializeGlobalAD00_from_thumb
            (uVar8,*(undefined1 *)
                    ((*(uint *)(uRam02062e88 & 0xfffffffc) >> (uRam02062e88 & 3) * 8 |
                     *(uint *)(uRam02062e88 & 0xfffffffc) << (uRam02062e88 & 3) * -8 + 0x20) + 0x3d0
                    ));
  CopyDefaultHeyhoColorPalettes_from_thumb();
  func_020872a4();
  Dispose_KM2_KSB_Mount_CRS_from_thumb();
  LoadMap2DStuff();
  SetActiveExecutionContextHeapGroupId_from_thumb(2);
  LoadCourseMapNkm_from_thumb(uVar8);
  LoadCourseModelsAnimations(uVar8);
  Dispose_CST_Mount_K2D_R2D_MAR_from_thumb();
  SetActiveExecutionContextHeapGroupId_from_thumb(7);
  InitializeGlobalMV(uVar8);
  InitializeGlobalAA(uVar8);
  SetActiveExecutionContextHeapGroupId_from_thumb(2);
  LoadCourseKcl_from_thumb();
  SetActiveExecutionContextHeapGroupId_from_thumb(8);
  AllocateSomePointers();
  SetActiveExecutionContextHeapGroupId_from_thumb(1);
  CreateGlobalBO(uVar8);
  CreateGlobalAEBC_from_thumb();
  CreateDriverEntriesAndRK
            (*(undefined1 *)
              ((*(uint *)(uRam02062e88 & 0xfffffffc) >> (uRam02062e88 & 3) * 8 |
               *(uint *)(uRam02062e88 & 0xfffffffc) << (uRam02062e88 & 3) * -8 + 0x20) + 0x3d0));
  CreateGlobalHD5_from_thumb();
  CreateAnotherGlobalHD_from_thumb
            (*(undefined1 *)
              ((*(uint *)(uRam02062e88 & 0xfffffffc) >> (uRam02062e88 & 3) * 8 |
               *(uint *)(uRam02062e88 & 0xfffffffc) << (uRam02062e88 & 3) * -8 + 0x20) + 99));
  uVar10 = *(uint *)((uint)puRam02062e84 & 0xfffffffc) >> ((uint)puRam02062e84 & 3) * 8 |
           *(uint *)((uint)puRam02062e84 & 0xfffffffc) << ((uint)puRam02062e84 & 3) * -8 + 0x20;
  uVar11 = uVar10 + 0x28;
  uVar3 = uVar11 & 3;
  uVar11 = *(uint *)(uVar11 & 0xfffffffc);
  if (uVar11 >> uVar3 * 8 != 0 || uVar11 << uVar3 * -8 + 0x20 != 0) {
    uVar10 = uVar10 + 0x2c;
    uVar11 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    if (uVar10 >> uVar11 * 8 == 0 && uVar10 << uVar11 * -8 + 0x20 == 0) {
      CreateGlobalHD_HD2_V2_from_thumb();
    }
    else {
      CreateGlobalHD_HD2_from_thumb();
    }
  }
  uVar9 = GetGlobalHD5();
  *puRam02062e8c = uVar9;
  uVar9 = GetAnotherGlobalHD();
  puVar5 = puRam02062e8c;
  *puRam02062e90 = uVar9;
  piVar6 = piRam02062e98;
  uVar11 = (uint)puVar5 & 3;
  uVar10 = *(uint *)((uint)puVar5 & 0xfffffffc);
  uVar11 = uVar10 >> uVar11 * 8 | uVar10 << uVar11 * -8 + 0x20;
  *puRam02062e94 = uVar11;
  *piVar6 = uVar11 + 0x30;
  StructHD_SomeFn_2();
  SetActiveExecutionContextHeapGroupId_from_thumb(3);
  uVar11 = (*(uint *)(uRam02062e88 & 0xfffffffc) >> (uRam02062e88 & 3) * 8 |
           *(uint *)(uRam02062e88 & 0xfffffffc) << (uRam02062e88 & 3) * -8 + 0x20) + 8;
  uVar10 = uVar11 & 3;
  uVar11 = *(uint *)(uVar11 & 0xfffffffc);
  uVar11 = uVar11 >> uVar10 * 8 | uVar11 << uVar10 * -8 + 0x20;
  if (uVar11 == 2) {
    func_020a0e00();
  }
  else if ((uVar11 == 4) &&
          (func_0x021819f4(),
          uVar11 = (*(uint *)(uRam02062e88 & 0xfffffffc) >> (uRam02062e88 & 3) * 8 |
                   *(uint *)(uRam02062e88 & 0xfffffffc) << (uRam02062e88 & 3) * -8 + 0x20) + 8,
          uVar10 = uVar11 & 3, uVar11 = *(uint *)(uVar11 & 0xfffffffc),
          (uVar11 >> uVar10 * 8 | uVar11 << uVar10 * -8 + 0x20) == 4)) {
    func_020a0e00();
  }
  SetActiveExecutionContextHeapGroupId_from_thumb(3);
  func_020e7460();
  func_020e7760();
  Maybe_MapObj_grpconf();
  MaybeLoadSlotListAndRacerPrs_from_thumb();
  SetActiveExecutionContextHeapGroupId_from_thumb(6);
  SomeEffectFileStuff(uVar8);
  func_020846c0(uVar8);
  LoadEffectMapObjModels(uVar8);
  func_0208f0f8(uVar8);
  SetActiveExecutionContextHeapGroupId_from_thumb(9);
  iVar15 = iRam02062ea4;
  _DAT_05000000 = 0xff00;
  *puRam02062e9c = (ushort)uRam02062ea0 & *puRam02062e9c;
  G3X_SetToonTable(iVar15);
  iVar14 = iRam02062eac;
  iVar12 = iRam02062ea8;
  iVar2 = iRam02062ea4;
  iVar15 = 0;
  do {
    iVar1 = iVar15 * 2;
    iVar13 = iVar15 + 0x10;
    iVar15 = (iVar15 + 1) * 0x10000 >> 0x10;
    uVar4 = *(undefined2 *)(iVar14 + iVar1);
    *(undefined2 *)(iVar2 + iVar1) = *(undefined2 *)(iVar12 + iVar1);
    *(undefined2 *)(iVar2 + iVar13 * 2) = uVar4;
    iVar1 = iRam02062ea4;
  } while (iVar15 < 8);
  iVar15 = 0;
  do {
    iVar2 = iVar15 * 2;
    iVar12 = iVar15 + 8;
    iVar13 = iVar15 + 0x10;
    iVar14 = iVar15 + 0x18;
    iVar15 = (iVar15 + 1) * 0x10000 >> 0x10;
    *(undefined2 *)(iVar1 + iVar12 * 2) = *(undefined2 *)(iVar1 + iVar2);
    *(undefined2 *)(iVar1 + iVar14 * 2) = *(undefined2 *)(iVar1 + iVar13 * 2);
  } while (iVar15 < 8);
  func_02061c28();
  func_020631b0();
  uVar11 = (*(uint *)(uRam02062e88 & 0xfffffffc) >> (uRam02062e88 & 3) * 8 |
           *(uint *)(uRam02062e88 & 0xfffffffc) << (uRam02062e88 & 3) * -8 + 0x20) + 0xc;
  uVar10 = uVar11 & 3;
  uVar11 = *(uint *)(uVar11 & 0xfffffffc);
  if ((uVar11 >> uVar10 * 8 | uVar11 << uVar10 * -8 + 0x20) == 5) {
    uVar7 = 0;
    do {
      func_0208eb1c(uVar7);
      uVar7 = uVar7 + 1;
    } while (uVar7 < 3);
    return;
  }
  return;
}

