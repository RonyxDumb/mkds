/* Decompiled C draft; module arm7; ROM address 0380105c. No matching claim. */
#include "types.h"
#include "deps/0380105c_FUN_0380105c.h"

void FUN_0380105c(void)

{
  uint uVar1;
  uint uVar3;
  uint uVar2;
  
  uVar2 = DAT_038010b8;
  if (*DAT_038010b4 != 0) {
    uVar2 = DAT_038010bc;
  }
  uVar1 = *(uint *)(uVar2 & 0xfffffffc);
  uVar3 = FUN_0380084c();
  *DAT_038010c0 = (uint)(uVar3 != (uVar1 >> (uVar2 & 3) * 8 | uVar1 << (uVar2 & 3) * -8 + 0x20));
  return;
}

