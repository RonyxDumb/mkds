/* Decompiled C draft; module arm9; ROM address 0205ba60. No matching claim. */
#include "types.h"
#include "deps/0205ba60_func_0205ba60.h"

void func_0205ba60(void)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar4;
  
  uVar2 = uRam0205bba4;
  uVar7 = 0;
  uVar5 = *(uint *)(uRam0205bba4 & 0xfffffffc) >> (uRam0205bba4 & 3) * 8 |
          *(uint *)(uRam0205bba4 & 0xfffffffc) << (uRam0205bba4 & 3) * -8 + 0x20;
  uVar6 = 0;
  uVar4 = uVar5 + 0x758 & 3;
  uVar3 = *(uint *)(uVar5 + 0x758 & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  if ((uVar4 == 3) || (uVar4 == 4)) {
    uVar4 = 0;
    do {
      if ((((((uint)*(byte *)((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                              *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x749) &
             1 << uVar4) != 0) && (uVar3 = func_0x0219bb50(), uVar4 != uVar3)) &&
          (cVar1 = *(char *)((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                             *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + uVar4 +
                            0x74e), cVar1 != '\x04')) && (cVar1 != '\x05')) {
        uVar7 = uVar7 | 1 << uVar4 & 0xffU;
      }
      uVar4 = uVar4 + 1 & 0xff;
    } while (uVar4 < 4);
    if (uVar7 == 0) {
      *(undefined4 *)
       ((*(uint *)(uRam0205bba4 & 0xfffffffc) >> (uRam0205bba4 & 3) * 8 |
        *(uint *)(uRam0205bba4 & 0xfffffffc) << (uRam0205bba4 & 3) * -8 + 0x20) + 0x758) = 5;
    }
  }
  else if (uVar4 == 5) {
    do {
      if ((((uint)*(byte *)(uVar5 + 0x749) & 1 << uVar7) != 0) &&
         (*(char *)(uVar5 + uVar7 + 0x74e) == '\x05')) {
        uVar6 = uVar6 | 1 << uVar7 & 0xffU;
      }
      uVar7 = uVar7 + 1 & 0xff;
    } while (uVar7 < 4);
    if (((uint)*(byte *)(uVar5 + 0x749) & ~uVar6) == 0) {
      *(ushort *)(uVar5 + 0x75c) = *(ushort *)(uVar5 + 0x75c) | 0x100;
    }
    uVar4 = *(uint *)(uRam0205bba4 & 0xfffffffc) >> (uRam0205bba4 & 3) * 8 |
            *(uint *)(uRam0205bba4 & 0xfffffffc) << (uRam0205bba4 & 3) * -8 + 0x20;
    if (*(char *)(uVar4 + 0x749) != '\0' || ~uVar6 != 0) {
      *(ushort *)(uVar4 + 0x75c) = *(ushort *)(uVar4 + 0x75c) | 0x100;
    }
  }
  uVar4 = *(uint *)(uRam0205bba4 & 0xfffffffc) >> (uRam0205bba4 & 3) * 8 |
          *(uint *)(uRam0205bba4 & 0xfffffffc) << (uRam0205bba4 & 3) * -8 + 0x20;
  if (((uint)*(byte *)(uVar4 + 0x749) & ~uVar6) == 0) {
    *(undefined4 *)(uVar4 + 0x758) = 5;
  }
  return;
}

