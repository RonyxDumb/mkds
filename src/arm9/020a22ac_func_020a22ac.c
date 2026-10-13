/* Decompiled C draft; module arm9; ROM address 020a22ac. No matching claim. */
#include "types.h"
#include "deps/020a22ac_func_020a22ac.h"

void func_020a22ac(int param_1)

{
  int iVar1;
  
  iVar1 = IsAwardOrStaffRoll();
  if (iVar1 != 1) {
    return;
  }
  GetDriverEntry(param_1);
  iVar1 = func_01ffc67c();
  if (iVar1 == 0) {
    *(undefined4 *)
     (param_1 * 0x70 +
      (*(uint *)(uRam020a22fc & 0xfffffffc) >> (uRam020a22fc & 3) * 8 |
      *(uint *)(uRam020a22fc & 0xfffffffc) << (uRam020a22fc & 3) * -8 + 0x20) + 100) = 10;
    return;
  }
  return;
}

