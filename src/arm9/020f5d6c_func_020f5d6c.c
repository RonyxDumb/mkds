/* Decompiled C draft; module arm9; ROM address 020f5d6c. No matching claim. */
#include "types.h"
#include "deps/020f5d6c_func_020f5d6c.h"

uint func_020f5d6c(int param_1,int param_2)

{
  undefined4 uVar1;
  ushort uVar2;
  short sVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  func_020f9114(param_2);
  func_0210b850((undefined4 *)(uintptr_t)(param_2 + 600));
  uVar1 = uRam020f5f70;
  *(undefined4 *)(param_2 + 0x30) = uRam020f5f6c;
  StateDualHandler_Create((undefined4 *)(uintptr_t)(param_2 + 0x23c),uVar1,7,param_2);
  uVar7 = uRam020f5f74;
  uVar5 = param_1 + 0xcU & 3;
  uVar4 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  if ((*(ushort *)((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + 0x1ec) & 0x20) == 0) {
    *(undefined4 *)(param_2 + 0x254) = 1;
    uVar5 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    uVar5 = (uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20) + 8;
    uVar7 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    if (((uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) == 2) ||
       (uVar5 = param_1 + 0xcU & 3, uVar7 = *(uint *)(param_1 + 0xcU & 0xfffffffc),
       uVar5 = (uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20) + 0x1f0, uVar7 = uVar5 & 3,
       uVar5 = *(uint *)(uVar5 & 0xfffffffc),
       uVar5 >> uVar7 * 8 == 0 && uVar5 << uVar7 * -8 + 0x20 == 0)) {
      func_020f2b94(param_2,param_1,0,1,0,0x5000);
      *(undefined2 *)(param_2 + 0x24c) = 2;
      *(undefined2 *)(param_2 + 0x24e) = 1;
      *(undefined4 *)(param_2 + 0x21c) = 0;
      *(undefined4 *)(param_2 + 0x220) = 1;
    }
    else {
      if ((*(ushort *)(param_2 + 0x78) & 0x8000) == 0) {
        uVar2 = *(ushort *)(param_2 + 0x78) & 0xff;
      }
      else {
        uVar2 = 8;
      }
      if (uVar2 < 8) {
        iVar6 = GetDriverPlace();
        uVar5 = iVar6 - 1U & 0xffff;
        if (uVar5 == 0) {
          uVar5 = (uint)*(byte *)((*(uint *)(uRam020f5f74 & 0xfffffffc) >> (uRam020f5f74 & 3) * 8 |
                                  *(uint *)(uRam020f5f74 & 0xfffffffc) <<
                                  (uRam020f5f74 & 3) * -8 + 0x20) + 0x3d0);
        }
        sVar3 = (short)*(char *)((*(uint *)(uRam020f5f78 & 0xfffffffc) >> (uRam020f5f78 & 3) * 8 |
                                 *(uint *)(uRam020f5f78 & 0xfffffffc) <<
                                 (uRam020f5f78 & 3) * -8 + 0x20) + (uVar5 & 0xff) + 0x473);
      }
      else {
        sVar3 = 8;
      }
      func_020ed268(param_2,param_1,0x2d,0x5b,1,0,1,0x5000,sVar3,0);
      *(undefined2 *)(param_2 + 0x24c) = 3;
      *(undefined2 *)(param_2 + 0x24e) = 1;
    }
    uVar5 = param_2 + 0x74U & 3;
    uVar7 = *(uint *)(param_2 + 0x74U & 0xfffffffc);
    *(uint *)(param_2 + 0x74) = uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20 | 0x200000;
  }
  else {
    *(undefined4 *)(param_2 + 0x254) = 0;
    func_020f2b94(param_2,param_1,0,0,0,0x5000);
    *(undefined2 *)(param_2 + 0x24c) = 1;
    *(undefined2 *)(param_2 + 0x24e) = 1;
    *(undefined4 *)(param_2 + 0x21c) = 0;
    *(undefined4 *)(param_2 + 0x220) = 1;
  }
  func_020f1a14(param_2);
  uVar5 = param_2 + 0x74U & 3;
  uVar7 = *(uint *)(param_2 + 0x74U & 0xfffffffc);
  if (((uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20) & 0x8000000) != 0) {
    *(undefined2 *)(param_2 + 0x24c) = 0;
    *(undefined2 *)(param_2 + 0x24e) = 1;
  }
  uVar5 = param_2 + 0x254U & 3;
  uVar7 = *(uint *)(param_2 + 0x254U & 0xfffffffc);
  return uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20;
}

