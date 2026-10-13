/* Decompiled C draft; module arm9; ROM address 0212f3f8. No matching claim. */
#include "types.h"
#include "deps/0212f3f8_func_0212f3f8.h"

void func_0212f3f8(int param_1,int param_2,uint param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  short *psVar7;
  short *psVar8;
  short local_28 [4];
  
  iVar2 = iRam0212f598;
  param_3 = param_3 >> 1;
  iVar4 = 0;
  do {
    iVar6 = (int)*(short *)(param_1 + param_3 * 2 + iVar4 * 2 + -4) -
            (int)*(short *)(param_2 + param_3 * 2 + iVar4 * 2 + -4);
    iVar5 = -0x8000;
    if ((-0x8001 < iVar6) && (iVar5 = iVar6, iRam0212f598 < iVar6)) {
      iVar5 = iRam0212f598;
    }
    iVar6 = iVar4 + 1;
    local_28[iVar4] = (short)iVar5;
    iVar4 = iVar6;
  } while (iVar6 < 2);
  psVar7 = (short *)(param_2 + (param_3 - 1) * 2);
  iVar4 = iRam0212f598;
  for (psVar8 = (short *)(param_1 + (param_3 - 1) * 2); iRam0212f598 = iVar4,
      (short *)(param_1 + 4) <= psVar8; psVar8 = psVar8 + -1) {
    iVar5 = (int)psVar8[-2] - (int)psVar7[-2];
    iVar4 = *psVar8 + iVar5;
    iVar6 = *psVar7 - iVar5;
    if (iVar5 < 0) {
      if (iVar4 < -0x7fff) {
        *psVar8 = -0x8000;
      }
      else {
        *psVar8 = (short)iVar4;
      }
      if (iVar6 < iVar2) {
        *psVar7 = (short)iVar6;
      }
      else {
        *psVar7 = (short)iVar2;
      }
    }
    else {
      if (iVar4 < iVar2) {
        *psVar8 = (short)iVar4;
      }
      else {
        *psVar8 = (short)iVar2;
      }
      if (iVar6 < -0x7fff) {
        *psVar7 = -0x8000;
      }
      else {
        *psVar7 = (short)iVar6;
      }
    }
    psVar7 = psVar7 + -1;
    iVar4 = iRam0212f598;
  }
  iVar2 = 1;
  do {
    uVar3 = param_4 + iVar2 * 4 + 0x18;
    uVar1 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    iVar6 = (int)*(short *)(param_1 + iVar2 * 2) + (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20)
    ;
    iVar5 = -0x8000;
    if ((-0x8001 < iVar6) && (iVar5 = iVar6, iVar4 < iVar6)) {
      iVar5 = iVar4;
    }
    *(short *)(param_1 + iVar2 * 2) = (short)iVar5;
    uVar3 = param_4 + iVar2 * 4 + 0x18;
    uVar1 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    iVar6 = (int)*(short *)(param_2 + iVar2 * 2) - (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20)
    ;
    iVar5 = -0x8000;
    if ((-0x8001 < iVar6) && (iVar5 = iVar6, iVar4 < iVar6)) {
      iVar5 = iVar4;
    }
    *(short *)(param_2 + iVar2 * 2) = (short)iVar5;
    iVar2 = iVar2 + -1;
  } while (-1 < iVar2);
  iVar2 = 0;
  do {
    psVar8 = local_28 + iVar2;
    iVar4 = iVar2 * 4;
    iVar2 = iVar2 + 1;
    *(int *)(param_4 + iVar4 + 0x18) = (int)*psVar8;
  } while (iVar2 < 2);
  return;
}

