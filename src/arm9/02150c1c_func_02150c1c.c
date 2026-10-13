/* Decompiled C draft; module arm9; ROM address 02150c1c. No matching claim. */
#include "types.h"
#include "deps/02150c1c_func_02150c1c.h"

void func_02150c1c(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar2;
  
  iVar5 = param_1 + 0x20;
  if (param_3 == 0) {
    return;
  }
  uVar2 = param_1 + 0x14U & 3;
  uVar1 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  uVar1 = uVar2 + param_3 * 8;
  if (uVar1 < uVar2) {
    uVar2 = param_1 + 0x18U & 3;
    uVar3 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
    *(uint *)(param_1 + 0x18) = (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) + 1;
  }
  uVar2 = param_1 + 0x18U & 3;
  uVar3 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
  *(uint *)(param_1 + 0x18) = (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) + (param_3 >> 0x1d);
  *(uint *)(param_1 + 0x14) = uVar1;
  uVar2 = param_1 + 0x1cU & 3;
  uVar1 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if (uVar2 != 0) {
    if (uVar2 + param_3 < 0x40) {
      Mem_CpuCopy8((ushort *)(uintptr_t)(param_2),(uint *)(uintptr_t)(iVar5 + uVar2),param_3);
      uVar2 = param_1 + 0x1cU & 3;
      uVar1 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
      *(uint *)(param_1 + 0x1c) = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) + param_3;
      return;
    }
    iVar4 = 0x40 - uVar2;
    Mem_CpuCopy8((ushort *)(uintptr_t)(param_2),(uint *)(uintptr_t)(iVar5 + uVar2),iVar4);
    param_3 = param_3 - iVar4;
    param_2 = param_2 + iVar4;
    (*(code *)(*(uint *)(uRam02150d74 & 0xfffffffc) >> (uRam02150d74 & 3) * 8 |
              *(uint *)(uRam02150d74 & 0xfffffffc) << (uRam02150d74 & 3) * -8 + 0x20))
              (param_1,iVar5,0x40);
    *(undefined4 *)(param_1 + 0x1c) = 0;
  }
  if (0x3f < param_3) {
    uVar2 = param_3 & 0xffffffc0;
    param_3 = param_3 - uVar2;
    if ((param_2 & 3) == 0) {
      (*(code *)(*(uint *)(uRam02150d74 & 0xfffffffc) >> (uRam02150d74 & 3) * 8 |
                *(uint *)(uRam02150d74 & 0xfffffffc) << (uRam02150d74 & 3) * -8 + 0x20))
                (param_1,param_2,uVar2);
      param_2 = param_2 + uVar2;
    }
    else {
      do {
        Mem_CpuCopy8((ushort *)(uintptr_t)(param_2),(uint *)(uintptr_t)(iVar5),0x40);
        param_2 = param_2 + 0x40;
        (*(code *)(*(uint *)(uRam02150d74 & 0xfffffffc) >> (uRam02150d74 & 3) * 8 |
                  *(uint *)(uRam02150d74 & 0xfffffffc) << (uRam02150d74 & 3) * -8 + 0x20))
                  (param_1,iVar5,0x40);
        uVar2 = uVar2 - 0x40;
      } while (0 < (int)uVar2);
    }
  }
  *(uint *)(param_1 + 0x1c) = param_3;
  if (param_3 != 0) {
    Mem_CpuCopy8((ushort *)(uintptr_t)(param_2),(uint *)(uintptr_t)(iVar5),param_3);
    return;
  }
  return;
}

