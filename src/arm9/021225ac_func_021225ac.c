/* Decompiled C draft; module arm9; ROM address 021225ac. No matching claim. */
#include "types.h"
#include "deps/021225ac_func_021225ac.h"

undefined4 func_021225ac(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = uRam02122680;
  uVar2 = *(uint *)(uRam02122680 & 0xfffffffc) >> (uRam02122680 & 3) * 8 |
          *(uint *)(uRam02122680 & 0xfffffffc) << (uRam02122680 & 3) * -8 + 0x20;
  uVar4 = uVar2 + 0x1980;
  uVar1 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar4 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  *(uint *)(uVar2 + 0x1980) = uVar4 + 1;
  if (uVar4 <= param_1) {
    return 0;
  }
  *(undefined4 *)
   ((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
    *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x1980) = 0;
  uVar1 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
          *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
  uVar4 = uVar1 + 0x1950 & 3;
  uVar3 = *(uint *)(uVar1 + 0x1950 & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  if (uVar4 < 3) {
    *(undefined1 *)(uVar1 + 0x194e) = 1;
    func_0x021a2ccc();
    func_0x0219bbfc();
    *(undefined4 *)
     ((*(uint *)(uRam02122680 & 0xfffffffc) >> (uRam02122680 & 3) * 8 |
      *(uint *)(uRam02122680 & 0xfffffffc) << (uRam02122680 & 3) * -8 + 0x20) + 0x1950) = 0xb;
  }
  else {
    if (uVar4 - 9 < 2) {
      return 1;
    }
    *(undefined1 *)(uVar1 + 0x19ad) = 1;
    func_0x021a2ccc();
    func_0x0219bbfc();
    *(undefined4 *)
     ((*(uint *)(uRam02122680 & 0xfffffffc) >> (uRam02122680 & 3) * 8 |
      *(uint *)(uRam02122680 & 0xfffffffc) << (uRam02122680 & 3) * -8 + 0x20) + 0x1950) = 0xb;
  }
  return 1;
}

