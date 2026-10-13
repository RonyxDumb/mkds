/* Decompiled C draft; module arm9; ROM address 0204e03c. No matching claim. */
#include "types.h"
#include "deps/0204e03c_func_0204e03c.h"

void func_0204e03c(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = piRam0204e06c;
  *(undefined4 *)(*piRam0204e06c + 0xc) = 0x22;
  *(undefined4 *)(*piVar1 + 0x10) = 1;
  *(undefined4 *)(*piVar1 + iRam0204e070) = 0;
  iVar2 = func_0200b610();
  if (iVar2 == 0) {
    func_02050e60(5);
  }
  return;
}

