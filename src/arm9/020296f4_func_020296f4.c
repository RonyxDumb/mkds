/* Decompiled C draft; module arm9; ROM address 020296f4. No matching claim. */
#include "types.h"
#include "deps/020296f4_func_020296f4.h"

void func_020296f4(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  piVar2 = piRam02029754;
  piVar1 = piRam02029750;
  uVar5 = 0;
  do {
    iVar3 = func_021227f8(uVar5);
    if (iVar3 != 0) {
      iVar3 = func_02122778(uVar5);
      iVar4 = uVar5 * 0xc;
      iVar3 = iVar3 * 0x18;
      *(undefined4 *)(*piVar2 + iVar3) = *(undefined4 *)(*piVar1 + iVar4 + 0x20);
      *(undefined4 *)(*piVar2 + iVar3 + 4) = *(undefined4 *)(*piVar1 + iVar4 + 0x24);
      *(undefined4 *)(*piVar2 + iVar3 + 8) = *(undefined4 *)(*piVar1 + iVar4 + 0x28);
    }
    uVar5 = uVar5 + 1 & 0xff;
  } while (uVar5 < 4);
  return;
}

