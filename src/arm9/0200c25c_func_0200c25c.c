/* Decompiled C draft; module arm9; ROM address 0200c25c. No matching claim. */
#include "types.h"
#include "deps/0200c25c_func_0200c25c.h"

int func_0200c25c(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  if (*piRam0200c2d4 == 0) {
    return 0;
  }
  uVar2 = (uint)*(byte *)(param_1 + 2);
  if (piRam0200c2d8[1] < (int)uVar2) {
    return 0;
  }
  iVar3 = (param_2 + -1) * 0x20;
  Mem_CpuCopy8(param_1 + 3,*piRam0200c2d4 + iVar3 + *piRam0200c2d8 * uVar2);
  iVar1 = (param_2 + -1) * 4;
  *(uint *)(*piRam0200c2d4 + iRam0200c2dc + iVar1) =
       *(uint *)(*piRam0200c2d4 + iRam0200c2dc + iVar1) | 1 << uVar2;
  iVar1 = func_0200c20c(param_2);
  if (iVar1 != 0) {
    return *piRam0200c2d4 + iVar3;
  }
  return 0;
}

