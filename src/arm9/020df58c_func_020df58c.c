/* Decompiled C draft; module arm9; ROM address 020df58c. No matching claim. */
#include "types.h"
#include "deps/020df58c_func_020df58c.h"

void func_020df58c(void)

{
  ushort uVar1;
  ushort *puVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  uint uVar6;
  
  puVar5 = puRam020df618;
  uVar4 = uRam020df614;
  piVar3 = piRam020df610;
  puVar2 = puRam020df604;
  uVar1 = *puRam020df604;
  uVar6 = (uint)*(short *)(iRam020df608 + ((int)(uint)uVar1 >> 4) * 4);
  *puRam020df60c = (uVar6 << 0xe) >> 0xc | (uVar6 >> 0x12) << 0x14;
  *puVar2 = uVar1 + 0x2d8;
  *piVar3 = 0xf00 - ((int)uVar6 >> 4);
  *puVar5 = uVar4;
  puVar5[1] = uVar4;
  puVar5[2] = uVar4;
  return;
}

