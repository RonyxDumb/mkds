/* Decompiled C draft; module arm7; ROM address 060155bc. No matching claim. */
#include "types.h"
#include "deps/060155bc_FUN_060155bc.h"

void FUN_060155bc(void)

{
  undefined2 uVar1;
  uint uVar2;
  uint uVar3;
  int unaff_r4;
  undefined2 *puVar4;
  
  uVar3 = *(uint *)(DAT_060156e4 & 0xfffffffc) >> (DAT_060156e4 & 3) * 8 |
          *(uint *)(DAT_060156e4 & 0xfffffffc) << (DAT_060156e4 & 3) * -8 + 0x20;
  puVar4 = (undefined2 *)(uVar3 + DAT_060156e8);
  thunk_FUN_037fb24c(0,puVar4,0x50);
  *DAT_060156ec = 0x8000;
  uVar2 = (uint)*(ushort *)
                 ((*(uint *)(DAT_060156e4 & 0xfffffffc) >> (DAT_060156e4 & 3) * 8 |
                  *(uint *)(DAT_060156e4 & 0xfffffffc) << (DAT_060156e4 & 3) * -8 + 0x20) + 0x350);
                    /* WARNING: Could not recover jumptable at 0x06015610. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  if (uVar2 < 4) {
    (*(code *)(uVar2 * 4 + 0x6015618))();
    return;
  }
  *DAT_06015700 = (short)unaff_r4 + (short)DAT_060156fc;
  uVar1 = (undefined2)((uint)(unaff_r4 << 0xf) >> 0x10);
  *DAT_06015704 = uVar1;
  *DAT_0601570c = (short)DAT_06015708;
  *DAT_06015710 = uVar1;
  puVar4[2] = uVar1;
  uVar1 = (undefined2)DAT_06015714;
  *puVar4 = uVar1;
  *(short *)(uVar3 + 0x3de) = (short)DAT_06015718 - (short)unaff_r4;
  *DAT_06015720 = (short)DAT_0601571c;
  *DAT_060156ec = (short)DAT_06015724;
  *DAT_06015728 = uVar1;
  *DAT_0601572c = uVar1;
  *DAT_06015730 = uVar1;
  *DAT_06015734 = uVar1;
  *DAT_06015738 = uVar1;
  *DAT_0601573c = uVar1;
  return;
}

