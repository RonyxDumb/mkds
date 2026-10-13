/* Decompiled C draft; module arm7; ROM address 037ff590. No matching claim. */
#include "types.h"
#include "deps/037ff590_FUN_037ff590.h"

void FUN_037ff590(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  FUN_037fb260(DAT_037ff5f8,param_1,0x1180);
  *(undefined4 *)(param_1 + 0x11c0) = DAT_037ff5f8;
  iVar2 = 0;
  do {
    uVar1 = FUN_037fbb64(iVar2);
    *(undefined4 *)(param_1 + iVar2 * 4 + 0x1180) = uVar1;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x10);
  uVar1 = FUN_037fc8ac(0);
  *(undefined4 *)(param_1 + 0x11c4) = uVar1;
  return;
}

