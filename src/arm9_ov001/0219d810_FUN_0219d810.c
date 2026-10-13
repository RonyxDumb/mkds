/* Decompiled C draft; module arm9_ov001; ROM address 0219d810. No matching claim. */
#include "types.h"
#include "deps/0219d810_FUN_0219d810.h"

void FUN_0219d810(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  piVar1 = DAT_0219d854;
  iVar4 = 0;
  iVar2 = *(int *)(DAT_0219d84c + 4);
  iVar3 = DAT_0219d850;
  if (0 < iVar2) {
    do {
      iVar5 = *piVar1;
      if (iVar4 == *(int *)(iVar5 + 0xc)) {
        *(undefined4 *)(*(int *)(iVar5 + 0x34) + (uint)*(byte *)(iVar3 + 2) * 0x40) = 1;
      }
      else {
        *(undefined4 *)(*(int *)(iVar5 + 0x34) + (uint)*(byte *)(iVar3 + 2) * 0x40) = 0;
      }
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + 1;
    } while (iVar4 < iVar2);
  }
  return;
}

