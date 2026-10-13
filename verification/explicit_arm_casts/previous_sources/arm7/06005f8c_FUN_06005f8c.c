/* Decompiled C draft; module arm7; ROM address 06005f8c. No matching claim. */
#include "types.h"
#include "deps/06005f8c_FUN_06005f8c.h"

void FUN_06005f8c(void)

{
  int iVar1;
  undefined2 *puVar2;
  undefined1 auStack_208 [520];
  
  FUN_06000680();
  iVar1 = FUN_060020c8(auStack_208);
  if (*(short *)(iVar1 + 4) == 0) {
    puVar2 = (undefined2 *)thunk_FUN_03807424();
    *puVar2 = 0x1f;
    puVar2[1] = 0;
    thunk_FUN_038074cc();
  }
  else {
    FUN_06005f50(DAT_06005fdc);
  }
  return;
}

