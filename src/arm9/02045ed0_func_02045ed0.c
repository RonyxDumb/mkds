/* Decompiled C draft; module arm9; ROM address 02045ed0. No matching claim. */
#include "types.h"
#include "deps/02045ed0_func_02045ed0.h"

void func_02045ed0(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  func_02046594();
  uVar3 = (*(uint *)(DAT_0204601c & 0xfffffffc) >> (DAT_0204601c & 3) * 8 |
          *(uint *)(DAT_0204601c & 0xfffffffc) << (DAT_0204601c & 3) * -8 + 0x20) + 0x1f0;
  uVar5 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  switch(uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) {
  case 0:
    CreateGlobalLU();
    uVar3 = DAT_0204601c;
    *(undefined2 *)
     ((*(uint *)(DAT_0204601c & 0xfffffffc) >> (DAT_0204601c & 3) * 8 |
      *(uint *)(DAT_0204601c & 0xfffffffc) << (DAT_0204601c & 3) * -8 + 0x20) + 0x248) = 1;
    iVar2 = DAT_02046020;
    *(undefined4 *)
     ((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
      *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 500) = 3;
    uVar6 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
            *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
    uVar3 = uVar6 + 0x1ec & 3;
    uVar5 = *(uint *)(uVar6 + 0x1ec & 0xfffffffc);
    uVar3 = iVar2 + (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) * 0x10 +
            (*(ushort *)(uVar6 + 0x248) - 1) * 4;
    uVar5 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    *(uint *)(uVar6 + 0x1e8) = uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20;
    return;
  case 1:
    break;
  case 2:
    func_02046024(0);
    return;
  case 3:
    func_02046024(1);
    return;
  case 4:
    CreateGlobalLU();
    uVar3 = *(uint *)(DAT_0204601c & 0xfffffffc) >> (DAT_0204601c & 3) * 8 |
            *(uint *)(DAT_0204601c & 0xfffffffc) << (DAT_0204601c & 3) * -8 + 0x20;
    if (*(char *)(uVar3 + 0x23d) == '\t') {
      *(undefined4 *)(uVar3 + 500) = 3;
    }
    else {
      *(undefined4 *)(uVar3 + 500) = 0;
    }
    *(undefined2 *)
     ((*(uint *)(DAT_0204601c & 0xfffffffc) >> (DAT_0204601c & 3) * 8 |
      *(uint *)(DAT_0204601c & 0xfffffffc) << (DAT_0204601c & 3) * -8 + 0x20) + 0x248) = 1;
    break;
  case 5:
    CreateGlobalLU();
    uVar3 = DAT_0204601c;
    uVar5 = 0;
    *(undefined2 *)
     ((*(uint *)(DAT_0204601c & 0xfffffffc) >> (DAT_0204601c & 3) * 8 |
      *(uint *)(DAT_0204601c & 0xfffffffc) << (DAT_0204601c & 3) * -8 + 0x20) + 0x248) = 1;
    *(undefined4 *)
     ((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
      *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 500) = 0;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
            *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
    do {
      uVar6 = uVar5 * 0x30 + uVar3 + 600;
      uVar1 = uVar6 & 3;
      uVar4 = *(uint *)(uVar6 & 0xfffffffc);
      uVar6 = uVar5;
      if (uVar4 >> uVar1 * 8 == 0 && uVar4 << uVar1 * -8 + 0x20 == 0) break;
      uVar5 = uVar5 + 1 & 0xff;
      uVar6 = 0xff;
    } while (uVar5 < 4);
    *(char *)(uVar3 + 0x24b) = (char)uVar6;
    return;
  }
  return;
}

