/* Decompiled C draft; module arm9; ROM address 020799a0. No matching claim. */
#include "types.h"
#include "deps/020799a0_DetermineIsP_from_thumb.h"

undefined4 DetermineIsP_from_thumb(uint param_1)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  
  bVar1 = true;
  bVar4 = true;
  bVar3 = true;
  bVar2 = true;
  iVar5 = *piRam02079a00;
  if ((param_1 != (int)*(char *)(iVar5 + 0x62)) && (param_1 != *(byte *)(iVar5 + 99))) {
    bVar2 = false;
  }
  if ((!bVar2) && (*(int *)(iVar5 + 8) != 4)) {
    bVar3 = false;
  }
  if ((!bVar3) && (iVar5 = IsAwardOrStaffRoll_0(), iVar5 == 0)) {
    bVar4 = false;
  }
  if ((!bVar4) && (*(int *)(*piRam02079a00 + 8) != 1)) {
    bVar1 = false;
  }
  if (bVar1) {
    return 1;
  }
  return 0;
}

