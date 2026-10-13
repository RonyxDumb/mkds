/* Decompiled C draft; module arm9; ROM address 020184e4. No matching claim. */
#include "types.h"
#include "deps/020184e4_func_020184e4.h"

void func_020184e4(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = func_0201e448(param_2 + 8);
  if (iVar1 != 0) {
    do {
      func_0201e494(param_1 + 0x1c);
      iVar1 = func_0201e448(param_2 + 8);
    } while (iVar1 != 0);
  }
  iVar1 = func_0201e448(param_2 + 0x14);
  if (iVar1 != 0) {
    do {
      func_0201e494(param_1 + 0x1c);
      iVar1 = func_0201e448(param_2 + 0x14);
    } while (iVar1 != 0);
  }
  func_0201e3c8(param_1 + 4,param_2);
  func_0201e494(param_1 + 0x10,param_2);
  return;
}

