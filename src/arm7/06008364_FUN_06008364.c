/* Decompiled C draft; module arm7; ROM address 06008364. No matching claim. */
#include "types.h"
#include "deps/06008364_FUN_06008364.h"

void FUN_06008364(void)

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
                *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) == 2) {
    iVar1 = FUN_06002124((undefined4)(uintptr_t)(auStack_210));
    if (*(short *)(iVar1 + 4) == 0) {
      *(undefined2 *)
       (*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
       *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) = 1;
      puVar2 = (undefined2 *)thunk_FUN_03807424();
      *puVar2 = 6;
      puVar2[1] = 0;
      thunk_FUN_038074cc();
    }
    else {
      puVar2 = (undefined2 *)thunk_FUN_03807424();
      *puVar2 = 6;
      puVar2[1] = 1;
      puVar2[2] = (short)DAT_06008418;
      puVar2[3] = *(undefined2 *)(iVar1 + 4);
      thunk_FUN_038074cc();
    }
  }
  else {
    puVar2 = (undefined2 *)thunk_FUN_03807424();
    *puVar2 = 6;
    puVar2[1] = 3;
    thunk_FUN_038074cc();
  }
  return;
}

