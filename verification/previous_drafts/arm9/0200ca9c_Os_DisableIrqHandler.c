/* Decompiled C draft; module arm9; ROM address 0200ca9c. No matching claim. */
#include "types.h"
#include "deps/0200ca9c_Os_DisableIrqHandler.h"

void Os_DisableIrqHandler(uint param_1)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  uint *puVar3;
  
  puVar3 = puRam0200cae0;
  puVar2 = puRam0200cadc;
  uVar1 = *puRam0200cadc;
  *puRam0200cadc = 0;
  *puVar3 = (*(uint *)((uint)puVar3 & 0xfffffffc) >> ((uint)puVar3 & 3) * 8 |
            *(uint *)((uint)puVar3 & 0xfffffffc) << ((uint)puVar3 & 3) * -8 + 0x20) & ~param_1;
  *puVar2 = uVar1;
  return;
}

