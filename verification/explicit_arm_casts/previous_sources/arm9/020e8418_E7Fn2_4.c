/* Decompiled C draft; module arm9; ROM address 020e8418. No matching claim. */
#include "types.h"
#include "deps/020e8418_E7Fn2_4.h"

void E7Fn2_4(void)

{
  uint uVar1;
  undefined4 *puVar2;
  int *piVar3;
  uint uVar4;
  int local_18;
  int iStack_14;
  int iStack_10;
  
  puVar2 = puRam020e8498;
  if (*psRam020e8490 != *psRam020e8494) {
    uVar1 = iRam020e849c + 0xcU & 3;
    uVar4 = *(uint *)(iRam020e849c + 0xcU & 0xfffffffc);
    *(short *)((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) + 0x18) = *psRam020e8490 + -2;
  }
  piVar3 = piRam020e84a0;
  *puVar2 = 0;
  iStack_14 = piVar3[1];
  iStack_10 = piVar3[2];
  local_18 = *piVar3 + (*(uint *)(uRam020e84a4 & 0xfffffffc) >> (uRam020e84a4 & 3) * 8 |
                       *(uint *)(uRam020e84a4 & 0xfffffffc) << (uRam020e84a4 & 3) * -8 + 0x20);
  func_02147288(&local_18,uRam020e84ac,uRam020e84a8);
  return;
}

