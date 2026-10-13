/* Decompiled C draft; module arm9_ov003; ROM address 021baa68. No matching claim. */
#include "types.h"
#include "deps/021baa68_FUN_021baa68.h"

undefined4 FUN_021baa68(void)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = func_0x0200fca0();
  if ((*DAT_021baaa8 == 5) && (iVar2 = func_0x021a61c4(0,0,0), iVar2 == 3)) {
    *DAT_021baaa8 = 4;
    func_0x0200fcb4(uVar1);
    return 1;
  }
  func_0x0200fcb4(uVar1);
  return 0;
}

