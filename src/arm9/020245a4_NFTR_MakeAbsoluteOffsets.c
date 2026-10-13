/* Decompiled C draft; module arm9; ROM address 020245a4. No matching claim. */
#include "types.h"
#include "deps/020245a4_NFTR_MakeAbsoluteOffsets.h"

void NFTR_MakeAbsoluteOffsets(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar3 = uRam02024694;
  uVar2 = uRam02024690;
  uVar1 = uRam0202468c;
  iVar4 = 0;
  uVar5 = param_1 + (uint)*(ushort *)(param_1 + 0xc);
  if (*(short *)(param_1 + 0xe) == 0) {
    return;
  }
  do {
    uVar6 = *(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
            *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20;
    if (uVar3 < uVar6) {
      if (uVar2 < uVar6) {
        if (uVar6 == uVar1) {
          uVar6 = uVar5 + 0x10 & 3;
          uVar7 = *(uint *)(uVar5 + 0x10 & 0xfffffffc);
          *(uint *)(uVar5 + 0x10) = (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) + param_1;
          uVar6 = uVar5 + 0x14 & 3;
          uVar7 = *(uint *)(uVar5 + 0x14 & 0xfffffffc);
          uVar6 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
          if (uVar6 != 0) {
            *(uint *)(uVar5 + 0x14) = uVar6 + param_1;
          }
          uVar6 = uVar5 + 0x18 & 3;
          uVar7 = *(uint *)(uVar5 + 0x18 & 0xfffffffc);
          uVar6 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
          if (uVar6 != 0) {
            *(uint *)(uVar5 + 0x18) = uVar6 + param_1;
          }
        }
      }
      else if ((uVar6 == uVar2) &&
              (uVar6 = uVar5 + 0xc & 3, uVar7 = *(uint *)(uVar5 + 0xc & 0xfffffffc),
              uVar6 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20, uVar6 != 0)) {
        *(uint *)(uVar5 + 0xc) = uVar6 + param_1;
      }
    }
    else if ((uVar3 <= uVar6) &&
            (uVar6 = uVar5 + 0x10 & 3, uVar7 = *(uint *)(uVar5 + 0x10 & 0xfffffffc),
            uVar6 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20, uVar6 != 0)) {
      *(uint *)(uVar5 + 0x10) = uVar6 + param_1;
    }
    uVar6 = uVar5 + 4 & 3;
    uVar7 = *(uint *)(uVar5 + 4 & 0xfffffffc);
    iVar4 = iVar4 + 1;
    uVar5 = uVar5 + (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20);
  } while (iVar4 < (int)(uint)*(ushort *)(param_1 + 0xe));
  return;
}

