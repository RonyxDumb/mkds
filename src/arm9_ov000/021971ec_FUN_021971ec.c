/* Decompiled C draft; module arm9_ov000; ROM address 021971ec. No matching claim. */
#include "types.h"
#include "deps/021971ec_FUN_021971ec.h"

void FUN_021971ec(int param_1,int param_2)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  
  pbVar2 = (byte *)*DAT_0219721c;
  iVar3 = 0;
  if (0 < param_2) {
    do {
      bVar1 = *pbVar2;
      pbVar2 = pbVar2 + 1;
      *(byte *)(param_1 + iVar3) = *(byte *)(param_1 + iVar3) ^ bVar1;
      if (*pbVar2 == 0) {
        pbVar2 = (byte *)*DAT_0219721c;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_2);
  }
  return;
}

