/* Decompiled C draft; module arm9; ROM address 0204eca0. No matching claim. */
#include "types.h"
#include "deps/0204eca0_func_0204eca0.h"

void func_0204eca0(void)

{
  int *piVar1;
  
  piVar1 = piRam0204ecd4;
  *(undefined4 *)(*piRam0204ecd4 + 0xc) = 0x2d;
  *(undefined4 *)(*piVar1 + 0x10) = 1;
  func_02006974();
  piVar1 = piRam0204ecd4;
  *(ushort *)(*piRam0204ecd4 + iRam0204ecd8) =
       *(ushort *)(*piRam0204ecd4 + iRam0204ecd8) & (ushort)uRam0204ecdc;
  *(undefined4 *)(*piVar1 + 0x10) = 0;
  return;
}

