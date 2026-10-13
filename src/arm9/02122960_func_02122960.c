/* Decompiled C draft; module arm9; ROM address 02122960. No matching claim. */
#include "types.h"
#include "deps/02122960_func_02122960.h"

void func_02122960(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = uRam02122aac;
  uVar3 = *(uint *)(uRam02122aac & 0xfffffffc) >> (uRam02122aac & 3) * 8 |
          *(uint *)(uRam02122aac & 0xfffffffc) << (uRam02122aac & 3) * -8 + 0x20;
  uVar4 = uVar3 + 0x1950 & 3;
  uVar2 = *(uint *)(uVar3 + 0x1950 & 0xfffffffc);
  if ((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) - 0xb < 2) {
    return;
  }
  uVar4 = 0;
  if (*(char *)(uVar3 + 0x1f53) != '\0') {
    do {
      uVar2 = 1 << uVar4;
      if (((*(byte *)(uVar3 + 0x1f55) & uVar2) != 0) && ((*(byte *)(uVar3 + 0x1f56) & uVar2) != 0))
      {
        uVar3 = func_0x0219bb50();
        if (uVar4 == uVar3) {
          *(undefined1 *)
           ((*(uint *)(uRam02122aac & 0xfffffffc) >> (uRam02122aac & 3) * 8 |
            *(uint *)(uRam02122aac & 0xfffffffc) << (uRam02122aac & 3) * -8 + 0x20) + 0x19ad) = 1;
          func_0x021a2ccc();
          func_0x0219bbfc();
          *(undefined4 *)
           ((*(uint *)(uRam02122aac & 0xfffffffc) >> (uRam02122aac & 3) * 8 |
            *(uint *)(uRam02122aac & 0xfffffffc) << (uRam02122aac & 3) * -8 + 0x20) + 0x1950) = 0xb;
          return;
        }
        uVar3 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
        *(byte *)(uVar3 + 0x1f55) = *(byte *)(uVar3 + 0x1f55) & ~(byte)uVar2;
        uVar3 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
        *(byte *)(uVar3 + 0x1f56) = *(byte *)(uVar3 + 0x1f56) & ~(byte)uVar2;
        uVar2 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
        *(char *)(uVar2 + 0x1f52) = *(char *)(uVar2 + 0x1f52) + -1;
      }
      uVar3 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
              *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
      uVar4 = uVar4 + 1 & 0xff;
    } while (uVar4 < *(byte *)(uVar3 + 0x1f53));
  }
  if (1 < *(byte *)(uVar3 + 0x1f52)) {
    return;
  }
  *(undefined1 *)(uVar3 + 0x19ad) = 1;
  func_0x021a2ccc();
  func_0x0219bbfc();
  *(undefined4 *)
   ((*(uint *)(uRam02122aac & 0xfffffffc) >> (uRam02122aac & 3) * 8 |
    *(uint *)(uRam02122aac & 0xfffffffc) << (uRam02122aac & 3) * -8 + 0x20) + 0x1950) = 0xb;
  return;
}

