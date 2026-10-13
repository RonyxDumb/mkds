/* Decompiled C draft; module arm9; ROM address 020d4ddc. No matching claim. */
#include "types.h"
#include "deps/020d4ddc_func_020d4ddc.h"

undefined4 func_020d4ddc(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  
  uVar4 = param_1 + 0x78U & 3;
  uVar5 = *(uint *)(param_1 + 0x78U & 0xfffffffc);
  if (((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) & 4) != 0) {
    return 1;
  }
  uVar4 = param_1 + 0x98U & 3;
  uVar5 = *(uint *)(param_1 + 0x98U & 0xfffffffc);
  uVar5 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
  uVar1 = iRam020d4e24 + 0xcU & 3;
  uVar8 = *(uint *)(iRam020d4e24 + 0xcU & 0xfffffffc);
  uVar2 = param_1 + 8U & 3;
  uVar6 = *(uint *)(param_1 + 8U & 0xfffffffc);
  uVar4 = uVar5 + 0x3c;
  uVar3 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  iVar7 = (uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20) -
          (uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20);
  if (((int)(uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) < iVar7) &&
     (uVar5 = uVar5 + 0x38, uVar4 = uVar5 & 3, uVar5 = *(uint *)(uVar5 & 0xfffffffc),
     iVar7 < (int)(uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20))) {
    return 0;
  }
  return 1;
}

