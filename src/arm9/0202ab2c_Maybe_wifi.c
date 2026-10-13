/* Decompiled C draft; module arm9; ROM address 0202ab2c. No matching claim. */
#include "types.h"
#include "deps/0202ab2c_Maybe_wifi.h"

void Maybe_wifi(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  ushort uVar1;
  short sVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  short *psVar9;
  ushort *puVar10;
  uint uVar11;
  int iVar12;
  int local_38;
  undefined2 local_20;
  ushort local_1e;
  undefined4 local_1c;
  
  uVar4 = Mem_CreateOrphanChildHeap();
  iVar5 = Mem_AllocateHeap(uVar4,uRam0202aecc);
  *piRam0202aed0 = iVar5;
  local_1c = 0;
  Mem_CpuFastMemorySet(0,(undefined4 *)(uintptr_t)(iVar5),uRam0202aecc);
  piVar3 = piRam0202aed0;
  *(undefined4 *)(*piRam0202aed0 + 0x90) = uVar4;
  *(undefined4 *)(*piVar3 + 0x80) = param_2;
  *(undefined4 *)(*piVar3 + 0x84) = param_3;
  uVar4 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam0202aed4);
  *(undefined4 *)(*piRam0202aed0 + 0x88) = uVar4;
  uVar4 = find_buf_fn_from_thumb(uRam0202aed8);
  *(undefined4 *)(*piRam0202aed0 + 0x8c) = uVar4;
  iVar5 = Os_GetTick();
  iVar6 = Os_GetTick();
  iVar7 = *piRam0202aed0;
  *(int *)(iVar7 + 0x94) = iVar5 * 0x10000 + iVar6;
  *(undefined4 *)(iVar7 + 0x98) = 0;
  uVar4 = uRam0202aee0;
  *(undefined4 *)(iVar7 + 0x9c) = uRam0202aedc;
  *(undefined4 *)(iVar7 + 0xa0) = uVar4;
  *(undefined4 *)(iVar7 + 0xa4) = uRam0202aee4;
  *(undefined4 *)(iVar7 + 0xa8) = 0;
  uVar4 = func_020295d0();
  *(undefined4 *)(*piRam0202aed0 + 0xb8) = uVar4;
  uVar4 = func_020295e4();
  *(undefined4 *)(*piRam0202aed0 + 0xb4) = uVar4;
  *(undefined4 *)(*piRam0202aed0 + iRam0202aeec) = uRam0202aee8;
  *(undefined2 *)(*piRam0202aed0 + iRam0202aef0) = 0xff40;
  iVar7 = 0;
  iVar6 = 0;
  iVar5 = 0;
  do {
    *(undefined4 *)(*piRam0202aed0 + iVar6 + 0xbc) = 0;
    func_02025f80(*piRam0202aed0 + 0xfc + iVar5,3,10,0xfc,0);
    iVar6 = iVar6 + 4;
    iVar5 = iVar5 + 0x10;
    iVar7 = iVar7 + 1;
  } while (iVar7 < 4);
  func_02025f80(*piRam0202aed0 + 0xdc,0,10,0xffffffc0,0);
  func_02025f80(*piRam0202aed0 + 0xcc,0,10,0xffffff40,0);
  func_02025f80(*piRam0202aed0 + 0xec,0,10,0x40,0);
  *puRam0202aef4 = *puRam0202aef4 & 0x43 | (ushort)uRam0202aef8;
  func_020258d4(0,*piRam0202aed0,uRam0202af04,uRam0202af08,uRam0202aefc,0,uRam0202af00);
  iVar5 = *piRam0202aed0;
  iVar6 = iVar5 + 0x48;
  local_38 = func_02148cb8();
  func_02025b20(iVar6,uRam0202af14,uRam0202af18,uRam0202af1c,uRam0202af0c,uRam0202af10,0,
                uRam0202af00);
  func_02025a50(0,*(undefined4 *)(*piRam0202aed0 + 0x90),(int *)(uintptr_t)(iVar6));
  uVar11 = (uint)*(ushort *)(*(int *)(iVar5 + 0x54) + 6);
  iVar7 = 0;
  if (uVar11 != 0) {
    do {
      func_021249a8(iVar7,1,*(undefined4 *)(iVar5 + 0x50),*(undefined4 *)(iVar5 + 0x54));
      iVar7 = iVar7 + 1;
    } while (iVar7 < (int)uVar11);
  }
  iVar12 = 0;
  iVar7 = iRam0202af20;
  if (*(short *)(*(int *)(iVar5 + 0x5c) + 6) != 0) {
    do {
      iVar8 = func_02025a00(0,*(undefined4 *)(*piRam0202aed0 + 0x90),iVar6,(short *)(uintptr_t)(iVar7),local_38);
      local_38 = local_38 - iVar8;
      iVar12 = iVar12 + 1;
      iVar7 = iVar7 + 8;
    } while (iVar12 < (int)(uint)*(ushort *)(*(int *)(iVar5 + 0x5c) + 6));
  }
  iVar6 = *(int *)(*piRam0202aed0 + 0xb8);
  if (iVar6 < 4) {
    puVar10 = (ushort *)(iRam0202af24 + iVar6 * 2);
    psVar9 = (short *)(iRam0202af20 + iVar6 * 8);
    do {
      *(undefined4 *)(*(int *)(iVar5 + 0x60) + (uint)*puVar10 * 0x40) = 0;
      *(undefined4 *)(*(int *)(iVar5 + 0x60) + (uVar11 + (int)*psVar9) * 0x40) = 0;
      puVar10 = puVar10 + 1;
      psVar9 = psVar9 + 4;
      iVar6 = iVar6 + 1;
    } while (iVar6 < 4);
  }
  iVar6 = 0;
  if (uVar11 != 0) {
    do {
      func_021249a8(iVar6,2,*(undefined4 *)(iVar5 + 0x50),*(undefined4 *)(iVar5 + 0x54));
      iVar6 = iVar6 + 1;
    } while (iVar6 < (int)uVar11);
  }
  iVar6 = func_0201ea30(*(undefined4 *)(iVar5 + 0x54),4);
  *(short *)(*(int *)(iVar5 + 0x60) + iRam0202af28) =
       0x60 - (short)(((int)*(short *)(iVar6 + 2) << 0x14) >> 0x14);
  *(undefined4 *)(*(int *)(iVar5 + 0x60) + iRam0202af2c) = 0;
  func_020258d4(1,*piRam0202aed0 + 0x24,uRam0202af34,uRam0202af38,uRam0202af30,3,uRam0202af00);
  iVar7 = *piRam0202aed0;
  iVar12 = iVar7 + 100;
  iVar5 = func_02148ca0();
  func_02025b20(iVar12,uRam0202af48,uRam0202af4c,uRam0202af50,uRam0202af3c,uRam0202af40,uRam0202af44
                ,uRam0202af00);
  func_02025a50(1,*(undefined4 *)(*piRam0202aed0 + 0x90),(int *)(uintptr_t)(iVar12));
  uVar1 = *(ushort *)(*(int *)(iVar7 + 0x70) + 6);
  uVar11 = (uint)uVar1;
  iVar6 = 0;
  if (uVar11 != 0) {
    do {
      func_021249a8(iVar6,1,*(undefined4 *)(iVar7 + 0x6c),*(undefined4 *)(iVar7 + 0x70));
      iVar6 = iVar6 + 1;
    } while (iVar6 < (int)uVar11);
  }
  iVar6 = 0;
  psVar9 = psRam0202af54;
  if (*(short *)(*(int *)(iVar7 + 0x78) + 6) != 0) {
    do {
      iVar8 = func_02025a00(1,*(undefined4 *)(*piRam0202aed0 + 0x90),iVar12,psVar9,iVar5);
      iVar5 = iVar5 - iVar8;
      iVar6 = iVar6 + 1;
      psVar9 = psVar9 + 4;
    } while (iVar6 < (int)(uint)*(ushort *)(*(int *)(iVar7 + 0x78) + 6));
  }
  iVar5 = 0;
  if (uVar11 != 0) {
    do {
      func_021249a8(iVar5,2,*(undefined4 *)(iVar7 + 0x6c),*(undefined4 *)(iVar7 + 0x70));
      iVar5 = iVar5 + 1;
    } while (iVar5 < (int)uVar11);
  }
  iVar5 = 0;
  psVar9 = psRam0202af54;
  do {
    sVar2 = *psVar9;
    iVar6 = *(int *)(iVar7 + 0x7c);
    func_02025c1c((int)psVar9[3],iVar6 + psVar9[3] * 0x40,*(undefined4 *)(iVar7 + 0x70));
    func_02025bf0((int)sVar2,iVar6 + sVar2 * 0x40 + uVar11 * 0x40,*(undefined4 *)(iVar7 + 0x78));
    psVar9 = psVar9 + 4;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 7);
  func_02025c1c(7,*(int *)(iVar7 + 0x7c) + iRam0202af58,*(undefined4 *)(iVar7 + 0x70));
  local_20 = 0;
  local_1e = uVar1;
  func_0202e530(*(undefined4 *)(*piRam0202aed0 + 0x90),2,(undefined4)(uintptr_t)(&local_20),7,8,0x7c,
                *(undefined4 *)(iVar7 + 0x7c),*(undefined4 *)(iVar7 + 0x74),
                *(int *)(*piRam0202aed0 + 0x44) + 0xc,5,6,0,0x15,uRam0202af5c);
  func_02036820(*(undefined4 *)(*piRam0202aed0 + 0x90));
  return;
}

