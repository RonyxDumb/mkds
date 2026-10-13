/* Decompiled C draft; module arm9; ROM address 020e8368. No matching claim. */
#include "types.h"
#include "deps/020e8368_E7Fn2_5.h"

void E7Fn2_5(void)

{
  uint uVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  int local_10;
  int iStack_c;
  int iStack_8;
  
  iStack_c = piRam020e83f8[1];
  iStack_8 = piRam020e83f8[2];
  local_10 = *piRam020e83f8 +
             (*(uint *)(uRam020e83fc & 0xfffffffc) >> (uRam020e83fc & 3) * 8 |
             *(uint *)(uRam020e83fc & 0xfffffffc) << (uRam020e83fc & 3) * -8 + 0x20);
  func_02147288(&local_10,uRam020e8400,uRam020e8404);
  uVar2 = *puRam020e840c;
  iVar4 = (*(uint *)((uint)piRam020e8408 & 0xfffffffc) >> ((uint)piRam020e8408 & 3) * 8 |
          *(uint *)((uint)piRam020e8408 & 0xfffffffc) << ((uint)piRam020e8408 & 3) * -8 + 0x20) + 1;
  *piRam020e8408 = iVar4;
  if ((iVar4 <= (int)(uint)uVar2) &&
     (uVar3 = (*(uint *)(uRam020e8410 & 0xfffffffc) >> (uRam020e8410 & 3) * 8 |
              *(uint *)(uRam020e8410 & 0xfffffffc) << (uRam020e8410 & 3) * -8 + 0x20) + 0x48,
     uVar1 = uVar3 & 3, uVar3 = *(uint *)(uVar3 & 0xfffffffc),
     ((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0x800) == 0)) {
    return;
  }
  StateDualHandler_SetState(uRam020e8414,5);
  return;
}

