/* Decompiled C draft; module arm9; ROM address 01ffba68. No matching claim. */
#include "types.h"
#include "deps/01ffba68_func_01ffba68.h"

void func_01ffba68(int param_1)

{
  short sVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  bool bVar11;
  uint local_18;
  
  uVar5 = param_1 + 0x44U & 3;
  uVar4 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  bVar11 = ((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) & 8) == 0;
  if (bVar11) {
    uVar5 = param_1 + 0x2ccU & 3;
    uVar4 = *(uint *)(param_1 + 0x2ccU & 0xfffffffc);
    uVar5 = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + 0x14;
    uVar4 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    local_18 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
    uVar5 = param_1 + 0x2ccU & 3;
    uVar4 = *(uint *)(param_1 + 0x2ccU & 0xfffffffc);
    uVar4 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
    uVar5 = uVar4 + 0x18;
    uVar6 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
    uVar4 = uVar4 + 0x1c;
    uVar5 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  }
  else {
    uVar5 = param_1 + 0x2ccU & 3;
    uVar4 = *(uint *)(param_1 + 0x2ccU & 0xfffffffc);
    uVar5 = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + 0x20;
    uVar4 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    local_18 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
    uVar5 = param_1 + 0x2ccU & 3;
    uVar4 = *(uint *)(param_1 + 0x2ccU & 0xfffffffc);
    uVar4 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
    uVar5 = uVar4 + 0x24;
    uVar6 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
    uVar4 = uVar4 + 0x28;
    uVar5 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  }
  uVar3 = local_18;
  uVar4 = param_1 + 0x48U & 3;
  uVar8 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  uVar4 = uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20;
  if ((uVar4 & 0x20) == 0) {
    if ((uVar4 & 4) == 0) {
      uVar4 = local_18;
      if (bVar11) {
        uVar8 = param_1 + 0x4cU & 3;
        uVar9 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
        if (((uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20) & uRam01ffbd88) == 0) {
          uVar8 = param_1 + 0x2a8U & 3;
          uVar9 = *(uint *)(param_1 + 0x2a8U & 0xfffffffc);
          uVar9 = uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20;
          uVar8 = param_1 + 0x2a0U & 3;
          uVar10 = *(uint *)(param_1 + 0x2a0U & 0xfffffffc);
          uVar8 = uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20;
          if ((int)uVar9 < 0) {
            uVar9 = -uVar9;
            lVar2 = (ulonglong)uVar9 * 0x52;
            uVar5 = (uint)lVar2;
            uVar4 = local_18 +
                    (uVar5 + 0x800 >> 0xc |
                    (((int)uVar9 >> 0x1f) * 0x52 + (int)((ulonglong)lVar2 >> 0x20) +
                    (uint)(0xfffff7ff < uVar5)) * 0x100000);
          }
          else if ((0x7ff < (int)uVar8) && (uVar4 = uVar6, (int)uVar8 <= (int)uVar5)) {
            iVar7 = FX_Div(local_18 - uVar6,uVar5 - 0x800);
            lVar2 = (longlong)iVar7 * (longlong)(int)(uVar8 - 0x800);
            uVar4 = uVar3 - ((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14);
          }
        }
        else {
          local_18 = uRam01ffbd8c;
          uVar4 = local_18;
        }
      }
    }
    else {
      local_18 = uRam01ffbd80;
      uVar5 = param_1 + 0x4cU & 3;
      uVar6 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
      uVar4 = local_18;
      if (((uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) & 0x40) != 0) {
        local_18 = uRam01ffbd84;
        uVar4 = local_18;
      }
    }
  }
  else {
    func_0206ceb4(&local_18,param_1);
    uVar4 = local_18;
  }
  local_18 = uVar4;
  uVar5 = param_1 + 0x4cU & 3;
  uVar4 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  if (((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) & 0x20000000) != 0) {
    func_020713a0(param_1);
  }
  uVar5 = param_1 + 0x48U & 3;
  uVar4 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  if ((uVar5 & 0x10000000) == 0) {
    uVar4 = param_1 + 0x44U & 3;
    uVar6 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
    if ((((uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) & 0x10) != 0) &&
       (uVar4 = param_1 + 0x4cU & 3, uVar6 = *(uint *)(param_1 + 0x4cU & 0xfffffffc),
       uVar4 = uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20, (uVar4 & 0x20000000) == 0)) {
      if ((uVar5 & 0x80) == 0) {
        if ((uVar5 & 0x26) == 0) {
          if ((uVar4 & 0x10000000) == 0) {
            uVar5 = param_1 + 0x44U & 3;
            uVar4 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
            *(uint *)(param_1 + 0x44) = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20 | 0x400;
          }
        }
        else {
          uVar5 = param_1 + 0x2a8U & 3;
          uVar4 = *(uint *)(param_1 + 0x2a8U & 0xfffffffc);
          *(uint *)(param_1 + 0x2a8) = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + local_18;
        }
      }
      else {
        uVar5 = param_1 + 0x2a8U & 3;
        uVar4 = *(uint *)(param_1 + 0x2a8U & 0xfffffffc);
        uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
        lVar2 = (ulonglong)uRam01ffbd90 * (ulonglong)uVar5;
        *(uint *)(param_1 + 0x2a8) =
             (uint)lVar2 >> 0xc |
             (((int)uVar5 >> 0x1f) * uRam01ffbd90 + (int)((ulonglong)lVar2 >> 0x20)) * 0x100000;
      }
    }
  }
  else {
    uVar5 = param_1 + 0x2a8U & 3;
    uVar4 = *(uint *)(param_1 + 0x2a8U & 0xfffffffc);
    *(uint *)(param_1 + 0x2a8) = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + 0x1000;
  }
  uVar5 = param_1 + 0x44U & 3;
  uVar4 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  if (((uVar5 & 0x8000) != 0) && ((uVar5 & 0x10) != 0)) {
    uVar5 = param_1 + 0x44U & 3;
    uVar4 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
    *(uint *)(param_1 + 0x44) = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) & 0xffff7fff;
  }
  if (*(short *)(param_1 + 0x386) != 0) {
    *(short *)(param_1 + 0x386) = (short)((uint)(iRam01ffbd94 * *(short *)(param_1 + 0x386)) >> 0xc)
    ;
    iVar7 = (int)*(short *)(param_1 + 0x386);
    if (iVar7 < 1) {
      iVar7 = -iVar7;
    }
    if (iVar7 < 0x14) {
      *(undefined2 *)(param_1 + 0x386) = 0;
    }
    *(short *)(param_1 + 0x236) = *(short *)(param_1 + 0x236) + *(short *)(param_1 + 0x386);
  }
  uVar5 = param_1 + 0x44U & 3;
  uVar4 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  if ((uVar5 & 0x10) == 0) {
    return;
  }
  if (!bVar11) {
    return;
  }
  if ((uVar5 & uRam01ffbd98) == 0) {
    sVar1 = *(short *)(param_1 + 0x388);
    if (0 < sVar1) {
      uVar5 = param_1 + 0x2ccU & 3;
      uVar4 = *(uint *)(param_1 + 0x2ccU & 0xfffffffc);
      uVar5 = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + 0x34;
      uVar4 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      *(ushort *)(param_1 + 0x388) =
           sVar1 - ((ushort)(uVar5 >> uVar4 * 8) | (ushort)(uVar5 << uVar4 * -8 + 0x20));
      if (*(short *)(param_1 + 0x388) < 0) {
        *(undefined2 *)(param_1 + 0x388) = 0;
      }
      return;
    }
    if (sVar1 < 0) {
      uVar5 = param_1 + 0x2ccU & 3;
      uVar4 = *(uint *)(param_1 + 0x2ccU & 0xfffffffc);
      uVar5 = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + 0x34;
      uVar4 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      *(ushort *)(param_1 + 0x388) =
           sVar1 + ((ushort)(uVar5 >> uVar4 * 8) | (ushort)(uVar5 << uVar4 * -8 + 0x20));
      if (0 < *(short *)(param_1 + 0x388)) {
        *(undefined2 *)(param_1 + 0x388) = 0;
      }
      return;
    }
    return;
  }
  return;
}

