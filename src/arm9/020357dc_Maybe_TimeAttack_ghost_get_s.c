/* Decompiled C draft; module arm9; ROM address 020357dc. No matching claim. */
#include "types.h"
#include "deps/020357dc_Maybe_TimeAttack_ghost_get_s.h"

void Maybe_TimeAttack_ghost_get_s(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  ushort uVar1;
  short sVar2;
  int *piVar3;
  short sVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  short *psVar9;
  short *psVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  short *local_34;
  undefined2 local_24;
  ushort local_22;
  short local_20;
  undefined4 local_1c;
  
  uVar5 = Mem_CreateOrphanChildHeap();
  iVar6 = Mem_AllocateHeap(uVar5,0xa8);
  *piRam02035a44 = iVar6;
  local_1c = 0;
  Mem_CpuFastMemorySet(0,(undefined4 *)(uintptr_t)(iVar6),0xa8);
  piVar3 = piRam02035a44;
  *(undefined4 *)(*piRam02035a44 + 0xa4) = uVar5;
  *(undefined4 *)(*piVar3 + 0x24) = param_2;
  *(undefined4 *)(*piVar3 + 0x28) = param_3;
  uVar5 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam02035a48);
  *(undefined4 *)(*piRam02035a44 + 0x84) = uVar5;
  uVar5 = find_buf_fn_from_thumb(uRam02035a4c);
  piVar3 = piRam02035a44;
  *(undefined4 *)(*piRam02035a44 + 0x88) = uVar5;
  iVar12 = *piVar3;
  iVar13 = iVar12 + 0x2c;
  iVar7 = func_02148cb8();
  func_02025b20(iVar13,uRam02035a5c,uRam02035a60,uRam02035a64,uRam02035a50,uRam02035a54,0,
                uRam02035a58);
  func_02025a50(0,*(undefined4 *)(*piRam02035a44 + 0xa4),(int *)(uintptr_t)(iVar13));
  iVar11 = 0;
  iVar6 = iRam02035a68;
  if (*(short *)(*(int *)(iVar12 + 0x40) + 6) != 0) {
    do {
      iVar8 = func_02025a00(0,*(undefined4 *)(*piRam02035a44 + 0xa4),iVar13,(short *)(uintptr_t)(iVar6),iVar7);
      iVar7 = iVar7 - iVar8;
      iVar11 = iVar11 + 1;
      iVar6 = iVar6 + 8;
    } while (iVar11 < (int)(uint)*(ushort *)(*(int *)(iVar12 + 0x40) + 6));
  }
  func_020258d4(1,*piRam02035a44,uRam02035a70,uRam02035a74,uRam02035a6c,3,uRam02035a58);
  iVar7 = *piRam02035a44;
  iVar11 = iVar7 + 0x48;
  iVar6 = func_02148ca0();
  sVar4 = 0;
  func_02025b20(iVar11,uRam02035a84,uRam02035a88,uRam02035a8c,uRam02035a78,uRam02035a7c,uRam02035a80
                ,uRam02035a58);
  func_02025a50(1,*(undefined4 *)(*piRam02035a44 + 0xa4),(int *)(uintptr_t)(iVar11));
  uVar1 = *(ushort *)(*(int *)(iVar7 + 0x54) + 6);
  iVar12 = 0;
  if (*(short *)(*(int *)(iVar7 + 0x5c) + 6) != 0) {
    local_34 = psRam02035a90;
    psVar9 = psRam02035a90;
    do {
      if (psVar9[3] < 0) {
        sVar2 = uVar1 + sVar4;
        sVar4 = sVar4 + 1;
        psVar9[3] = sVar2;
      }
      iVar13 = func_02025a00(1,*(undefined4 *)(*piRam02035a44 + 0xa4),iVar11,local_34,iVar6);
      iVar6 = iVar6 - iVar13;
      psVar9 = psVar9 + 4;
      local_34 = local_34 + 4;
      iVar12 = iVar12 + 1;
    } while (iVar12 < (int)(uint)*(ushort *)(*(int *)(iVar7 + 0x5c) + 6));
  }
  iVar6 = 0;
  do {
    func_021249a8(iVar6,3,*(undefined4 *)(iVar7 + 0x50),*(undefined4 *)(iVar7 + 0x54));
    psVar9 = psRam02035a90;
    iVar6 = iVar6 + 1;
  } while (iVar6 < 8);
  iVar6 = 0;
  psVar10 = psRam02035a90;
  do {
    sVar4 = *psVar10;
    sVar2 = psVar9[(iVar6 + 7) * 4];
    iVar11 = *(int *)(iVar7 + 0x60);
    func_02025c1c((int)psVar10[3],iVar11 + psVar10[3] * 0x40,*(undefined4 *)(iVar7 + 0x54));
    func_02025bf0((int)sVar4,iVar11 + sVar4 * 0x40 + (uint)uVar1 * 0x40,
                  *(undefined4 *)(iVar7 + 0x5c));
    func_02025bf0((int)sVar2,iVar11 + sVar2 * 0x40 + (uint)uVar1 * 0x40,
                  *(undefined4 *)(iVar7 + 0x5c));
    psVar10 = psVar10 + 4;
    iVar6 = iVar6 + 1;
  } while (iVar6 < 7);
  func_02025c1c(7,*(int *)(iVar7 + 0x60) + iRam02035a94,*(undefined4 *)(iVar7 + 0x54));
  local_24 = 0;
  local_20 = uVar1 + 7;
  local_22 = uVar1;
  func_0202e530(*(undefined4 *)(*piRam02035a44 + 0xa4),3,(undefined4)(uintptr_t)(&local_24),7,8,0x7c,
                *(undefined4 *)(iVar7 + 0x60),*(undefined4 *)(iVar7 + 0x58),
                *(int *)(*piRam02035a44 + 0x20) + 0xc,0,1,2,10,uRam02035a98);
  LoadPlayerGfxData_from_thumb(0,(undefined4 *)(uintptr_t)(*piRam02035a44 + 100));
  func_02035a9c();
  func_02025f80(*piRam02035a44 + 0x90,0,10,0xffffff40,0);
  func_02128374();
  func_021281c8(0xf);
  func_02035c14();
  func_02036820(*(undefined4 *)(*piRam02035a44 + 0xa4));
  return;
}

