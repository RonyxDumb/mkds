/* Decompiled C draft; module arm9; ROM address 0204c28c. No matching claim. */
#include "types.h"
#include "deps/0204c28c_func_0204c28c.h"

void func_0204c28c(undefined2 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = iRam0204c314;
  Fs_Initialize(0xffffffff);
  *(undefined2 *)(iVar2 + 0x30) = param_1;
  *(undefined4 *)(iVar2 + 4) = 0;
  *(undefined4 *)(iVar2 + 8) = 0;
  *(undefined4 *)(iVar2 + 0xc) = 0;
  *(undefined4 *)(iVar2 + 0x10) = param_2;
  *(undefined4 *)(iVar2 + 0x14) = param_3;
  *(undefined4 *)(iVar2 + 0x18) = param_4;
  *(undefined4 *)(iVar2 + 0x1c) = 0;
  *(undefined4 *)(iVar2 + 0x24) = 0;
  *(undefined4 *)(iVar2 + 0x20) = 0;
  *(undefined4 *)(iVar2 + 0x28) = 0;
  *(undefined4 *)(iVar2 + 0x2c) = 0xe;
  uVar1 = uRam0204c31c;
  *puRam0204c318 = 0;
  iVar2 = func_0214358c(param_1,uVar1);
  if (iVar2 != 0) {
    Os_Terminate();
    return;
  }
  return;
}

