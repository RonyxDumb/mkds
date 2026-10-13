/* Decompiled C draft; module arm9_ov000; ROM address 021a8f84. No matching claim. */
#include "types.h"
#include "deps/021a8f84_FUN_021a8f84.h"

undefined4 * FUN_021a8f84(undefined4 param_1)

{
  undefined4 *puVar1;
  uint *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  
  uVar3 = FUN_021a88e4();
  if (uVar3 == 0) {
    return (undefined4 *)0x0;
  }
  func_0x0200c858(DAT_021a8fe8,param_1,DAT_021a8fec);
  puVar4 = DAT_021a8ff0;
  *DAT_021a8ff0 = DAT_021a8fe8;
  puVar4[1] = 0;
  *(undefined2 *)(puVar4 + 2) = 2;
  *(undefined2 *)((int)puVar4 + 10) = 4;
  puVar1 = DAT_021a8ff4;
  puVar4[3] = DAT_021a8ff4;
  puVar2 = DAT_021a8ff8;
  *puVar1 = DAT_021a8ff8;
  puVar1[1] = 0;
  *puVar2 = uVar3 << 0x18 & DAT_021a8ffc |
            uVar3 << 8 & DAT_021a9000 | uVar3 >> 0x18 | uVar3 >> 8 & DAT_021a9004;
  return puVar4;
}

