/* Decompiled C draft; module arm9; ROM address 02047054. No matching claim. */
#include "types.h"
#include "deps/02047054_func_02047054.h"

void func_02047054(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(uRam020470c0 & 0xfffffffc) >> (uRam020470c0 & 3) * 8 |
          *(uint *)(uRam020470c0 & 0xfffffffc) << (uRam020470c0 & 3) * -8 + 0x20;
  uVar2 = uVar3 + 0x30;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if (-1 < (int)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) << 0x1f)) {
    func_0214e788(10,4,uVar3,5);
    WaitForTPFlags(2);
    func_0214e308(2);
    uVar3 = *(uint *)(uRam020470c0 & 0xfffffffc) >> (uRam020470c0 & 3) * 8 |
            *(uint *)(uRam020470c0 & 0xfffffffc) << (uRam020470c0 & 3) * -8 + 0x20;
    uVar2 = uVar3 + 0x30;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    *(uint *)(uVar3 + 0x30) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0xfffffffe | 1;
    return;
  }
  return;
}

