/* Decompiled C draft; module arm9_ov003; ROM address 021c85a0. No matching claim. */
#include "types.h"
#include "deps/021c85a0_FUN_021c85a0.h"

void FUN_021c85a0(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  uint uVar6;
  undefined4 local_20;
  
  iVar1 = func_0x02147d30(*DAT_021c86fc,0x1d);
  iVar2 = func_0x02147cd8(*DAT_021c86fc,0x1d);
  uVar3 = 0x34 - iVar2;
  if (*(int *)(*DAT_021c8700 + 0x34) != 0) {
    if (iVar1 == 0) {
      local_20 = 0x26;
    }
    else {
      local_20 = DAT_021c8704;
    }
    puVar4 = *(uint **)(*DAT_021c8700 + 0x34);
    *puVar4 = (local_20 & DAT_021c8708) << 0x10 | *puVar4 & DAT_021c870c | uVar3 & 0xff;
  }
  iVar5 = 0;
  iVar2 = 0;
  uVar6 = uVar3;
  do {
    puVar4 = *(uint **)(*DAT_021c8700 + iVar2 + 0x18);
    *puVar4 = ((**(uint **)(*DAT_021c8700 + iVar2 + 0x18) & DAT_021c8710) >> 0x10 & DAT_021c8708) <<
              0x10 | *puVar4 & DAT_021c870c | uVar6 & 0xff;
    iVar2 = iVar2 + 4;
    iVar5 = iVar5 + 1;
    uVar6 = uVar6 + 0x1d;
  } while (iVar5 < 5);
  if (iVar1 < 3) {
    puVar4 = *(uint **)(*DAT_021c8700 + 0x2c);
    *puVar4 = ((**(uint **)(*DAT_021c8700 + 0x2c) & DAT_021c8710) >> 0x10 & DAT_021c8708) << 0x10 |
              *puVar4 & DAT_021c870c | uVar3 + (2 - iVar1) * 0x1d & 0xff;
  }
  else {
    **(uint **)(*DAT_021c8700 + 0x2c) =
         **(uint **)(*DAT_021c8700 + 0x2c) & DAT_021c870c | DAT_021c8714;
  }
  if ((iVar1 < 2) || (6 < iVar1)) {
    **(uint **)(*DAT_021c8700 + 0x30) =
         **(uint **)(*DAT_021c8700 + 0x30) & DAT_021c870c | DAT_021c8714;
  }
  else {
    puVar4 = *(uint **)(*DAT_021c8700 + 0x30);
    *puVar4 = ((**(uint **)(*DAT_021c8700 + 0x30) & DAT_021c8710) >> 0x10 & DAT_021c8708) << 0x10 |
              *puVar4 & DAT_021c870c | uVar3 + (6 - iVar1) * 0x1d & 0xff;
  }
  *(undefined1 *)(*DAT_021c8700 + 0x44) = 1;
  return;
}

