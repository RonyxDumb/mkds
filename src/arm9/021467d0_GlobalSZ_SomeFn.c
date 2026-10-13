/* Decompiled C draft; module arm9; ROM address 021467d0. No matching claim. */
#include "types.h"
#include "deps/021467d0_GlobalSZ_SomeFn.h"

bool GlobalSZ_SomeFn(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  
  iVar1 = iRam02146864;
  uVar6 = iRam02146864 + 0x1cU & 3;
  uVar5 = *(uint *)(iRam02146864 + 0x1cU & 0xfffffffc);
  uVar2 = param_1 + 8U & 3;
  uVar3 = *(uint *)(param_1 + 8U & 0xfffffffc);
  uVar6 = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) & 0xfffffe00;
  if (uVar6 == (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20)) {
    uVar2 = iRam02146864 + 0x1cU & 3;
    uVar4 = *(uint *)(iRam02146864 + 0x1cU & 0xfffffffc);
    uVar3 = iRam02146864 + 0x24U & 3;
    uVar5 = *(uint *)(iRam02146864 + 0x24U & 0xfffffffc);
    uVar3 = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20;
    iVar7 = (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) - uVar6;
    uVar6 = 0x200 - iVar7;
    if (uVar3 < uVar6) {
      uVar6 = uVar3;
    }
    uVar2 = iRam02146864 + 0x20U & 3;
    uVar3 = *(uint *)(iRam02146864 + 0x20U & 0xfffffffc);
    Mem_CpuCopy8((ushort *)(uintptr_t)(param_1 + 0x20 + iVar7),(uint *)(uintptr_t)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20),uVar6);
    uVar2 = iVar1 + 0x1cU & 3;
    uVar3 = *(uint *)(iVar1 + 0x1cU & 0xfffffffc);
    *(uint *)(iVar1 + 0x1c) = (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) + uVar6;
    uVar2 = iVar1 + 0x20U & 3;
    uVar3 = *(uint *)(iVar1 + 0x20U & 0xfffffffc);
    *(uint *)(iVar1 + 0x20) = (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) + uVar6;
    uVar2 = iVar1 + 0x24U & 3;
    uVar3 = *(uint *)(iVar1 + 0x24U & 0xfffffffc);
    *(uint *)(iVar1 + 0x24) = (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) - uVar6;
  }
  uVar6 = iVar1 + 0x24U & 3;
  uVar2 = *(uint *)(iVar1 + 0x24U & 0xfffffffc);
  return uVar2 >> uVar6 * 8 != 0 || uVar2 << uVar6 * -8 + 0x20 != 0;
}

