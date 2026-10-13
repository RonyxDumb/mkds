/* Decompiled C draft; module arm9; ROM address 02017070. No matching claim. */
#include "types.h"
#include "deps/02017070_func_02017070.h"

void func_02017070(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                  int param_5)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  iVar1 = iRam020170c8;
  *(undefined4 *)(iRam020170c8 + 0xc) = param_1;
  *(undefined4 *)(iVar1 + 0x10) = param_2;
  *(undefined4 *)(iVar1 + 0x14) = param_3;
  *(undefined4 *)(iVar1 + 0x18) = param_4;
  func_02016d34();
  puVar3 = puRam020170d8;
  uVar2 = uRam020170d4;
  if (param_5 != 0) {
    *puRam020170d0 = uRam020170cc;
    *puVar3 = uVar2;
    return;
  }
  return;
}

