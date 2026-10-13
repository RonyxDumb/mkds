/* Decompiled C draft; module arm9; ROM address 020a1cd8. No matching claim. */
#include "types.h"
#include "deps/020a1cd8_func_020a1cd8.h"

uint func_020a1cd8(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar5;
  int iVar6;
  uint uVar4;
  
  uVar5 = *(uint *)(uRam020a1dd4 & 0xfffffffc) >> (uRam020a1dd4 & 3) * 8 |
          *(uint *)(uRam020a1dd4 & 0xfffffffc) << (uRam020a1dd4 & 3) * -8 + 0x20;
  uVar2 = uVar5 + 8 & 3;
  uVar1 = *(uint *)(uVar5 + 8 & 0xfffffffc);
  if ((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) == 2) {
    uVar2 = uVar5 + 0x18 & 3;
    uVar1 = *(uint *)(uVar5 + 0x18 & 0xfffffffc);
    uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    if (uVar2 == 0) {
      uVar2 = param_1 * 0x70 +
              (*(uint *)(uRam020a1dd8 & 0xfffffffc) >> (uRam020a1dd8 & 3) * 8 |
              *(uint *)(uRam020a1dd8 & 0xfffffffc) << (uRam020a1dd8 & 3) * -8 + 0x20) + 0x4c;
      uVar1 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      param_1 = 4 - (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
    }
    else if (uVar2 == 1) {
      uVar2 = 1;
      iVar6 = 0;
      if (*(char *)(uVar5 + 0x3d0) != '\0') {
        uVar1 = *(uint *)(uRam020a1dd8 & 0xfffffffc) >> (uRam020a1dd8 & 3) * 8 |
                *(uint *)(uRam020a1dd8 & 0xfffffffc) << (uRam020a1dd8 & 3) * -8 + 0x20;
        do {
          uVar4 = uVar1 + 0x4c & 3;
          uVar3 = *(uint *)(uVar1 + 0x4c & 0xfffffffc);
          uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
          iVar6 = iVar6 + 1;
          if ((int)uVar2 < (int)uVar4) {
            uVar2 = uVar4;
          }
          uVar1 = uVar1 + 0x70;
        } while (iVar6 < (int)(uint)*(byte *)(uVar5 + 0x3d0));
      }
      uVar1 = param_1 * 0x70 +
              (*(uint *)(uRam020a1dd8 & 0xfffffffc) >> (uRam020a1dd8 & 3) * 8 |
              *(uint *)(uRam020a1dd8 & 0xfffffffc) << (uRam020a1dd8 & 3) * -8 + 0x20) + 0x4c;
      uVar5 = uVar1 & 3;
      uVar1 = *(uint *)(uVar1 & 0xfffffffc);
      param_1 = (int)((uVar2 + 1) - (uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20)) / 2 + 1;
    }
  }
  else {
    uVar2 = param_1 * 0x70 +
            (*(uint *)(uRam020a1dd8 & 0xfffffffc) >> (uRam020a1dd8 & 3) * 8 |
            *(uint *)(uRam020a1dd8 & 0xfffffffc) << (uRam020a1dd8 & 3) * -8 + 0x20) + 0x4c;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    param_1 = 4 - (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  }
  if ((int)param_1 < 1) {
    param_1 = 1;
  }
  else if (3 < (int)param_1) {
    param_1 = 3;
  }
  return param_1 & 0xffff;
}

