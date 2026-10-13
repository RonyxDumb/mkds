/* Decompiled C draft; module arm9; ROM address 0207aa7c. No matching claim. */
#include "types.h"
#include "deps/0207aa7c_func_0207aa7c.h"

void func_0207aa7c(void)

{
  uint uVar1;
  ushort *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  iVar3 = iRam0207aae8;
  puVar2 = puRam0207aae0;
  uVar5 = *(uint *)(uRam0207aae4 & 0xfffffffc) >> (uRam0207aae4 & 3) * 8 |
          *(uint *)(uRam0207aae4 & 0xfffffffc) << (uRam0207aae4 & 3) * -8 + 0x20;
  iVar6 = 0;
  if (*puRam0207aae0 == 0) {
    return;
  }
  do {
    uVar1 = uVar5 + 0x214 & 3;
    uVar4 = *(uint *)(uVar5 + 0x214 & 0xfffffffc);
    (*(code *)(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20))(uVar5);
    iVar6 = (iVar6 + 1) * 0x10000 >> 0x10;
    uVar5 = uVar5 + iVar3;
  } while (iVar6 < (int)(uint)*puVar2);
  return;
}

