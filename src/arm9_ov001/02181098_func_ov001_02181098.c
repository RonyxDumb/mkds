/* Decompiled C draft; module arm9_ov001; ROM address 02181098. No matching claim. */
#include "types.h"
#include "deps/02181098_func_ov001_02181098.h"

void func_ov001_02181098(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  piVar1 = piRam021810b8;
  iVar3 = *piRam021810b8;
  uVar2 = *(undefined4 *)(iVar3 + 0x20);
  *(undefined4 *)(iVar3 + 0x20) = *(undefined4 *)(iVar3 + 0x24);
  *(undefined4 *)(*piVar1 + 0x24) = uVar2;
  iVar3 = *piVar1;
  *(uint *)(iVar3 + 0x14) = (uint)(*(int *)(iVar3 + 0x14) == 0);
  return;
}

