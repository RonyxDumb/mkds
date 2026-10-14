/* Decompiled C draft; module arm7; ROM address 037fe270. No matching claim. */
#include "types.h"
#include "deps/037fe270_FUN_037fe270.h"

void FUN_037fe270(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_037fe2e4();
  if (iVar1 != 0) {
    FUN_037fe2c4(iVar1,param_1);
    uVar2 = (uint)*(byte *)(param_1 + 8 + param_2);
    *(byte *)(DAT_037fe2c0 + uVar2 * 0x40) = *(byte *)(DAT_037fe2c0 + uVar2 * 0x40) & 0xfe;
    *(undefined1 *)(param_1 + 8 + param_2) = 0xff;
  }
  return;
}

