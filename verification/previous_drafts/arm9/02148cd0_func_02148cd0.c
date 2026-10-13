/* Decompiled C draft; module arm9; ROM address 02148cd0. No matching claim. */
#include "types.h"
#include "deps/02148cd0_func_02148cd0.h"

int func_02148cd0(uint param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if ((param_1 & 1) != 0) {
    iVar1 = 0x20000;
  }
  if ((param_1 & 2) != 0) {
    iVar1 = iVar1 + 0x20000;
  }
  if ((param_1 & 4) != 0) {
    iVar1 = iVar1 + 0x20000;
  }
  if ((param_1 & 8) != 0) {
    iVar1 = iVar1 + 0x20000;
  }
  if ((param_1 & 0x10) != 0) {
    iVar1 = iVar1 + 0x10000;
  }
  if ((param_1 & 0x20) != 0) {
    iVar1 = iVar1 + 0x4000;
  }
  if ((param_1 & 0x40) != 0) {
    iVar1 = iVar1 + 0x4000;
  }
  if ((param_1 & 0x80) != 0) {
    iVar1 = iVar1 + 0x8000;
  }
  if ((param_1 & 0x100) != 0) {
    iVar1 = iVar1 + 0x4000;
  }
  return iVar1;
}

