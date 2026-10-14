/* Decompiled C draft; module arm9; ROM address 0201e5ac. No matching claim. */
#include "types.h"
#include "deps/0201e5ac_Fifo15Handler.h"

void Fifo15Handler(undefined4 param_1,uint param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  code *pcVar5;
  
  uVar3 = param_2 & 0xff;
  pcVar5 = (code *)(*(uint *)((uint)puRam0201e6a8 & 0xfffffffc) >> ((uint)puRam0201e6a8 & 3) * 8 |
                   *(uint *)((uint)puRam0201e6a8 & 0xfffffffc) <<
                   ((uint)puRam0201e6a8 & 3) * -8 + 0x20);
  uVar1 = (uint)puRam0201e6ac & 3;
  uVar4 = *(uint *)((uint)puRam0201e6ac & 0xfffffffc);
  if ((param_2 & 0xffff0000) == 0x10000) {
    if (((uVar3 == 7) && (*psRam0201e6b0 != 0)) && (*psRam0201e6b4 != 0)) {
      Os_UnlockVram(*psRam0201e6b0,*psRam0201e6b4);
      *psRam0201e6b0 = 0;
    }
  }
  else if ((param_2 & 0xffff0000) == 0x20000) {
    if (((uVar3 == 0) && (*psRam0201e6b0 != 0)) && (*psRam0201e6b4 != 0)) {
      Os_UnlockVram(*psRam0201e6b0,*psRam0201e6b4);
      *psRam0201e6b0 = 0;
    }
    Fifo_RegisterHandler(0xf,0);
  }
  puVar2 = puRam0201e6ac;
  if (pcVar5 == (code *)0x0) {
    return;
  }
  *puRam0201e6a8 = 0;
  *puVar2 = 0;
  (*pcVar5)(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20,uVar3);
  return;
}

