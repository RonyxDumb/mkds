/* Decompiled C draft; module arm9; ROM address 02104a0c. No matching claim. */
#include "types.h"
#include "deps/02104a0c_func_02104a0c.h"

void func_02104a0c(int param_1)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar5;
  int iVar6;
  undefined1 auStack_2c [4];
  undefined1 auStack_28 [12];
  uint local_1c;
  uint local_18;
  uint local_14;
  uint uVar4;
  
  uVar4 = param_1 + 0x74U & 3;
  uVar3 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  if ((uVar4 & 0x180000) == 0) {
    if ((uVar4 & 0x8000) == 0) {
      if ((uVar4 & 0x4000) == 0) {
        uVar4 = param_1 + 0x130U & 3;
        uVar3 = *(uint *)(param_1 + 0x130U & 0xfffffffc);
        if (uVar3 >> uVar4 * 8 == 0 && uVar3 << uVar4 * -8 + 0x20 == 0) {
          func_020f2df0(param_1,uRam02104c60,uRam02104c64,0,auStack_2c);
        }
        else {
          func_020f2df0(param_1,0x1ec,uRam02104c5c,0,auStack_2c);
        }
        uVar4 = param_1 + 0x74U & 3;
        uVar3 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
        uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
        if (((uVar4 & 8) != 0) && ((uVar4 & 3) == 0)) {
          uVar4 = param_1 + 0x130U & 3;
          uVar3 = *(uint *)(param_1 + 0x130U & 0xfffffffc);
          if (uVar3 >> uVar4 * 8 != 0 || uVar3 << uVar4 * -8 + 0x20 != 0) {
            uVar4 = param_1 + 0x60U & 3;
            uVar3 = *(uint *)(param_1 + 0x60U & 0xfffffffc);
            *(uint *)(param_1 + 0x60) = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) << 1;
          }
          func_02109060(param_1,0xda);
          func_020f6a6c(param_1,auStack_2c);
        }
      }
      else {
        func_020f63cc();
      }
    }
    else {
      uVar4 = (*(uint *)(uRam02104c50 & 0xfffffffc) >> (uRam02104c50 & 3) * 8 |
              *(uint *)(uRam02104c50 & 0xfffffffc) << (uRam02104c50 & 3) * -8 + 0x20) + 8;
      uVar3 = uVar4 & 3;
      uVar4 = *(uint *)(uVar4 & 0xfffffffc);
      if ((uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) == 2) {
        uVar2 = *(ushort *)(param_1 + 0x78) & 0xffff00ff;
        uVar4 = iRam02104c54 + uVar2 * 4;
        uVar3 = uVar4 & 3;
        uVar4 = *(uint *)(uVar4 & 0xfffffffc);
        iVar6 = (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) - 0x3c;
        if (iVar6 < *(short *)(param_1 + 0xd8)) {
          *(short *)(param_1 + 0xd8) = (short)iVar6;
        }
        if ((iVar6 < 10) && (func_020f9c40(param_1), iVar6 == 0)) {
          uVar4 = param_1 + 0x44U & 3;
          uVar3 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
          func_020f0f70((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) * 0x44 +
                        (*(uint *)(uRam02104c58 & 0xfffffffc) >> (uRam02104c58 & 3) * 8 |
                        *(uint *)(uRam02104c58 & 0xfffffffc) << (uRam02104c58 & 3) * -8 + 0x20),
                        param_1);
          return;
        }
        uVar4 = iRam02104c54 + uVar2 * 4;
        uVar3 = uVar4 & 3;
        uVar4 = *(uint *)(uVar4 & 0xfffffffc);
        *(uint *)(iRam02104c54 + uVar2 * 4) = (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) - 1;
      }
      func_020f68b0(param_1);
    }
  }
  else if ((uVar4 & 0x80000) == 0) {
    if ((uVar4 & 0x100000) != 0) {
      func_020f758c();
    }
  }
  else {
    func_020f6e58();
  }
  uVar4 = param_1 + 0x138U & 3;
  uVar2 = *(uint *)(param_1 + 0x138U & 0xfffffffc);
  uVar3 = param_1 + 0x134U & 3;
  uVar5 = *(uint *)(param_1 + 0x134U & 0xfffffffc);
  uVar3 = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20;
  if ((uVar2 >> uVar4 * 8 == 0 && uVar2 << uVar4 * -8 + 0x20 == 0) ||
     (uVar4 = param_1 + 0x148U & 3, uVar2 = *(uint *)(param_1 + 0x148U & 0xfffffffc),
     uVar4 = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20, 0xfff < (int)uVar4)) {
    *(undefined4 *)(param_1 + 0x13c) = *(undefined4 *)(param_1 + 0x50);
    *(undefined4 *)(param_1 + 0x140) = *(undefined4 *)(param_1 + 0x54);
    *(undefined4 *)(param_1 + 0x144) = *(undefined4 *)(param_1 + 0x58);
    func_02105338(uVar3,(int)*(short *)(param_1 + 0xd8),param_1 + 0x68);
  }
  else {
    *(uint *)(param_1 + 0x148) = uVar4 + 0xcd;
    uVar4 = param_1 + 0x148U & 3;
    uVar2 = *(uint *)(param_1 + 0x148U & 0xfffffffc);
    uVar5 = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20;
    uVar4 = param_1 + 0x68U & 3;
    uVar2 = *(uint *)(param_1 + 0x68U & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) * (longlong)(int)uVar5;
    local_1c = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    uVar4 = param_1 + 0x6cU & 3;
    uVar2 = *(uint *)(param_1 + 0x6cU & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) * (longlong)(int)uVar5;
    local_18 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    uVar4 = param_1 + 0x70U & 3;
    uVar2 = *(uint *)(param_1 + 0x70U & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) * (longlong)(int)uVar5;
    local_14 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    VecFx32_Subtract(param_1 + 0x50,param_1 + 0x13c,auStack_28);
    uVar4 = param_1 + 0x148U & 3;
    uVar2 = *(uint *)(param_1 + 0x148U & 0xfffffffc);
    uVar4 = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20;
    lVar1 = (longlong)(int)uVar4 * (longlong)(int)uVar4;
    VecFx32_AddScale1((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14,auStack_28,
                      param_1 + 0x13c,param_1 + 0x13c);
    func_02105338(uVar3,(int)*(short *)(param_1 + 0xd8),&local_1c);
  }
  func_021052fc(uVar3);
  return;
}

