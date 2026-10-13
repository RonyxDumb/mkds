/* Decompiled C draft; module arm9; ROM address 0204d5bc. No matching claim. */
#include "types.h"
#include "deps/0204d5bc_func_0204d5bc.h"

void func_0204d5bc(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = uRam0204d60c + 0xc & 3;
  uVar2 = *(uint *)(uRam0204d60c + 0xc & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 == 0 && uVar2 << uVar1 * -8 + 0x20 == 0) {
    return;
  }
  if (*(uint *)(uRam0204d60c & 0xfffffffc) >> (uRam0204d60c & 3) * 8 != 0 ||
      *(uint *)(uRam0204d60c & 0xfffffffc) << (uRam0204d60c & 3) * -8 + 0x20 != 0) {
    *(undefined4 *)(uRam0204d60c + 0x4b14) = 0;
    func_0204d28c();
    return;
  }
  return;
}

