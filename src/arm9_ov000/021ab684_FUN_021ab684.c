/* Decompiled C draft; module arm9_ov000; ROM address 021ab684. No matching claim. */
#include "types.h"
#include "deps/021ab684_FUN_021ab684.h"

int FUN_021ab684(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  
  iVar3 = 0;
  iVar2 = DAT_021ab6d0;
  while ((*(char *)(iVar2 + 0x5a) == '\0' ||
         (iVar1 = func_0x02134d30(iVar2,param_1,0x20), iVar1 != 0))) {
    iVar2 = iVar2 + 0x5c;
    iVar3 = iVar3 + 1;
    if (3 < iVar3) {
      return 0;
    }
  }
  uVar4 = func_0x0200f5ac();
  *(uint *)(iVar2 + 0x50) = (uint)uVar4 >> 0x10 | (int)((ulonglong)uVar4 >> 0x20) << 0x10;
  return iVar2;
}

