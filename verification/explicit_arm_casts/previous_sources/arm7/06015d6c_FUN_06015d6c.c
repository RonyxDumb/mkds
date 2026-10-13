/* Decompiled C draft; module arm7; ROM address 06015d6c. No matching claim. */
#include "types.h"
#include "deps/06015d6c_FUN_06015d6c.h"

undefined4 FUN_06015d6c(int param_1)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  ushort *puVar5;
  uint uVar6;
  
  FUN_0600e8a0(*(undefined2 *)(param_1 + 2));
  FUN_06009678();
  uVar2 = FUN_060096c4(param_1 + 0x33);
  uVar6 = 0;
  uVar3 = uVar2;
  puVar5 = (ushort *)(param_1 + 0x34);
  while( true ) {
    if (uVar2 >> 1 <= uVar6) {
      if (((uVar2 & 1) == 0) || (uVar1 = FUN_06009648(), (*puVar5 & 0xff) == (uVar1 & 0xff))) {
        uVar4 = 1;
      }
      else {
        uVar4 = 0;
      }
      return uVar4;
    }
    uVar3 = FUN_06009648(uVar3);
    if (*puVar5 != uVar3) break;
    uVar6 = uVar6 + 1;
    puVar5 = puVar5 + 1;
  }
  return 0;
}

