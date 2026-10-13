/* Decompiled C draft; module arm9; ROM address 020ebb04. No matching claim. */
#include "types.h"
#include "deps/020ebb04_func_020ebb04.h"

void func_020ebb04(int param_1)

{
  longlong lVar1;
  short sVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  bool bVar8;
  undefined1 auStack_18 [16];
  
  uVar3 = GetSomeTimeOrDuration();
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) & 0xfffe;
  bVar8 = (uVar3 & 1) != 0;
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) & 0xfffd;
  puVar4 = (undefined4 *)(*(ushort *)(param_1 + 2) & 0xfffffff7);
  *(short *)(param_1 + 2) = (short)puVar4;
  if (bVar8) {
    puVar4 = (undefined4 *)(param_1 + 0xf4);
  }
  *(undefined2 *)(param_1 + 0x66) = 1;
  if (!bVar8) {
    puVar4 = (undefined4 *)(param_1 + 0x100);
  }
  uVar6 = puVar4[1];
  uVar7 = puVar4[2];
  *(undefined4 *)(param_1 + 0xd8) = *puVar4;
  *(undefined4 *)(param_1 + 0xdc) = uVar6;
  *(undefined4 *)(param_1 + 0xe0) = uVar7;
  if ((uVar3 & 2) == 0) {
    sVar2 = -*(short *)(param_1 + 0xf0);
  }
  else {
    sVar2 = *(short *)(param_1 + 0x10c);
  }
  *(short *)(param_1 + 0xf0) = sVar2;
  *(undefined4 *)(param_1 + 0xe4) = 0;
  *(undefined4 *)(param_1 + 0xe8) = 0;
  *(undefined4 *)(param_1 + 0xec) = 0;
  uVar3 = param_1 + 0xd8U & 3;
  uVar5 = *(uint *)(param_1 + 0xd8U & 0xfffffffc);
  lVar1 = (ulonglong)(uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) * 0x14000;
  *(uint *)(param_1 + 0xcc) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000;
  *(undefined4 *)(param_1 + 0xd0) = 0x3c000;
  uVar3 = param_1 + 0xe0U & 3;
  uVar5 = *(uint *)(param_1 + 0xe0U & 0xfffffffc);
  lVar1 = (ulonglong)(uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) * 0x14000;
  *(uint *)(param_1 + 0xd4) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  VecFx32_Add(param_1 + 0xbc,param_1 + 0xd8,param_1 + 0xa0);
  *(short *)(param_1 + 0xac) = *(short *)(param_1 + 200) + *(short *)(param_1 + 0xf0);
  func_020d7a3c(param_1 + 0xa0,*(undefined2 *)(param_1 + 0xac),auStack_18);
  func_01ffccd0(param_1 + 0x28,auStack_18);
  return;
}

