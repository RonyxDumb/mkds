/* Decompiled C draft; module arm7; ROM address 0600bd44. No matching claim. */
#include "types.h"
#include "deps/0600bd44_FUN_0600bd44.h"

void FUN_0600bd44(undefined4 param_1,undefined2 param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = *(uint *)(DAT_0600bdd8 & 0xfffffffc) >> (DAT_0600bdd8 & 3) * 8 |
          *(uint *)(DAT_0600bdd8 & 0xfffffffc) << (DAT_0600bdd8 & 3) * -8 + 0x20;
  uVar1 = uVar3 + 0x3e0;
  uVar2 = uVar1 & 3;
  uVar4 = *(uint *)(uVar1 & 0xfffffffc);
  thunk_FUN_037fb218(0,uVar3 + 0x31c,0x28);
  thunk_FUN_037fb218(0,(*(uint *)(DAT_0600bdd8 & 0xfffffffc) >> (DAT_0600bdd8 & 3) * 8 |
                       *(uint *)(DAT_0600bdd8 & 0xfffffffc) << (DAT_0600bdd8 & 3) * -8 + 0x20) +
                       0x344,0xc0);
  uVar1 = DAT_0600bdd8;
  *(undefined4 *)
   ((*(uint *)(DAT_0600bdd8 & 0xfffffffc) >> (DAT_0600bdd8 & 3) * 8 |
    *(uint *)(DAT_0600bdd8 & 0xfffffffc) << (DAT_0600bdd8 & 3) * -8 + 0x20) + 0x31c) = param_1;
  *(undefined2 *)
   ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 800) = param_2;
  *(undefined2 *)
   ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x322) = param_2;
  *(uint *)((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
            *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x3e0) =
       uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20;
  return;
}

