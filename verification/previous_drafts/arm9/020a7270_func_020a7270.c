/* Decompiled C draft; module arm9; ROM address 020a7270. No matching claim. */
#include "types.h"
#include "deps/020a7270_func_020a7270.h"

void func_020a7270(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  iVar1 = func_020a1154();
  if (iVar1 != 0) {
    MaybeUpdateDriverBalloonShineCount(param_1,0xffffffff);
    uVar2 = GetDriverEntry(param_1);
    uVar3 = GetDriverEntry(param_1);
    func_020a5608(uVar2,uVar3);
    return;
  }
  return;
}

