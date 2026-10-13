/* Decompiled C draft; module arm9; ROM address 020eddb4. No matching claim. */
#include "types.h"
#include "deps/020eddb4_func_020eddb4.h"

void func_020eddb4(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar7;
  uint uVar8;
  uint uVar10;
  uint uVar11;
  code *pcVar6;
  uint uVar9;
  
  uVar5 = param_1 + 8U & 3;
  uVar10 = *(uint *)(param_1 + 8U & 0xfffffffc);
  iVar2 = func_020ee528();
  if (iVar2 != 0) {
    uVar9 = param_1 + 0x20U & 3;
    uVar8 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
    uVar9 = uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20;
    iVar2 = 0;
    if (0 < (int)uVar9) {
      do {
        uVar8 = param_1 + iVar2 * 4 + 0x14;
        uVar11 = uVar8 & 3;
        uVar3 = *(uint *)(uVar8 & 0xfffffffc);
        uVar8 = param_1 + 0x84U & 3;
        uVar4 = *(uint *)(param_1 + 0x84U & 0xfffffffc);
        uVar1 = param_1 + 0x88U & 3;
        uVar7 = *(uint *)(param_1 + 0x88U & 0xfffffffc);
        func_020f9f08(uVar3 >> uVar11 * 8 | uVar3 << uVar11 * -8 + 0x20,
                      uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20,
                      uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20);
        iVar2 = iVar2 + 1;
      } while (iVar2 < (int)uVar9);
    }
  }
  uVar5 = iRam020edf08 + (uVar10 >> uVar5 * 8 | uVar10 << uVar5 * -8 + 0x20) * 4;
  uVar10 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  pcVar6 = (code *)(uVar5 >> uVar10 * 8 | uVar5 << uVar10 * -8 + 0x20);
  if (pcVar6 != (code *)0x0) {
    (*pcVar6)(param_1);
  }
  func_020edf10(param_1);
  uVar5 = param_1 + 0x20U & 3;
  uVar10 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
  if (uVar10 >> uVar5 * 8 == 0 && uVar10 << uVar5 * -8 + 0x20 == 0) {
    func_020ee6a8(param_1);
  }
  uVar5 = param_1 + 0x24U & 3;
  uVar10 = *(uint *)(param_1 + 0x24U & 0xfffffffc);
  uVar5 = uVar10 >> uVar5 * 8 | uVar10 << uVar5 * -8 + 0x20;
  if ((int)uVar5 < 1) {
    return;
  }
  *(uint *)(param_1 + 0x24) = uVar5 - 1;
  uVar5 = param_1 + 0x24U & 3;
  uVar10 = *(uint *)(param_1 + 0x24U & 0xfffffffc);
  uVar5 = uVar10 >> uVar5 * 8 | uVar10 << uVar5 * -8 + 0x20;
  if (((uVar5 != 8) && (uVar5 != 4)) && (uVar5 != 0)) {
    return;
  }
  uVar5 = param_1 + 0x20U & 3;
  uVar10 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
  *(uint *)(param_1 + 0x20) = (uVar10 >> uVar5 * 8 | uVar10 << uVar5 * -8 + 0x20) - 1;
  uVar5 = param_1 + 0x20U & 3;
  uVar10 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
  uVar8 = uVar10 >> uVar5 * 8 | uVar10 << uVar5 * -8 + 0x20;
  uVar5 = param_1 + 0x10U & 3;
  uVar10 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
  uVar11 = uVar10 >> uVar5 * 8 | uVar10 << uVar5 * -8 + 0x20;
  uVar5 = param_1 + uVar8 * 4 + 0x14;
  uVar10 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  uVar9 = uVar5 >> uVar10 * 8 | uVar5 << uVar10 * -8 + 0x20;
  func_020efb84(param_1,uVar9);
  func_020f6630(uVar9,uVar8 + 1,uVar11 + 0x98,uVar11 + 0xa4);
  uVar5 = uVar9 + 0x44 & 3;
  uVar10 = *(uint *)(uVar9 + 0x44 & 0xfffffffc);
  uVar5 = (uVar10 >> uVar5 * 8 | uVar10 << uVar5 * -8 + 0x20) * 0xa8 +
          (*(uint *)(uRam020edf0c & 0xfffffffc) >> (uRam020edf0c & 3) * 8 |
          *(uint *)(uRam020edf0c & 0xfffffffc) << (uRam020edf0c & 3) * -8 + 0x20) + 0x38;
  uVar10 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  pcVar6 = (code *)(uVar5 >> uVar10 * 8 | uVar5 << uVar10 * -8 + 0x20);
  if (pcVar6 != (code *)0x0) {
    (*pcVar6)(uVar9);
  }
  uVar5 = param_1 + 0x20U & 3;
  uVar10 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
  if (uVar10 >> uVar5 * 8 == 0 && uVar10 << uVar5 * -8 + 0x20 == 0) {
    func_020ee6a8(param_1);
    return;
  }
  return;
}

