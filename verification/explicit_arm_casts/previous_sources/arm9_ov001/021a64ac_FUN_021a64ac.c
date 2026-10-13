/* Decompiled C draft; module arm9_ov001; ROM address 021a64ac. No matching claim. */
#include "types.h"
#include "deps/021a64ac_FUN_021a64ac.h"

void FUN_021a64ac(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = func_0x02036bec(param_1,0x10);
  *DAT_021a6508 = iVar1;
  uVar2 = func_0x0204799c(*DAT_021a650c);
  func_0x020b49bc(*DAT_021a6508,uVar2);
  uVar2 = func_0x0204799c(*DAT_021a6510);
  func_0x020b48b4(*DAT_021a6508 + 4,uVar2);
  uVar2 = func_0x0204799c(*DAT_021a6514);
  func_0x020b4a44(*DAT_021a6508 + 8,uVar2);
  uVar2 = func_0x0204799c(*DAT_021a6518);
  *(undefined4 *)(*DAT_021a6508 + 0xc) = uVar2;
  return;
}

