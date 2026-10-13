/* Decompiled C draft; module arm9; ROM address 020a21bc. No matching claim. */
#include "types.h"
#include "deps/020a21bc_func_020a21bc.h"

void func_020a21bc(undefined4 param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  code *pcVar3;
  
  if (param_2 == 0) {
    return;
  }
  uVar2 = (*(uint *)(uRam020a2200 & 0xfffffffc) >> (uRam020a2200 & 3) * 8 |
          *(uint *)(uRam020a2200 & 0xfffffffc) << (uRam020a2200 & 3) * -8 + 0x20) + 0x39c;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  pcVar3 = (code *)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  if (pcVar3 != (code *)0x0) {
    (*pcVar3)();
    return;
  }
  return;
}

