/* Decompiled C draft; module arm9; ROM address 02034bf4. No matching claim. */
#include "types.h"
#include "deps/02034bf4_Maybe_TimeAttack_ghost_get_s_sel.h"

void Maybe_TimeAttack_ghost_get_s_sel(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  ushort uVar1;
  short sVar2;
  int *piVar3;
  short sVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined4 local_20;
  
  uVar5 = Mem_CreateOrphanChildHeap();
  iVar6 = Mem_AllocateHeap(uVar5,uRam02034e08);
  *piRam02034e0c = iVar6;
  Mem_CpuFastMemorySet(0,(undefined4 *)(uintptr_t)(iVar6),uRam02034e08);
  piVar3 = piRam02034e0c;
  *(undefined4 *)(*piRam02034e0c + iRam02034e10) = uVar5;
  *(undefined4 *)(*piVar3 + 0x24) = param_2;
  *(undefined4 *)(*piVar3 + 0x28) = param_3;
  uVar5 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam02034e14);
  *(undefined4 *)(*piRam02034e0c + 0x84) = uVar5;
  uVar5 = find_buf_fn_from_thumb(uRam02034e18);
  piVar3 = piRam02034e0c;
  *(undefined4 *)(*piRam02034e0c + 0x88) = uVar5;
  func_0204f240(*(undefined4 *)(*piVar3 + iRam02034e10),2);
  piVar3 = piRam02034e0c;
  iVar10 = 0;
  *(undefined4 *)(*piRam02034e0c + 0x80) = 0xffffffff;
  iVar6 = 0;
  do {
    func_02025f80(*piVar3 + 200 + iVar6,3,10,iRam02034e1c,0);
    iVar6 = iVar6 + 0x3c;
    iVar10 = iVar10 + 1;
  } while (iVar10 < 4);
  func_020258d4(0,*piRam02034e0c,uRam02034e28,uRam02034e2c,uRam02034e20,0,uRam02034e24);
  iVar11 = *piRam02034e0c;
  iVar12 = iVar11 + 0x2c;
  iVar10 = func_02148cb8();
  func_02025b20(iVar12,uRam02034e38,uRam02034e3c,uRam02034e40,uRam02034e30,uRam02034e34,0,
                uRam02034e24);
  func_02025a50(0,*(undefined4 *)(*piRam02034e0c + iRam02034e10),(int *)(uintptr_t)(iVar12));
  iVar9 = 0;
  uVar8 = (uint)*(ushort *)(*(int *)(iVar11 + 0x40) + 6);
  iVar6 = iRam02034e44;
  if (uVar8 != 0) {
    do {
      iVar7 = func_02025a00(0,*(undefined4 *)(*piRam02034e0c + iRam02034e10),iVar12,(short *)(uintptr_t)(iVar6),iVar10);
      iVar10 = iVar10 - iVar7;
      iVar9 = iVar9 + 1;
      uVar8 = (uint)*(ushort *)(*(int *)(iVar11 + 0x40) + 6);
      iVar6 = iVar6 + 8;
    } while (iVar9 < (int)uVar8);
  }
  iVar10 = *(ushort *)(*(int *)(iVar11 + 0x38) + 6) + uVar8;
  iVar6 = 0;
  if (iVar10 != 0) {
    iVar9 = 0;
    do {
      *(undefined4 *)(*(int *)(iVar11 + 0x44) + iVar9) = 0;
      iVar9 = iVar9 + 0x40;
      iVar6 = iVar6 + 1;
    } while (iVar6 < iVar10);
  }
  iVar10 = *piRam02034e0c;
  iVar9 = iVar10 + 0x48;
  iVar6 = func_02148ca0();
  sVar4 = 0;
  func_02025b20(iVar9,uRam02034e54,uRam02034e58,uRam02034e5c,uRam02034e48,uRam02034e4c,uRam02034e50,
                uRam02034e24);
  func_02025a50(1,*(undefined4 *)(*piRam02034e0c + iRam02034e10),(int *)(uintptr_t)(iVar9));
  uVar1 = *(ushort *)(*(int *)(iVar10 + 0x54) + 6);
  iVar11 = 0;
  if (*(short *)(*(int *)(iVar10 + 0x5c) + 6) != 0) {
    local_20 = iRam02034e60;
    iVar12 = iRam02034e60;
    do {
      if (*(short *)(iVar12 + 6) < 0) {
        sVar2 = uVar1 + sVar4;
        sVar4 = sVar4 + 1;
        *(short *)(iVar12 + 6) = sVar2;
      }
      iVar7 = func_02025a00(1,*(undefined4 *)(*piRam02034e0c + iRam02034e10),iVar9,(short *)(uintptr_t)(local_20),iVar6);
      iVar6 = iVar6 - iVar7;
      iVar12 = iVar12 + 8;
      local_20 = local_20 + 8;
      iVar11 = iVar11 + 1;
    } while (iVar11 < (int)(uint)*(ushort *)(*(int *)(iVar10 + 0x5c) + 6));
  }
  iVar6 = 0;
  if (uVar1 != 0) {
    do {
      func_021249a8(iVar6,3,*(undefined4 *)(iVar10 + 0x50),*(undefined4 *)(iVar10 + 0x54));
      iVar6 = iVar6 + 1;
    } while (iVar6 < (int)(uint)uVar1);
  }
  *(undefined4 *)(*(int *)(iVar10 + 0x60) + iRam02034e1c) = 0;
  LoadPlayerGfxData_from_thumb(0,(undefined4 *)(uintptr_t)(*piRam02034e0c + 100));
  func_02025f80(*piRam02034e0c + iRam02034e64,3,10,0xffffff40,0);
  func_021281c8(0xf);
  func_02036820(*(undefined4 *)(*piRam02034e0c + iRam02034e10));
  return;
}

