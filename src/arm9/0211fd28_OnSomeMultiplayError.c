/* Decompiled C draft; module arm9; ROM address 0211fd28. No matching claim. */
#include "types.h"
#include "deps/0211fd28_OnSomeMultiplayError.h"

void OnSomeMultiplayError(void)

{
  uint uVar1;
  
  func_0x0219c0f4();
  func_0x021a37dc();
  func_02120714();
  uVar1 = *(uint *)(uRam0211fd64 & 0xfffffffc) >> (uRam0211fd64 & 3) * 8 |
          *(uint *)(uRam0211fd64 & 0xfffffffc) << (uRam0211fd64 & 3) * -8 + 0x20;
  *(undefined2 *)(uVar1 + 0x18) = 0;
  *(undefined2 *)(uVar1 + 0x1a) = 1;
  return;
}

