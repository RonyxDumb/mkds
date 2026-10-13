/* Decompiled C draft; module arm9; ROM address 0202d20c. No matching claim. */
#include "types.h"
#include "deps/0202d20c_Maybe_TimeAttack_ghost_send_m.h"

void Maybe_TimeAttack_ghost_send_m(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  ushort uVar1;
  short sVar2;
  int *piVar3;
  short sVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  short *psVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  short *local_3c;
  int local_38;
  undefined2 local_2c;
  undefined2 local_2a;
  ushort local_28;
  short local_26;
  undefined4 local_24;
  
  uVar5 = Mem_CreateOrphanChildHeap();
  iVar6 = Mem_AllocateHeap(uVar5,0xe0);
  *piRam0202d4f0 = iVar6;
  local_24 = 0;
  Mem_CpuFastMemorySet(0,(undefined4 *)(uintptr_t)(iVar6),0xe0);
  piVar3 = piRam0202d4f0;
  *(undefined4 *)(*piRam0202d4f0 + 0xdc) = uVar5;
  *(undefined4 *)(*piVar3 + 0x48) = param_2;
  *(undefined4 *)(*piVar3 + 0x4c) = param_3;
  uVar5 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam0202d4f4);
  *(undefined4 *)(*piRam0202d4f0 + 0xa8) = uVar5;
  uVar5 = find_buf_fn_from_thumb(uRam0202d4f8);
  piVar3 = piRam0202d4f0;
  *(undefined4 *)(*piRam0202d4f0 + 0xac) = uVar5;
  func_0204f240(*(undefined4 *)(*piVar3 + 0xdc),2);
  func_020258d4(0,*piRam0202d4f0,uRam0202d504,uRam0202d508,uRam0202d4fc,0,uRam0202d500);
  iVar12 = *piRam0202d4f0;
  iVar13 = iVar12 + 0x50;
  iVar7 = func_02148cb8();
  func_02025b20(iVar13,uRam0202d514,uRam0202d518,uRam0202d51c,uRam0202d50c,uRam0202d510,0,
                uRam0202d500);
  func_02025a50(0,*(undefined4 *)(*piRam0202d4f0 + 0xdc),(int *)(uintptr_t)(iVar13));
  iVar11 = 0;
  iVar6 = iRam0202d520;
  if (*(short *)(*(int *)(iVar12 + 100) + 6) != 0) {
    do {
      iVar8 = func_02025a00(0,*(undefined4 *)(*piRam0202d4f0 + 0xdc),iVar13,(short *)(uintptr_t)(iVar6),iVar7);
      iVar7 = iVar7 - iVar8;
      iVar11 = iVar11 + 1;
      iVar6 = iVar6 + 8;
    } while (iVar11 < (int)(uint)*(ushort *)(*(int *)(iVar12 + 100) + 6));
  }
  func_020258d4(1,*piRam0202d4f0 + 0x24,uRam0202d528,uRam0202d52c,uRam0202d524,3,uRam0202d500);
  iVar7 = *piRam0202d4f0;
  iVar11 = iVar7 + 0x6c;
  iVar6 = func_02148ca0();
  sVar4 = 0;
  func_02025b20(iVar11,uRam0202d53c,uRam0202d540,uRam0202d544,uRam0202d530,uRam0202d534,uRam0202d538
                ,uRam0202d500);
  func_02025a50(1,*(undefined4 *)(*piRam0202d4f0 + 0xdc),(int *)(uintptr_t)(iVar11));
  uVar1 = *(ushort *)(*(int *)(iVar7 + 0x78) + 6);
  uVar9 = (uint)uVar1;
  iVar12 = 0;
  if (*(short *)(*(int *)(iVar7 + 0x80) + 6) != 0) {
    local_3c = psRam0202d548;
    psVar10 = psRam0202d548;
    do {
      if (psVar10[3] < 0) {
        sVar2 = uVar1 + sVar4;
        sVar4 = sVar4 + 1;
        psVar10[3] = sVar2;
      }
      iVar13 = func_02025a00(1,*(undefined4 *)(*piRam0202d4f0 + 0xdc),iVar11,local_3c,iVar6);
      iVar6 = iVar6 - iVar13;
      psVar10 = psVar10 + 4;
      local_3c = local_3c + 4;
      iVar12 = iVar12 + 1;
    } while (iVar12 < (int)(uint)*(ushort *)(*(int *)(iVar7 + 0x80) + 6));
  }
  func_0202d720();
  iVar6 = 0;
  do {
    func_021249a8(iVar6,3,*(undefined4 *)(iVar7 + 0x74),*(undefined4 *)(iVar7 + 0x78));
    iVar6 = iVar6 + 1;
  } while (iVar6 < 0xf);
  iVar6 = 0;
  do {
    func_02124094(iVar6,2,*(undefined4 *)(iVar7 + 0x80),*(undefined4 *)(iVar7 + 0x84),
                  *(undefined4 *)(iVar7 + 0x78));
    iVar6 = iVar6 + 1;
  } while (iVar6 < 0xe);
  local_38 = 0;
  psVar10 = psRam0202d548;
  do {
    sVar4 = *psVar10;
    iVar6 = *(int *)(iVar7 + 0x84);
    func_02025c1c((int)psVar10[3],iVar6 + psVar10[3] * 0x40,*(undefined4 *)(iVar7 + 0x78));
    func_02025bf0((int)sVar4,iVar6 + uVar9 * 0x40 + sVar4 * 0x40,*(undefined4 *)(iVar7 + 0x80));
    psVar10 = psVar10 + 4;
    local_38 = local_38 + 1;
  } while (local_38 < 0xe);
  func_02025c1c(0xe,*(int *)(iVar7 + 0x84) + iRam0202d54c,*(undefined4 *)(iVar7 + 0x78));
  iVar6 = func_0202ddc4();
  if (iVar6 == 0) {
    iVar6 = 0;
    if (uVar9 != 0) {
      iVar11 = 0;
      do {
        *(undefined4 *)(*(int *)(iVar7 + 0x84) + iVar11) = 0;
        iVar11 = iVar11 + 0x40;
        iVar6 = iVar6 + 1;
      } while (iVar6 < (int)uVar9);
    }
    iVar6 = 0;
    do {
      *(undefined4 *)(*(int *)(iVar7 + 0x84) + (uVar9 + iVar6) * 0x40) = 0;
      iVar6 = iVar6 + 1;
    } while (iVar6 < 0xe);
  }
  else {
    iVar6 = *piRam0202d4f0;
    local_2c = 0;
    local_2a = 7;
    local_26 = uVar1 + 7;
    local_28 = uVar1;
    uVar5 = func_0202ddc4();
    func_0202e530(*(undefined4 *)(*piRam0202d4f0 + 0xdc),4,(undefined4)(uintptr_t)(&local_2c),0xe,0xf,0x7c,
                  *(undefined4 *)(iVar7 + 0x84),*(undefined4 *)(iVar7 + 0x7c),
                  *(int *)(iVar6 + 0x44) + 0xc,0,1,2,uVar5,uRam0202d550);
  }
  LoadPlayerGfxData_from_thumb(0,(undefined4 *)(uintptr_t)(*piRam0202d4f0 + 0x88));
  func_02025f80(*piRam0202d4f0 + 0xcc,3,10,0xffffff40,0);
  func_021281c8(0xf);
  func_0204f804();
  piVar3 = piRam0202d4f0;
  *(undefined4 *)(*piRam0202d4f0 + 0xb0) = 1;
  func_02036820(*(undefined4 *)(*piVar3 + 0xdc));
  return;
}

