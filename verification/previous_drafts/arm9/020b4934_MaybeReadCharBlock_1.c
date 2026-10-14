/* Decompiled C draft; module arm9; ROM address 020b4934. No matching claim. */
#include "types.h"
#include "deps/020b4934_MaybeReadCharBlock_1.h"

void MaybeReadCharBlock_1(int *param_1,int param_2)

{
  int iVar1;
  
  if (param_2 != 0) {
    iVar1 = Common_FindBlockByMagic(param_2,uRam020b4968);
    if (iVar1 != 0) {
      *param_1 = iVar1 + 8;
    }
    return;
  }
  return;
}

