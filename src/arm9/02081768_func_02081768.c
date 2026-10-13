/* Decompiled C draft; module arm9; ROM address 02081768. No matching claim. */
#include "types.h"
#include "deps/02081768_func_02081768.h"

void func_02081768(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = 0;
  iVar4 = param_1 * 0xc +
          (*(uint *)(uRam020817b4 & 0xfffffffc) >> (uRam020817b4 & 3) * 8 |
          *(uint *)(uRam020817b4 & 0xfffffffc) << (uRam020817b4 & 3) * -8 + 0x20);
  do {
    uVar2 = iVar4 + uVar3 * 4;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    if (uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0) {
      func_0208b710();
      *(undefined4 *)(iVar4 + uVar3 * 4) = 0;
    }
    uVar3 = uVar3 + 1 & 0xffff;
  } while (uVar3 < 3);
  return;
}

