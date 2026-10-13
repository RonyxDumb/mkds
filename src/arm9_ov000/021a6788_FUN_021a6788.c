/* Decompiled C draft; module arm9_ov000; ROM address 021a6788. No matching claim. */
#include "types.h"
#include "deps/021a6788_FUN_021a6788.h"

int FUN_021a6788(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = func_0x0200fca0();
  iVar2 = FUN_021a5b30();
  if (iVar2 == 0) {
    func_0x0200fcb4(uVar1);
    return 0;
  }
  iVar2 = FUN_021a65d8(param_1);
  if (iVar2 == 0) {
    func_0x0200fcb4(uVar1);
    return 0;
  }
  func_0x0200fcb4(uVar1);
  return iVar2 + 0x10;
}

