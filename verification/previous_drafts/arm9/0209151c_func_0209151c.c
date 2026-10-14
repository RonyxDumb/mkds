/* Decompiled C draft; module arm9; ROM address 0209151c. No matching claim. */
#include "types.h"
#include "deps/0209151c_func_0209151c.h"

void func_0209151c(uint param_1)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  uVar2 = uRam020915bc;
  if (param_1 == 0) {
    return;
  }
  iVar4 = 0;
  while( true ) {
    if ((int)(uint)*(ushort *)(param_1 + 4) <= iVar4) {
      return;
    }
    uVar3 = (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
            *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + iVar4 * 4;
    uVar6 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    uVar3 = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
    if (uVar3 == 0) break;
    *(undefined4 *)(uVar3 + 0xb0) = 0x1000;
    *(undefined4 *)(uVar3 + 0xb4) = 0x1000;
    uVar6 = uVar3 + 0x20 & 3;
    uVar5 = *(uint *)(uVar3 + 0x20 & 0xfffffffc);
    uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
    iVar4 = iVar4 + 1;
    lVar1 = (ulonglong)uVar2 * (ulonglong)uVar6;
    *(uint *)(uVar3 + 0xc0) =
         (uint)lVar1 >> 0xc |
         (((int)uVar6 >> 0x1f) * uVar2 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
    uVar6 = uVar3 + 0x20 & 3;
    uVar5 = *(uint *)(uVar3 + 0x20 & 0xfffffffc);
    uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
    *(uint *)(uVar3 + 0xc4) = (uVar6 << 0xd) >> 0xc | (uVar6 >> 0x13) << 0x14;
    uVar6 = uVar3 + 0xc0 & 3;
    uVar5 = *(uint *)(uVar3 + 0xc0 & 0xfffffffc);
    *(uint *)(uVar3 + 0xb8) = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  }
  return;
}

