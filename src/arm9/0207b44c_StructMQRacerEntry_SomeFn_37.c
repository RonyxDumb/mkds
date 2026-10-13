/* Decompiled C draft; module arm9; ROM address 0207b44c. No matching claim. */
#include "types.h"
#include "deps/0207b44c_StructMQRacerEntry_SomeFn_37.h"

void StructMQRacerEntry_SomeFn_37(int param_1)

{
  byte bVar1;
  longlong lVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar11;
  short sVar12;
  short sVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar10;
  
  uVar3 = *(uint *)(uRam0207b6b0 & 0xfffffffc) >> (uRam0207b6b0 & 3) * 8 |
          *(uint *)(uRam0207b6b0 & 0xfffffffc) << (uRam0207b6b0 & 3) * -8 + 0x20;
  uVar10 = param_1 + 0x7cU & 3;
  uVar9 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  uVar10 = uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20;
  bVar1 = *(byte *)(uVar3 + 0x3d0);
  sVar12 = 1;
  sVar13 = 0;
  if ((uVar10 & 0x10) == 0) {
    return;
  }
  uVar9 = uVar3 + 8 & 3;
  uVar16 = *(uint *)(uVar3 + 8 & 0xfffffffc);
  uVar9 = uVar16 >> uVar9 * 8 | uVar16 << uVar9 * -8 + 0x20;
  if (uVar9 == 2) {
    return;
  }
  if (uVar9 == 4) {
    return;
  }
  if ((uVar9 == 2) ||
     (uVar16 = uVar3 + 0x1c & 3, uVar6 = *(uint *)(uVar3 + 0x1c & 0xfffffffc),
     (uVar6 >> uVar16 * 8 | uVar6 << uVar16 * -8 + 0x20) != 1)) {
    if (uVar9 == 1) {
      if ((uVar10 & 4) == 0) {
        iVar5 = func_020c7148();
        if ((iVar5 == 0) && (iVar5 = GetLastTimeTrialWasRecord(), iVar5 == 0)) {
          sVar12 = 2;
        }
        else {
          sVar12 = 0;
        }
      }
    }
    else if (1 < bVar1) {
      iVar5 = GetDriverPlace(*(undefined2 *)(param_1 + 0x74));
      sVar12 = *(short *)((iVar5 + -1) * 2 + iRam0207b6b8 + (bVar1 - 2) * 0x10);
    }
  }
  else {
    uVar10 = (int)*(char *)((*(uint *)(uRam0207b6b4 & 0xfffffffc) >> (uRam0207b6b4 & 3) * 8 |
                            *(uint *)(uRam0207b6b4 & 0xfffffffc) << (uRam0207b6b4 & 3) * -8 + 0x20)
                           + 0x474) & 0xffff;
    sVar12 = sVar13;
    if (*(char *)(uVar3 + 0x58) == '\0') {
      if (*(ushort *)(param_1 + 0x74) == uVar10) {
        uVar10 = param_1 + 0x7cU & 3;
        uVar3 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
        *(uint *)(param_1 + 0x7c) = uVar3 >> uVar10 * 8 | uVar3 << uVar10 * -8 + 0x20 | 0x2000000;
        sVar13 = 1;
      }
      else {
        sVar12 = 2;
      }
    }
    else {
      uVar9 = (uint)*(ushort *)(param_1 + 0x74) * 0x30 + uVar3 + 0x74;
      uVar16 = uVar9 & 3;
      uVar9 = *(uint *)(uVar9 & 0xfffffffc);
      uVar10 = uVar10 * 0x30 + uVar3 + 0x74;
      uVar3 = uVar10 & 3;
      uVar10 = *(uint *)(uVar10 & 0xfffffffc);
      if ((uVar10 >> uVar3 * 8 | uVar10 << uVar3 * -8 + 0x20) ==
          (uVar9 >> uVar16 * 8 | uVar9 << uVar16 * -8 + 0x20)) {
        uVar10 = param_1 + 0x7cU & 3;
        uVar3 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
        *(uint *)(param_1 + 0x7c) = uVar3 >> uVar10 * 8 | uVar3 << uVar10 * -8 + 0x20 | 0x2000000;
        sVar13 = 1;
      }
      else {
        sVar12 = 2;
      }
    }
  }
  if (sVar12 == 0) {
    uVar10 = param_1 + 0x590U & 3;
    uVar3 = *(uint *)(param_1 + 0x590U & 0xfffffffc);
    uVar9 = uVar3 >> uVar10 * 8 | uVar3 << uVar10 * -8 + 0x20;
    uVar10 = uVar9 + 8 & 3;
    uVar3 = *(uint *)(uVar9 + 8 & 0xfffffffc);
    Animation_SetLoop((undefined2 *)(uintptr_t)(uVar3 >> uVar10 * 8 | uVar3 << uVar10 * -8 + 0x20),0,1);
    DriverContext_UpdateCharacterAnimation(param_1,2,1);
    uVar10 = uRam0207b6b4;
    if (sVar13 == 0) {
      *(undefined4 *)(uVar9 + 0x28) = 1;
      uVar3 = uVar10 & 3;
      uVar10 = *(uint *)(uVar10 & 0xfffffffc);
      uVar6 = uVar10 >> uVar3 * 8 | uVar10 << uVar3 * -8 + 0x20;
      uVar10 = uVar6 + 0x498 & 3;
      uVar3 = *(uint *)(uVar6 + 0x498 & 0xfffffffc);
      uVar11 = uVar3 >> uVar10 * 8 | uVar3 << uVar10 * -8 + 0x20;
      iVar5 = uVar6 + iRam0207b6bc;
      uVar10 = iVar5 + 8U & 3;
      uVar3 = *(uint *)(iVar5 + 8U & 0xfffffffc);
      uVar14 = uVar3 >> uVar10 * 8 | uVar3 << uVar10 * -8 + 0x20;
      uVar10 = iVar5 + 4U & 3;
      uVar7 = *(uint *)(iVar5 + 4U & 0xfffffffc);
      lVar2 = (ulonglong)uVar11 * (ulonglong)uVar14;
      uVar18 = (uint)lVar2;
      uVar3 = iVar5 + 0x10U & 3;
      uVar16 = *(uint *)(iVar5 + 0x10U & 0xfffffffc);
      uVar17 = uVar16 >> uVar3 * 8 | uVar16 << uVar3 * -8 + 0x20;
      uVar3 = iVar5 + 0xcU & 3;
      uVar8 = *(uint *)(iVar5 + 0xcU & 0xfffffffc);
      uVar16 = iVar5 + 0x14U & 3;
      uVar15 = *(uint *)(iVar5 + 0x14U & 0xfffffffc);
      *(uint *)(uVar6 + 0x498) = uVar17 + uVar18;
      *(uint *)(iVar5 + 4) =
           (uVar15 >> uVar16 * 8 | uVar15 << uVar16 * -8 + 0x20) +
           (uVar8 >> uVar3 * 8 | uVar8 << uVar3 * -8 + 0x20) * uVar11 +
           uVar14 * (uVar7 >> uVar10 * 8 | uVar7 << uVar10 * -8 + 0x20) +
           (int)((ulonglong)lVar2 >> 0x20) + (uint)CARRY4(uVar17,uVar18);
      uVar10 = iVar5 + 4U & 3;
      uVar3 = *(uint *)(iVar5 + 4U & 0xfffffffc);
      *(short *)(uVar9 + 0x34) =
           (short)((ulonglong)(uVar3 >> uVar10 * 8 | uVar3 << uVar10 * -8 + 0x20) * 200 >> 0x20);
      *(short *)(uVar9 + 0x34) = *(short *)(uVar9 + 0x34) + 0x96;
    }
    else {
      uVar10 = param_1 + 0x7cU & 3;
      uVar3 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
      *(uint *)(param_1 + 0x7c) = uVar3 >> uVar10 * 8 | uVar3 << uVar10 * -8 + 0x20 | 0x10000;
    }
  }
  else if (sVar12 == 2) {
    uVar10 = param_1 + 0x7cU & 3;
    uVar3 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    *(uint *)(param_1 + 0x7c) = uVar3 >> uVar10 * 8 | uVar3 << uVar10 * -8 + 0x20 | 0x20000;
    DriverContext_UpdateCharacterAnimation(param_1,3,1);
  }
  uVar10 = param_1 + 0x7cU & 3;
  uVar3 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar3 >> uVar10 * 8 | uVar3 << uVar10 * -8 + 0x20) & 1) == 0) {
    return;
  }
  uVar4 = 1;
  if (sVar12 == 0) {
    uVar4 = 0;
  }
  else if (sVar12 == 2) {
    uVar4 = 2;
  }
  func_021112fc(uVar4);
  return;
}

