/* Decompiled C draft; module arm9; ROM address 02128570. No matching claim. */
#include "types.h"
#include "deps/02128570_func_02128570.h"

void func_02128570(void)

{
  int iVar1;
  
  iVar1 = *piRam021285a4;
  if (*(int *)(iVar1 + iRam021285a8) != 0) {
    *(undefined4 *)(iVar1 + 8) = 3;
    func_02128624(0);
    return;
  }
  if (*(int *)(iVar1 + iRam021285ac) != 0) {
    *(undefined4 *)(iVar1 + 8) = 4;
  }
  return;
}

