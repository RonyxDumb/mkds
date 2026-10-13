/* Decompiled C draft; module arm7; ROM address 037fcadc. No matching claim. */
#include "types.h"
#include "deps/037fcadc_FUN_037fcadc.h"

int FUN_037fcadc(uint param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar6;
  int iVar7;
  int iVar8;
  code *pcVar5;
  
  param_1 = param_1 & ~(*(uint *)(DAT_037fcc04 & 0xfffffffc) >> (DAT_037fcc04 & 3) * 8 |
                       *(uint *)(DAT_037fcc04 & 0xfffffffc) << (DAT_037fcc04 & 3) * -8 + 0x20);
  if (param_3 == 0) {
    param_1 = param_1 & ~(*(uint *)(DAT_037fcc08 & 0xfffffffc) >> (DAT_037fcc08 & 3) * 8 |
                         *(uint *)(DAT_037fcc08 & 0xfffffffc) << (DAT_037fcc08 & 3) * -8 + 0x20);
  }
  iVar7 = 0;
  iVar8 = 0;
  do {
    iVar3 = iVar8;
    if (((param_1 & 1 << (uint)*(byte *)(DAT_037fcc0c + iVar7)) != 0) &&
       (iVar6 = (uint)*(byte *)(DAT_037fcc0c + iVar7) * 0x54 + DAT_037fcc10, iVar3 = iVar6,
       iVar8 != 0)) {
      iVar3 = iVar8;
      if ((*(byte *)(iVar6 + 0x22) <= *(byte *)(iVar8 + 0x22)) &&
         ((*(byte *)(iVar6 + 0x22) != *(byte *)(iVar8 + 0x22) ||
          (iVar2 = FUN_037fc584(iVar8,iVar6), iVar2 < 0)))) {
        iVar3 = iVar6;
      }
    }
    iVar7 = iVar7 + 1;
    iVar8 = iVar3;
  } while (iVar7 < 0x10);
  if (iVar3 == 0) {
    iVar3 = 0;
  }
  else if (param_2 < (int)(uint)*(byte *)(iVar3 + 0x22)) {
    iVar3 = 0;
  }
  else {
    uVar1 = iVar3 + 0x48U & 3;
    uVar4 = *(uint *)(iVar3 + 0x48U & 0xfffffffc);
    pcVar5 = (code *)(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20);
    if (pcVar5 != (code *)0x0) {
      uVar1 = iVar3 + 0x4cU & 3;
      uVar4 = *(uint *)(iVar3 + 0x4cU & 0xfffffffc);
      (*pcVar5)(iVar3,0,uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20);
    }
    *(byte *)(iVar3 + 3) = *(byte *)(iVar3 + 3) & 7 | 0x10;
    *(byte *)(iVar3 + 3) = *(byte *)(iVar3 + 3) & 0xfe;
    FUN_037fc630(iVar3,param_4,param_5,param_2);
  }
  return iVar3;
}

