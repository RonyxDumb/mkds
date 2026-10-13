/* Decompiled C draft; module arm9; ROM address 02118414. No matching claim. */
#include "types.h"
#include "deps/02118414_func_02118414.h"

void func_02118414(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = piRam02118454;
  *(int *)(*piRam02118454 + 0x74) = *(int *)(*piRam02118454 + 0x74) + 1;
  iVar2 = *piVar1;
  if (0x4a < *(int *)(iVar2 + 0x74)) {
    *(short *)(iVar2 + 0x78) = *(short *)(iVar2 + 0x78) + 1;
    iVar2 = *piVar1;
    if (3 < *(short *)(iVar2 + 0x78)) {
      *(undefined2 *)(iVar2 + 0x78) = 0;
    }
    *(undefined4 *)(*piRam02118454 + 0x74) = 0;
    func_021187d4();
  }
  return;
}

