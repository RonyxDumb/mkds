/* Decompiled C draft; module arm9; ROM address 02081374. No matching claim. */
#include "types.h"
#include "deps/02081374_func_02081374.h"

void func_02081374(uint param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar4;
  uint uVar3;
  
  if (param_2 != 0) {
    return;
  }
  uVar1 = param_1 + 0x94 & 3;
  uVar2 = *(uint *)(param_1 + 0x94 & 0xfffffffc);
  uVar3 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  uVar1 = uVar3 + 0x48 & 3;
  uVar2 = *(uint *)(uVar3 + 0x48 & 0xfffffffc);
  if (((((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0x400) != 0) &&
      (uVar1 = uVar3 + 0x44 & 3, uVar2 = *(uint *)(uVar3 + 0x44 & 0xfffffffc),
      ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0x80) != 0)) &&
     (uVar1 = uVar3 + 0x2a4 & 3, uVar2 = *(uint *)(uVar3 + 0x2a4 & 0xfffffffc),
     iRam020813e4 <= (int)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20))) {
    return;
  }
  iVar4 = (uint)*(ushort *)(uVar3 + 0x74) * 0x58 +
          (*(uint *)(uRam020813e8 & 0xfffffffc) >> (uRam020813e8 & 3) * 8 |
          *(uint *)(uRam020813e8 & 0xfffffffc) << (uRam020813e8 & 3) * -8 + 0x20);
  uVar1 = iVar4 + 0x28;
  uVar2 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  if (param_1 != (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20)) {
    return;
  }
  uVar1 = param_1 + 0x24 & 3;
  uVar2 = *(uint *)(param_1 + 0x24 & 0xfffffffc);
  *(uint *)(param_1 + 0x24) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0xfffffffe | 1;
  *(undefined4 *)(iVar4 + 0x28) = 0;
  return;
}

