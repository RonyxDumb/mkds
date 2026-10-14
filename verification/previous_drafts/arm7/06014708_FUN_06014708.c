/* Decompiled C draft; module arm7; ROM address 06014708. No matching claim. */
#include "types.h"
#include "deps/06014708_FUN_06014708.h"

void FUN_06014708(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar5;
  int iVar6;
  uint uVar4;
  
  iVar5 = (*(uint *)(DAT_06014790 & 0xfffffffc) >> (DAT_06014790 & 3) * 8 |
          *(uint *)(DAT_06014790 & 0xfffffffc) << (DAT_06014790 & 3) * -8 + 0x20) + DAT_06014794;
  iVar6 = iVar5 + param_1 * 0x14;
  thunk_FUN_037f8850(0x1000000);
  *DAT_0601479c = *(undefined2 *)(DAT_06014798 + param_1 * 2);
  if (*(short *)(iVar5 + param_1 * 0x14) != 0) {
    uVar4 = iVar6 + 0xcU & 3;
    uVar3 = *(uint *)(iVar6 + 0xcU & 0xfffffffc);
    uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
    if ((*(ushort *)(uVar4 + 0x14) & 0x4000) == 0) {
      uVar3 = iVar6 + 8U & 3;
      uVar1 = *(uint *)(iVar6 + 8U & 0xfffffffc);
      *(undefined2 *)(uVar4 + 0xc) =
           *(undefined2 *)((uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) + 4);
    }
    uVar4 = iVar6 + 8U & 3;
    uVar1 = *(uint *)(iVar6 + 8U & 0xfffffffc);
    uVar3 = iVar6 + 0xcU & 3;
    uVar2 = *(uint *)(iVar6 + 0xcU & 0xfffffffc);
    *(undefined2 *)((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + 0x2a) =
         *(undefined2 *)((uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20) + 0x22);
  }
  thunk_FUN_037f888c();
  return;
}

