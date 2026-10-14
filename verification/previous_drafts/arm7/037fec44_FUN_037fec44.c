/* Decompiled C draft; module arm7; ROM address 037fec44. No matching claim. */
#include "types.h"
#include "deps/037fec44_FUN_037fec44.h"

void FUN_037fec44(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  param_1 = param_1 * 0x24;
  iVar2 = DAT_037fecc4 + param_1;
  *(byte *)(DAT_037fecc4 + param_1) =
       *(byte *)(DAT_037fecc4 + param_1) & 0xfb | (byte)((param_2 & 1) << 2);
  if (param_2 != 0) {
    iVar3 = 0;
    do {
      iVar1 = FUN_037fe2e4(iVar2,iVar3);
      if (iVar1 != 0) {
        FUN_037fe40c(iVar1,iVar2,0x7f);
        FUN_037fe3d0(iVar1);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 0x10);
  }
  return;
}

