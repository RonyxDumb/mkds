/* Decompiled C draft; module arm9; ROM address 020c5eb8. No matching claim. */
#include "types.h"
#include "deps/020c5eb8_StructE8_SomeFnHandle5.h"

void StructE8_SomeFnHandle5(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = func_020b1a20();
  if (iVar2 == 0) {
    func_020b1d64();
    uVar3 = uRam020c5f00;
    *(undefined4 *)
     (*(uint *)(uRam020c5f00 & 0xfffffffc) >> (uRam020c5f00 & 3) * 8 |
     *(uint *)(uRam020c5f00 & 0xfffffffc) << (uRam020c5f00 & 3) * -8 + 0x20) = uRam020c5f04;
    uVar1 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    *(undefined4 *)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 4) = 0;
    return;
  }
  return;
}

