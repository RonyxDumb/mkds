/* Decompiled C draft; module arm9; ROM address 02016134. No matching claim. */
#include "types.h"
#include "deps/02016134_func_02016134.h"

void func_02016134(void)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  iVar3 = 0;
  uVar4 = (uint)*puRam020161ac;
  puVar2 = puRam020161b0;
  if (1 < uVar4) {
    uVar4 = uVar4 + 1;
  }
  do {
    if (iVar3 < (int)uVar4) {
      puVar2[2] = 1;
    }
    else {
      puVar2[2] = 0;
    }
    uVar1 = (uint)(puVar2 + 3) & 3;
    uVar5 = *(uint *)((uint)(puVar2 + 3) & 0xfffffffc);
    iVar3 = iVar3 + 1;
    if (uVar5 >> uVar1 * 8 == 0 && uVar5 << uVar1 * -8 + 0x20 == 0) {
      *puVar2 = 0;
      puVar2[1] = 0x20000;
    }
    else {
      *puVar2 = 0;
      puVar2[1] = 0x10000;
    }
    puVar2 = puVar2 + 6;
  } while (iVar3 < 5);
  return;
}

