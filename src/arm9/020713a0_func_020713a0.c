/* Decompiled C draft; module arm9; ROM address 020713a0. No matching claim. */
#include "types.h"
#include "deps/020713a0_func_020713a0.h"

void func_020713a0(int param_1)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  if (*(ushort *)(param_1 + 0x4e4) < 3) {
    *(short *)(param_1 + 0x4e0) = *(short *)(param_1 + 0x4e2) * 0x3c + *(short *)(param_1 + 0x4e0);
    if (*(short *)(param_1 + 0x4e0) < 0x17d) {
      if (*(short *)(param_1 + 0x4e0) < -0x17c) {
        *(undefined2 *)(param_1 + 0x4e0) = 0xfe84;
      }
    }
    else {
      *(undefined2 *)(param_1 + 0x4e0) = 0x17c;
    }
    *(short *)(param_1 + 0x4de) = *(short *)(param_1 + 0x4de) + *(short *)(param_1 + 0x4e0);
    iVar2 = (int)*(short *)(param_1 + 0x4de);
    iVar3 = iVar2;
    if (iVar2 < 1) {
      iVar3 = -iVar2;
    }
    if ((iRam02071560 < iVar3) &&
       (((0 < iVar2 && (0 < *(short *)(param_1 + 0x4e2))) ||
        ((iVar2 < 0 && (*(short *)(param_1 + 0x4e2) < 0)))))) {
      *(short *)(param_1 + 0x4e2) = -*(short *)(param_1 + 0x4e2);
      *(short *)(param_1 + 0x4e4) = *(short *)(param_1 + 0x4e4) + 1;
    }
    *(undefined4 *)(param_1 + 0x4d4) = 0x1000;
    return;
  }
  *(short *)(param_1 + 0x4e0) = *(short *)(param_1 + 0x4e2) * 0x3c + *(short *)(param_1 + 0x4e0);
  if (*(short *)(param_1 + 0x4e0) < 0xd3) {
    if (*(short *)(param_1 + 0x4e0) < -0xd2) {
      *(undefined2 *)(param_1 + 0x4e0) = 0xff2e;
    }
  }
  else {
    *(undefined2 *)(param_1 + 0x4e0) = 0xd2;
  }
  uVar4 = uRam02071564;
  *(short *)(param_1 + 0x4de) = *(short *)(param_1 + 0x4de) + *(short *)(param_1 + 0x4e0);
  uVar6 = param_1 + 0x4d4U & 3;
  uVar5 = *(uint *)(param_1 + 0x4d4U & 0xfffffffc);
  uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  lVar1 = (ulonglong)uVar4 * (ulonglong)uVar6;
  *(uint *)(param_1 + 0x4d4) =
       (uint)lVar1 >> 0xc |
       (((int)uVar6 >> 0x1f) * uVar4 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
  if ((*(short *)(param_1 + 0x4de) < 1) || (*(short *)(param_1 + 0x4e2) < 1)) {
    if (-1 < *(short *)(param_1 + 0x4de)) {
      return;
    }
    if (-1 < *(short *)(param_1 + 0x4e2)) {
      return;
    }
  }
  *(undefined2 *)(param_1 + 0x4de) = 0;
  uVar6 = param_1 + 0x4cU & 3;
  uVar4 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  *(uint *)(param_1 + 0x4c) = (uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) & 0xdfffffff;
  DriverContext_UpdateCharacterAnimation(param_1,0,1);
  uVar6 = param_1 + 0x44U & 3;
  uVar4 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  *(uint *)(param_1 + 0x44) = uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20 | 0x1000000;
  return;
}

