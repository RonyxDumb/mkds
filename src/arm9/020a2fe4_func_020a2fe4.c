/* Decompiled C draft; module arm9; ROM address 020a2fe4. No matching claim. */
#include "types.h"
#include "deps/020a2fe4_func_020a2fe4.h"

int func_020a2fe4(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  func_02100138(0x6c);
  iVar1 = func_0209bbfc();
  if (iVar1 != 0) {
    uVar2 = param_2[1];
    uVar3 = param_2[2];
    *(undefined4 *)(iVar1 + 0xb0) = *param_2;
    *(undefined4 *)(iVar1 + 0xb4) = uVar2;
    *(undefined4 *)(iVar1 + 0xb8) = uVar3;
    *(undefined4 *)(iVar1 + 4) = *(undefined4 *)(iVar1 + 0xb0);
    *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(iVar1 + 0xb4);
    *(undefined4 *)(iVar1 + 0xc) = *(undefined4 *)(iVar1 + 0xb8);
    *(undefined4 *)(iVar1 + 0xd0) = 0;
    *(undefined4 *)(iVar1 + 0xd4) = 0;
    *(undefined4 *)(iVar1 + 0xd8) = 0;
    *(undefined4 *)(iVar1 + 0xdc) = 0;
    *(undefined4 *)(iVar1 + 0xe0) = 0;
    *(undefined4 *)(iVar1 + 0xa8) = param_1;
    *(undefined4 *)(iVar1 + 0xfc) = 0;
    return iVar1;
  }
  return 0;
}

