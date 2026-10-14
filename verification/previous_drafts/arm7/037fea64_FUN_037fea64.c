/* Decompiled C draft; module arm7; ROM address 037fea64. No matching claim. */
#include "types.h"
#include "deps/037fea64_FUN_037fea64.h"

void FUN_037fea64(int param_1,uint param_2,undefined2 param_3)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = param_1 * 0x24 + DAT_037fead8;
  iVar2 = 0;
  for (; (iVar2 < 0x10 && (param_2 != 0)); param_2 = param_2 >> 1) {
    if (((param_2 & 1) != 0) && (pbVar1 = (byte *)FUN_037fe2e4(iVar3,iVar2), pbVar1 != (byte *)0x0))
    {
      *(undefined2 *)(pbVar1 + 0x1e) = param_3;
      *pbVar1 = *pbVar1 | 0x80;
    }
    iVar2 = iVar2 + 1;
  }
  return;
}

