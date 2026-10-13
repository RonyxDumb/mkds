/* Decompiled C draft; module arm9_ov001; ROM address 0219c8ec. No matching claim. */
#include "types.h"
#include "deps/0219c8ec_FUN_0219c8ec.h"

void FUN_0219c8ec(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar2 = DAT_0219c94c;
  piVar1 = DAT_0219c948;
  iVar4 = 0;
  iVar3 = DAT_0219c944;
  do {
    iVar5 = *piVar1;
    if ((iVar4 == *(int *)(iVar5 + 8)) && (*(int *)(iVar5 + 0x20) != 0)) {
      *(undefined4 *)(*(int *)(iVar5 + iVar2) + (uint)*(byte *)(iVar3 + 1) * 0x40) = 1;
      *(undefined4 *)(*(int *)(*piVar1 + iVar2) + (uint)*(byte *)(iVar3 + 2) * 0x40) = 0;
    }
    else {
      *(undefined4 *)(*(int *)(iVar5 + iVar2) + (uint)*(byte *)(iVar3 + 1) * 0x40) = 0;
      *(undefined4 *)(*(int *)(*piVar1 + iVar2) + (uint)*(byte *)(iVar3 + 2) * 0x40) = 1;
    }
    iVar3 = iVar3 + 3;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 6);
  return;
}

