/* Decompiled C draft; module arm9; ROM address 0204dfe0. No matching claim. */
#include "types.h"
#include "deps/0204dfe0_func_0204dfe0.h"

void func_0204dfe0(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = piRam0204e030;
  *(undefined4 *)(*piRam0204e030 + 0xc) = 0x23;
  *(undefined4 *)(*piVar1 + 0x10) = 1;
  iVar2 = func_0200b15c(param_1,*(undefined4 *)(*piVar1 + 0x24),uRam0204e034,0x36,0,0);
  piVar1 = piRam0204e030;
  *(undefined4 *)(*piRam0204e030 + 0x10) = 0;
  *(ushort *)(*(int *)(*piVar1 + 0x24) + 0x48) =
       *(short *)(*(int *)(*piVar1 + 0x24) + 0x48) + 7U & (ushort)uRam0204e038;
  if (iVar2 == 0) {
    func_02050e60(5);
  }
  return;
}

