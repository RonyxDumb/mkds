/* Decompiled C draft; module arm9; ROM address 0207d6a4. No matching claim. */
#include "types.h"
#include "deps/0207d6a4_func_0207d6a4.h"

void func_0207d6a4(int param_1,uint param_2)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  uVar2 = func_02061f90();
  if (*(ushort *)(param_2 + 4) == uVar2) {
    *(undefined4 *)(param_1 + 8) = 0;
    uVar2 = (*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
            *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) + 0xcc;
    uVar5 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    uVar2 = uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20;
    if (0xa000 < (int)uVar2) {
      uVar2 = 0xa000;
    }
    *(uint *)(param_1 + 0xc) = uVar2;
    uVar5 = param_2 + 0x70 & 3;
    uVar4 = *(uint *)(param_2 + 0x70 & 0xfffffffc);
    uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
    if (0x5000 < (int)uVar5) {
      uVar5 = uVar5 - 0x5000;
      lVar1 = (ulonglong)uVar5 * 0x5b;
      uVar5 = (uint)lVar1 >> 0xc |
              (((int)uVar5 >> 0x1f) * 0x5b + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
      if (0x1000 < (int)uVar5) {
        uVar5 = 0x1000;
      }
      lVar1 = (ulonglong)
              (0x1000 - ((uint)((ulonglong)uRam0207d7dc * (ulonglong)uVar5) >> 0xc |
                        (((int)uVar5 >> 0x1f) * uRam0207d7dc +
                        (int)((ulonglong)uRam0207d7dc * (ulonglong)uVar5 >> 0x20)) * 0x100000)) *
              0xa000;
      *(uint *)(param_1 + 0xc) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000;
    }
    uVar5 = param_1 + 0xcU & 3;
    uVar4 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
    uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
    if ((int)uVar5 < (int)uVar2) {
      uVar2 = uVar5;
    }
    if (0xa000 < (int)uVar2) {
      uVar2 = 0xa000;
    }
    *(uint *)(param_1 + 4) = uVar2;
  }
  uVar5 = *(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
          *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20;
  uVar2 = uVar5 + 0x180;
  uVar4 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if (uVar2 >> uVar4 * 8 == 0 && uVar2 << uVar4 * -8 + 0x20 == 0) {
    uVar5 = uVar5 + 0x48;
    uVar2 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    if (((uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) & uRam0207d7e0) == 0) {
      iVar3 = func_0207fe70(param_2 + 8);
      uVar2 = param_1 + 4U & 3;
      uVar5 = *(uint *)(param_1 + 4U & 0xfffffffc);
      lVar1 = (longlong)(int)(uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) * (longlong)iVar3 +
              0x800;
      *(uint *)((*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
                *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) + 0xcc) =
           (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000;
      return;
    }
    return;
  }
  return;
}

