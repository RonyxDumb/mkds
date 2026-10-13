/* Decompiled C draft; module arm7; ROM address 06000294. No matching claim. */
#include "types.h"
#include "deps/06000294_FUN_06000294.h"

bool FUN_06000294(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  bool bVar5;
  uint uVar4;
  
  iVar1 = FUN_06000680();
  uVar2 = iVar1 + 0x154cU & 3;
  uVar3 = *(uint *)(iVar1 + 0x154cU & 0xfffffffc);
  uVar4 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
  thunk_FUN_037fb390((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
                     *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 0xdc,param_2 + 0x10
                     ,6);
  *(undefined2 *)(param_2 + 0x16) = 7;
  *(undefined2 *)(param_2 + 0x18) =
       *(undefined2 *)
        ((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
         *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 0x1f0);
  *(undefined2 *)(param_2 + 0x1e) =
       *(undefined2 *)
        ((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
         *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 0x1e8);
  *(undefined2 *)(param_2 + 0x1c) =
       *(undefined2 *)
        ((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
         *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 0xe2);
  uVar2 = (*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
          *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 0x194;
  uVar3 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if (uVar2 >> uVar3 * 8 == 0 && uVar2 << uVar3 * -8 + 0x20 == 0) {
    *(undefined2 *)(param_2 + 0x20) = 0;
    *(undefined2 *)(param_2 + 0x22) = 0;
    thunk_FUN_037fb218(0,param_2 + 0x24,0x50);
    *(undefined2 *)(param_2 + 0x9e) = 0;
  }
  else {
    FUN_06000680();
    *(undefined2 *)(param_2 + 0x20) =
         *(undefined2 *)
          ((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
           *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 0x192);
    *(undefined2 *)(param_2 + 0x22) =
         *(undefined2 *)
          ((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
           *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 0xc0);
    thunk_FUN_037fb390((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
                       *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 0x198,
                       param_2 + 0x24,0x50);
    *(undefined2 *)(param_2 + 0x9e) = 1;
  }
  *(undefined2 *)(param_2 + 0x74) = 1;
  *(undefined2 *)(param_2 + 0x76) = 1;
  if (*(short *)((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
                 *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 0xe2) == 1) {
    *(undefined2 *)(param_2 + 0x78) = 0;
  }
  else {
    *(undefined2 *)(param_2 + 0x78) = 0x10;
  }
  *(undefined2 *)(param_2 + 0x7a) = 10;
  if (param_1 == 0x26) {
    thunk_FUN_037fb218(0,param_2 + 0x7c,0x20);
  }
  else {
    thunk_FUN_037fb218(0,param_2 + 0x7c,8);
    thunk_FUN_037fb218(DAT_06000438 & 0xffff,param_2 + 0x84,0x18);
  }
  *(undefined2 *)(param_2 + 0x9c) =
       *(undefined2 *)
        ((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
         *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 0x1ea);
  iVar1 = FUN_060025a0((undefined2 *)(uintptr_t)(param_2));
  bVar5 = *(short *)(iVar1 + 4) == 0;
  if (!bVar5) {
    FUN_06000080(param_1,0x200);
  }
  return bVar5;
}

