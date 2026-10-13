/* Decompiled C draft; module arm9; ROM address 0207aaec. No matching claim. */
#include "types.h"
#include "deps/0207aaec_func_0207aaec.h"

void func_0207aaec(void)

{
  ushort uVar1;
  ushort *puVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  
  puVar3 = puRam0207abe4;
  uVar7 = uRam0207abdc;
  puVar2 = puRam0207abd8;
  uVar1 = *puRam0207abd8;
  iVar6 = 0;
  *puRam0207abe0 = 0;
  *puVar3 = 0xffffffff;
  iVar4 = iRam0207abe8;
  uVar8 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  uVar8 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
  if (uVar1 != 0) {
    do {
      func_01ffcac0(uVar8);
      iVar6 = iVar6 + 1;
      uVar8 = uVar8 + iVar4;
    } while (iVar6 < (int)(uint)*puVar2);
  }
  func_0207a32c();
  iVar4 = iRam0207abe8;
  puVar2 = puRam0207abd8;
  uVar8 = (uint)*puRam0207abd8;
  uVar7 = *(uint *)(uRam0207abdc & 0xfffffffc) >> (uRam0207abdc & 3) * 8 |
          *(uint *)(uRam0207abdc & 0xfffffffc) << (uRam0207abdc & 3) * -8 + 0x20;
  iVar6 = 0;
  if (uVar8 != 0) {
    do {
      uVar8 = uVar7 + 0x218 & 3;
      uVar5 = *(uint *)(uVar7 + 0x218 & 0xfffffffc);
      (*(code *)(uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20))(uVar7);
      uVar8 = (uint)*puVar2;
      iVar6 = iVar6 + 1;
      uVar7 = uVar7 + iVar4;
    } while (iVar6 < (int)uVar8);
  }
  iVar4 = iRam0207abe8;
  puVar2 = puRam0207abd8;
  uVar7 = *(uint *)(uRam0207abdc & 0xfffffffc) >> (uRam0207abdc & 3) * 8 |
          *(uint *)(uRam0207abdc & 0xfffffffc) << (uRam0207abdc & 3) * -8 + 0x20;
  iVar6 = 0;
  if (uVar8 == 0) {
    return;
  }
  do {
    uVar8 = uVar7 + 0x21c & 3;
    uVar5 = *(uint *)(uVar7 + 0x21c & 0xfffffffc);
    (*(code *)(uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20))(uVar7);
    iVar6 = iVar6 + 1;
    uVar7 = uVar7 + iVar4;
  } while (iVar6 < (int)(uint)*puVar2);
  return;
}

