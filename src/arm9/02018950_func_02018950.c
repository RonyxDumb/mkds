/* Decompiled C draft; module arm9; ROM address 02018950. No matching claim. */
#include "types.h"
#include "deps/02018950_func_02018950.h"

undefined4 func_02018950(int param_1,code *param_2)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar4;
  
  func_0214c6a8();
  iVar8 = 0;
  if (*(short *)(param_1 + 0x32) != 0) {
    iVar5 = 0;
    do {
      uVar1 = param_1 + 0x2cU & 3;
      uVar3 = *(uint *)(param_1 + 0x2cU & 0xfffffffc);
      uVar4 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
      uVar1 = uVar4 + iVar5 & 3;
      uVar3 = *(uint *)(uVar4 + iVar5 & 0xfffffffc);
      uVar6 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
      uVar7 = uVar4 + iVar5;
      uVar1 = uVar6 + 4 & 3;
      uVar3 = *(uint *)(uVar6 + 4 & 0xfffffffc);
      uVar1 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
      if ((int)(uVar1 << 0xe) < 0) {
        uVar1 = ((uVar1 << 6) >> 0x18) * 0x14 + uVar4 + 4;
        uVar3 = uVar1 & 3;
        uVar1 = *(uint *)(uVar1 & 0xfffffffc);
        *(uint *)(uVar7 + 4) = uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20;
      }
      else {
        uVar3 = uVar6 + 8 & 3;
        uVar4 = *(uint *)(uVar6 + 8 & 0xfffffffc);
        uVar2 = (*param_2)(uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20,(uVar1 & 0xf) == 5);
        uVar1 = uVar6 + 8 & 3;
        uVar3 = *(uint *)(uVar6 + 8 & 0xfffffffc);
        func_0214c544((*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
                      *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + 0x20,uVar2,
                      uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
        *(undefined4 *)(uVar7 + 4) = uVar2;
      }
      iVar8 = iVar8 + 1;
      iVar5 = iVar5 + 0x14;
    } while (iVar8 < (int)(uint)*(ushort *)(param_1 + 0x32));
  }
  func_0214c4d4();
  return 1;
}

