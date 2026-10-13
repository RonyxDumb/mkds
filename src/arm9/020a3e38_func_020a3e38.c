/* Decompiled C draft; module arm9; ROM address 020a3e38. No matching claim. */
#include "types.h"
#include "deps/020a3e38_func_020a3e38.h"

void func_020a3e38(undefined4 param_1)

{
  uint uVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  iVar4 = GetGlobalHD4();
  piVar2 = piRam020a3eac;
  uVar1 = iVar4 + 0x24U & 3;
  uVar5 = *(uint *)(iVar4 + 0x24U & 0xfffffffc);
  *piRam020a3eac = (int)(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) >> 1;
  uVar6 = uRam020a3eb0;
  uVar1 = iVar4 + 0x28U & 3;
  uVar5 = *(uint *)(iVar4 + 0x28U & 0xfffffffc);
  piVar2[1] = (int)(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) >> 1;
  piVar3 = piRam020a3eb4;
  uVar1 = iVar4 + 0x2cU & 3;
  uVar5 = *(uint *)(iVar4 + 0x2cU & 0xfffffffc);
  piVar2[2] = (int)(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) >> 1;
  uVar1 = iVar4 + 0x24U & 3;
  uVar7 = *(uint *)(iVar4 + 0x24U & 0xfffffffc);
  uVar5 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  *piVar3 = (int)(uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20) >> 3;
  uVar1 = iVar4 + 0x28U & 3;
  uVar7 = *(uint *)(iVar4 + 0x28U & 0xfffffffc);
  piVar3[1] = (int)(uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20) >> 3;
  uVar1 = iVar4 + 0x2cU & 3;
  uVar7 = *(uint *)(iVar4 + 0x2cU & 0xfffffffc);
  piVar3[2] = (int)(uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20) >> 3;
  StructMapObject_SomeFn_9(param_1,uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20);
  return;
}

