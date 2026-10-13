/* Decompiled C draft; module arm9_ov000; ROM address 02184b68. No matching claim. */
#include "types.h"
#include "deps/02184b68_FUN_02184b68.h"

void FUN_02184b68(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  iVar1 = func_0x02036bec(param_1,8);
  *DAT_02184ba4 = iVar1;
  *(undefined4 *)(iVar1 + 4) = param_1;
  FUN_02184b4c();
  uVar2 = func_ov000_021804f4();
  uVar3 = func_ov000_021804e0();
  func_0x0202ab2c(param_1,uVar2,uVar3);
  func_0x0212a910(1,1);
  return;
}

