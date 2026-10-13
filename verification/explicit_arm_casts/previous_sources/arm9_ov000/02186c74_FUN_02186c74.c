/* Decompiled C draft; module arm9_ov000; ROM address 02186c74. No matching claim. */
#include "types.h"
#include "deps/02186c74_FUN_02186c74.h"

undefined4 FUN_02186c74(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar4 = param_1 + DAT_02186cf4;
  uVar5 = DAT_02186cfc;
  if (*(int *)(param_1 + 8) == 0) {
    uVar5 = DAT_02186cf8;
  }
  iVar1 = func_0x0213a434(*(undefined4 *)(param_1 + 0xa8));
  iVar2 = func_0x0213a434(uVar5);
  iVar3 = func_0x0213a434(*(undefined4 *)(param_1 + 0xac));
  iVar1 = FUN_02186a38(param_1,param_1 + DAT_02186cf4,iVar1 + iVar2 + -4 + iVar3 + DAT_02186d00);
  if (iVar1 == 1) {
    iVar1 = func_0x0200d9e0(*(undefined4 *)(iVar4 + 4),*(undefined4 *)(iVar4 + 0xc),uVar5,
                            *(undefined4 *)(param_1 + 0xac),*(undefined4 *)(param_1 + 0xa8));
    *(int *)(iVar4 + 4) = *(int *)(iVar4 + 4) + iVar1;
    return 0;
  }
  return 1;
}

