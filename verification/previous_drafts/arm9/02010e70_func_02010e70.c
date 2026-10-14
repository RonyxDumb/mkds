/* Decompiled C draft; module arm9; ROM address 02010e70. No matching claim. */
#include "types.h"
#include "deps/02010e70_func_02010e70.h"

void func_02010e70(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  MTX_Concat43(uRam02010ec0,(uint *)(uintptr_t)(uRam02010ec4),(uint *)(uintptr_t)(uRam02010ec8));
  uVar1 = iRam02010ecc + 0xf4U & 3;
  uVar4 = *(uint *)(iRam02010ecc + 0xf4U & 0xfffffffc);
  uVar2 = iRam02010ecc + 0xecU & 3;
  uVar5 = *(uint *)(iRam02010ecc + 0xecU & 0xfffffffc);
  uVar3 = iRam02010ecc + 0xf0U & 3;
  uVar6 = *(uint *)(iRam02010ecc + 0xf0U & 0xfffffffc);
  func_02147914(uRam02010ec8,uRam02010ec8,uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20,
                uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20,
                uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20);
  func_0214755c((uint *)(uintptr_t)(uRam02010ec8),(uint *)(uintptr_t)(uRam02010ed0));
  return;
}

