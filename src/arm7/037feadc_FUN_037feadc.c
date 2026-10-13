/* Decompiled C draft; module arm7; ROM address 037feadc. No matching claim. */
#include "types.h"
#include "deps/037feadc_FUN_037feadc.h"

void FUN_037feadc(int param_1,uint param_2,uint param_3)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = param_1 * 0x24 + DAT_037feb74;
  iVar2 = 0;
  for (; (iVar2 < 0x10 && (param_2 != 0)); param_2 = param_2 >> 1) {
    if (((param_2 & 1) != 0) && (pbVar1 = (byte *)FUN_037fe2e4(iVar3,iVar2), pbVar1 != (byte *)0x0))
    {
      if (param_3 != 0) {
        FUN_037fe40c((int)(uintptr_t)(pbVar1),iVar3,0x7f);
        FUN_037fe3d0((int)(uintptr_t)(pbVar1));
      }
      *pbVar1 = *pbVar1 & 0xfb | (byte)((param_3 & 1) << 2);
    }
    iVar2 = iVar2 + 1;
  }
  return;
}

