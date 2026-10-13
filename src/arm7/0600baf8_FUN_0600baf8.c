/* Decompiled C draft; module arm7; ROM address 0600baf8. No matching claim. */
#include "types.h"
#include "deps/0600baf8_FUN_0600baf8.h"

undefined4 FUN_0600baf8(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = *(uint *)(DAT_0600bba0 & 0xfffffffc) >> (DAT_0600bba0 & 3) * 8 |
          *(uint *)(DAT_0600bba0 & 0xfffffffc) << (DAT_0600bba0 & 3) * -8 + 0x20;
  if (param_1 < 4) {
    *(short *)(uVar2 + 0x334) = (short)param_1;
    if (param_1 == 0) {
      *(ushort *)(uVar2 + 0x3c0) = *(ushort *)(uVar2 + 0x3c0) & 0xffef;
      *(ushort *)(uVar2 + 0x3ce) = *(ushort *)(uVar2 + 0x3ce) & 0xbfff;
    }
    else {
      *(ushort *)(uVar2 + 0x3c0) = *(ushort *)(uVar2 + 0x3c0) | 0x10;
      *(ushort *)(uVar2 + 0x3ce) = *(ushort *)(uVar2 + 0x3ce) | 0x4000;
    }
    if ((*(short *)(uVar2 + 0x34c) == 0x40) && (param_1 == 1)) {
      uVar3 = (*(uint *)(DAT_0600bba0 & 0xfffffffc) >> (DAT_0600bba0 & 3) * 8 |
              *(uint *)(DAT_0600bba0 & 0xfffffffc) << (DAT_0600bba0 & 3) * -8 + 0x20) + 0x4ac;
      uVar1 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      *(undefined2 *)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 0x2e) =
           *(undefined2 *)(uVar2 + 0x3c0);
    }
    if (param_1 == 0) {
      param_1 = 1;
    }
    *DAT_0600bba4 = *DAT_0600bba4 & (ushort)DAT_0600bba8 | (ushort)(param_1 << 3);
    return 0;
  }
  return 5;
}

