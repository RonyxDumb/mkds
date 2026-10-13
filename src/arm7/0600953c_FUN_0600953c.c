/* Decompiled C draft; module arm7; ROM address 0600953c. No matching claim. */
#include "types.h"
#include "deps/0600953c_FUN_0600953c.h"

undefined4 FUN_0600953c(int param_1)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = param_1 + 8U & 3;
  uVar4 = *(uint *)(param_1 + 8U & 0xfffffffc);
  uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  if ((*(ushort *)(uVar5 - 4) == DAT_060095c4) && (*(ushort *)(uVar5 - 2) == DAT_060095c8)) {
    uVar3 = 0;
  }
  else {
    *(undefined2 *)(uVar5 + 10) = 1;
    uVar1 = (undefined2)DAT_060095c4;
    *(undefined2 *)(uVar5 - 4) = uVar1;
    uVar2 = (undefined2)DAT_060095c8;
    *(undefined2 *)(uVar5 - 2) = uVar2;
    uVar5 = param_1 + 8U & 3;
    uVar4 = *(uint *)(param_1 + 8U & 0xfffffffc);
    uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
    *(undefined2 *)(uVar5 + 0xc) = uVar1;
    *(undefined2 *)(uVar5 + 0xe) = uVar2;
    uVar5 = *(uint *)(DAT_060095cc & 0xfffffffc) >> (DAT_060095cc & 3) * 8 |
            *(uint *)(DAT_060095cc & 0xfffffffc) << (DAT_060095cc & 3) * -8 + 0x20;
    *(short *)(uVar5 + 0x3fa) = *(short *)(uVar5 + 0x3fa) + 1;
    uVar3 = 1;
  }
  return uVar3;
}

