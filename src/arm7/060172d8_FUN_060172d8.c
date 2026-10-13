/* Decompiled C draft; module arm7; ROM address 060172d8. No matching claim. */
#include "types.h"
#include "deps/060172d8_FUN_060172d8.h"

void FUN_060172d8(int param_1)

{
  uint uVar1;
  undefined2 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  short *psVar6;
  
  uVar5 = *(uint *)(DAT_060173f8 & 0xfffffffc) >> (DAT_060173f8 & 3) * 8 |
          *(uint *)(DAT_060173f8 & 0xfffffffc) << (DAT_060173f8 & 3) * -8 + 0x20;
  psVar6 = (short *)(uVar5 + DAT_060173fc);
  if ((((*(short *)(uVar5 + 0x350) == 2) || (*(short *)(uVar5 + 0x350) == 3)) && (*psVar6 == 0x51))
     && (uVar1 = (uint)(psVar6 + 0xc) & 3, uVar3 = *(uint *)((uint)(psVar6 + 0xc) & 0xfffffffc),
        iVar4 = FUN_0600a578((short *)(uintptr_t)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 0x10),(short *)(uintptr_t)(param_1 + 0x1e)
                            ), iVar4 != 0)) {
    FUN_0600983c();
    if (*(short *)(param_1 + 0x2e) == 0) {
      FUN_0600aabc(DAT_06017400 & *(ushort *)(param_1 + 0x30));
      FUN_060135f8(*(undefined2 *)(uVar5 + 0x3ae));
      FUN_0600a954((undefined2 *)(uintptr_t)(uVar5 + 0x3c6),(undefined2 *)(uintptr_t)(param_1 + 0x1e));
      uVar2 = FUN_0600ef30((ushort *)(uintptr_t)(param_1 + 0x1e));
      *(undefined2 *)(uVar5 + 0x3cc) = uVar2;
      FUN_0600ebbc(*(undefined2 *)(uVar5 + 0x3cc),0x40);
    }
    if (*(short *)(param_1 + 0x2e) == 0) {
      uVar1 = (uint)(psVar6 + 0xe) & 3;
      uVar3 = *(uint *)((uint)(psVar6 + 0xe) & 0xfffffffc);
      *(undefined2 *)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 4) = 0;
      uVar1 = (uint)(psVar6 + 0xe) & 3;
      uVar3 = *(uint *)((uint)(psVar6 + 0xe) & 0xfffffffc);
      *(undefined2 *)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 6) = 0;
      FUN_0600a970(0x40);
    }
    else {
      uVar1 = (uint)(psVar6 + 0xe) & 3;
      uVar3 = *(uint *)((uint)(psVar6 + 0xe) & 0xfffffffc);
      *(undefined2 *)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 4) = 0xc;
      uVar1 = (uint)(psVar6 + 0xe) & 3;
      uVar3 = *(uint *)((uint)(psVar6 + 0xe) & 0xfffffffc);
      *(undefined2 *)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 6) =
           *(undefined2 *)(param_1 + 0x2e);
    }
    uVar1 = (uint)(psVar6 + 0xe) & 3;
    uVar3 = *(uint *)((uint)(psVar6 + 0xe) & 0xfffffffc);
    *(undefined2 *)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 8) =
         *(undefined2 *)(uVar5 + 0x3ae);
    *psVar6 = 0x53;
    FUN_06008a8c(2,3);
  }
  return;
}

