/* Decompiled C draft; module arm9; ROM address 020fa8ac. No matching claim. */
#include "types.h"
#include "deps/020fa8ac_func_020fa8ac.h"

/* WARNING: Removing unreachable block (ram,0x020fa8cc) */
/* WARNING: Removing unreachable block (ram,0x020fa8c8) */
/* WARNING: Removing unreachable block (ram,0x020fa8d0) */

void func_020fa8ac(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  iVar3 = func_020e6b38();
  func_020e6a74();
  uVar2 = uRam020fa91c;
  iVar6 = 0;
  do {
    uVar1 = uVar2 & 3;
    uVar4 = *(uint *)(uVar2 & 0xfffffffc);
    iVar5 = iVar6 * 0x44 + (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20);
    uVar1 = iVar5 + 0x10U & 3;
    uVar4 = *(uint *)(iVar5 + 0x10U & 0xfffffffc);
    if ((0 < (int)(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20)) &&
       (uVar1 = iVar5 + 0x40U & 3, uVar4 = *(uint *)(iVar5 + 0x40U & 0xfffffffc),
       uVar4 >> uVar1 * 8 == 0 && uVar4 << uVar1 * -8 + 0x20 == 0)) {
      func_020f0df8(iVar5,iVar3 + 0x18);
    }
    iVar6 = iVar6 + 1;
  } while (iVar6 < 0xe);
  return;
}

