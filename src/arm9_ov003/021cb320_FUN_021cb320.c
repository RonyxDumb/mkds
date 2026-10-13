/* Decompiled C draft; module arm9_ov003; ROM address 021cb320. No matching claim. */
#include "types.h"
#include "deps/021cb320_FUN_021cb320.h"

void FUN_021cb320(int param_1)

{
  char cVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  cVar1 = *DAT_021cb3bc;
  iVar3 = FUN_021c20a8(1);
  cVar2 = *(char *)(param_1 + cVar1 * 4 + DAT_021cb3c0 + iVar3 * 0x10);
  if (cVar2 != -1) {
    if (cVar2 == '\0') {
      *DAT_021cb3c4 = cVar1;
    }
    if (cVar2 == -2) {
      *DAT_021cb3bc = *DAT_021cb3c4;
    }
    else {
      *DAT_021cb3bc = cVar2;
    }
    FUN_021cdc10(8);
    iVar3 = FUN_021c20a8(1);
    iVar4 = FUN_021c20a8(1);
    iVar5 = FUN_021c20a8(1);
    iVar6 = FUN_021c20a8(1);
    iVar7 = *DAT_021cb3bc * 8;
    FUN_021bf6c8(*(undefined2 *)(iVar7 + DAT_021cb3c8 + iVar3 * 0x20),
                 *(undefined2 *)(iVar7 + DAT_021cb3cc + iVar4 * 0x20),
                 *(undefined2 *)(iVar7 + DAT_021cb3d0 + iVar5 * 0x20),
                 *(undefined2 *)(iVar7 + DAT_021cb3d4 + iVar6 * 0x20));
  }
  return;
}

