/* Decompiled C draft; module arm9; ROM address 0200cae4. No matching claim. */
#include "types.h"
#include "deps/0200cae4_Os_EnableIrqHandler.h"

uint Os_EnableIrqHandler(uint param_1)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  uint *puVar3;
  uint uVar4;
  
  puVar3 = puRam0200cb18;
  puVar2 = puRam0200cb14;
  uVar1 = *puRam0200cb14;
  *puRam0200cb14 = 0;
  uVar4 = *(uint *)((uint)puVar3 & 0xfffffffc) >> ((uint)puVar3 & 3) * 8 |
          *(uint *)((uint)puVar3 & 0xfffffffc) << ((uint)puVar3 & 3) * -8 + 0x20;
  *puVar3 = uVar4 | param_1;
  *puVar2 = uVar1;
  return uVar4;
}

