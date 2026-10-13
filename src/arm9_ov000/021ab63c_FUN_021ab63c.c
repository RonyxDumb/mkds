/* Decompiled C draft; module arm9_ov000; ROM address 021ab63c. No matching claim. */
#include "types.h"
#include "deps/021ab63c_FUN_021ab63c.h"

int FUN_021ab63c(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  
  iVar1 = 0;
  iVar2 = DAT_021ab680;
  while (((*(char *)(iVar2 + 0x5a) == '\0' || (*(int *)(iVar2 + 0x54) != param_1)) ||
         (*(ushort *)(iVar2 + 0x58) != param_2))) {
    iVar2 = iVar2 + 0x5c;
    iVar1 = iVar1 + 1;
    if (3 < iVar1) {
      return 0;
    }
  }
  uVar3 = func_0x0200f5ac();
  *(uint *)(iVar2 + 0x50) = (uint)uVar3 >> 0x10 | (int)((ulonglong)uVar3 >> 0x20) << 0x10;
  return iVar2;
}

