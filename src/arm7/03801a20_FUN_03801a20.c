/* Decompiled C draft; module arm7; ROM address 03801a20. No matching claim. */
#include "types.h"
#include "deps/03801a20_FUN_03801a20.h"

void FUN_03801a20(uint param_1,int param_2)

{
  uint uVar1;
  byte *pbVar2;
  byte *pbVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  pbVar2 = DAT_03801b08;
  uVar5 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  if ((int)(uVar5 << 7) < 0) {
    if ((uVar5 << 5) >> 0x1e == 0) {
      *DAT_03801b08 = 0;
      iVar4 = DAT_03801b10;
      pbVar3 = DAT_03801b0c;
      uVar5 = DAT_03801b10 + 0x24U & 3;
      uVar6 = *(uint *)(DAT_03801b10 + 0x24U & 0xfffffffc);
      uVar5 = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20;
      if (param_2 < (int)uVar5 >> 1) {
        *DAT_03801b0c = *DAT_03801b0c + 1;
        if ((3 < *pbVar3) &&
           (*pbVar3 = 0, uVar6 = iVar4 + 0x28, uVar1 = uVar6 & 3,
           uVar6 = *(uint *)(uVar6 & 0xfffffffc),
           (int)(uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) < (int)uVar5)) {
          *(uint *)(iVar4 + 0x24) = uVar5 - 1;
          *pbVar2 = 3;
        }
      }
      else {
        *DAT_03801b0c = 0;
      }
    }
    else {
      *DAT_03801b0c = 0;
      pbVar2 = DAT_03801b08;
      *DAT_03801b08 = *DAT_03801b08 + 1;
      if (3 < *pbVar2) {
        *pbVar2 = 0;
        uVar5 = DAT_03801b10 + 0x24U & 3;
        uVar6 = *(uint *)(DAT_03801b10 + 0x24U & 0xfffffffc);
        uVar5 = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20;
        if ((int)uVar5 < 0x23) {
          *(uint *)(DAT_03801b10 + 0x24) = uVar5 + 1;
        }
      }
    }
  }
  else {
    *DAT_03801b08 = 0;
    *DAT_03801b0c = 0;
  }
  return;
}

