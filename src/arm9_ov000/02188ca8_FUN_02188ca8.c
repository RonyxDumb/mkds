/* Decompiled C draft; module arm9_ov000; ROM address 02188ca8. No matching claim. */
#include "types.h"
#include "deps/02188ca8_FUN_02188ca8.h"

void FUN_02188ca8(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = -1;
  iVar1 = FUN_02188584(0x10);
  iVar2 = FUN_02188584(1);
  *(undefined1 *)(iVar2 + 0xb) = 1;
  iVar2 = FUN_02188528();
  if (iVar2 == 3) {
    if ((*(short *)(param_1 + 10) == 0) || (*(char *)(param_1 + 0xc) == '\0')) {
      FUN_02189e54(*(undefined2 *)(param_1 + 0x36));
    }
    else if ((*(short *)(param_1 + 10) == 1) || (*(char *)(param_1 + 0xc) == ' ')) {
      FUN_02189e54(*(undefined2 *)(param_1 + 0x36));
      iVar4 = FUN_02188bc0(param_1,*(undefined1 *)(iVar1 + DAT_02188d6c),iVar1 + DAT_02188d70);
    }
    else {
      iVar4 = FUN_02188bc0(param_1,*(undefined1 *)(iVar1 + DAT_02188d6c),iVar1 + DAT_02188d70);
    }
  }
  else {
    if ((iVar2 != 4) && (iVar2 != 5)) {
      return;
    }
    iVar4 = FUN_02188bc0(param_1,1,
                         iVar1 + DAT_02188d70 + (uint)*(byte *)(iVar1 + DAT_02188d74) * 0x24);
    if (-1 < iVar4) {
      iVar2 = (uint)*(byte *)(iVar1 + DAT_02188d74) * 0x24;
      *(byte *)(iVar1 + DAT_02188d70 + iVar2) = *(byte *)(iVar1 + DAT_02188d70 + iVar2) & 0xf0 | 1;
    }
  }
  if (-1 < iVar4) {
    uVar3 = FUN_02188b20(iVar4,param_1,iVar1);
    FUN_021889b0(uVar3,iVar1);
  }
  return;
}

