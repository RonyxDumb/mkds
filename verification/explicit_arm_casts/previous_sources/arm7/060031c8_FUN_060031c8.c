/* Decompiled C draft; module arm7; ROM address 060031c8. No matching claim. */
#include "types.h"
#include "deps/060031c8_FUN_060031c8.h"

void FUN_060031c8(void)

{
  int iVar1;
  undefined2 *puVar2;
  uint uVar3;
  undefined1 auStack_208 [512];
  uint uVar4;
  
  iVar1 = FUN_06000680();
  uVar4 = iVar1 + 0x154cU & 3;
  uVar3 = *(uint *)(iVar1 + 0x154cU & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  if (*(short *)(*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
                *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) == 2) {
    iVar1 = FUN_06002124(auStack_208);
    if (*(short *)(iVar1 + 4) == 0) {
      *(undefined2 *)
       (*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
       *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) = 1;
      thunk_FUN_03802c6c();
      *(undefined2 *)
       (*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
       *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) = 0;
      puVar2 = (undefined2 *)thunk_FUN_03807424();
      *puVar2 = 2;
      puVar2[1] = 0;
      thunk_FUN_038074cc();
    }
    else {
      FUN_0600318c(DAT_06003268);
    }
  }
  else {
    puVar2 = (undefined2 *)thunk_FUN_03807424();
    *puVar2 = 2;
    puVar2[1] = 3;
    thunk_FUN_038074cc();
  }
  return;
}

