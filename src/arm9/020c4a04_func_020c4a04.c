/* Decompiled C draft; module arm9; ROM address 020c4a04. No matching claim. */
#include "types.h"
#include "deps/020c4a04_func_020c4a04.h"

void func_020c4a04(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  uVar5 = uRam020c4ab4;
  uVar1 = (*(uint *)(uRam020c4ab0 & 0xfffffffc) >> (uRam020c4ab0 & 3) * 8 |
          *(uint *)(uRam020c4ab0 & 0xfffffffc) << (uRam020c4ab0 & 3) * -8 + 0x20) + 8;
  uVar3 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  if ((uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) != 1) {
    return;
  }
  iVar7 = 0;
  iVar6 = 0;
  iVar2 = 0;
  do {
    iVar7 = iVar7 + 1;
    *(undefined4 *)
     (iVar6 + param_1 * 0x3c0 +
              (*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
              *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) + 0x20) = 0;
    uVar1 = uRam020c4ab4;
    iVar6 = iVar6 + 0x18;
  } while (iVar7 < 0x28);
  uVar4 = *(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
          *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20;
  uVar3 = uVar4 + param_1 * 0x40 + 0x790;
  uVar5 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  if (0 < (int)(uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20)) {
    do {
      *(undefined4 *)(param_1 * 0x40 + uVar4 + iVar2 * 4 + 0x7c4) = 0x28;
      uVar3 = uVar1 & 3;
      uVar5 = *(uint *)(uVar1 & 0xfffffffc);
      uVar4 = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20;
      iVar2 = iVar2 + 1;
      uVar3 = param_1 * 0x40 + uVar4 + 0x790;
      uVar5 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    } while (iVar2 < (int)(uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20));
  }
  *(undefined4 *)(uVar4 + param_1 * 4 + 4) = 1;
  return;
}

