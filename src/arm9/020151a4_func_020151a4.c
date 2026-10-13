/* Decompiled C draft; module arm9; ROM address 020151a4. No matching claim. */
#include "types.h"
#include "deps/020151a4_func_020151a4.h"

void func_020151a4(undefined4 param_1)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar7;
  uint uVar6;
  
  uVar7 = *(uint *)(uRam02015208 & 0xfffffffc) >> (uRam02015208 & 3) * 8 |
          *(uint *)(uRam02015208 & 0xfffffffc) << (uRam02015208 & 3) * -8 + 0x20;
  uVar2 = uVar7 + 0xd4 & 3;
  uVar5 = *(uint *)(uVar7 + 0xd4 & 0xfffffffc);
  uVar6 = uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20;
  uVar2 = (uint)*(ushort *)(uVar6 + *(ushort *)(uVar6 + 6)) *
          (uint)*(byte *)((*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
                          *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + 1) +
          uVar6 + *(ushort *)(uVar6 + 6) + 4;
  uVar5 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar2 = uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20;
  uVar1 = *(ushort *)(uVar6 + uVar2);
  iVar3 = uVar6 + uVar2;
  iVar4 = iVar3 + 4;
  if ((uVar1 & 1) == 0) {
    iVar4 = iVar3 + 0x10;
  }
  if ((uVar1 & 2) == 0) {
    if ((uVar1 & 8) == 0) {
      iVar4 = iVar4 + 0x10;
    }
    else {
      iVar4 = iVar4 + 4;
    }
  }
  uVar2 = uVar7 + 0xe8 & 3;
  uVar5 = *(uint *)(uVar7 + 0xe8 & 0xfffffffc);
  (*(code *)(uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20))(param_1,iVar4);
  return;
}

