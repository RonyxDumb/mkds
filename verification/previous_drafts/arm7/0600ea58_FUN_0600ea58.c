/* Decompiled C draft; module arm7; ROM address 0600ea58. No matching claim. */
#include "types.h"
#include "deps/0600ea58_FUN_0600ea58.h"

void FUN_0600ea58(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = (*(uint *)(DAT_0600ea78 & 0xfffffffc) >> (DAT_0600ea78 & 3) * 8 |
          *(uint *)(DAT_0600ea78 & 0xfffffffc) << (DAT_0600ea78 & 3) * -8 + 0x20) + 0x31c;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  iVar2 = param_1 * 0x1c + (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
  *(undefined2 *)(iVar2 + 0x18) = *(undefined2 *)(iVar2 + 0x1a);
  return;
}

