/* Decompiled C draft; module arm7; ROM address 037fde38. No matching claim. */
#include "types.h"
#include "deps/037fde38_FUN_037fde38.h"

void FUN_037fde38(byte *param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined1 local_28 [16];
  
  uVar3 = 0;
  if (((int)((uint)*param_1 << 0x1c) < 0) &&
     (uVar3 = (uint)(param_1 + 0x3c) & 3, uVar4 = *(uint *)((uint)(param_1 + 0x3c) & 0xfffffffc),
     uVar3 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20, uVar3 != 0)) {
    *(char *)(uVar3 + 8) = (char)param_3;
    *(char *)(uVar3 + 9) = (char)param_4;
  }
  if (uVar3 == 0) {
    uVar3 = param_2 + 0x20U & 3;
    uVar4 = *(uint *)(param_2 + 0x20U & 0xfffffffc);
    iVar1 = FUN_037ff170(uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20,
                         *(undefined2 *)(param_1 + 2),param_3,(undefined2 *)(void *)(local_28));
    if (iVar1 == 0) {
      return;
    }
    uVar3 = DAT_037fe03c;
    switch(local_28[0]) {
    case 0:
      return;
    case 1:
      break;
    case 2:
      uVar3 = 0x3f00;
      break;
    case 3:
      uVar3 = 0xc000;
      break;
    case 4:
      break;
    default:
      return;
    }
    uVar3 = FUN_037fcadc(uVar3 & *(ushort *)(param_1 + 0x1e),
                         (uint)*(byte *)(param_2 + 4) + (uint)param_1[0x12],
                         ((uint)*param_1 << 0x18) >> 0x1f,DAT_037fe040,(undefined4)(uintptr_t)(param_1));
    if (uVar3 == 0) {
      return;
    }
    iVar1 = FUN_037ff000(uVar3,param_3,param_4);
    if (iVar1 == 0) {
      *(undefined1 *)(uVar3 + 0x22) = 0;
      FUN_037fcac8(uVar3);
      return;
    }
    uVar4 = (uint)(param_1 + 0x3c) & 3;
    uVar2 = *(uint *)((uint)(param_1 + 0x3c) & 0xfffffffc);
    *(uint *)(uVar3 + 0x50) = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20;
    *(uint *)(param_1 + 0x3c) = uVar3;
  }
  if (param_1[0xe] != 0xff) {
    FUN_037fcc70(uVar3);
  }
  if (param_1[0xf] != 0xff) {
    FUN_037fcc54(uVar3);
  }
  if (param_1[0x10] != 0xff) {
    FUN_037fcc4c(uVar3);
  }
  if (param_1[0x11] != 0xff) {
    FUN_037fcc30(uVar3);
  }
  *(undefined2 *)(uVar3 + 0x32) = *(undefined2 *)(param_1 + 0x16);
  if ((int)((uint)*param_1 << 0x1a) < 0) {
    *(short *)(uVar3 + 0x32) =
         *(short *)(uVar3 + 0x32) + (short)(((uint)param_1[0x14] - param_3) * 0x400000 >> 0x10);
  }
  uVar4 = (uint)param_1[0x15];
  if (uVar4 == 0) {
    *(undefined4 *)(uVar3 + 0x18) = param_5;
    *(byte *)(uVar3 + 3) = *(byte *)(uVar3 + 3) & 0xfb;
  }
  else {
    iVar1 = (int)*(short *)(uVar3 + 0x32);
    if (iVar1 < 0) {
      iVar1 = -iVar1;
    }
    *(int *)(uVar3 + 0x18) = (int)(uVar4 * uVar4 * iVar1) >> 0xb;
  }
  *(undefined4 *)(uVar3 + 0x14) = 0;
  return;
}

