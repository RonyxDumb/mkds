/* Decompiled C draft; module arm9; ROM address 0214cd94. No matching claim. */
#include "types.h"
#include "deps/0214cd94_SomeDmaIrqHandler.h"

void SomeDmaIrqHandler(void)

{
  uint uVar1;
  undefined4 *puVar2;
  code *pcVar3;
  uint uVar4;
  
  Os_DisableIrqHandler(0x200000);
  puVar2 = puRam0214ce04;
  uVar1 = (uint)(puRam0214ce04 + 6) & 3;
  uVar4 = *(uint *)((uint)(puRam0214ce04 + 6) & 0xfffffffc);
  *puRam0214ce00 =
       (*(uint *)((uint)puRam0214ce00 & 0xfffffffc) >> ((uint)puRam0214ce00 & 3) * 8 |
       *(uint *)((uint)puRam0214ce00 & 0xfffffffc) << ((uint)puRam0214ce00 & 3) * -8 + 0x20) &
       0x3fffffff | (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) << 0x1e;
  uVar1 = (uint)(puVar2 + 7) & 3;
  uVar4 = *(uint *)((uint)(puVar2 + 7) & 0xfffffffc);
  Os_SetIrqHandler(0x200000,uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20);
  puVar2 = puRam0214ce04;
  uVar1 = (uint)(puRam0214ce04 + 4) & 3;
  uVar4 = *(uint *)((uint)(puRam0214ce04 + 4) & 0xfffffffc);
  pcVar3 = (code *)(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20);
  *puRam0214ce04 = 0;
  uVar1 = (uint)(puVar2 + 5) & 3;
  uVar4 = *(uint *)((uint)(puVar2 + 5) & 0xfffffffc);
  if (pcVar3 != (code *)0x0) {
    (*pcVar3)(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20);
    return;
  }
  return;
}

