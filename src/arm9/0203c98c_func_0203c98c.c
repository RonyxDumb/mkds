/* Decompiled C draft; module arm9; ROM address 0203c98c. No matching claim. */
#include "types.h"
#include "deps/0203c98c_func_0203c98c.h"

void func_0203c98c(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  Struct5624_SetXflag2(1);
  iVar2 = iRam0203ca1c;
  uVar1 = uRam0203ca18;
  uVar6 = 0;
  uVar5 = *(uint *)(uRam0203ca18 & 0xfffffffc) >> (uRam0203ca18 & 3) * 8 |
          *(uint *)(uRam0203ca18 & 0xfffffffc) << (uRam0203ca18 & 3) * -8 + 0x20;
  if (*(char *)(uVar5 + 0x3d0) == '\0') {
    return;
  }
  do {
    uVar5 = uVar6 * 0x30 + uVar5 + 0x7c;
    uVar3 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    iVar4 = (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) * 0x5c + iVar2;
    uVar5 = iVar4 + 0x3cU & 3;
    uVar3 = *(uint *)(iVar4 + 0x3cU & 0xfffffffc);
    uVar5 = uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20;
    if (uVar5 == 1) {
      func_0204a910(iVar4 + 0x28);
    }
    else if (uVar5 == 2) {
      func_0204a978(iVar4 + 0x28);
    }
    uVar5 = uVar1 & 3;
    uVar3 = *(uint *)(uVar1 & 0xfffffffc);
    uVar5 = uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20;
    uVar6 = uVar6 + 1 & 0xffff;
  } while (uVar6 < *(byte *)(uVar5 + 0x3d0));
  return;
}

