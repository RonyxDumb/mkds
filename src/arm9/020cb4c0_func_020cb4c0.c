/* Decompiled C draft; module arm9; ROM address 020cb4c0. No matching claim. */
#include "types.h"
#include "deps/020cb4c0_func_020cb4c0.h"

void func_020cb4c0(void)

{
  int iVar1;
  
  iVar1 = func_02049b6c();
  if ((iVar1 == 0) &&
     (((iVar1 = GetPMaybeState_1(), iVar1 != 1 && (iVar1 = GetPMaybeState_1(), iVar1 != 2)) ||
      ((*(int *)(*piRam020cb508 + iRam020cb50c) != 0 &&
       (*(int *)(*piRam020cb508 + iRam020cb510) != 0)))))) {
    OamBuffer_SomeFn2_from_thumb(*piRam020cb508 + iRam020cb514,*piRam020cb508 + iRam020cb518);
  }
  return;
}

