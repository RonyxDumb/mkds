/* Decompiled C draft; module arm9; ROM address 0208b6d0. No matching claim. */
#include "types.h"
#include "deps/0208b6d0_func_0208b6d0.h"

void func_0208b6d0(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined1 auStack_10 [8];
  
  uVar1 = (*(code *)(*(uint *)(uRam0208b70c & 0xfffffffc) >> (uRam0208b70c & 3) * 8 |
                    *(uint *)(uRam0208b70c & 0xfffffffc) << (uRam0208b70c & 3) * -8 + 0x20))
                    (auStack_10,0);
  func_020184e4(uVar1,*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                      *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20);
  *param_1 = 0;
  return;
}

