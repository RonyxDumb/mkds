/* Decompiled C draft; module arm9; ROM address 0209886c. No matching claim. */
#include "types.h"
#include "deps/0209886c_func_0209886c.h"

void func_0209886c(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar7;
  uint uVar6;
  
  uVar2 = uRam02098950;
  uVar1 = uRam0209894c;
  if (*(uint *)(uRam0209894c & 0xfffffffc) >> (uRam0209894c & 3) * 8 == 0 &&
      *(uint *)(uRam0209894c & 0xfffffffc) << (uRam0209894c & 3) * -8 + 0x20 == 0) {
    return;
  }
  iVar7 = 0;
  while( true ) {
    uVar6 = uVar1 & 3;
    uVar5 = *(uint *)(uVar1 & 0xfffffffc);
    uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
    if ((int)(uint)*(ushort *)(uVar6 + 4) <= iVar7) {
      return;
    }
    uVar6 = (*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
            *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + iVar7 * 4;
    uVar5 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    uVar6 = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20;
    if (uVar6 == 0) break;
    iVar3 = StructMapObject_GetAnimationBCAFrameCount
                      (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                       *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20);
    if (iVar3 + -1 < 1) {
      iVar3 = StructMapObject_GetAnimationBCAFrameCount
                        (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                         *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20);
      uVar4 = FUN_02132440((iVar3 + -1) * 0x1000);
      func_021329f8(uVar4,0x3f000000);
    }
    else {
      iVar3 = StructMapObject_GetAnimationBCAFrameCount
                        (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                         *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20);
      uVar4 = FUN_02132440((iVar3 + -1) * 0x1000);
      func_02131234(0x3f000000,uVar4);
    }
    *(undefined4 *)(uVar6 + 0xa4) = 0;
    *(undefined4 *)(uVar6 + 0xa8) = 0x1000;
    *(undefined4 *)(uVar6 + 0xac) = 0;
    uVar4 = func_021322c8();
    *(undefined4 *)(uVar6 + 0xb0) = uVar4;
    *(undefined4 *)(uVar6 + 0x1e0) = 0xffffff5c;
    iVar7 = iVar7 + 1;
  }
  return;
}

