/* Decompiled C draft; module arm9; ROM address 0202f688. No matching claim. */
#include "types.h"
#include "deps/0202f688_func_0202f688.h"

void func_0202f688(void)

{
  int *piVar1;
  uint *puVar2;
  undefined4 uVar3;
  int iVar4;
  
  puVar2 = puRam0202f71c;
  iVar4 = 0x16;
  if (*(int *)(*piRam0202f718 + 0x4c) != 4) {
    iVar4 = 0x1e;
  }
  *puRam0202f71c = *puRam0202f71c & uRam0202f720 | iVar4 << 8;
  piVar1 = piRam0202f718;
  *puRam0202f728 = *(int *)(*piRam0202f718 + 0x90) * -0x10000 & uRam0202f724;
  if (*(int *)(*piVar1 + 0x90) != 0) {
    *puVar2 = *puVar2 & uRam0202f72c | uRam0202f730;
    *puRam0202f734 = *puRam0202f734 & 0xffc0 | 0x3f;
    *puRam0202f738 = *puRam0202f738 & 0xffc0 | 0x27;
    uVar3 = *(undefined4 *)(*piVar1 + 0x90);
    *puRam0202f73c = 0xff;
    *puRam0202f740 = (short)uVar3 + 0xc0U & 0xff;
    return;
  }
  *puVar2 = *puVar2 & uRam0202f72c;
  return;
}

