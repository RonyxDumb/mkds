/* Decompiled C draft; module arm9; ROM address 0203c7cc. No matching claim. */
#include "types.h"
#include "deps/0203c7cc_GetPlayerTotalTime.h"

void GetPlayerTotalTime(int param_1,undefined1 *param_2,undefined1 *param_3,undefined2 *param_4)

{
  uint uVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar3 = *(uint *)(uRam0203c87c & 0xfffffffc) >> (uRam0203c87c & 3) * 8 |
          *(uint *)(uRam0203c87c & 0xfffffffc) << (uRam0203c87c & 3) * -8 + 0x20;
  uVar4 = uVar3 + 8;
  uVar1 = uVar4 & 3;
  uVar5 = *(uint *)(uVar4 & 0xfffffffc);
  uVar4 = param_1 * 0x8c +
          (*(uint *)(uRam0203c878 & 0xfffffffc) >> (uRam0203c878 & 3) * 8 |
          *(uint *)(uRam0203c878 & 0xfffffffc) << (uRam0203c878 & 3) * -8 + 0x20) + 0x14;
  bVar2 = true;
  if (((uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) == 2) &&
     (uVar3 = uVar3 + 0x18, uVar1 = uVar3 & 3, uVar3 = *(uint *)(uVar3 & 0xfffffffc),
     (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) == 1)) {
    bVar2 = false;
  }
  if (bVar2) {
    uVar3 = *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
            *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
    bVar2 = false;
    if (((uVar3 == 1) || (uVar3 == 2)) || (uVar3 == 3)) {
      bVar2 = true;
    }
    if (bVar2) {
      *param_2 = *(undefined1 *)(uVar4 + 0x22);
      *param_3 = *(undefined1 *)(uVar4 + 0x23);
      *param_4 = *(undefined2 *)(uVar4 + 0x20);
      return;
    }
  }
  *param_2 = 0;
  *param_3 = 0;
  *param_4 = 0;
  return;
}

