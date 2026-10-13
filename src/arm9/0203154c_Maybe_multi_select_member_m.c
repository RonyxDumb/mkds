/* Decompiled C draft; module arm9; ROM address 0203154c. No matching claim. */
#include "types.h"
#include "deps/0203154c_Maybe_multi_select_member_m.h"

void Maybe_multi_select_member_m(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  short sVar6;
  short sVar7;
  short *psVar8;
  int iVar9;
  int iVar10;
  short *psVar11;
  int iVar12;
  int local_28;
  
  uVar2 = Mem_CreateOrphanChildHeap();
  iVar3 = Mem_AllocateHeap(uVar2,uRam02031748);
  *piRam0203174c = iVar3;
  Mem_CpuFastMemorySet(0,(undefined4 *)(uintptr_t)(iVar3),uRam02031748);
  piVar1 = piRam0203174c;
  *(undefined4 *)(*piRam0203174c + iRam02031750) = uVar2;
  *(undefined4 *)(*piVar1 + 0x5c) = param_2;
  *(undefined4 *)(*piVar1 + 0x60) = param_3;
  uVar2 = find_buf_fn_from_thumb(uRam02031754);
  *(undefined4 *)(*piRam0203174c + 100) = uVar2;
  uVar2 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam02031758);
  piVar1 = piRam0203174c;
  *(undefined4 *)(*piRam0203174c + 0x68) = uVar2;
  *(undefined4 *)(*piVar1 + 0x6c) = 0xffffffff;
  iVar3 = func_02148cb8();
  iVar9 = *piRam0203174c;
  iVar10 = iVar9 + 0x24;
  func_02025b20(iVar10,uRam02031768,uRam0203176c,uRam02031770,uRam0203175c,uRam02031760,0,
                uRam02031764);
  func_02025a50(0,*(undefined4 *)(*piRam0203174c + iRam02031750),(int *)(uintptr_t)(iVar10));
  local_28 = 0;
  psVar8 = psRam02031774;
  psVar11 = psRam02031774;
  do {
    iVar4 = func_02025a00(0,*(undefined4 *)(*piRam0203174c + iRam02031750),iVar10,psVar11,iVar3);
    iVar3 = iVar3 - iVar4;
    uVar2 = Bmg_GetRawStringPointer_from_thumb
                      (*(undefined4 *)(*piRam0203174c + 100),*(undefined4 *)(psVar8 + 4));
    func_0212426c(0,(int)*psVar8,*(undefined4 *)(iVar9 + 0x38),uVar2,*(undefined4 *)(iVar9 + 0x30),
                  *(undefined4 *)(iVar9 + 0x3c));
    psVar11 = psVar11 + 6;
    psVar8 = psVar8 + 6;
    local_28 = local_28 + 1;
  } while (local_28 < 2);
  func_02031b6c();
  func_020258d4(1,*piRam0203174c,uRam0203177c,uRam02031780,uRam02031778,3,uRam02031764);
  iVar9 = func_02148ca0();
  iVar4 = *piRam0203174c;
  iVar12 = iVar4 + 0x40;
  func_02025b20(iVar12,uRam02031790,uRam02031794,uRam02031798,uRam02031784,uRam02031788,uRam0203178c
                ,uRam02031764);
  func_02025a50(1,*(undefined4 *)(*piRam0203174c + iRam02031750),(int *)(uintptr_t)(iVar12));
  iVar10 = 0;
  iVar3 = iRam0203179c;
  do {
    iVar5 = func_02025a00(1,*(undefined4 *)(*piRam0203174c + iRam02031750),iVar12,(short *)(uintptr_t)(iVar3),iVar9);
    iVar9 = iVar9 - iVar5;
    iVar3 = iVar3 + 0xc;
    iVar10 = iVar10 + 1;
  } while (iVar10 < 9);
  func_02025f80(*piRam0203174c + 0xd0,3,10,0x40,0);
  func_0212b928(*(undefined4 *)(*piRam0203174c + iRam02031750),*(undefined4 *)(iVar4 + 0x44),3);
  func_02031b30(1);
  func_02025f80(*piRam0203174c + 0xa0,0,10,0xffffffc0,0);
  func_02025f80(*piRam0203174c + 0xb0,0,10,0x40,0);
  func_02025f80(*piRam0203174c + 0xc0,0,10,0xffffff40,0);
  piVar1 = piRam0203174c;
  *(undefined4 *)(*piRam0203174c + 0xe0) = 2;
  iVar3 = 0;
  sVar7 = 0;
  iVar9 = 0;
  sVar6 = 1;
  do {
    *(short *)(*piVar1 + iVar9 + 0xe8) = sVar7;
    *(short *)(*piVar1 + iVar9 + 0xea) = sVar6;
    sVar7 = sVar7 + 2;
    iVar9 = iVar9 + 0xc;
    sVar6 = sVar6 + 2;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 8);
  TextSystem_SetSomeValues_from_thumb(0x20,0);
  return;
}

