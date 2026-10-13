/* Decompiled C draft; module arm9; ROM address 020a49d4. No matching claim. */
#include "types.h"
#include "deps/020a49d4_func_020a49d4.h"

void func_020a49d4(int param_1)

{
  int iVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  
  iVar3 = func_020d3bf8(0x6c);
  if (iVar3 != 0) {
    func_020d2398(param_1);
    return;
  }
  uVar5 = *(uint *)(uRam020a4b50 & 0xfffffffc) >> (uRam020a4b50 & 3) * 8 |
          *(uint *)(uRam020a4b50 & 0xfffffffc) << (uRam020a4b50 & 3) * -8 + 0x20;
  uVar4 = uVar5 + 8;
  uVar6 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar5 = (uint)*(byte *)(uVar5 + 0x3d0);
  if ((uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) == 2) {
    func_020ac588(0x6c,0x20,param_1);
  }
  else {
    func_020ac588(0x6c,4,param_1);
  }
  uVar4 = uRam020a4b50;
  uVar6 = 0;
  if (uVar5 != 0) {
    iVar3 = param_1 + 0xa4;
    do {
      uVar8 = param_1 + 0x9cU & 3;
      uVar7 = *(uint *)(param_1 + 0x9cU & 0xfffffffc);
      sVar2 = *(short *)((uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) + 0x2c);
      if (sVar2 == 0) {
        uVar8 = uVar4 & 3;
        uVar7 = *(uint *)(uVar4 & 0xfffffffc);
        uVar8 = (uVar6 & 0xffff) * 0x30 + (uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) + 0x74;
        uVar7 = uVar8 & 3;
        uVar8 = *(uint *)(uVar8 & 0xfffffffc);
        uVar8 = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
        if (uVar8 == 0) {
          *(undefined2 *)(iVar3 + 0x30) = 1;
        }
        else if (uVar8 == 1) {
          *(undefined2 *)(iVar3 + 0x30) = 3;
        }
        else {
          *(short *)(iVar3 + 0x30) = (short)uVar6;
        }
      }
      else {
        *(short *)(iVar3 + 0x30) = sVar2;
      }
      uVar6 = uVar6 + 1;
      iVar3 = iVar3 + 0x38;
    } while ((int)uVar6 < (int)uVar5);
  }
  iVar3 = 0;
  iVar10 = 0;
  do {
    iVar11 = 0;
    iVar9 = iVar10;
    do {
      iVar1 = iVar11 * 4;
      iVar11 = iVar11 + 1;
      *(int *)(param_1 + iVar3 * 0x20 + iVar1 + 0x264) = iVar9;
      iVar9 = iVar9 + 0xc00;
    } while (iVar11 < 8);
    iVar3 = iVar3 + 1;
    iVar10 = iVar10 + -0x600;
  } while (iVar3 < 8);
  iVar3 = IsNotStaffRoll();
  if (iVar3 == 0) {
    *(undefined4 *)(param_1 + 0xa0) = 0x3c;
  }
  else {
    *(undefined4 *)(param_1 + 0xa0) = uRam020a4b54;
  }
  func_020a238c(param_1 + 0xa4);
  func_020a2364(uRam020a4b58);
  func_020a2350(uRam020a4b5c);
  func_020a233c(uRam020a4b60);
  func_020a2328(uRam020a4b64);
  func_020a2314(uRam020a4b68);
  func_020a2300(uRam020a4b6c);
  return;
}

