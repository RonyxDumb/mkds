/* Decompiled C draft; module arm9; ROM address 0214cffc. No matching claim. */
#include "types.h"
#include "deps/0214cffc_CopyMemory16.h"

void CopyMemory16(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  for (iVar1 = 0; iVar1 < param_3; iVar1 = iVar1 + 2) {
    *(undefined2 *)(param_2 + iVar1) = *(undefined2 *)(param_1 + iVar1);
  }
  return;
}

