/* Decompiled C draft; module arm9; ROM address 020ac5e4. No matching claim. */
#include "types.h"
#include "deps/020ac5e4_func_020ac5e4.h"

void func_020ac5e4(undefined4 param_1)

{
  int iVar1;
  
  func_02100138(0x70);
  iVar1 = func_0209bbfc();
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 4) = 0;
    *(undefined4 *)(iVar1 + 8) = 0;
    *(undefined4 *)(iVar1 + 0xc) = 0;
    *(undefined4 *)(iVar1 + 0x10) = 0;
    *(undefined4 *)(iVar1 + 0x14) = 0;
    *(undefined4 *)(iVar1 + 0x18) = 0;
    *(undefined4 *)(iVar1 + 0xac) = param_1;
    *(undefined4 *)(iVar1 + 0xa0) = 0;
    *(undefined4 *)(iVar1 + 0xa4) = 0;
    *(undefined4 *)(iVar1 + 0xa8) = 0;
    *(undefined4 *)(iVar1 + 0xb0) = 0;
    return;
  }
  return;
}

