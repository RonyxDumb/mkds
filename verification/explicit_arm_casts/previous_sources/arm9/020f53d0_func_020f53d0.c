/* Decompiled C draft; module arm9; ROM address 020f53d0. No matching claim. */
#include "types.h"
#include "deps/020f53d0_func_020f53d0.h"

void func_020f53d0(int param_1)

{
  undefined4 uVar1;
  ushort uVar2;
  short sVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  func_020f8e78();
  func_0210b850(param_1 + 600);
  uVar1 = uRam020f5544;
  *(undefined4 *)(param_1 + 0x30) = uRam020f5540;
  StateDualHandler_Create(param_1 + 0x23c,uVar1,7,param_1);
  uVar6 = param_1 + 0x254U & 3;
  uVar4 = *(uint *)(param_1 + 0x254U & 0xfffffffc);
  if (uVar4 >> uVar6 * 8 == 0 && uVar4 << uVar6 * -8 + 0x20 == 0) {
    *(undefined2 *)(param_1 + 0x24c) = 1;
    *(undefined2 *)(param_1 + 0x24e) = 1;
    uVar6 = param_1 + 0x250U & 3;
    uVar4 = *(uint *)(param_1 + 0x250U & 0xfffffffc);
    func_020f1ea4(param_1,0,uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20,0);
  }
  else {
    uVar6 = param_1 + 0x21cU & 3;
    uVar4 = *(uint *)(param_1 + 0x21cU & 0xfffffffc);
    if (uVar4 >> uVar6 * 8 == 0 && uVar4 << uVar6 * -8 + 0x20 == 0) {
      *(undefined2 *)(param_1 + 0x24c) = 2;
      *(undefined2 *)(param_1 + 0x24e) = 1;
      uVar6 = param_1 + 0x250U & 3;
      uVar4 = *(uint *)(param_1 + 0x250U & 0xfffffffc);
      func_020f1ea4(param_1,0,uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20,0);
    }
    else {
      *(undefined2 *)(param_1 + 0x24c) = 3;
      *(undefined2 *)(param_1 + 0x24e) = 1;
      if ((*(ushort *)(param_1 + 0x78) & 0x8000) == 0) {
        uVar2 = *(ushort *)(param_1 + 0x78) & 0xff;
      }
      else {
        uVar2 = 8;
      }
      if (uVar2 < 8) {
        iVar5 = GetDriverPlace();
        uVar6 = iVar5 - 1U & 0xffff;
        if (uVar6 == 0) {
          uVar6 = (uint)*(byte *)((*(uint *)(uRam020f5548 & 0xfffffffc) >> (uRam020f5548 & 3) * 8 |
                                  *(uint *)(uRam020f5548 & 0xfffffffc) <<
                                  (uRam020f5548 & 3) * -8 + 0x20) + 0x3d0);
        }
        sVar3 = (short)*(char *)((*(uint *)(uRam020f554c & 0xfffffffc) >> (uRam020f554c & 3) * 8 |
                                 *(uint *)(uRam020f554c & 0xfffffffc) <<
                                 (uRam020f554c & 3) * -8 + 0x20) + (uVar6 & 0xff) + 0x473);
      }
      else {
        sVar3 = 8;
      }
      uVar6 = param_1 + 0x250U & 3;
      uVar4 = *(uint *)(param_1 + 0x250U & 0xfffffffc);
      func_020ec8bc(param_1,0x2d,0x5b,0,1,uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20,sVar3,0);
    }
    uVar6 = param_1 + 0x74U & 3;
    uVar4 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
    *(uint *)(param_1 + 0x74) = uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20 | 0x200000;
  }
  func_020f1a14(param_1);
  return;
}

