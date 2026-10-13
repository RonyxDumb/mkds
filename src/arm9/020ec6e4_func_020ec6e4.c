/* Decompiled C draft; module arm9; ROM address 020ec6e4. No matching claim. */
#include "types.h"
#include "deps/020ec6e4_func_020ec6e4.h"

void func_020ec6e4(int param_1,int param_2)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint local_18 [2];
  uint local_10;
  uint uVar6;
  
  VecFx32_Subtract(param_1 + 4,param_2 + 0x80,local_18);
  uVar6 = param_2 + 0xa4U & 3;
  uVar4 = *(uint *)(param_2 + 0xa4U & 0xfffffffc);
  uVar5 = param_2 + 0xacU & 3;
  uVar3 = *(uint *)(param_2 + 0xacU & 0xfffffffc);
  lVar1 = (longlong)(int)local_10 * (longlong)(int)(uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20)
  ;
  lVar2 = (longlong)(int)local_18[0] *
          (longlong)(int)(uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20);
  if ((int)((int)((ulonglong)lVar1 >> 0x20) -
           ((int)((ulonglong)lVar2 >> 0x20) + (uint)((uint)lVar1 < (uint)lVar2))) < 0) {
    uVar6 = param_2 + 0x50U & 3;
    uVar3 = *(uint *)(param_2 + 0x50U & 0xfffffffc);
    uVar5 = param_2 + 0x58U & 3;
    uVar4 = *(uint *)(param_2 + 0x58U & 0xfffffffc);
    local_18[0] = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
    local_10 = -(uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20);
    *(undefined4 *)(param_1 + 0xa8) = 1;
  }
  else {
    uVar6 = param_2 + 0x58U & 3;
    uVar4 = *(uint *)(param_2 + 0x58U & 0xfffffffc);
    uVar5 = param_2 + 0x50U & 3;
    uVar3 = *(uint *)(param_2 + 0x50U & 0xfffffffc);
    local_10 = uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20;
    local_18[0] = -(uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20);
    *(undefined4 *)(param_1 + 0xa8) = 0;
  }
  uVar6 = param_1 + 0xb4U & 3;
  uVar5 = *(uint *)(param_1 + 0xb4U & 0xfffffffc);
  uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  lVar1 = (longlong)(int)local_18[0] * (longlong)(int)uVar6;
  *(uint *)(param_1 + 0x10) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  *(undefined4 *)(param_1 + 0x14) = 0;
  lVar1 = (longlong)(int)local_10 * (longlong)(int)uVar6;
  *(uint *)(param_1 + 0x18) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar6 = param_1 + 0x10U & 3;
  uVar4 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
  uVar5 = param_2 + 0xa4U & 3;
  uVar3 = *(uint *)(param_2 + 0xa4U & 0xfffffffc);
  *(uint *)(param_1 + 0x10) =
       (uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) +
       ((int)(uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) >> 1);
  uVar6 = param_1 + 0x18U & 3;
  uVar4 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
  uVar5 = param_2 + 0xacU & 3;
  uVar3 = *(uint *)(param_2 + 0xacU & 0xfffffffc);
  *(uint *)(param_1 + 0x18) =
       (uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) +
       ((int)(uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) >> 1);
  uVar6 = param_1 + 0xb0U & 3;
  uVar5 = *(uint *)(param_1 + 0xb0U & 0xfffffffc);
  *(uint *)(param_1 + 0x14) = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  return;
}

