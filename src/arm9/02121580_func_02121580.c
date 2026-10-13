/* Decompiled C draft; module arm9; ROM address 02121580. No matching claim. */
#include "types.h"
#include "deps/02121580_func_02121580.h"

bool func_02121580(void)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar2 = uRam021216a4;
  uVar5 = 0;
  uVar1 = *(uint *)(uRam021216a4 & 0xfffffffc) >> (uRam021216a4 & 3) * 8 |
          *(uint *)(uRam021216a4 & 0xfffffffc) << (uRam021216a4 & 3) * -8 + 0x20;
  cVar3 = '\0';
  uVar6 = 0;
  if (*(char *)(uVar1 + 0x1f53) != '\0') {
    do {
      uVar1 = func_0x0219bb50();
      if (uVar6 != uVar1) {
        uVar1 = *(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20;
        if (((uint)*(byte *)(uVar1 + 0x1f55) & 1 << uVar6) != 0) {
          cVar3 = cVar3 + '\x01';
          if (((uint)*(byte *)(uVar1 + 0x19ab) & 1 << uVar6) == 0) break;
          uVar5 = uVar5 + 1 & 0xff;
        }
      }
      uVar1 = *(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
              *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20;
      uVar6 = uVar6 + 1 & 0xff;
    } while (uVar6 < *(byte *)(uVar1 + 0x1f53));
  }
  if (cVar3 != '\0') {
    uVar1 = 0;
    uVar2 = *(uint *)(uRam021216a4 & 0xfffffffc) >> (uRam021216a4 & 3) * 8 |
            *(uint *)(uRam021216a4 & 0xfffffffc) << (uRam021216a4 & 3) * -8 + 0x20;
    uVar6 = 0;
    uVar4 = (uint)*(byte *)(uVar2 + 0x1f53);
    if (uVar4 != 0) {
      do {
        if (((uint)*(byte *)(uVar2 + 0x1f55) & 1 << uVar6) != 0) {
          uVar1 = uVar1 + 1 & 0xff;
        }
        uVar6 = uVar6 + 1 & 0xff;
      } while (uVar6 < uVar4);
    }
    return uVar5 == uVar1 - 1;
  }
  *(undefined1 *)(uVar1 + 0x19ad) = 1;
  func_0x021a2ccc();
  func_0x0219bbfc();
  *(undefined4 *)
   ((*(uint *)(uRam021216a4 & 0xfffffffc) >> (uRam021216a4 & 3) * 8 |
    *(uint *)(uRam021216a4 & 0xfffffffc) << (uRam021216a4 & 3) * -8 + 0x20) + 0x1950) = 0xb;
  return false;
}

