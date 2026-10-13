/* Decompiled C draft; module arm9; ROM address 0205d88c. No matching claim. */
#include "types.h"
#include "deps/0205d88c_func_0205d88c.h"

void func_0205d88c(uint param_1,int param_2)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  int iVar6;
  int iVar7;
  uint uVar5;
  
  uVar3 = *(uint *)(uRam0205d96c & 0xfffffffc) >> (uRam0205d96c & 3) * 8 |
          *(uint *)(uRam0205d96c & 0xfffffffc) << (uRam0205d96c & 3) * -8 + 0x20;
  uVar4 = uVar3 + 8;
  uVar5 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  iVar1 = *(ushort *)(uVar3 + 0x60) - 1;
  iVar6 = iVar1 >> 0x1f;
  uVar4 = ((uint)(iVar1 * 0x40000000 + iVar6) >> 0x1e | iVar6 << 2) - iVar6;
  iVar6 = (int)(((uVar4 & 0xff) - 1) * 0x1000000) >> 0x18;
  if ((((uVar5 == 2) || (uVar5 == 3)) || (uVar5 == 5)) && (iVar6 < 0)) {
    iVar6 = (iVar6 + 4) * 0x1000000 >> 0x18;
  }
  if (iVar6 < 0) {
    bVar2 = 0;
  }
  else {
    bVar2 = *(byte *)((param_1 & 0xff) * 10 +
                      iVar6 * 0x50 +
                      (*(uint *)(uRam0205d970 & 0xfffffffc) >> (uRam0205d970 & 3) * 8 |
                      *(uint *)(uRam0205d970 & 0xfffffffc) << (uRam0205d970 & 3) * -8 + 0x20) + 5);
  }
  iVar6 = (uVar4 & 0xff) * 0x50 +
          (*(uint *)(uRam0205d970 & 0xfffffffc) >> (uRam0205d970 & 3) * 8 |
          *(uint *)(uRam0205d970 & 0xfffffffc) << (uRam0205d970 & 3) * -8 + 0x20);
  iVar7 = (param_1 & 0xff) * 10;
  iVar1 = iVar6 + iVar7;
  *(undefined1 *)(iVar1 + 4) = 0;
  *(undefined1 *)(iVar1 + 3) = 1;
  if (param_2 != 0) {
    bVar2 = bVar2 + 1;
  }
  *(undefined2 *)(iVar6 + iVar7) = 0;
  if (99 < bVar2) {
    bVar2 = 99;
  }
  *(byte *)(iVar1 + 5) = bVar2;
  return;
}

