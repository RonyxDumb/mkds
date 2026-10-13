/* Decompiled C draft; module arm9; ROM address 02047634. No matching claim. */
#include "types.h"
#include "deps/02047634_SetMountData_from_thumb.h"

void SetMountData_from_thumb(undefined4 param_1,int param_2,int param_3,uint param_4,uint param_5)

{
  int iVar1;
  
  iVar1 = *piRam0204768c + iRam02047690 + param_2 * 0xc;
  *(undefined4 *)(*piRam0204768c + iRam02047690 + param_2 * 0xc) = param_1;
  *(undefined4 *)(iVar1 + 4) = 0;
  *(uint *)(iVar1 + 8) = *(uint *)(iVar1 + 8) & uRam02047694 | param_3 << 10 & uRam02047698;
  *(uint *)(iVar1 + 8) = *(uint *)(iVar1 + 8) & uRam0204769c | (param_4 & 1) << 0x1d;
  *(uint *)(iVar1 + 8) = *(uint *)(iVar1 + 8) & uRam020476a0 | (param_5 & 1) << 0x1e;
  *(uint *)(iVar1 + 8) = *(uint *)(iVar1 + 8) & uRam020476a4 | uRam020476a8;
  return;
}

