/* Decompiled C draft; module arm9; ROM address 02035228. No matching claim. */
#include "types.h"
#include "deps/02035228_func_02035228.h"

void func_02035228(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = *piRam02035278;
  iVar3 = *(int *)(iVar1 + 0x80);
  if (param_1 == 0) {
    uVar2 = 0xf;
  }
  else {
    uVar2 = 0xe;
  }
  *(int *)(*(int *)(iVar1 + 0x60) + iRam0203527c) = param_1;
  func_02124100(iVar3 + 4,uVar2,*(undefined4 *)(iVar1 + 0x5c),*(undefined4 *)(iVar1 + 0x60),
                *(undefined4 *)(iVar1 + 0x54));
  func_02124100(iVar3,uVar2,*(undefined4 *)(iVar1 + 0x5c),*(undefined4 *)(iVar1 + 0x60),
                *(undefined4 *)(iVar1 + 0x54));
  return;
}

