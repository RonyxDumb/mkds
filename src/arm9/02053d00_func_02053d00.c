/* Decompiled C draft; module arm9; ROM address 02053d00. No matching claim. */
#include "types.h"
#include "deps/02053d00_func_02053d00.h"

void func_02053d00(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint uVar6;
  int iVar8;
  uint *puVar7;
  
  uVar6 = uRam02053e48;
  puVar4 = (undefined4 *)
           (*(uint *)(uRam02053e48 & 0xfffffffc) >> (uRam02053e48 & 3) * 8 |
           *(uint *)(uRam02053e48 & 0xfffffffc) << (uRam02053e48 & 3) * -8 + 0x20);
  if (puVar4 != (undefined4 *)0x0) {
    *puVar4 = 0;
    *(undefined4 *)
     ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
      *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 4) = 0;
    *(undefined4 *)
     ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
      *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 8) = 9;
    *(undefined4 *)
     ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
      *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0xc) = 0;
    *(undefined4 *)
     ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
      *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x10) = 0;
    *(undefined2 *)
     ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
      *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x454) = 0;
    uVar5 = *(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
            *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20;
    uVar6 = uVar5 + 0x1c;
    uVar1 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    puVar7 = (uint *)(uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20);
    uVar5 = uVar5 + 0x28;
    uVar6 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    *puVar7 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
    *(undefined2 *)(puVar7 + 1) = 0;
    *(undefined2 *)((int)puVar7 + 6) = 0;
    iVar3 = 0;
    do {
      iVar2 = iVar3 + 1;
      *(undefined1 *)((int)puVar7 + iVar3 + 8) = 0xff;
      iVar3 = iVar2;
    } while (iVar2 < 6);
    uVar5 = *(uint *)(uRam02053e48 & 0xfffffffc) >> (uRam02053e48 & 3) * 8 |
            *(uint *)(uRam02053e48 & 0xfffffffc) << (uRam02053e48 & 3) * -8 + 0x20;
    uVar6 = uVar5 + 0x20;
    uVar1 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    puVar7 = (uint *)(uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20);
    uVar5 = uVar5 + 0x2c;
    uVar6 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    *puVar7 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
    *(undefined2 *)(puVar7 + 1) = 0x400;
    *(undefined2 *)((int)puVar7 + 6) = 0;
    *(undefined2 *)(puVar7 + 2) = 0;
    *(undefined2 *)(puVar7 + 4) = 1;
    *(undefined2 *)((int)puVar7 + 0x12) = 0;
    iVar3 = 0;
    do {
      iVar2 = iVar3 + 1;
      *(undefined1 *)((int)puVar7 + iVar3 + 10) = 0xff;
      iVar3 = iVar2;
    } while (iVar2 < 6);
    func_02053fa8();
    iVar2 = 0;
    iVar8 = (*(uint *)(uRam02053e48 & 0xfffffffc) >> (uRam02053e48 & 3) * 8 |
            *(uint *)(uRam02053e48 & 0xfffffffc) << (uRam02053e48 & 3) * -8 + 0x20) + iRam02053e4c;
    iVar3 = iVar8;
    do {
      *(undefined1 *)(iVar3 + 0x34) = 0;
      iVar2 = iVar2 + 1;
      *(undefined4 *)(iVar3 + 0x74) = 0;
      iVar3 = iVar3 + 0x88;
    } while (iVar2 < 0xc);
    *(undefined1 *)(iVar8 + 0x6b4) = 0;
    *(undefined4 *)(iVar8 + 0x660) = 0;
    *(undefined4 *)(iVar8 + 0x798) = 0;
    uVar5 = uRam02053e48;
    *(undefined4 *)(iVar8 + 0x79c) = 0;
    uVar6 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    StructBin_SomeFn_from_thumb((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + iRam02053e50);
    func_02059878();
    func_0204fb40(1);
    return;
  }
  return;
}

