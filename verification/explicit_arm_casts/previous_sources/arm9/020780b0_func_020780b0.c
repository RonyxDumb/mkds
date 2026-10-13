/* Decompiled C draft; module arm9; ROM address 020780b0. No matching claim. */
#include "types.h"
#include "deps/020780b0_func_020780b0.h"

void func_020780b0(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *piRam020780e8;
  iVar1 = (int)*(short *)(iVar2 + iRam020780ec);
  if (-1 < iVar1) {
    func_020787f4(0,*puRam020780f0);
    func_02078580(iVar2 + 0x58 + iVar1 * 0xb8,*piRam020780e8 + 0x24,0);
    func_01ff9234();
  }
  return;
}

