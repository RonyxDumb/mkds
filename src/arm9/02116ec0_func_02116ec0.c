/* Decompiled C draft; module arm9; ROM address 02116ec0. No matching claim. */
#include "types.h"
#include "deps/02116ec0_func_02116ec0.h"

void func_02116ec0(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = iRam02116ef4;
  uVar3 = 0;
  do {
    iVar2 = func_020296d4(uVar3 & 0xffff);
    func_020294e8(uVar3 & 0xffff,*(undefined4 *)(iVar1 + iVar2 * 4));
    func_020294ac(uVar3 & 0xffff,1);
    uVar3 = uVar3 + 1;
  } while ((int)uVar3 < 8);
  return;
}

