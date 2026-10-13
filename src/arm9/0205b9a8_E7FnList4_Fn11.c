/* Decompiled C draft; module arm9; ROM address 0205b9a8. No matching claim. */
#include "types.h"
#include "deps/0205b9a8_E7FnList4_Fn11.h"

void E7FnList4_Fn11(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  func_0205a908();
  func_0205a350();
  uVar3 = *(uint *)(uRam0205ba58 & 0xfffffffc) >> (uRam0205ba58 & 3) * 8 |
          *(uint *)(uRam0205ba58 & 0xfffffffc) << (uRam0205ba58 & 3) * -8 + 0x20;
  uVar2 = uVar3 + 0x754 & 3;
  uVar6 = *(uint *)(uVar3 + 0x754 & 0xfffffffc);
  uVar7 = uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20;
  uVar2 = uVar7 + 4 & 3;
  uVar5 = *(uint *)(uVar7 + 4 & 0xfffffffc);
  uVar6 = uVar3 + 0x728 & 3;
  uVar4 = *(uint *)(uVar3 + 0x728 & 0xfffffffc);
  uVar3 = 0x68 - *(ushort *)(uVar3 + 0x724);
  *(uint *)(uVar7 + 4) =
       (uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) & 0xff000000 |
       (uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) & 0xffffff;
  *(char *)(uVar7 + 7) = (char)(uVar3 * 0x10000 >> 0x10);
  iVar1 = func_0x0219bb50();
  if (*(char *)((*(uint *)(uRam0205ba5c & 0xfffffffc) >> (uRam0205ba5c & 3) * 8 |
                *(uint *)(uRam0205ba5c & 0xfffffffc) << (uRam0205ba5c & 3) * -8 + 0x20) + iVar1 + 6)
      < '\0') {
    *(undefined4 *)(uVar7 + 8) = 0;
  }
  else {
    uVar2 = func_0205afa8();
    *(uint *)(uVar7 + 8) =
         uVar2 | (*(byte *)((*(uint *)(uRam0205ba58 & 0xfffffffc) >> (uRam0205ba58 & 3) * 8 |
                            *(uint *)(uRam0205ba58 & 0xfffffffc) << (uRam0205ba58 & 3) * -8 + 0x20)
                           + 0x73e) & 0xf) << 0x17;
  }
  func_0205c234(uVar3 & 0xffff);
  func_0205be0c();
  func_0205ba60();
  return;
}

