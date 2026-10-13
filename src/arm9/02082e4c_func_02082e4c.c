/* Decompiled C draft; module arm9; ROM address 02082e4c. No matching claim. */
#include "types.h"
#include "deps/02082e4c_func_02082e4c.h"

void func_02082e4c(int param_1)

{
  uint uVar1;
  short sVar2;
  undefined4 uVar3;
  int iVar4;
  short sVar5;
  uint uVar6;
  int iVar7;
  short *psVar8;
  uint uVar9;
  short *psVar10;
  short *psVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  int local_28;
  
  psVar10 = (short *)(iRam02082f7c + param_1 * 0x10);
  iVar7 = 4;
  psVar8 = psRam02082f80;
  do {
    psVar11 = psVar10 + 1;
    sVar5 = *psVar10;
    psVar10 = psVar10 + 2;
    sVar2 = *psVar11;
    iVar7 = iVar7 + -1;
    psVar11 = psVar8 + 1;
    *psVar8 = sVar5;
    psVar8 = psVar8 + 2;
    *psVar11 = sVar2;
    psVar11 = psRam02082f80;
  } while (iVar7 != 0);
  uVar9 = *(uint *)(uRam02082f84 & 0xfffffffc) >> (uRam02082f84 & 3) * 8 |
          *(uint *)(uRam02082f84 & 0xfffffffc) << (uRam02082f84 & 3) * -8 + 0x20;
  if ((int)uVar9 < 4) {
    uVar1 = uRam02082f88 & 3;
    uVar12 = *(uint *)(uRam02082f88 & 0xfffffffc);
    uVar6 = uVar9;
    do {
      if ((uVar6 != uVar9) || (uVar12 >> uVar1 * 8 == 0 && uVar12 << uVar1 * -8 + 0x20 == 0)) {
        psVar11[uVar6 * 2] = -1;
      }
      uVar13 = uVar6 + 1;
      psVar11[uVar6 * 2 + 1] = -1;
      uVar6 = uVar13;
    } while ((int)uVar13 < 4);
  }
  uVar3 = uRam02082f90;
  iVar7 = 0;
  local_28 = 0;
  uVar9 = uRam02082f8c;
  do {
    iVar14 = local_28;
    psVar8 = psRam02082f80;
    do {
      if (*psVar8 < 0) break;
      iVar4 = func_0208b60c(*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
                            *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20,uVar3);
      uVar1 = uVar9 + 4 & 3;
      uVar6 = *(uint *)(uVar9 + 4 & 0xfffffffc);
      iVar14 = iVar14 + 1;
      *(uint *)(iVar4 + 0x90) = uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20;
      *(char *)(iVar4 + 0x98) = (char)*psVar8;
      sVar5 = psVar8[1];
      if (sVar5 < 0) {
        sVar5 = 0xff;
      }
      *(char *)(iVar4 + 0x99) = (char)sVar5;
      *(bool *)(iVar4 + 0x9a) = iVar7 != 0;
      *(undefined1 *)(iVar4 + 0x9b) = 0;
      *(undefined4 *)(iVar4 + 0x94) = 0;
      psVar8 = psVar8 + 2;
    } while (iVar14 < 4);
    iVar7 = iVar7 + 1;
    uVar9 = uVar9 + 8;
    if (1 < iVar7) {
      return;
    }
  } while( true );
}

