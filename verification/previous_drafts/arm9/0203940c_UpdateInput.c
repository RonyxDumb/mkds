/* Decompiled C draft; module arm9; ROM address 0203940c. No matching claim. */
#include "types.h"
#include "deps/0203940c_UpdateInput.h"

void UpdateInput(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = iRam02039468 + 0x24U & 3;
  uVar1 = *(uint *)(iRam02039468 + 0x24U & 0xfffffffc);
  if (uVar1 >> uVar2 * 8 == 0 && uVar1 << uVar2 * -8 + 0x20 == 0) {
    uVar2 = ((*puRam0203946c | *puRam02039470) ^ uRam02039474) & uRam02039474 & 0xffff;
  }
  else {
    uVar2 = GetSomeInput();
  }
  StructG_UpdateInput(uVar2,(ushort *)(uintptr_t)(iRam02039468));
  return;
}

