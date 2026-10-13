/* Decompiled C draft; module arm7; ROM address 0600601c. No matching claim. */
#include "types.h"
#include "deps/0600601c_FUN_0600601c.h"

void FUN_0600601c(void)

{
  int iVar1;
  undefined2 *puVar2;
  undefined1 auStack_210 [516];
  
  FUN_06000680();
  iVar1 = FUN_06002098(auStack_210);
  if (*(short *)(iVar1 + 4) == 0) {
    puVar2 = (undefined2 *)thunk_FUN_03807424();
    *puVar2 = 0x20;
    puVar2[1] = 0;
    thunk_FUN_037fb230(iVar1 + 8,puVar2 + 4,0xb4);
    thunk_FUN_038074cc(puVar2);
  }
  else {
    FUN_06005fe0(DAT_06006088);
  }
  return;
}

