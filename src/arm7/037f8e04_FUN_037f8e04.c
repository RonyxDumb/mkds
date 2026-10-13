/* Decompiled C draft; module arm7; ROM address 037f8e04. No matching claim. */
#include "types.h"
#include "deps/037f8e04_FUN_037f8e04.h"

void FUN_037f8e04(int param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint local_3c;
  undefined1 auStack_38 [44];
  
  FUN_037fa814((undefined4 *)(void *)(auStack_38));
  uVar2 = *(uint *)(DAT_037f8e8c & 0xfffffffc) >> (DAT_037f8e8c & 3) * 8 |
          *(uint *)(DAT_037f8e8c & 0xfffffffc) << (DAT_037f8e8c & 3) * -8 + 0x20;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  local_3c = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  uVar3 = FUN_037faf70();
  *(undefined1 **)(local_3c + 0x94) = auStack_38;
  FUN_037fa670((undefined4 *)(void *)(auStack_38),(uint)(param_1 * DAT_037f8e90) >> 6,0,DAT_037f8e94,(undefined4)(uintptr_t)(&local_3c));
  while (local_3c != 0) {
    FUN_037f9104(0);
  }
  FUN_037faf84(uVar3);
  return;
}

