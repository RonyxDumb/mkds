/* Decompiled C draft; module arm7; ROM address 037fe40c. No matching claim. */
#include "types.h"
#include "deps/037fe40c_FUN_037fe40c.h"

void FUN_037fe40c(int param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  FUN_037fe088(param_1,param_2,0);
  uVar3 = param_1 + 0x3cU & 3;
  uVar2 = *(uint *)(param_1 + 0x3cU & 0xfffffffc);
  for (uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20; uVar3 != 0;
      uVar3 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) {
    iVar1 = FUN_037fcc14(uVar3);
    if (iVar1 != 0) {
      if (-1 < (int)param_3) {
        FUN_037fcc30(uVar3,param_3 & 0xff);
      }
      *(undefined1 *)(uVar3 + 0x22) = 1;
      FUN_037fcc24(uVar3);
    }
    uVar2 = uVar3 + 0x50 & 3;
    uVar3 = *(uint *)(uVar3 + 0x50 & 0xfffffffc);
  }
  return;
}

