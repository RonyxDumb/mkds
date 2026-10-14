/* Decompiled C draft; module arm7; ROM address 0600d3a0. No matching claim. */
#include "types.h"
#include "deps/0600d3a0_FUN_0600d3a0.h"

void FUN_0600d3a0(void)

{
  uint uVar1;
  undefined2 *puVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  short *psVar7;
  
  *DAT_0600d4b4 = 8;
  if (((int)((uint)*(ushort *)
                    ((*(uint *)(DAT_0600d4b8 & 0xfffffffc) >> (DAT_0600d4b8 & 3) * 8 |
                     *(uint *)(DAT_0600d4b8 & 0xfffffffc) << (DAT_0600d4b8 & 3) * -8 + 0x20) + 0x33a
                    ) << 0x1b) < 0) && ((*DAT_0600d4bc & 1) == 0)) {
    *DAT_0600d4c0 = *DAT_0600d4c0 ^ 1;
  }
  puVar2 = DAT_0600d4c8;
  uVar4 = *(uint *)(DAT_0600d4b8 & 0xfffffffc) >> (DAT_0600d4b8 & 3) * 8 |
          *(uint *)(DAT_0600d4b8 & 0xfffffffc) << (DAT_0600d4b8 & 3) * -8 + 0x20;
  if ((*(ushort *)(uVar4 + 0x690) & 8) != 0) {
    iVar5 = uVar4 + DAT_0600d4c4;
    uVar6 = 0;
    do {
      if ((((*(short *)(iVar5 + uVar6 * 0x14) != 0) &&
           (uVar3 = iVar5 + uVar6 * 0x14 + 8, uVar1 = uVar3 & 3,
           uVar3 = *(uint *)(uVar3 & 0xfffffffc),
           uVar3 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20,
           (*(ushort *)(uVar3 + 0xc) & 0x4000) != 0)) && ((*(ushort *)(uVar3 + 4) & 0xff) != 0)) &&
         ((psVar7 = (short *)(uVar3 + *(ushort *)(uVar3 + 10) + 5 & 0xfffffffe), *psVar7 == 0 &&
          (psVar7[1] == 0)))) {
        *(undefined2 *)(uVar3 + 4) = 0;
        *puVar2 = 0;
        *puVar2 = 0x8000;
        *(short *)(uVar4 + 0x3fe) = *(short *)(uVar4 + 0x3fe) + 1;
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < 3);
  }
  return;
}

