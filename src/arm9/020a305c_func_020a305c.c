/* Decompiled C draft; module arm9; ROM address 020a305c. No matching claim. */
#include "types.h"
#include "deps/020a305c_func_020a305c.h"

void func_020a305c(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  uVar3 = func_02100138(0x6c);
  uVar2 = uRam020a3110;
  if (uVar3 == 0) {
    return;
  }
  iVar6 = 0;
  while( true ) {
    if ((int)(uint)*(ushort *)(uVar3 + 4) <= iVar6) {
      return;
    }
    uVar4 = (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
            *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + iVar6 * 4;
    uVar1 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    uVar4 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
    if (uVar4 == 0) break;
    uVar1 = uVar4 + 0xa4 & 3;
    uVar5 = *(uint *)(uVar4 + 0xa4 & 0xfffffffc);
    if ((int)(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) < 0) {
      if ((*(ushort *)(uVar4 + 2) & 0x100) == 0) {
        func_020d2398();
      }
    }
    else {
      uVar1 = uVar2 & 3;
      uVar5 = *(uint *)(uVar2 & 0xfffffffc);
      *(uint *)(uVar4 + 0xa4) =
           (int)*(char *)((uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) + 0x62) & 0xffff;
      *(undefined4 *)(uVar4 + 0xd0) = 0x1000;
      *(undefined4 *)(uVar4 + 0xd4) = 0;
      *(undefined4 *)(uVar4 + 0xd8) = 0;
      *(undefined4 *)(uVar4 + 0xdc) = 0;
      *(undefined4 *)(uVar4 + 0xfc) = 2;
    }
    iVar6 = iVar6 + 1;
  }
  return;
}

