/* Decompiled C draft; module arm9; ROM address 02150164. No matching claim. */
#include "types.h"
#include "deps/02150164_func_02150164.h"

void func_02150164(undefined4 param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  code *pcVar4;
  
  puVar2 = puRam021501b4;
  uVar1 = (uint)(puRam021501b4 + 1) & 3;
  uVar3 = *(uint *)((uint)(puRam021501b4 + 1) & 0xfffffffc);
  pcVar4 = (code *)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
  if (*(uint *)((uint)puRam021501b4 & 0xfffffffc) >> ((uint)puRam021501b4 & 3) * 8 != 0 ||
      *(uint *)((uint)puRam021501b4 & 0xfffffffc) << ((uint)puRam021501b4 & 3) * -8 + 0x20 != 0) {
    *puRam021501b4 = 0;
  }
  uVar1 = (uint)(puVar2 + 2) & 3;
  uVar3 = *(uint *)((uint)(puVar2 + 2) & 0xfffffffc);
  if (pcVar4 != (code *)0x0) {
    puRam021501b4[1] = 0;
    (*pcVar4)(param_1,uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
    return;
  }
  return;
}

