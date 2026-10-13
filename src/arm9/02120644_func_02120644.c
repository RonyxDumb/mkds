/* Decompiled C draft; module arm9; ROM address 02120644. No matching claim. */
#include "types.h"
#include "deps/02120644_func_02120644.h"

undefined4 func_02120644(void)

{
  int iVar1;
  uint uVar2;
  uint uVar4;
  uint uVar3;
  
  uVar4 = *(uint *)(uRam02120710 & 0xfffffffc) >> (uRam02120710 & 3) * 8 |
          *(uint *)(uRam02120710 & 0xfffffffc) << (uRam02120710 & 3) * -8 + 0x20;
  if (*(short *)(uVar4 + 0x16) != 0) {
    uVar3 = uVar4 + 0x1f44 & 3;
    uVar2 = *(uint *)(uVar4 + 0x1f44 & 0xfffffffc);
    uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    if ((((uVar3 == 6) || (uVar3 == 3)) || (uVar3 == 4)) || (uVar3 == 0xb)) {
      return 3;
    }
    uVar3 = uVar4 + 8000 & 3;
    uVar2 = *(uint *)(uVar4 + 8000 & 0xfffffffc);
    uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    if (uVar3 == 2) {
      iVar1 = func_0x0219bb68();
      if (iVar1 < 2) {
        uVar4 = *(uint *)(uRam02120710 & 0xfffffffc) >> (uRam02120710 & 3) * 8 |
                *(uint *)(uRam02120710 & 0xfffffffc) << (uRam02120710 & 3) * -8 + 0x20;
        *(undefined2 *)(uVar4 + 0x18) = 2;
        *(undefined2 *)(uVar4 + 0x1a) = 1;
        return 2;
      }
    }
    else if (uVar3 == 1) {
      *(undefined2 *)(uVar4 + 0x18) = 2;
      *(undefined2 *)(uVar4 + 0x1a) = 1;
      return 1;
    }
  }
  return 0;
}

