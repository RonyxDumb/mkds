/* Decompiled C draft; module arm7; ROM address 06013528. No matching claim. */
#include "types.h"
#include "deps/06013528_FUN_06013528.h"

undefined4 FUN_06013528(undefined4 param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = (*(uint *)(DAT_06013598 & 0xfffffffc) >> (DAT_06013598 & 3) * 8 |
          *(uint *)(DAT_06013598 & 0xfffffffc) << (DAT_06013598 & 3) * -8 + 0x20) + 0x1a0;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  while( true ) {
    if (uVar3 == 0xffffffff) {
      return 0;
    }
    if ((*(ushort *)(uVar3 + 0x24) == param_2) &&
       (iVar2 = FUN_0600a578(uVar3 + 0x28,param_1), iVar2 != 0)) break;
    uVar3 = FUN_06008e48(uVar3);
  }
  return 1;
}

