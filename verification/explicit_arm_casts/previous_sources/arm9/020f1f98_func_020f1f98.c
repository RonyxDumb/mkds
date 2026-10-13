/* Decompiled C draft; module arm9; ROM address 020f1f98. No matching claim. */
#include "types.h"
#include "deps/020f1f98_func_020f1f98.h"

void func_020f1f98(int param_1,undefined4 param_2,undefined4 *param_3)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 uStack_10;
  
  uVar1 = (uint)(param_3 + 1) & 3;
  uVar3 = *(uint *)((uint)(param_3 + 1) & 0xfffffffc);
  if ((int)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) < 1) {
    local_18 = *param_3;
    uStack_10 = param_3[2];
    local_14 = 0;
    func_020f2768(param_1,&local_18);
  }
  else {
    func_020f2768(param_1,param_3);
  }
  uVar1 = param_1 + 300U & 3;
  uVar3 = *(uint *)(param_1 + 300U & 0xfffffffc);
  uVar4 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  uVar1 = param_1 + 0x13cU & 3;
  uVar3 = *(uint *)(param_1 + 0x13cU & 0xfffffffc);
  lVar2 = (longlong)(int)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) * (longlong)(int)uVar4;
  *(uint *)(param_1 + 0x5c) = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
  uVar1 = param_1 + 0x140U & 3;
  uVar3 = *(uint *)(param_1 + 0x140U & 0xfffffffc);
  lVar2 = (longlong)(int)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) * (longlong)(int)uVar4;
  *(uint *)(param_1 + 0x60) = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
  uVar1 = param_1 + 0x144U & 3;
  uVar3 = *(uint *)(param_1 + 0x144U & 0xfffffffc);
  lVar2 = (longlong)(int)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) * (longlong)(int)uVar4;
  *(uint *)(param_1 + 100) = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
  return;
}

