/* Decompiled C draft; module arm9; ROM address 0212b1c0. No matching claim. */
#include "types.h"
#include "deps/0212b1c0_func_0212b1c0.h"

void func_0212b1c0(void)

{
  uint uVar1;
  int iVar2;
  code *UNRECOVERED_JUMPTABLE;
  uint uVar3;
  
  UNRECOVERED_JUMPTABLE = pcRam0212b200;
  uVar3 = (*(uint *)(uRam0212b1f4 & 0xfffffffc) >> (uRam0212b1f4 & 3) * 8 |
          *(uint *)(uRam0212b1f4 & 0xfffffffc) << (uRam0212b1f4 & 3) * -8 + 0x20) + 8;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  iVar2 = (int)uVar3 >> 0x1f;
  *puRam0212b1fc =
       uRam0212b1f8 &
       (((uint)(((int)uVar3 >> 0xc) * 0x1000000 + iVar2) >> 0x18 | iVar2 << 8) - iVar2) * 0x10000;
                    /* WARNING: Could not recover jumptable at 0x0212b1f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

