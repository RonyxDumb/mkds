/* Decompiled C draft; module arm7; ROM address 0600e85c. No matching claim. */
#include "types.h"
#include "deps/0600e85c_FUN_0600e85c.h"

undefined4 FUN_0600e85c(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_0600e808();
  if ((*(ushort *)(iVar1 + 0x10) & 2) == 0) {
    uVar2 = 10;
  }
  else {
    uVar2 = 0x14;
  }
  return uVar2;
}

