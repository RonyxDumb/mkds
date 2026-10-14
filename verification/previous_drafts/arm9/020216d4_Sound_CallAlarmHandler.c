/* Decompiled C draft; module arm9; ROM address 020216d4. No matching claim. */
#include "types.h"
#include "deps/020216d4_Sound_CallAlarmHandler.h"

void Sound_CallAlarmHandler(uint param_1)

{
  uint uVar1;
  code *pcVar2;
  uint uVar3;
  
  uVar3 = (param_1 & 0xff) * 0xc + iRam02021730;
  if (((int)param_1 >> 8 & 0xffU) != (uint)*(byte *)(uVar3 + 8)) {
    return;
  }
  pcVar2 = (code *)(*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                   *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20);
  if (pcVar2 != (code *)0x0) {
    uVar1 = uVar3 + 4 & 3;
    uVar3 = *(uint *)(uVar3 + 4 & 0xfffffffc);
    (*pcVar2)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
    return;
  }
  return;
}

