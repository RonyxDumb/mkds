/* Decompiled C draft; module arm9_ov000; ROM address 0219f8b0. No matching claim. */
#include "types.h"
#include "deps/0219f8b0_FUN_0219f8b0.h"

void FUN_0219f8b0(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  piVar1 = DAT_0219f92c;
  iVar5 = 1;
  iVar2 = *DAT_0219f92c;
  if (*(char *)(iVar2 + 0xd) != '\0') {
    iVar4 = 2;
    iVar3 = 4;
    do {
      iVar2 = *piVar1;
      iVar2 = FUN_021a0ae8(10,*(undefined4 *)(iVar2 + iVar3 + 0xf4),
                           *(undefined4 *)(iVar2 + iVar3 + 0x24),
                           *(undefined2 *)(iVar2 + iVar4 + 0xa4),(undefined4 *)(uintptr_t)(iVar2 + DAT_0219f930),
                           *(int *)(iVar2 + DAT_0219f930) + 1);
      if (iVar2 != 0) {
        return;
      }
      iVar4 = iVar4 + 2;
      iVar3 = iVar3 + 4;
      iVar5 = iVar5 + 1;
      iVar2 = *piVar1;
    } while (iVar5 <= (int)(uint)*(byte *)(iVar2 + 0xd));
  }
  *(undefined1 *)(iVar2 + 0x17) = 0;
  piVar1 = DAT_0219f92c;
  *(undefined4 *)(*DAT_0219f92c + 0x20) = 0;
  *(undefined1 *)(*piVar1 + DAT_0219f934) = 1;
  FUN_021988e8(**(undefined4 **)(*piVar1 + 4));
  *(undefined1 *)(*DAT_0219f92c + DAT_0219f934) = 0;
  return;
}

