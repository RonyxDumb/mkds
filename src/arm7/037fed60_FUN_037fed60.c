/* Decompiled C draft; module arm7; ROM address 037fed60. No matching claim. */
#include "types.h"
#include "deps/037fed60_FUN_037fed60.h"

void FUN_037fed60(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  byte *pbVar8;
  
  pbVar8 = (byte *)(DAT_037feea8 + param_1 * 0x24);
  if ((int)((uint)*(byte *)(DAT_037feea8 + param_1 * 0x24) << 0x1f) < 0) {
    FUN_037fe230(pbVar8);
  }
  FUN_037fe47c(pbVar8,param_4);
  iVar1 = FUN_037fd37c();
  if (-1 < iVar1) {
    iVar7 = DAT_037feeac + iVar1 * 0x40;
    FUN_037fe540((byte *)(uintptr_t)(iVar7));
    FUN_037fe52c(iVar7,param_2,param_3);
    pbVar8[8] = (byte)iVar1;
    uVar3 = iVar7 + 0x28U & 3;
    uVar2 = *(uint *)(iVar7 + 0x28U & 0xfffffffc);
    FUN_037fe83c(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20);
    uVar3 = iVar7 + 0x28U & 3;
    uVar2 = *(uint *)(iVar7 + 0x28U & 0xfffffffc);
    iVar1 = FUN_037fe7ec(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20);
    piVar6 = (int *)(iVar7 + 0x28);
    uVar3 = iVar7 + 0x28U & 3;
    uVar2 = *(uint *)(iVar7 + 0x28U & 0xfffffffc);
    *(uint *)(iVar7 + 0x28) = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + 1;
    if (iVar1 == 0xfe) {
      uVar3 = FUN_037fe79c(iVar7);
      iVar1 = DAT_037feeac;
      iVar7 = 1;
      while (uVar3 = (uVar3 << 0xf) >> 0x10, uVar3 != 0) {
        if ((uVar3 & 1) != 0) {
          iVar4 = FUN_037fd37c();
          if (iVar4 < 0) break;
          FUN_037fe540((byte *)(uintptr_t)(iVar1 + iVar4 * 0x40));
          pbVar8[iVar7 + 8] = (byte)iVar4;
        }
        iVar7 = iVar7 + 1;
      }
    }
    else {
      *piVar6 = (*(uint *)((uint)piVar6 & 0xfffffffc) >> ((uint)piVar6 & 3) * 8 |
                *(uint *)((uint)piVar6 & 0xfffffffc) << ((uint)piVar6 & 3) * -8 + 0x20) - 1;
    }
    *pbVar8 = *pbVar8 & 0xfe | 1;
    *pbVar8 = *pbVar8 & 0xfd;
    uVar3 = *(uint *)(DAT_037feeb0 & 0xfffffffc) >> (DAT_037feeb0 & 3) * 8 |
            *(uint *)(DAT_037feeb0 & 0xfffffffc) << (DAT_037feeb0 & 3) * -8 + 0x20;
    if (uVar3 != 0) {
      uVar2 = uVar3 + 4 & 3;
      uVar5 = *(uint *)(uVar3 + 4 & 0xfffffffc);
      *(uint *)(uVar3 + 4) = uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20 | 1 << (param_1 & 0xff)
      ;
    }
  }
  return;
}

