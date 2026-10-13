/* Decompiled C draft; module arm9_ov000; ROM address 0219ea88. No matching claim. */
#include "types.h"
#include "deps/0219ea88_FUN_0219ea88.h"

void FUN_0219ea88(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = DAT_0219eac0;
  do {
    if (*(int *)(iVar1 + 4) != 0) {
      FUN_021a3704(4,*(int *)(iVar1 + 4),0);
    }
    iVar1 = iVar1 + 0xc;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x9a);
  func_0x0214d018(0,(undefined4 *)(uintptr_t)(DAT_0219eac0),DAT_0219eac4);
  return;
}

