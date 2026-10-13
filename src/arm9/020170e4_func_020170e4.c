/* Decompiled C draft; module arm9; ROM address 020170e4. No matching claim. */
#include "types.h"
#include "deps/020170e4_func_020170e4.h"

void func_020170e4(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar1 = iRam02017130 + 0x10U & 3;
  uVar5 = *(uint *)(iRam02017130 + 0x10U & 0xfffffffc);
  uVar6 = iRam02017130 + 0xcU & 3;
  uVar3 = *(uint *)(iRam02017130 + 0xcU & 0xfffffffc);
  uVar4 = func_02016cd8(uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20,
                        (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) >> 4);
  iVar2 = iRam02017130;
  *(undefined4 *)(iRam02017130 + 4) = uVar4;
  func_02016d28((undefined4 *)(uintptr_t)(iVar2));
  uVar1 = iRam02017130 + 8U & 3;
  uVar6 = *(uint *)(iRam02017130 + 8U & 0xfffffffc);
  func_02016c64((undefined4 *)(uintptr_t)(iRam02017130),(uint *)(uintptr_t)(uRam02017134),0,uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20);
  return;
}

