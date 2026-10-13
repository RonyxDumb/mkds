/* Decompiled C draft; module arm9; ROM address 02020430. No matching claim. */
#include "types.h"
#include "deps/02020430_func_02020430.h"

void func_02020430(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  undefined1 *puVar4;
  int iVar5;
  
  puVar4 = puRam02020494;
  puVar3 = puRam02020490;
  puVar2 = puRam0202048c;
  puVar1 = puRam02020488;
  iVar5 = 0;
  *puRam02020484 = param_1;
  *puVar1 = 1;
  *puVar2 = 0;
  *puVar3 = 0;
  do {
    iVar5 = iVar5 + 1;
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  } while (iVar5 < 4);
  return;
}

