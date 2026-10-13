/* Decompiled C draft; module arm9; ROM address 0200a184. No matching claim. */
#include "types.h"
#include "deps/0200a184_func_0200a184.h"

undefined4 func_0200a184(void)

{
  byte *pbVar1;
  undefined4 extraout_r1;
  int iVar2;
  int iVar3;
  byte local_10 [16];
  
  pbVar1 = local_10;
  Os_GetMacAddress((undefined4)(uintptr_t)(local_10));
  iVar2 = 0;
  iVar3 = 0;
  do {
    iVar3 = iVar3 + (uint)*pbVar1;
    pbVar1 = pbVar1 + 1;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 6);
  MaybeBoundsCheck((iVar3 + *piRam0200a1b8) * 7,0x14);
  return extraout_r1;
}

