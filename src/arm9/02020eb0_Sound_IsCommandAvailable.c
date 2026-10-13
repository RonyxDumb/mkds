/* Decompiled C draft; module arm9; ROM address 02020eb0. No matching claim. */
#include "types.h"
#include "deps/02020eb0_Sound_IsCommandAvailable.h"

bool Sound_IsCommandAvailable(void)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = Os_IsEmulator();
  if (iVar3 != 0) {
    Os_DisableIrq(iVar3);
    puVar2 = puRam02020ef4;
    *puRam02020ef4 = 0x10;
    uVar1 = (uint)puVar2 & 3;
    uVar4 = *(uint *)((uint)puVar2 & 0xfffffffc);
    Os_RestoreIrq();
    return uVar4 >> uVar1 * 8 != 0 || uVar4 << uVar1 * -8 + 0x20 != 0;
  }
  return true;
}

