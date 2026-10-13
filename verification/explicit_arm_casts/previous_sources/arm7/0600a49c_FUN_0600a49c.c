/* Decompiled C draft; module arm7; ROM address 0600a49c. No matching claim. */
#include "types.h"
#include "deps/0600a49c_FUN_0600a49c.h"

void FUN_0600a49c(int param_1,ushort *param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  ushort *puVar5;
  uint uVar6;
  
  *param_2 = 0;
  param_2[1] = 0;
  uVar2 = FUN_060096c4(param_1 + 1);
  iVar1 = DAT_0600a554;
  puVar5 = param_2 + 1;
  for (uVar6 = 0; uVar6 < uVar2; uVar6 = uVar6 + 1) {
    uVar3 = FUN_060096c4(param_1 + 2 + uVar6);
    uVar4 = (uVar3 & 0x7f) - 1;
    if ((uVar4 < 0x78) && (uVar4 = (uint)*(ushort *)(iVar1 + uVar4 * 2), uVar4 != 0xff)) {
      *puVar5 = *puVar5 | (ushort)(1 << (uVar4 & 0xff));
      if ((uVar3 & 0x80) != 0) {
        *param_2 = *param_2 | (ushort)(1 << (uVar4 & 0xff));
      }
    }
    else {
      *puVar5 = *puVar5 | 0x8000;
      if ((uVar3 & 0x80) != 0) {
        *param_2 = *param_2 | 0x8000;
      }
    }
  }
  return;
}

