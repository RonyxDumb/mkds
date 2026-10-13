/* Decompiled C draft; module arm9; ROM address 02084478. No matching claim. */
#include "types.h"
#include "deps/02084478_StructMQRacerEntry_SomeFn_61.h"

void StructMQRacerEntry_SomeFn_61(int param_1)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  uint local_48 [3];
  undefined1 local_3c [12];
  int local_30;
  undefined4 local_2c;
  int local_28;
  undefined4 *puVar7;
  
  uVar12 = param_1 + 0x508U & 3;
  uVar6 = *(uint *)(param_1 + 0x508U & 0xfffffffc);
  puVar7 = (undefined4 *)(uVar6 >> uVar12 * 8 | uVar6 << uVar12 * -8 + 0x20);
  iVar11 = (uint)*(ushort *)(param_1 + 0x74) * 0x58 +
           (*(uint *)(uRam020845c0 & 0xfffffffc) >> (uRam020845c0 & 3) * 8 |
           *(uint *)(uRam020845c0 & 0xfffffffc) << (uRam020845c0 & 3) * -8 + 0x20);
  uVar8 = puVar7[1];
  uVar9 = puVar7[2];
  *(undefined4 *)(param_1 + 0x174) = *puVar7;
  *(undefined4 *)(param_1 + 0x178) = uVar8;
  *(undefined4 *)(param_1 + 0x17c) = uVar9;
  iVar3 = iRam020845c8;
  iVar2 = iRam020845c4;
  uVar12 = 0;
  do {
    uVar6 = param_1 + 0x590U & 3;
    uVar4 = *(uint *)(param_1 + 0x590U & 0xfffffffc);
    uVar6 = (uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) + 0x20;
    uVar4 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    iVar5 = (uVar12 + 2) * 0xc + (uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20);
    local_28 = *(int *)(iVar5 + 0x1c);
    uVar6 = iVar2 + uVar12 * 4;
    uVar4 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    local_2c = 0;
    local_30 = *(int *)(iVar5 + 0x14) + (uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20);
    uVar6 = param_1 + 0xbcU & 3;
    uVar4 = *(uint *)(param_1 + 0xbcU & 0xfffffffc);
    iVar10 = uVar12 * 0xc;
    lVar1 = (longlong)local_30 * (longlong)(int)(uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20);
    local_48[0] = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    local_48[1] = 0;
    uVar6 = param_1 + 0xc4U & 3;
    uVar4 = *(uint *)(param_1 + 0xc4U & 0xfffffffc);
    lVar1 = (longlong)local_28 * (longlong)(int)(uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20);
    local_48[2] = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    func_02147288((uint)(uintptr_t)(local_48),param_1 + 0x150,(uint *)(uintptr_t)(iVar11 + 0x34 + iVar10));
    iVar5 = iVar11 + iVar10;
    uVar6 = iVar5 + 0x34U & 3;
    uVar4 = *(uint *)(iVar5 + 0x34U & 0xfffffffc);
    *(int *)(iVar5 + 0x34) = (int)(uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) >> 4;
    uVar6 = iVar5 + 0x38U & 3;
    uVar4 = *(uint *)(iVar5 + 0x38U & 0xfffffffc);
    *(int *)(iVar5 + 0x38) = (int)(uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) >> 4;
    uVar6 = iVar5 + 0x3cU & 3;
    uVar4 = *(uint *)(iVar5 + 0x3cU & 0xfffffffc);
    *(int *)(iVar5 + 0x3c) = (int)(uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) >> 4;
    MTX_MultVec33(iVar3 + iVar10,param_1 + 0x150,(uint *)(void *)(local_3c));
    iVar5 = uVar12 * 6 + iVar11;
    uVar12 = uVar12 + 1 & 0xffff;
    *(short *)(iVar5 + 0x4c) = (short)MKDS_SLICE_4(local_3c,0);
    *(short *)(iVar5 + 0x4e) = (short)MKDS_SLICE_4(local_3c,4);
    *(short *)(iVar5 + 0x50) = (short)MKDS_SLICE_4(local_3c,8);
  } while (uVar12 < 2);
  return;
}

