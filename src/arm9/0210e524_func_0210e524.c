/* Decompiled C draft; module arm9; ROM address 0210e524. No matching claim. */
#include "types.h"
#include "deps/0210e524_func_0210e524.h"

bool func_0210e524(void)

{
  undefined1 uVar1;
  uint uVar2;
  int iVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  
  uVar2 = GetCourseBgmEntry(0x29);
  uVar4 = (undefined1)uVar2;
  uVar5 = uVar4;
  uVar1 = func_0211127c();
  uVar6 = uVar5;
  Sound_MaybeSetActiveSdat(uRam0210e5e0);
  iVar3 = func_0210e98c(uVar1,uVar2 >> 0x10 & 0xff,uVar2 >> 0x18,1,uVar4,uVar5,uVar6);
  return iVar3 != 0;
}

