/* Decompiled C draft; module arm9; ROM address 0207c270. No matching claim. */
#include "types.h"
#include "deps/0207c270_func_0207c270.h"

void func_0207c270(undefined4 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = IsRacerFinishedRace(*(undefined2 *)(param_2 + 4));
  if (iVar1 != 0) {
    return;
  }
  uVar2 = (uint)*(ushort *)(param_2 + 4) * 0x210 +
          (*(uint *)(uRam0207c2e8 & 0xfffffffc) >> (uRam0207c2e8 & 3) * 8 |
          *(uint *)(uRam0207c2e8 & 0xfffffffc) << (uRam0207c2e8 & 3) * -8 + 0x20) + 0x30;
  uVar3 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if (((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) == 0xe) &&
     (uVar2 = param_2 + 8U & 3, uVar3 = *(uint *)(param_2 + 8U & 0xfffffffc),
     1 < *(ushort *)((uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) + 0x24))) {
    return;
  }
  func_0207c2ec(param_1,param_2);
  return;
}

