/* Decompiled C draft; module arm7; ROM address 06007d6c. No matching claim. */
#include "types.h"
#include "deps/06007d6c_FUN_06007d6c.h"

void FUN_06007d6c(int param_1)

{
  short sVar1;
  undefined2 *puVar2;
  int unaff_r4;
  int iVar3;
  undefined1 auStack_220 [8];
  undefined1 auStack_218 [512];
  
  thunk_FUN_037fb390(param_1 + 4,auStack_220,6);
  for (iVar3 = 0; iVar3 < 2; iVar3 = iVar3 + 1) {
    unaff_r4 = FUN_060029f8((undefined2 *)(void *)(auStack_218),(undefined4)(uintptr_t)(auStack_220),0x13);
    sVar1 = *(short *)(unaff_r4 + 4);
    if ((sVar1 == 0) || ((sVar1 != 7 && (sVar1 != 0xc)))) break;
  }
  puVar2 = (undefined2 *)thunk_FUN_03807424();
  *puVar2 = 0x22;
  if (*(short *)(unaff_r4 + 4) == 0) {
    puVar2[1] = 0;
  }
  else {
    puVar2[1] = 1;
    puVar2[2] = 5;
    puVar2[3] = *(undefined2 *)(unaff_r4 + 4);
  }
  thunk_FUN_038074cc();
  return;
}

