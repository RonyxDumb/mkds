/* Decompiled C draft; module arm9_ov001; ROM address 02187e00. No matching claim. */
#include "types.h"
#include "deps/02187e00_FUN_02187e00.h"

undefined4 FUN_02187e00(undefined2 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = func_0x020ac524(0xc9);
  if (iVar1 != 0) {
    func_0x020de9ec();
    *(undefined2 *)(iVar1 + 0xf2) = param_1;
    *(undefined2 *)(iVar1 + 0xf4) = param_1;
    *(undefined4 *)(iVar1 + 0xac) = 1;
    uVar2 = func_0x020fd338(iVar1,DAT_02187e44);
    return uVar2;
  }
  return 0;
}

