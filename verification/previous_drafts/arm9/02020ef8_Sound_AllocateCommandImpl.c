/* Decompiled C draft; module arm9; ROM address 02020ef8. No matching claim. */
#include "types.h"
#include "deps/02020ef8_Sound_AllocateCommandImpl.h"

uint Sound_AllocateCommandImpl(void)

{
  uint uVar1;
  uint uVar2;
  
  Os_DisableIrq();
  uVar2 = *(uint *)((uint)puRam02020f48 & 0xfffffffc) >> ((uint)puRam02020f48 & 3) * 8 |
          *(uint *)((uint)puRam02020f48 & 0xfffffffc) << ((uint)puRam02020f48 & 3) * -8 + 0x20;
  if (uVar2 != 0) {
    uVar1 = *(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
            *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20;
    *puRam02020f48 = uVar1;
    if (uVar1 == 0) {
      *puRam02020f4c = 0;
    }
    Os_RestoreIrq();
    return uVar2;
  }
  Os_RestoreIrq();
  return 0;
}

