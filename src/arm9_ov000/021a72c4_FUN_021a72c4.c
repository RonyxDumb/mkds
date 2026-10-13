/* Decompiled C draft; module arm9_ov000; ROM address 021a72c4. No matching claim. */
#include "types.h"
#include "deps/021a72c4_FUN_021a72c4.h"

int FUN_021a72c4(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = 0x80;
  if (*(short *)(param_1 + 2) != 0) {
    iVar5 = DAT_021a7324 + 0x80;
    iVar1 = FUN_021a8a54();
    iVar2 = FUN_021a8a54(*(undefined2 *)(param_1 + 8));
    iVar4 = FUN_021a72a4((undefined2 *)(uintptr_t)(param_1 + 0x10));
    iVar4 = iVar5 + iVar1 + iVar2 + iVar4;
  }
  if (*(short *)(param_1 + 6) != 0) {
    iVar4 = iVar4 + DAT_021a7328;
    iVar1 = FUN_021a8a54();
    iVar2 = FUN_021a8a54(*(undefined2 *)(param_1 + 10));
    iVar5 = FUN_021a8a54(*(undefined2 *)(param_1 + 0xc));
    iVar3 = FUN_021a72a4((undefined2 *)(uintptr_t)(param_1 + 0x14));
    iVar4 = iVar4 + iVar1 + iVar2 + iVar5 + iVar3;
  }
  return iVar4;
}

