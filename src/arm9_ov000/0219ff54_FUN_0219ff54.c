/* Decompiled C draft; module arm9_ov000; ROM address 0219ff54. No matching claim. */
#include "types.h"
#include "deps/0219ff54_FUN_0219ff54.h"

int FUN_0219ff54(int param_1,undefined4 param_2,undefined2 param_3)

{
  int *piVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_20;
  uint local_1c;
  
  iVar3 = *DAT_021a0048;
  if ((*(char *)(iVar3 + 0x17) != '\0') && (*(int *)(iVar3 + 0x20) == param_1)) {
    return 0;
  }
  *(undefined1 *)(iVar3 + 0x17) = 1;
  piVar1 = DAT_021a0048;
  *(int *)(*DAT_021a0048 + 0x20) = param_1;
  *(undefined4 *)(*piVar1 + DAT_021a004c) = 0;
  *(undefined4 *)(*piVar1 + DAT_021a0050) = 0;
  FUN_021a4818(*(undefined4 *)(*piVar1 + 0x10));
  piVar1 = DAT_021a0048;
  *(undefined4 *)(*DAT_021a0048 + DAT_021a0054) = 0;
  *(int *)(*piVar1 + (*(byte *)(*piVar1 + 0x14) + 1) * 4 + 0xf4) = param_1;
  *(undefined4 *)(*piVar1 + (*(byte *)(*piVar1 + 0x14) + 1) * 4 + 0x24) = param_2;
  *(undefined2 *)(*piVar1 + (*(byte *)(*piVar1 + 0x14) + 1) * 2 + 0xa4) = param_3;
  *(undefined4 *)(*piVar1 + DAT_021a0058) = param_2;
  *(undefined2 *)(*piVar1 + DAT_021a005c) = param_3;
  iVar5 = *piVar1;
  uVar2 = FUN_0219ea48();
  iVar3 = DAT_021a0060;
  *(undefined1 *)(iVar5 + *(byte *)(iVar5 + 0x14) + 1 + DAT_021a0060) = uVar2;
  iVar5 = *DAT_021a0048;
  local_1c = (uint)*(byte *)(iVar5 + *(byte *)(iVar5 + 0x14) + 1 + iVar3);
  iVar3 = 1;
  local_20 = param_1;
  if (*(char *)(iVar5 + 0x14) != '\0') {
    iVar5 = 2;
    iVar6 = 4;
    do {
      iVar4 = *DAT_021a0048 + iVar6;
      iVar4 = FUN_021a0ae8(7,*(undefined4 *)(iVar4 + 0xf4),*(undefined4 *)(iVar4 + 0x24),
                           *(undefined2 *)(*DAT_021a0048 + iVar5 + 0xa4),&local_20,2);
      if (iVar4 != 0) {
        return iVar4;
      }
      iVar5 = iVar5 + 2;
      iVar6 = iVar6 + 4;
      iVar3 = iVar3 + 1;
    } while (iVar3 <= (int)(uint)*(byte *)(*DAT_021a0048 + 0x14));
  }
  FUN_0219e8b8(1);
  return 0;
}

