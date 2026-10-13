/* Decompiled C draft; module arm7; ROM address 06004298. No matching claim. */
#include "types.h"
#include "deps/06004298_FUN_06004298.h"

void FUN_06004298(void)

{
  int iVar1;
  undefined2 *puVar2;
  uint uVar3;
  undefined1 auStack_210 [516];
  uint uVar4;
  
  iVar1 = FUN_06000680();
  uVar4 = iVar1 + 0x154cU & 3;
  uVar3 = *(uint *)(iVar1 + 0x154cU & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  if (*(short *)(*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
                *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) == 5) {
    iVar1 = FUN_0600210c(auStack_210);
    if (*(short *)(iVar1 + 4) == 0) {
      *(undefined2 *)
       (*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
       *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) = 2;
      if (*(short *)((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
                     *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 0x1ea) == 0) {
        iVar1 = FUN_06002400(auStack_210,1);
        if (*(short *)(iVar1 + 4) != 0) {
          FUN_0600425c(DAT_06004378);
          return;
        }
        *(undefined2 *)
         ((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
          *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 0x1ea) = 1;
      }
      puVar2 = (undefined2 *)thunk_FUN_03807424();
      *puVar2 = 0xb;
      puVar2[1] = 0;
      thunk_FUN_038074cc();
    }
    else {
      FUN_0600425c(DAT_06004374);
    }
  }
  else {
    puVar2 = (undefined2 *)thunk_FUN_03807424();
    *puVar2 = 0xb;
    puVar2[1] = 3;
    thunk_FUN_038074cc();
  }
  return;
}

