/* Decompiled C draft; module arm9; ROM address 01ffad14. No matching claim. */
#include "types.h"
#include "deps/01ffad14_func_01ffad14.h"

void func_01ffad14(int param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int local_38 [2];
  int local_30;
  int local_2c;
  undefined1 auStack_28 [20];
  
  piVar4 = (int *)(param_1 + 0x100);
  iVar2 = func_01ffd0e8(local_38,uRam01ffae10,param_2);
  func_01ffd0e8(auStack_28,param_1 + 0x244,param_2);
  func_01ffcebc(auStack_28,piVar4,piVar4);
  if (iVar2 != 0) {
    if (((local_2c < 0) &&
        (uVar1 = param_1 + 0x10cU & 3, uVar3 = *(uint *)(param_1 + 0x10cU & 0xfffffffc),
        0 < (int)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20))) ||
       ((0 < local_2c &&
        (uVar1 = param_1 + 0x10cU & 3, uVar3 = *(uint *)(param_1 + 0x10cU & 0xfffffffc),
        (int)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) < 0)))) {
      *piVar4 = -local_38[0];
      *(undefined4 *)(param_1 + 0x104) = 0;
      *(int *)(param_1 + 0x108) = -local_30;
      *(int *)(param_1 + 0x10c) = -local_2c;
      uVar1 = param_1 + 0x48U & 3;
      uVar3 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
      *(uint *)(param_1 + 0x48) = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20 | 0x80000000;
    }
    else {
      *piVar4 = local_38[0];
      *(undefined4 *)(param_1 + 0x104) = 0;
      *(int *)(param_1 + 0x108) = local_30;
      *(int *)(param_1 + 0x10c) = local_2c;
      uVar1 = param_1 + 0x48U & 3;
      uVar3 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
      *(uint *)(param_1 + 0x48) = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0x7fffffff;
    }
  }
  func_01ffcf7c(piVar4,piVar4);
  return;
}

