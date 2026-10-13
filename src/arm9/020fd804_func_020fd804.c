/* Decompiled C draft; module arm9; ROM address 020fd804. No matching claim. */
#include "types.h"
#include "deps/020fd804_func_020fd804.h"

void func_020fd804(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1 + 0x198U & 3;
  uVar1 = *(uint *)(param_1 + 0x198U & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if (uVar2 != 0) {
    *(ushort *)(uVar2 + 2) = *(ushort *)(uVar2 + 2) & 0xfffe;
    func_020d2398();
    return;
  }
  return;
}

