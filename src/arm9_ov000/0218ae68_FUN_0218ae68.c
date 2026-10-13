/* Decompiled C draft; module arm9_ov000; ROM address 0218ae68. No matching claim. */
#include "types.h"
#include "deps/0218ae68_FUN_0218ae68.h"

undefined4 FUN_0218ae68(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = *param_1;
  while( true ) {
    if (iVar2 == 0) {
      return 0;
    }
    if (iVar2 == param_2) break;
    iVar1 = iVar2;
    iVar2 = *(int *)(iVar2 + 0x20);
  }
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x20) = *(undefined4 *)(iVar2 + 0x20);
  }
  if (*param_1 == iVar2) {
    *param_1 = *(int *)(iVar2 + 0x20);
  }
  if (param_1[1] == iVar2) {
    param_1[1] = iVar1;
  }
  param_1[2] = param_1[2] + -1;
  return 1;
}

