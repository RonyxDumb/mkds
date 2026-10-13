/* Decompiled C draft; module arm9; ROM address 02046f54. No matching claim. */
#include "types.h"
#include "deps/02046f54_func_02046f54.h"

void func_02046f54(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = (*(uint *)(uRam02046fb0 & 0xfffffffc) >> (uRam02046fb0 & 3) * 8 |
          *(uint *)(uRam02046fb0 & 0xfffffffc) << (uRam02046fb0 & 3) * -8 + 0x20) + 0x30;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((int)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) << 0x1f) < 0) {
    func_0214e6e4();
    WaitForTPFlags(4);
    func_0214e308(4);
    uVar3 = *(uint *)(uRam02046fb0 & 0xfffffffc) >> (uRam02046fb0 & 3) * 8 |
            *(uint *)(uRam02046fb0 & 0xfffffffc) << (uRam02046fb0 & 3) * -8 + 0x20;
    uVar2 = uVar3 + 0x30;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    *(uint *)(uVar3 + 0x30) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0xfffffffe;
    return;
  }
  return;
}

