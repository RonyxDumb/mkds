/* Decompiled C draft; module arm9_ov000; ROM address 021a7bfc. No matching claim. */
#include "types.h"
#include "deps/021a7bfc_FUN_021a7bfc.h"

int FUN_021a7bfc(int param_1,int *param_2,undefined2 *param_3,undefined2 *param_4,
                undefined4 *param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(*(int *)(param_1 + 100) + 0xc4);
  iVar2 = *(int *)(*(int *)(param_1 + 100) + 0xf8);
  iVar1 = *(int *)(iVar3 + 0x44) - iVar2;
  if (iVar1 < 0) {
    *param_2 = -1;
    return 0;
  }
  *param_3 = *(undefined2 *)(iVar3 + 10);
  *param_4 = *(undefined2 *)(iVar3 + 0x18);
  *param_5 = *(undefined4 *)(iVar3 + 0x1c);
  *param_2 = iVar1;
  if ((iVar1 == 0) && (*(char *)(iVar3 + 8) != '\x04')) {
    return 0;
  }
  return *(int *)(iVar3 + 0x40) + iVar2;
}

