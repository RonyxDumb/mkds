/* Decompiled C draft; module arm9; ROM address 0200b15c. No matching claim. */
#include "types.h"
#include "deps/0200b15c_func_0200b15c.h"

undefined4
func_0200b15c(undefined4 param_1,int param_2,undefined2 param_3,undefined2 param_4,int param_5,
             int param_6)

{
  byte bVar1;
  int iVar2;
  byte bVar3;
  
  iVar2 = func_0200b1b0();
  if (iVar2 == 0) {
    return 0;
  }
  *(undefined2 *)(param_2 + 0x3c) = 0x10;
  bVar1 = 0;
  *(undefined1 *)(param_2 + 0x4a) = 0;
  *(undefined2 *)(param_2 + 0x4c) = param_3;
  *(undefined2 *)(param_2 + 0x4e) = param_4;
  if (param_6 != 0) {
    bVar1 = 8;
  }
  if (param_5 == 0) {
    bVar3 = 0;
  }
  else {
    bVar3 = 4;
  }
  *(byte *)(param_2 + 0x4b) = bVar3 | bVar1 | 1;
  return 1;
}

