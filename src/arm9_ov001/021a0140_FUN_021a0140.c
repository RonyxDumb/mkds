/* Decompiled C draft; module arm9_ov001; ROM address 021a0140. No matching claim. */
#include "types.h"
#include "deps/021a0140_FUN_021a0140.h"

void FUN_021a0140(void)

{
  undefined4 uVar1;
  
  if (*(int *)(*DAT_021a018c + 0xbc) == 1) {
    uVar1 = func_0x02029608();
    func_0x02105550(4,uVar1);
  }
  else if (*(int *)(*DAT_021a018c + 0xbc) == 2) {
    uVar1 = func_0x02029608();
    func_0x02105550(0,uVar1);
  }
  FUN_021a64a0();
  func_0x02036ab0(*(undefined4 *)(*DAT_021a018c + 0x5c));
  *DAT_021a018c = 0;
  return;
}

