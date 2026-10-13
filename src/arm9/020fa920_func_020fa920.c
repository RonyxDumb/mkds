/* Decompiled C draft; module arm9; ROM address 020fa920. No matching claim. */
#include "types.h"
#include "deps/020fa920_func_020fa920.h"

void func_020fa920(void)

{
  ushort *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  uVar2 = (*(uint *)(uRam020fa9d4 & 0xfffffffc) >> (uRam020fa9d4 & 3) * 8 |
          *(uint *)(uRam020fa9d4 & 0xfffffffc) << (uRam020fa9d4 & 3) * -8 + 0x20) + 8;
  uVar5 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) == 5) {
    func_020fec30();
    func_020feb44();
  }
  uVar2 = uRam020fa9d8;
  iVar6 = 0;
  do {
    uVar5 = uVar2 & 3;
    uVar3 = *(uint *)(uVar2 & 0xfffffffc);
    uVar5 = iVar6 * 0x44 + (uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) + 0x14;
    uVar3 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    if (uVar5 >> uVar3 * 8 != 0 || uVar5 << uVar3 * -8 + 0x20 != 0) {
      func_020f03f8();
    }
    uVar5 = uRam020fa9e0;
    puVar1 = puRam020fa9dc;
    iVar6 = iVar6 + 1;
  } while (iVar6 < 0xe);
  uVar2 = 0;
  if (*puRam020fa9dc != 0) {
    do {
      uVar3 = uVar5 & 3;
      uVar4 = *(uint *)(uVar5 & 0xfffffffc);
      func_01fff694(uVar2 * 0x210 + (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20));
      uVar2 = uVar2 + 1 & 0xffff;
    } while (uVar2 < *puVar1);
  }
  func_020f8258();
  func_02104368();
  func_02104ff8();
  return;
}

