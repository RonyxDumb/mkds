/* Decompiled C draft; module arm9; ROM address 0201520c. No matching claim. */
#include "types.h"
#include "deps/0201520c_func_0201520c.h"

void func_0201520c(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  uVar1 = *(uint *)(uRam02015270 & 0xfffffffc) >> (uRam02015270 & 3) * 8 |
          *(uint *)(uRam02015270 & 0xfffffffc) << (uRam02015270 & 3) * -8 + 0x20;
  uVar2 = uVar1 + 0xd4 & 3;
  uVar4 = *(uint *)(uVar1 + 0xd4 & 0xfffffffc);
  uVar4 = uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20;
  uVar2 = (uint)*(ushort *)(uVar4 + *(ushort *)(uVar4 + 6)) *
          (uint)*(byte *)((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                          *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 1) +
          uVar4 + *(ushort *)(uVar4 + 6) + 4;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  iVar3 = uVar4 + uVar2;
  if ((*(ushort *)(uVar4 + uVar2) & 1) == 0) {
    uVar2 = iVar3 + 4U & 3;
    uVar1 = *(uint *)(iVar3 + 4U & 0xfffffffc);
    param_1[0x13] = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    uVar2 = iVar3 + 8U & 3;
    uVar1 = *(uint *)(iVar3 + 8U & 0xfffffffc);
    param_1[0x14] = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    uVar2 = iVar3 + 0xcU & 3;
    uVar1 = *(uint *)(iVar3 + 0xcU & 0xfffffffc);
    param_1[0x15] = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    return;
  }
  *param_1 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
             *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20 | 4;
  return;
}

