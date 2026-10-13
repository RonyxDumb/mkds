/* Decompiled C draft; module arm9; ROM address 020fb61c. No matching claim. */
#include "types.h"
#include "deps/020fb61c_func_020fb61c.h"

void func_020fb61c(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint local_18;
  uint local_14;
  uint local_10;
  
  uVar2 = param_1 + 0x260U & 3;
  uVar3 = *(uint *)(param_1 + 0x260U & 0xfffffffc);
  *(uint *)(param_1 + 0x260) = (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) + iRam020fb760;
  uVar2 = param_1 + 0x264U & 3;
  uVar1 = *(uint *)(param_1 + 0x264U & 0xfffffffc);
  uVar3 = param_1 + 0x260U & 3;
  uVar4 = *(uint *)(param_1 + 0x260U & 0xfffffffc);
  func_020fcce4(param_1,uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20,
                uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20);
  uVar2 = param_1 + 0x264U & 3;
  uVar3 = *(uint *)(param_1 + 0x264U & 0xfffffffc);
  uVar2 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
  if ((int)uVar2 < iRam020fb764) {
    *(uint *)(param_1 + 0x264) = uVar2 + 0x52;
  }
  uVar3 = param_1 + 0x260U & 3;
  uVar1 = *(uint *)(param_1 + 0x260U & 0xfffffffc);
  uVar1 = uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20;
  uVar3 = uVar1;
  if (0x2d000 < (int)uVar1) {
    uVar3 = param_1 + 0x200;
    uVar2 = 6;
  }
  if (0x2d000 < (int)uVar1) {
    *(short *)(uVar3 + 0xf8) = (short)uVar2;
    *(undefined2 *)(uVar3 + 0xfa) = 1;
  }
  iVar5 = iRam020fb76c;
  uVar2 = param_1 + 0x27cU & 3;
  uVar3 = *(uint *)(param_1 + 0x27cU & 0xfffffffc);
  *(uint *)(param_1 + 0x27c) = (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) - iRam020fb768;
  uVar2 = param_1 + 0x284U & 3;
  uVar3 = *(uint *)(param_1 + 0x284U & 0xfffffffc);
  *(uint *)(param_1 + 0x284) = (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) - iVar5;
  uVar2 = param_1 + 0x284U & 3;
  uVar3 = *(uint *)(param_1 + 0x284U & 0xfffffffc);
  if ((int)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) < 0x7b) {
    *(undefined4 *)(param_1 + 0x284) = 0x7b;
  }
  if (*(ushort *)(param_1 + 0x2f6) < 3) {
    uVar2 = param_1 + 0x74U & 3;
    uVar3 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
    if (((uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) & 0x40000000) != 0) {
      iVar5 = param_1 + 0xf0;
      goto LAB_020fb6e4;
    }
  }
  else {
    uVar2 = param_1 + 0x228U & 3;
    uVar3 = *(uint *)(param_1 + 0x228U & 0xfffffffc);
    uVar2 = (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) + 0x1fc;
    uVar3 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    uVar1 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    uVar2 = uVar1 + 0x48;
    uVar3 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    if (((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) & 1) != 0) {
      iVar5 = uVar1 + 0x244;
      goto LAB_020fb6e4;
    }
  }
  iVar5 = 0;
LAB_020fb6e4:
  if (iVar5 == 0) {
    uVar2 = param_1 + 0x234U & 3;
    uVar3 = *(uint *)(param_1 + 0x234U & 0xfffffffc);
    local_10 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
    uVar2 = param_1 + 0x27cU & 3;
    uVar3 = *(uint *)(param_1 + 0x27cU & 0xfffffffc);
    local_14 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
    uVar2 = param_1 + 0x22cU & 3;
    uVar3 = *(uint *)(param_1 + 0x22cU & 0xfffffffc);
    local_18 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
  }
  else {
    uVar2 = param_1 + 0x27cU & 3;
    uVar3 = *(uint *)(param_1 + 0x27cU & 0xfffffffc);
    VecFx32_AddScale1(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20,iVar5,param_1 + 0x22c,
                      &local_18);
  }
  VecFx32_Subtract((uint)(uintptr_t)(&local_18),param_1 + 0x2a4,&local_18);
  uVar2 = param_1 + 0x284U & 3;
  uVar3 = *(uint *)(param_1 + 0x284U & 0xfffffffc);
  VecFx32_AddScale1(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20,(uint)(uintptr_t)(&local_18),param_1 + 0x2a4,
                    (int *)(uintptr_t)(param_1 + 0x2a4));
  func_020fc2e8(param_1,(undefined4 *)(uintptr_t)(param_1 + 0x2a4),0,iVar5);
  return;
}

