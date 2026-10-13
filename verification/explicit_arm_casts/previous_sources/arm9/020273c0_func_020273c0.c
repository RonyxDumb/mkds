/* Decompiled C draft; module arm9; ROM address 020273c0. No matching claim. */
#include "types.h"
#include "deps/020273c0_func_020273c0.h"

void func_020273c0(void)

{
  int *piVar1;
  
  piVar1 = piRam02027418;
  *(undefined4 *)(*piRam02027418 + 0x68) = 0;
  *(undefined4 *)(*piVar1 + 0x8c) = 2;
  *(undefined4 *)(*piVar1 + 0x6c) = 8;
  func_02128310();
  func_02027424(3);
  func_02025f14(*piRam02027418 + 0xf8,2);
  func_02025f14(*piRam02027418 + iRam0202741c,2);
  func_02025f14(*piRam02027418 + iRam02027420,2);
  func_020789d4();
  return;
}

