/* Decompiled C draft; module arm7; ROM address 06007fe4. No matching claim. */
#include "types.h"
#include "deps/06007fe4_FUN_06007fe4.h"

void FUN_06007fe4(void)

{
  int iVar1;
  undefined2 *puVar2;
  uint uVar3;
  uint uVar4;
  
  iVar1 = FUN_06000680();
  uVar4 = iVar1 + 0x154cU & 3;
  uVar3 = *(uint *)(iVar1 + 0x154cU & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  if (*(short *)(*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
                *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) == 1) {
    thunk_FUN_03802c6c(1);
    *(undefined2 *)
     (*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
     *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) = 0;
    puVar2 = (undefined2 *)thunk_FUN_03807424();
    *puVar2 = 4;
    puVar2[1] = 0;
    thunk_FUN_038074cc();
  }
  else {
    puVar2 = (undefined2 *)thunk_FUN_03807424();
    *puVar2 = 4;
    puVar2[1] = 3;
    thunk_FUN_038074cc();
  }
  return;
}

