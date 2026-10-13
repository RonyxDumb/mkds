/* Decompiled C draft; module arm7; ROM address 0238015c. No matching claim. */
#include "types.h"
#include "deps/0238015c_FUN_0238015c.h"

void FUN_0238015c(void)

{
  undefined2 *puVar1;
  undefined2 uVar2;
  uint uVar3;
  ushort *puVar4;
  
  puVar1 = puRam02380194;
  uVar2 = 1;
  uVar3 = 0;
  puVar4 = puRam02380194 + -0x200000;
  do {
    *puVar1 = (short)uVar3;
    if (uVar3 != *puVar4) {
      uVar2 = 2;
      break;
    }
    uVar3 = uVar3 + 1;
  } while (uVar3 != 2);
  *puVar1 = uVar2;
  return;
}

