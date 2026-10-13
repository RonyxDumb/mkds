/* Decompiled C draft; module arm9; ROM address 0204ac10. No matching claim. */
#include "types.h"
#include "deps/0204ac10_func_0204ac10.h"

void func_0204ac10(void)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  
  uVar4 = *(uint *)(uRam0204ac5c & 0xfffffffc) >> (uRam0204ac5c & 3) * 8 |
          *(uint *)(uRam0204ac5c & 0xfffffffc) << (uRam0204ac5c & 3) * -8 + 0x20;
  uVar2 = uVar4 + 0x1c;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((int)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) << 0x1f) < 0) {
    uVar3 = func_0210d960();
    func_0210dca8(uVar4 + 8,uVar3);
    uVar4 = *(uint *)(uRam0204ac5c & 0xfffffffc) >> (uRam0204ac5c & 3) * 8 |
            *(uint *)(uRam0204ac5c & 0xfffffffc) << (uRam0204ac5c & 3) * -8 + 0x20;
    uVar2 = uVar4 + 0x1c;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    *(uint *)(uVar4 + 0x1c) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0xfffffffe;
    return;
  }
  return;
}

