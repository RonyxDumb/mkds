/* Decompiled C draft; module arm9; ROM address 020c7464. No matching claim. */
#include "types.h"
#include "deps/020c7464_func_020c7464.h"

undefined4 func_020c7464(void)

{
  undefined2 uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  undefined2 local_18 [2];
  
  uVar9 = 0;
  local_18[0] = *puRam020c7544;
  local_18[1] = puRam020c7544[1];
  do {
    uVar1 = local_18[uVar9];
    iVar3 = func_021000d0(uVar1);
    if (iVar3 != 0) {
      uVar4 = func_020c0c2c((undefined4 *)(uintptr_t)(uRam020c7548),uVar1);
      uVar2 = uRam020c7548;
      iVar3 = 0;
      uVar7 = *(uint *)(uRam020c7548 & 0xfffffffc) >> (uRam020c7548 & 3) * 8 |
              *(uint *)(uRam020c7548 & 0xfffffffc) << (uRam020c7548 & 3) * -8 + 0x20;
      uVar9 = uVar7 + 8 & 3;
      uVar5 = *(uint *)(uVar7 + 8 & 0xfffffffc);
      iVar8 = 0;
      if (0 < (int)(uVar5 >> uVar9 * 8 | uVar5 << uVar9 * -8 + 0x20)) {
        do {
          uVar9 = (*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
                  *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + iVar8 * 4;
          uVar5 = uVar9 & 3;
          uVar9 = *(uint *)(uVar9 & 0xfffffffc);
          iVar6 = func_020de9f8(uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20);
          uVar9 = uVar2 & 3;
          uVar5 = *(uint *)(uVar2 & 0xfffffffc);
          uVar7 = uVar5 >> uVar9 * 8 | uVar5 << uVar9 * -8 + 0x20;
          if (iVar3 < iVar6) {
            iVar3 = iVar6;
          }
          uVar9 = uVar7 + 8 & 3;
          uVar5 = *(uint *)(uVar7 + 8 & 0xfffffffc);
          iVar8 = iVar8 + 1;
        } while (iVar8 < (int)(uVar5 >> uVar9 * 8 | uVar5 << uVar9 * -8 + 0x20));
      }
      if (iVar3 < 0x3e8000) {
        *puRam020c754c = 1;
      }
      else {
        *puRam020c754c = 0;
      }
      return uVar4;
    }
    uVar9 = uVar9 + 1 & 0xffff;
  } while (uVar9 < 2);
  return 0;
}

