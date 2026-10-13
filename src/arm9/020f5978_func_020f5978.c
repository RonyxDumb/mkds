/* Decompiled C draft; module arm9; ROM address 020f5978. No matching claim. */
#include "types.h"
#include "deps/020f5978_func_020f5978.h"

void func_020f5978(int param_1)

{
  ushort uVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  if ((*(ushort *)(param_1 + 0x78) & 0x8000) == 0) {
    uVar1 = *(ushort *)(param_1 + 0x78) & 0xff;
  }
  else {
    uVar1 = 8;
  }
  if (uVar1 < 8) {
    iVar3 = GetDriverPlace();
    uVar5 = iVar3 - 1U & 0xffff;
    if (uVar5 == 0) {
      uVar5 = (uint)*(byte *)((*(uint *)(uRam020f5b60 & 0xfffffffc) >> (uRam020f5b60 & 3) * 8 |
                              *(uint *)(uRam020f5b60 & 0xfffffffc) << (uRam020f5b60 & 3) * -8 + 0x20
                              ) + 0x3d0);
    }
    sVar2 = (short)*(char *)((*(uint *)(uRam020f5b64 & 0xfffffffc) >> (uRam020f5b64 & 3) * 8 |
                             *(uint *)(uRam020f5b64 & 0xfffffffc) << (uRam020f5b64 & 3) * -8 + 0x20)
                             + (uVar5 & 0xff) + 0x473);
  }
  else {
    sVar2 = 8;
  }
  func_020ec918(param_1,0xd000,0x29,sVar2,0);
  uVar5 = param_1 + 0x74U & 3;
  uVar4 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  if (((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) & 1) == 0) {
    uVar5 = param_1 + 0xd4U & 3;
    uVar4 = *(uint *)(param_1 + 0xd4U & 0xfffffffc);
    func_0210ddf4(uRam020f5b68,(uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) & 0x3fffffe0,
                  uRam020f5b6c,param_1,0);
  }
  uVar5 = param_1 + 0x74U & 3;
  uVar4 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  if (((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) & 1) != 0) {
    return;
  }
  uVar5 = param_1 + 0x240U & 3;
  uVar4 = *(uint *)(param_1 + 0x240U & 0xfffffffc);
  uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  if (uRam020f5b70 < uVar5) {
    func_020f29e8(param_1);
    *(undefined2 *)(param_1 + 0x24c) = 1;
    *(undefined2 *)(param_1 + 0x24e) = 1;
    return;
  }
  if (0x10 < uVar5) {
    iVar3 = func_020f11f0(param_1,1);
    if (iVar3 == 0) {
      return;
    }
    *(undefined2 *)(param_1 + 0x24c) = 4;
    *(undefined2 *)(param_1 + 0x24e) = 1;
    uVar5 = param_1 + 0x74U & 3;
    uVar4 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
    if (((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) & 0x8000000) != 0) {
      uVar5 = param_1 + 0x228U & 3;
      uVar4 = *(uint *)(param_1 + 0x228U & 0xfffffffc);
      func_020fe71c(1,*(undefined2 *)((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + 0x1f8),
                    (int)*(short *)(param_1 + 0x4e));
      return;
    }
    return;
  }
  if (uVar5 < 5) {
    return;
  }
  iVar3 = func_020f1180(param_1,1);
  if (iVar3 != 0) {
    *(undefined2 *)(param_1 + 0x24c) = 4;
    *(undefined2 *)(param_1 + 0x24e) = 1;
    uVar5 = param_1 + 0x74U & 3;
    uVar4 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
    if (((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) & 0x8000000) != 0) {
      uVar5 = param_1 + 0x228U & 3;
      uVar4 = *(uint *)(param_1 + 0x228U & 0xfffffffc);
      func_020fe71c(1,*(undefined2 *)((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + 0x1f8),
                    (int)*(short *)(param_1 + 0x4e));
      return;
    }
    return;
  }
  return;
}

