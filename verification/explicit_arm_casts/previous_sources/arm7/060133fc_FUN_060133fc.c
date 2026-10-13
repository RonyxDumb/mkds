/* Decompiled C draft; module arm7; ROM address 060133fc. No matching claim. */
#include "types.h"
#include "deps/060133fc_FUN_060133fc.h"

int FUN_060133fc(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  uVar3 = *(uint *)(DAT_060134ac & 0xfffffffc) >> (DAT_060134ac & 3) * 8 |
          *(uint *)(DAT_060134ac & 0xfffffffc) << (DAT_060134ac & 3) * -8 + 0x20;
  FUN_060096e4(param_1,1);
  iVar2 = DAT_060134b0;
  iVar5 = 2;
  uVar4 = 0;
  do {
    uVar1 = 1 << (uVar4 & 0xff);
    if ((*(ushort *)(uVar3 + 0x3a6) & uVar1) != 0) {
      if ((*(ushort *)(uVar3 + 0x3a4) & uVar1) == 0) {
        FUN_060096e4(param_1 + iVar5,*(ushort *)(iVar2 + uVar4 * 2) & 0xff);
      }
      else {
        FUN_060096e4(param_1 + iVar5,*(ushort *)(iVar2 + uVar4 * 2) & 0xff | 0x80);
      }
      iVar5 = iVar5 + 1;
    }
    uVar4 = uVar4 + 1;
  } while (uVar4 < 0x10);
  FUN_060096e4(param_1 + 1,iVar5 - 2U & 0xff);
  return iVar5;
}

