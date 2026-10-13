/* Decompiled C draft; module arm9; ROM address 0209f338. No matching claim. */
#include "types.h"
#include "deps/0209f338_func_0209f338.h"

void func_0209f338(undefined4 param_1,int param_2)

{
  short sVar1;
  uint uVar2;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 local_40;
  int local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  int local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  uint uVar3;
  
  uVar3 = param_2 + 0xa8U & 3;
  uVar2 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if (uVar3 == 0) {
    uVar3 = param_2 + 0xa4U & 3;
    uVar2 = *(uint *)(param_2 + 0xa4U & 0xfffffffc);
    uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    *(uint *)(param_2 + 0xa4) = uVar3 - 1;
    if ((int)uVar3 < 1) {
      *(undefined4 *)(param_2 + 0xa8) = 1;
    }
    return;
  }
  if (uVar3 == 1) {
    sVar1 = *(short *)(param_2 + 0xa0);
    if ((sVar1 == 0) || (sVar1 == 0x7d)) {
      uVar3 = param_2 + 0x78U & 3;
      uVar2 = *(uint *)(param_2 + 0x78U & 0xfffffffc);
      if (((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) & 4) == 0) {
        uVar3 = param_2 + 0x70U & 3;
        uVar2 = *(uint *)(param_2 + 0x70U & 0xfffffffc);
        uVar5 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
        uVar3 = iRam0209f500 + 0x68U & 3;
        uVar2 = *(uint *)(iRam0209f500 + 0x68U & 0xfffffffc);
        if (uVar5 == (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20)) {
          local_38 = 2;
        }
        else {
          uVar3 = iRam0209f500 + 0x8cU & 3;
          uVar2 = *(uint *)(iRam0209f500 + 0x8cU & 0xfffffffc);
          if (uVar5 == (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20)) {
            local_38 = 3;
          }
          else {
            local_38 = 4;
          }
        }
        local_3c = param_2 + 4;
        local_40 = uRam0209f504;
        local_34 = func_020d4ef4();
        func_0210b7a8((uint)(uintptr_t)(&local_40));
      }
    }
    else if ((sVar1 == 0x46) || (sVar1 == 0xaf)) {
      uVar3 = param_2 + 0x78U & 3;
      uVar2 = *(uint *)(param_2 + 0x78U & 0xfffffffc);
      if (((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) & 4) == 0) {
        uVar3 = param_2 + 0x70U & 3;
        uVar2 = *(uint *)(param_2 + 0x70U & 0xfffffffc);
        uVar5 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
        uVar3 = iRam0209f500 + 0x68U & 3;
        uVar2 = *(uint *)(iRam0209f500 + 0x68U & 0xfffffffc);
        if (uVar5 == (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20)) {
          local_28 = 2;
        }
        else {
          uVar3 = iRam0209f500 + 0x8cU & 3;
          uVar2 = *(uint *)(iRam0209f500 + 0x8cU & 0xfffffffc);
          if (uVar5 == (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20)) {
            local_28 = 3;
          }
          else {
            local_28 = 4;
          }
        }
        local_2c = param_2 + 4;
        local_30 = uRam0209f508;
        local_24 = func_020d4ef4();
        func_0210b7a8((uint)(uintptr_t)(&local_30));
      }
    }
    else if ((sVar1 == 0xfa) &&
            (uVar3 = param_2 + 0x78U & 3, uVar2 = *(uint *)(param_2 + 0x78U & 0xfffffffc),
            ((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) & 4) == 0)) {
      uVar3 = param_2 + 0x70U & 3;
      uVar2 = *(uint *)(param_2 + 0x70U & 0xfffffffc);
      uVar5 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
      uVar3 = iRam0209f500 + 0x68U & 3;
      uVar2 = *(uint *)(iRam0209f500 + 0x68U & 0xfffffffc);
      if (uVar5 == (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20)) {
        local_18 = 2;
      }
      else {
        uVar3 = iRam0209f500 + 0x8cU & 3;
        uVar2 = *(uint *)(iRam0209f500 + 0x8cU & 0xfffffffc);
        if (uVar5 == (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20)) {
          local_18 = 3;
        }
        else {
          local_18 = 4;
        }
      }
      local_1c = param_2 + 4;
      local_20 = uRam0209f50c;
      local_14 = func_020d4ef4();
      func_0210b7a8((uint)(uintptr_t)(&local_20));
    }
    iVar6 = *(ushort *)(param_2 + 0xa0) + 1;
    iVar4 = StructMapObject_GetAnimationBCAFrameCount
                      (*(uint *)(uRam0209f510 & 0xfffffffc) >> (uRam0209f510 & 3) * 8 |
                       *(uint *)(uRam0209f510 & 0xfffffffc) << (uRam0209f510 & 3) * -8 + 0x20);
    if (iVar4 <= iVar6) {
      iVar6 = 0;
    }
    *(short *)(param_2 + 0xa0) = (short)iVar6;
    if (*(short *)(param_2 + 0xa0) == 0) {
      *(undefined4 *)(param_2 + 0xa8) = 0;
    }
    return;
  }
  return;
}

