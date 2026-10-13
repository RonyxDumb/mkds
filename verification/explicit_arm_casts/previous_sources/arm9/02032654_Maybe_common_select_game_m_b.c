/* Decompiled C draft; module arm9; ROM address 02032654. No matching claim. */
#include "types.h"
#include "deps/02032654_Maybe_common_select_game_m_b.h"

void Maybe_common_select_game_m_b
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  ushort uVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  short *psVar8;
  int iVar9;
  short *psVar10;
  int local_58;
  undefined1 auStack_3c [40];
  
  uVar3 = Mem_CreateOrphanChildHeap();
  iVar4 = Mem_AllocateHeap(uVar3,0x6c);
  *piRam02032874 = iVar4;
  Mem_CpuFastMemorySet(0,iVar4,0x6c);
  piVar2 = piRam02032874;
  *(undefined4 *)(*piRam02032874 + 0x40) = uVar3;
  *(undefined4 *)(*piVar2 + 0x68) = param_2;
  *(undefined4 *)(*piVar2 + 0x38) = param_3;
  *(undefined4 *)(*piVar2 + 0x3c) = param_4;
  *(undefined4 *)(*piVar2 + 0x5c) = 0xee;
  *(undefined4 *)(*piVar2 + 0x60) = 0xffffff40;
  if (*psRam02032878 != 2) {
    uVar3 = find_buf_fn_from_thumb(uRam0203287c);
    *(undefined4 *)(*piRam02032874 + 0x50) = uVar3;
  }
  piVar2 = piRam02032874;
  iVar4 = *piRam02032874;
  if (*(int *)(iVar4 + 0x68) == 0) {
    *(undefined4 *)(iVar4 + 0x54) = 3;
    *(undefined4 *)(*piVar2 + 0x48) = 2;
    *(undefined4 *)(*piVar2 + 0x4c) = uRam02032880;
  }
  else if (*(int *)(iVar4 + 0x68) == 1) {
    *(undefined4 *)(iVar4 + 0x54) = 3;
    *(undefined4 *)(*piVar2 + 0x48) = 3;
    *(undefined4 *)(*piVar2 + 0x4c) = uRam02032884;
    func_02050080();
  }
  if (*psRam02032878 != 2) {
    func_020258d4(0,auStack_3c,uRam02032890,uRam02032894,
                  *(undefined4 *)(iRam02032888 + *(int *)(*piRam02032874 + 0x68) * 0xc),1,
                  uRam0203288c);
  }
  if (*psRam02032878 != 2) {
    iVar4 = func_02148cb8();
    iVar9 = *piRam02032874;
    func_02025b20(iVar9,uRam020328a0,uRam020328a4,uRam020328a8,uRam02032898,uRam0203289c,0,
                  uRam0203288c);
    func_02025a50(0,*(undefined4 *)(*piRam02032874 + 0x40),iVar9);
    uVar1 = *(ushort *)(*(int *)(iVar9 + 0xc) + 6);
    uVar5 = (uint)*(ushort *)(*(int *)(iVar9 + 0x14) + 6);
    local_58 = 0;
    psVar8 = psRam020328ac;
    psVar10 = psRam020328ac;
    if (uVar5 != 0) {
      do {
        iVar6 = func_02025a00(0,*(undefined4 *)(*piRam02032874 + 0x40),iVar9,psVar10,iVar4);
        iVar4 = iVar4 - iVar6;
        uVar3 = Bmg_GetRawStringPointer_from_thumb
                          (*(undefined4 *)(*piRam02032874 + 0x50),*(undefined4 *)(psVar8 + 4));
        func_0212426c(0,(int)*psVar8,*(undefined4 *)(iVar9 + 0x14),uVar3,
                      *(undefined4 *)(iVar9 + 0xc),*(undefined4 *)(iVar9 + 0x18));
        local_58 = local_58 + 1;
        psVar8 = psVar8 + 6;
        psVar10 = psVar10 + 6;
      } while (local_58 < (int)uVar5);
    }
    if (*(int *)(*piRam02032874 + 0x68) == 0) {
      uVar5 = 4;
      iVar4 = 6;
    }
    else {
      uVar5 = 0;
      iVar4 = 4;
    }
    uVar7 = uVar5 + iVar4;
    if (uVar5 < uVar7) {
      do {
        *(undefined4 *)(*(int *)(iVar9 + 0x18) + (uVar5 + uVar1) * 0x40) = 0;
        uVar5 = uVar5 + 1;
      } while ((int)uVar5 < (int)uVar7);
    }
  }
  iVar9 = *piRam02032874 + 0x1c;
  iVar4 = *(int *)(*piRam02032874 + 0x68) * 0xc;
  func_02025b20(iVar9,uRam020328b8,uRam020328bc,uRam020328c0,*(undefined4 *)(iRam020328b0 + iVar4),0
                ,*(undefined4 *)(iRam020328b4 + iVar4),uRam0203288c);
  func_02025a50(1,*(undefined4 *)(*piRam02032874 + 0x40),iVar9);
  func_020328c8(0);
  if (*psRam02032878 == 2) {
    func_021281c8(0xffffffff);
  }
  else {
    func_021281c8(0xe);
  }
  func_02128374();
  if (*(int *)(*piRam02032874 + 0x68) == 1) {
    func_0212775c(0,5);
    func_0212775c(1,0xf);
  }
  *(undefined4 *)(*piRam020328c4 + 8) = 0;
  func_02036820(*(undefined4 *)(*piRam02032874 + 0x40));
  return;
}

