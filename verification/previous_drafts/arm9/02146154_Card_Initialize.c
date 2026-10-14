/* Decompiled C draft; module arm9; ROM address 02146154. No matching claim. */
#include "types.h"
#include "deps/02146154_Card_Initialize.h"

void Card_Initialize(void)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 uVar5;
  
  iVar2 = iRam021461cc;
  uVar1 = iRam021461cc + 0x114U & 3;
  uVar4 = *(uint *)(iRam021461cc + 0x114U & 0xfffffffc);
  if (uVar4 >> uVar1 * 8 == 0 && uVar4 << uVar1 * -8 + 0x20 == 0) {
    *(undefined4 *)(iRam021461cc + 0x114) = 1;
    *(undefined4 *)(iVar2 + 0x24) = 0;
    uVar1 = iVar2 + 0x24U & 3;
    uVar4 = *(uint *)(iVar2 + 0x24U & 0xfffffffc);
    *(uint *)(iVar2 + 0x20) = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
    puVar3 = puRam021461d0;
    uVar1 = iVar2 + 0x20U & 3;
    uVar4 = *(uint *)(iVar2 + 0x20U & 0xfffffffc);
    *(uint *)(iVar2 + 0x1c) = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
    *(undefined4 *)(iVar2 + 0x28) = 0xffffffff;
    *(undefined4 *)(iVar2 + 0x38) = 0;
    *(undefined4 *)(iVar2 + 0x3c) = 0;
    *puVar3 = 0;
    Card_InitializeContext();
    uVar5 = Card_GetRomAccessFunction();
    *puRam021461d4 = uVar5;
    Card_InitializePulledOutCallback();
    return;
  }
  return;
}

