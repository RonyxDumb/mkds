/* Decompiled C draft; module arm9; ROM address 020fa9e4. No matching claim. */
#include "types.h"
#include "deps/020fa9e4_func_020fa9e4.h"

void func_020fa9e4(void)

{
  uint uVar1;
  ushort *puVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  uVar6 = uRam020faa6c;
  iVar5 = 0;
  do {
    uVar1 = uVar6 & 3;
    uVar3 = *(uint *)(uVar6 & 0xfffffffc);
    func_020f03bc(iVar5 * 0x44 + (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20));
    uVar1 = uRam020faa74;
    puVar2 = puRam020faa70;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 0xe);
  uVar6 = 0;
  if (*puRam020faa70 == 0) {
    return;
  }
  do {
    uVar3 = uVar1 & 3;
    uVar4 = *(uint *)(uVar1 & 0xfffffffc);
    func_020f0044(uVar6 * 0x210 + (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20));
    uVar6 = uVar6 + 1 & 0xffff;
  } while (uVar6 < *puVar2);
  return;
}

