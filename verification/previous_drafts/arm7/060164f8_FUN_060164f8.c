/* Decompiled C draft; module arm7; ROM address 060164f8. No matching claim. */
#include "types.h"
#include "deps/060164f8_FUN_060164f8.h"

void FUN_060164f8(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(DAT_0601655c & 0xfffffffc) >> (DAT_0601655c & 3) * 8 |
          *(uint *)(DAT_0601655c & 0xfffffffc) << (DAT_0601655c & 3) * -8 + 0x20;
  uVar1 = *(undefined2 *)(param_1 + 2);
  iVar2 = FUN_0600e918(uVar1);
  if (iVar2 == 0x40) {
    FUN_0600eadc(uVar1);
    if (*(short *)(uVar3 + 0x1a8) != 0) {
      FUN_0601536c(1);
    }
    if (*(short *)(uVar3 + 0x19c) != 0) {
      FUN_0601536c(0);
    }
  }
  return;
}

