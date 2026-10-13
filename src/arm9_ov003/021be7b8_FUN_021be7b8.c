/* Decompiled C draft; module arm9_ov003; ROM address 021be7b8. No matching claim. */
#include "types.h"
#include "deps/021be7b8_FUN_021be7b8.h"

undefined4 FUN_021be7b8(void)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = func_0x0200fca0();
  if (*DAT_021be81c != 3) {
    iVar2 = FUN_021be9b8();
    if (iVar2 == 1) {
      *DAT_021be81c = 2;
      func_0x0200fcb4(uVar1);
      return 1;
    }
    func_0x0200fcb4(uVar1);
    return 0;
  }
  iVar2 = func_0x021a61e4();
  if (iVar2 != 3) {
    func_0x0200fcb4(uVar1);
    return 0;
  }
  *DAT_021be81c = 2;
  func_0x0200fcb4(uVar1);
  return 1;
}

