/* Decompiled C draft; module arm9; ROM address 0208b710. No matching claim. */
#include "types.h"
#include "deps/0208b710_func_0208b710.h"

void func_0208b710(undefined4 param_1)

{
  undefined4 uVar1;
  undefined1 auStack_10 [8];
  
  uVar1 = (*(code *)(*(uint *)(uRam0208b744 & 0xfffffffc) >> (uRam0208b744 & 3) * 8 |
                    *(uint *)(uRam0208b744 & 0xfffffffc) << (uRam0208b744 & 3) * -8 + 0x20))
                    (auStack_10,0);
  func_020184e4(uVar1,param_1);
  return;
}

