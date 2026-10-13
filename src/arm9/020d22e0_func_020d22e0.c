/* Decompiled C draft; module arm9; ROM address 020d22e0. No matching claim. */
#include "types.h"
#include "deps/020d22e0_func_020d22e0.h"

void func_020d22e0(void)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  
  piVar3 = piRam020d2338;
  iVar2 = iRam020d2334;
  uVar4 = (*(uint *)(uRam020d2328 & 0xfffffffc) >> (uRam020d2328 & 3) * 8 |
          *(uint *)(uRam020d2328 & 0xfffffffc) << (uRam020d2328 & 3) * -8 + 0x20) + 8;
  uVar1 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  if ((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) == 5) {
    uVar4 = *(uint *)(uRam020d2330 & 0xfffffffc) >> (uRam020d2330 & 3) * 8 |
            *(uint *)(uRam020d2330 & 0xfffffffc) << (uRam020d2330 & 3) * -8 + 0x20;
    iVar5 = uVar4 + 0x4b0;
  }
  else {
    uVar4 = *(uint *)(uRam020d2330 & 0xfffffffc) >> (uRam020d2330 & 3) * 8 |
            *(uint *)(uRam020d2330 & 0xfffffffc) << (uRam020d2330 & 3) * -8 + 0x20;
    iVar5 = uVar4 + iRam020d2334;
  }
  *piRam020d232c = iVar5;
  *piVar3 = uVar4 + iVar2;
  return;
}

