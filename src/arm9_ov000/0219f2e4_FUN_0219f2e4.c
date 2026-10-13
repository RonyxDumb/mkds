/* Decompiled C draft; module arm9_ov000; ROM address 0219f2e4. No matching claim. */
#include "types.h"
#include "deps/0219f2e4_FUN_0219f2e4.h"

void FUN_0219f2e4(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 local_10 [2];
  
  local_10[0] = 0;
  iVar3 = *DAT_0219f33c;
  if (((*(char *)(iVar3 + 0x17) != '\0') && (*(int *)(iVar3 + 0x20) != 0)) &&
     (*(int *)(iVar3 + 0x20) != *(int *)(iVar3 + DAT_0219f340))) {
    iVar2 = *(byte *)(iVar3 + 0xd) + 1;
    FUN_021a0ae8(0xc,*(undefined4 *)(iVar3 + 0x20),*(undefined4 *)(iVar3 + iVar2 * 4 + 0x24),
                 *(undefined2 *)(iVar3 + iVar2 * 2 + 0xa4),local_10,1);
    piVar1 = DAT_0219f33c;
    *(undefined1 *)(*DAT_0219f33c + 0x17) = 0;
    *(undefined4 *)(*piVar1 + 0x20) = 0;
  }
  return;
}

