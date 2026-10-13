/* Decompiled C draft; module arm7; ROM address 060082b4. No matching claim. */
#include "types.h"
#include "deps/060082b4_FUN_060082b4.h"

void FUN_060082b4(void)

{
  int iVar1;
  undefined2 *puVar2;
  uint uVar3;
  undefined2 local_10;
  undefined2 local_e [3];
  uint uVar4;
  
  iVar1 = FUN_06000680();
  uVar4 = iVar1 + 0x154cU & 3;
  uVar3 = *(uint *)(iVar1 + 0x154cU & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  if (*(short *)(*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
                *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) == 1) {
    iVar1 = FUN_0600808c(&local_10,local_e);
    if (iVar1 == 0) {
      puVar2 = (undefined2 *)thunk_FUN_03807424();
      *puVar2 = 5;
      puVar2[1] = 1;
      puVar2[2] = local_10;
      puVar2[3] = local_e[0];
      thunk_FUN_038074cc();
    }
    else {
      *(undefined2 *)
       (*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
       *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) = 2;
      puVar2 = (undefined2 *)thunk_FUN_03807424();
      *puVar2 = 5;
      puVar2[1] = 0;
      thunk_FUN_038074cc();
    }
  }
  else {
    puVar2 = (undefined2 *)thunk_FUN_03807424();
    *puVar2 = 5;
    puVar2[1] = 3;
    thunk_FUN_038074cc();
  }
  return;
}

