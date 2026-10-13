/* Decompiled C draft; module arm9_ov001; ROM address 021a03a0. No matching claim. */
#include "types.h"
#include "deps/021a03a0_FUN_021a03a0.h"

void FUN_021a03a0(void)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = DAT_021a03f4;
  *(undefined4 *)(*DAT_021a03f4 + 100) = 8;
  *(undefined4 *)(*piVar1 + 0x68) = 0;
  func_0x021282c8();
  if (*(int *)(*DAT_021a03f4 + 0xbc) == 1) {
    uVar2 = func_0x02029608();
    func_0x02105584(4,10,uVar2);
    return;
  }
  if (*(int *)(*DAT_021a03f4 + 0xbc) != 2) {
    return;
  }
  uVar2 = func_0x02029608();
  func_0x02105584(0,10,uVar2);
  return;
}

