/* Decompiled C draft; module arm9_ov000; ROM address 0218c8ac. No matching claim. */
#include "types.h"
#include "deps/0218c8ac_FUN_0218c8ac.h"

int FUN_0218c8ac(uint param_1)

{
  int iVar1;
  
  iVar1 = 5;
  if ((param_1 & 2) != 0) {
    iVar1 = 9;
  }
  if ((param_1 & 8) != 0) {
    iVar1 = iVar1 + 4;
  }
  if ((param_1 & 0x10) != 0) {
    iVar1 = iVar1 + 2;
  }
  if ((param_1 & 0x20) != 0) {
    iVar1 = iVar1 + 2;
  }
  return iVar1;
}

