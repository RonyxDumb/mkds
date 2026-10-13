/* Decompiled C draft; module arm9; ROM address 0207a218. No matching claim. */
#include "types.h"
#include "deps/0207a218_func_0207a218.h"

/* WARNING: Removing unreachable block (ram,0x0207a274) */

undefined4 func_0207a218(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  
  uVar5 = 1;
  uVar2 = *(uint *)(uRam0207a298 & 0xfffffffc) >> (uRam0207a298 & 3) * 8 |
          *(uint *)(uRam0207a298 & 0xfffffffc) << (uRam0207a298 & 3) * -8 + 0x20;
  uVar4 = uVar2 + 8;
  uVar1 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  if (((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) == 4) &&
     ((((iVar3 = *(char *)(uVar2 + 0x62) * iRam0207a2a0 +
                 (*(uint *)(uRam0207a29c & 0xfffffffc) >> (uRam0207a29c & 3) * 8 |
                 *(uint *)(uRam0207a29c & 0xfffffffc) << (uRam0207a29c & 3) * -8 + 0x20),
        uVar4 = iVar3 + 0x180U & 3, uVar1 = *(uint *)(iVar3 + 0x180U & 0xfffffffc),
        uVar1 >> uVar4 * 8 != 0 || uVar1 << uVar4 * -8 + 0x20 != 0 ||
        (uVar4 = iVar3 + 0x48U & 3, uVar1 = *(uint *)(iVar3 + 0x48U & 0xfffffffc),
        ((uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20) & uRam0207a2a4) != 0)) ||
       (uVar4 = iVar3 + 0x44U & 3, uVar1 = *(uint *)(iVar3 + 0x44U & 0xfffffffc),
       ((uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20) & 0x10) == 0)) ||
      (iVar3 = func_0x021816b4(), iVar3 != 0)))) {
    uVar5 = 0;
  }
  return uVar5;
}

