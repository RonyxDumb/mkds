/* Decompiled C draft; module arm7; ROM address 0600da04. No matching claim. */
#include "types.h"
#include "deps/0600da04_FUN_0600da04.h"

int FUN_0600da04(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_06009138((*(uint *)(DAT_0600da74 & 0xfffffffc) >> (DAT_0600da74 & 3) * 8 |
                       *(uint *)(DAT_0600da74 & 0xfffffffc) << (DAT_0600da74 & 3) * -8 + 0x20) +
                       0x188,param_2 + 0x22);
  if (iVar1 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = iVar1 + 0x10;
    FUN_060097b8(iVar1 + 0x18,param_1,param_2 + 0xc);
    *(short *)(iVar1 + 0x16) = (short)param_2 + -0x18;
    *(ushort *)(iVar1 + 0x1e) =
         *(ushort *)(iVar1 + 0x1e) & 0xff |
         (ushort)(((*(ushort *)(iVar1 + 0x22) & 0xff) << 0x10) >> 8);
  }
  return iVar2;
}

