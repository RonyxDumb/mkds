/* Decompiled C draft; module arm9; ROM address 020a72c8. No matching claim. */
#include "types.h"
#include "deps/020a72c8_func_020a72c8.h"

undefined4 func_020a72c8(uint param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  iVar1 = func_020a1154();
  if (iVar1 != 0) {
    MaybeUpdateDriverBalloonShineCount(param_1,0xffffffff);
    if (7 < param_2) {
      param_2 = param_1;
    }
    uVar2 = GetDriverEntry(param_1);
    uVar3 = GetDriverEntry(param_2);
    func_020a5608(uVar2,uVar3);
    return 1;
  }
  return 0;
}

