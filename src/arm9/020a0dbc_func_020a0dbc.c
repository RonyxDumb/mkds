/* Decompiled C draft; module arm9; ROM address 020a0dbc. No matching claim. */
#include "types.h"
#include "deps/020a0dbc_func_020a0dbc.h"

void func_020a0dbc(void)

{
  uint uVar1;
  uint uVar2;
  code *pcVar3;
  
  uVar1 = uRam020a0dfc;
  *(undefined4 *)
   ((*(uint *)(uRam020a0dfc & 0xfffffffc) >> (uRam020a0dfc & 3) * 8 |
    *(uint *)(uRam020a0dfc & 0xfffffffc) << (uRam020a0dfc & 3) * -8 + 0x20) + 0x3a8) = 0xffffffff;
  uVar2 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  uVar2 = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) + 0x390;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  pcVar3 = (code *)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  if (pcVar3 != (code *)0x0) {
    (*pcVar3)();
    return;
  }
  return;
}

