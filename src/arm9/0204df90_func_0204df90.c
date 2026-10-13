/* Decompiled C draft; module arm9; ROM address 0204df90. No matching claim. */
#include "types.h"
#include "deps/0204df90_func_0204df90.h"

void func_0204df90(void)

{
  int *piVar1;
  
  piVar1 = piRam0204dfd4;
  *(undefined4 *)(*piRam0204dfd4 + 0xc) = 0x1a;
  *(undefined4 *)(*piVar1 + 0x10) = 1;
  func_02007ec4(*(undefined4 *)(*piVar1 + 0x24),uRam0204dfd8,0x36,0,0);
  piVar1 = piRam0204dfd4;
  *(ushort *)(*(int *)(*piRam0204dfd4 + 0x24) + 0x48) =
       *(short *)(*(int *)(*piRam0204dfd4 + 0x24) + 0x48) + 7U & (ushort)uRam0204dfdc;
  *(undefined4 *)(*piVar1 + 0x10) = 0;
  return;
}

