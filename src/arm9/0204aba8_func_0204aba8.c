/* Decompiled C draft; module arm9; ROM address 0204aba8. No matching claim. */
#include "types.h"
#include "deps/0204aba8_func_0204aba8.h"

void func_0204aba8(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(uRam0204ac0c & 0xfffffffc) >> (uRam0204ac0c & 3) * 8 |
          *(uint *)(uRam0204ac0c & 0xfffffffc) << (uRam0204ac0c & 3) * -8 + 0x20;
  uVar2 = uVar3 + 0x1c;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  if ((int)(uVar2 << 0x1f) < 0) {
    return;
  }
  if ((int)(uVar2 << 0x1e) < 0) {
    func_0210dc7c(uVar3 + 8);
    uVar3 = *(uint *)(uRam0204ac0c & 0xfffffffc) >> (uRam0204ac0c & 3) * 8 |
            *(uint *)(uRam0204ac0c & 0xfffffffc) << (uRam0204ac0c & 3) * -8 + 0x20;
    uVar2 = uVar3 + 0x1c;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    *(uint *)(uVar3 + 0x1c) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0xfffffffd;
    return;
  }
  return;
}

