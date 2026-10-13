/* Decompiled C draft; module arm7; ROM address 037fbb00. No matching claim. */
#include "types.h"
#include "deps/037fbb00_FUN_037fbb00.h"

void FUN_037fbb00(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  undefined1 uVar3;
  uint uVar4;
  
  *DAT_037fbb58 = param_1;
  uVar2 = DAT_037fbb60;
  iVar1 = DAT_037fbb5c;
  uVar4 = 0;
  do {
    if ((1 << (uVar4 & 0xff) & uVar2) != 0) {
      uVar3 = FUN_037fba94(*(undefined1 *)(iVar1 + uVar4),*(undefined1 *)(uVar4 * 0x10 + 0x4000402))
      ;
      *(undefined1 *)(uVar4 * 0x10 + 0x4000400) = uVar3;
    }
    uVar4 = uVar4 + 1;
  } while ((int)uVar4 < 0x10);
  return;
}

