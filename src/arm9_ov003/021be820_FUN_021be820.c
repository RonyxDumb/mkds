/* Decompiled C draft; module arm9_ov003; ROM address 021be820. No matching claim. */
#include "types.h"
#include "deps/021be820_FUN_021be820.h"

undefined4 FUN_021be820(void)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = func_0x0200fca0();
  if ((*DAT_021be85c == 7) && (iVar2 = func_0x021a5db0(), iVar2 == 3)) {
    *DAT_021be85c = 4;
    func_0x0200fcb4(uVar1);
    return 1;
  }
  func_0x0200fcb4(uVar1);
  return 0;
}

