/* Decompiled C draft; module arm9; ROM address 0214b720. No matching claim. */
#include "types.h"
#include "deps/0214b720_func_0214b720.h"

void func_0214b720(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = func_0214903c();
  *piRam0214b80c = iVar2;
  puVar1 = puRam0214b818;
  if (iVar2 < 0x21) {
    if (iVar2 < 0x20) {
      if (iVar2 < 1) {
        return;
      }
      if (iVar2 != 0x10) {
        return;
      }
      *puRam0214b814 = uRam0214b810;
      *puVar1 = 0;
      return;
    }
  }
  else {
    if (iVar2 < 0x41) {
      if (iVar2 != 0x40) {
        return;
      }
      *puRam0214b814 = uRam0214b81c;
      *puVar1 = 0x4000;
      return;
    }
    if (iVar2 != 0x60) {
      return;
    }
  }
  *puRam0214b814 = uRam0214b820;
  *puVar1 = 0;
  return;
}

