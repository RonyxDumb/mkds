/* Decompiled C draft; module arm9; ROM address 020d4484. No matching claim. */
#include "types.h"
#include "deps/020d4484_func_020d4484.h"

void func_020d4484(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar4;
  int iVar5;
  uint uVar6;
  code *pcVar3;
  uint uVar7;
  
  param_1 = param_1 + 0x30;
  func_020d4d44(param_1);
  uVar1 = *(uint *)(uRam020d4588 & 0xfffffffc) >> (uRam020d4588 & 3) * 8 |
          *(uint *)(uRam020d4588 & 0xfffffffc) << (uRam020d4588 & 3) * -8 + 0x20;
  if (uVar1 != 0) {
    func_020d9e60(uVar1,param_1);
  }
  iVar5 = 0;
  uVar1 = *(uint *)(uRam020d458c & 0xfffffffc) >> (uRam020d458c & 3) * 8 |
          *(uint *)(uRam020d458c & 0xfffffffc) << (uRam020d458c & 3) * -8 + 0x20;
  uVar4 = (uint)*(ushort *)(uVar1 + 0x12a);
  if (uVar4 != 0) {
    do {
      uVar6 = uVar1 + 0x68 + iVar5 * 4;
      uVar2 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      uVar7 = uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20;
      func_0208ab00();
      uVar6 = uVar7 + 0xc & 3;
      uVar2 = *(uint *)(uVar7 + 0xc & 0xfffffffc);
      pcVar3 = (code *)(uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20);
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(uVar7);
      }
      func_020d4c28(uVar7,param_1);
      uVar6 = uVar7 + 0x14 & 3;
      uVar2 = *(uint *)(uVar7 + 0x14 & 0xfffffffc);
      pcVar3 = (code *)(uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20);
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(uVar7);
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < (int)uVar4);
  }
  func_020e6a74();
  iVar5 = 0;
  uVar1 = *(uint *)(uRam020d458c & 0xfffffffc) >> (uRam020d458c & 3) * 8 |
          *(uint *)(uRam020d458c & 0xfffffffc) << (uRam020d458c & 3) * -8 + 0x20;
  uVar4 = (uint)*(ushort *)(uVar1 + 300);
  if (uVar4 != 0) {
    do {
      uVar6 = uVar1 + 200 + iVar5 * 4;
      uVar2 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      uVar7 = uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20;
      uVar6 = uVar7 + 0xc & 3;
      uVar2 = *(uint *)(uVar7 + 0xc & 0xfffffffc);
      pcVar3 = (code *)(uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20);
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(uVar7);
      }
      func_020d4c28(uVar7,param_1);
      uVar6 = uVar7 + 0x14 & 3;
      uVar2 = *(uint *)(uVar7 + 0x14 & 0xfffffffc);
      pcVar3 = (code *)(uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20);
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(uVar7);
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < (int)uVar4);
    return;
  }
  return;
}

