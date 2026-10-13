/* Decompiled C draft; module arm9; ROM address 020dd27c. No matching claim. */
#include "types.h"
#include "deps/020dd27c_func_020dd27c.h"

void func_020dd27c(undefined4 param_1,int param_2)

{
  int iVar1;
  longlong lVar2;
  bool bVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint local_78;
  undefined1 auStack_74 [16];
  uint local_64;
  int local_60;
  uint local_5c;
  undefined4 local_58;
  int local_54;
  undefined4 local_50;
  int local_4c [2];
  int local_44;
  undefined4 local_40;
  int local_3c;
  undefined4 uStack_38;
  uint local_34;
  undefined4 local_30;
  int local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  uVar10 = param_2 + 0xb0U & 3;
  uVar12 = *(uint *)(param_2 + 0xb0U & 0xfffffffc);
  uVar8 = uVar12 >> uVar10 * 8;
  iVar1 = uVar12 << uVar10 * -8 + 0x20;
  StateDualHandler_Execute(param_2 + 0x80);
  uVar10 = param_2 + 0x14U & 3;
  uVar12 = *(uint *)(param_2 + 0x14U & 0xfffffffc);
  *(uint *)(param_2 + 0x14) = (uVar12 >> uVar10 * 8 | uVar12 << uVar10 * -8 + 0x20) - 0x400;
  uVar10 = param_2 + 8U & 3;
  uVar9 = *(uint *)(param_2 + 8U & 0xfffffffc);
  uVar12 = param_2 + 0x14U & 3;
  uVar4 = *(uint *)(param_2 + 0x14U & 0xfffffffc);
  bVar3 = false;
  *(uint *)(param_2 + 8) =
       (uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20) +
       (uVar4 >> uVar12 * 8 | uVar4 << uVar12 * -8 + 0x20);
  uVar10 = param_2 + 4U & 3;
  uVar12 = *(uint *)(param_2 + 4U & 0xfffffffc);
  local_64 = uVar12 >> uVar10 * 8 | uVar12 << uVar10 * -8 + 0x20;
  uVar10 = param_2 + 8U & 3;
  uVar9 = *(uint *)(param_2 + 8U & 0xfffffffc);
  uVar12 = param_2 + 0xf4U & 3;
  uVar4 = *(uint *)(param_2 + 0xf4U & 0xfffffffc);
  local_60 = (uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20) +
             (uVar4 >> uVar12 * 8 | uVar4 << uVar12 * -8 + 0x20) + 0x5000;
  uVar10 = param_2 + 0xcU & 3;
  uVar12 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
  local_5c = uVar12 >> uVar10 * 8 | uVar12 << uVar10 * -8 + 0x20;
  if (uVar8 == 0 && iVar1 == 0) {
    uVar10 = param_2 + 0xacU & 3;
    uVar12 = *(uint *)(param_2 + 0xacU & 0xfffffffc);
    local_54 = ((uVar12 >> uVar10 * 8 | uVar12 << uVar10 * -8 + 0x20) + 0xd000) - local_60;
    if (0 < local_54) {
      local_58 = 0;
      local_50 = 0;
      uVar10 = param_2 + 0xfcU & 3;
      uVar12 = *(uint *)(param_2 + 0xfcU & 0xfffffffc);
      bVar3 = true;
      if ((uVar12 >> uVar10 * 8 != 0 || uVar12 << uVar10 * -8 + 0x20 != 0) &&
         (uVar10 = param_2 + 0x78U & 3, uVar12 = *(uint *)(param_2 + 0x78U & 0xfffffffc),
         ((uVar12 >> uVar10 * 8 | uVar12 << uVar10 * -8 + 0x20) & 4) == 0)) {
        uVar10 = param_2 + 0x70U & 3;
        uVar12 = *(uint *)(param_2 + 0x70U & 0xfffffffc);
        uVar4 = uVar12 >> uVar10 * 8 | uVar12 << uVar10 * -8 + 0x20;
        uVar10 = iRam020dd6b0 + 0x68U & 3;
        uVar12 = *(uint *)(iRam020dd6b0 + 0x68U & 0xfffffffc);
        if (uVar4 == (uVar12 >> uVar10 * 8 | uVar12 << uVar10 * -8 + 0x20)) {
          local_28 = 2;
        }
        else {
          uVar10 = iRam020dd6b0 + 0x8cU & 3;
          uVar12 = *(uint *)(iRam020dd6b0 + 0x8cU & 0xfffffffc);
          if (uVar4 == (uVar12 >> uVar10 * 8 | uVar12 << uVar10 * -8 + 0x20)) {
            local_28 = 3;
          }
          else {
            local_28 = 4;
          }
        }
        local_2c = param_2 + 4;
        local_30 = uRam020dd6b4;
        local_24 = func_020d4ef4();
        func_0210b7a8((uint)(uintptr_t)(&local_30));
      }
    }
  }
  else {
    iVar5 = func_01ffdee4(&local_64,0,0,0xd000,8,0xfffffffe,&local_58,local_4c,0,&local_78,0,0,0,0);
    if (((iVar5 != 0) &&
        (uVar10 = param_2 + 0xfcU & 3, uVar12 = *(uint *)(param_2 + 0xfcU & 0xfffffffc),
        bVar3 = true, uVar12 >> uVar10 * 8 != 0 || uVar12 << uVar10 * -8 + 0x20 != 0)) &&
       (uVar10 = param_2 + 0x78U & 3, uVar12 = *(uint *)(param_2 + 0x78U & 0xfffffffc),
       ((uVar12 >> uVar10 * 8 | uVar12 << uVar10 * -8 + 0x20) & 4) == 0)) {
      uVar10 = param_2 + 0x70U & 3;
      uVar12 = *(uint *)(param_2 + 0x70U & 0xfffffffc);
      uVar4 = uVar12 >> uVar10 * 8 | uVar12 << uVar10 * -8 + 0x20;
      uVar10 = iRam020dd6b0 + 0x68U & 3;
      uVar12 = *(uint *)(iRam020dd6b0 + 0x68U & 0xfffffffc);
      if (uVar4 == (uVar12 >> uVar10 * 8 | uVar12 << uVar10 * -8 + 0x20)) {
        local_18 = 2;
      }
      else {
        uVar10 = iRam020dd6b0 + 0x8cU & 3;
        uVar12 = *(uint *)(iRam020dd6b0 + 0x8cU & 0xfffffffc);
        if (uVar4 == (uVar12 >> uVar10 * 8 | uVar12 << uVar10 * -8 + 0x20)) {
          local_18 = 3;
        }
        else {
          local_18 = 4;
        }
      }
      local_1c = param_2 + 4;
      local_20 = uRam020dd6b8;
      local_14 = func_020d4ef4();
      func_0210b7a8((uint)(uintptr_t)(&local_20));
    }
  }
  if (bVar3) {
    bVar3 = true;
    if ((*(short *)(param_2 + 0x8e) == 2) &&
       (uVar10 = param_2 + 0x84U & 3, uVar12 = *(uint *)(param_2 + 0x84U & 0xfffffffc),
       (uVar12 >> uVar10 * 8 | uVar12 << uVar10 * -8 + 0x20) < 0x78)) {
      bVar3 = false;
    }
    uVar10 = param_2 + 8U & 3;
    uVar12 = *(uint *)(param_2 + 8U & 0xfffffffc);
    *(uint *)(param_2 + 8) = (uVar12 >> uVar10 * 8 | uVar12 << uVar10 * -8 + 0x20) + local_54;
    uVar10 = param_2 + 0xfcU & 3;
    uVar4 = *(uint *)(param_2 + 0xfcU & 0xfffffffc);
    uVar12 = uVar4 >> uVar10 * 8;
    iVar5 = uVar4 << uVar10 * -8 + 0x20;
    if ((uVar12 != 0 || iVar5 != 0) || (bVar3)) {
      if (uVar12 == 0 && iVar5 == 0) {
        uVar10 = param_2 + 0x168U & 3;
        uVar12 = *(uint *)(param_2 + 0x168U & 0xfffffffc);
        uVar4 = uVar12 >> uVar10 * 8 | uVar12 << uVar10 * -8 + 0x20;
        uVar10 = param_2 + 4U & 3;
        uVar11 = *(uint *)(param_2 + 4U & 0xfffffffc);
        uVar12 = uVar4 + 8 & 3;
        uVar7 = *(uint *)(uVar4 + 8 & 0xfffffffc);
        uVar9 = param_2 + 0xcU & 3;
        uVar6 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
        uVar4 = (*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
                *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) -
                (uVar11 >> uVar10 * 8 | uVar11 << uVar10 * -8 + 0x20);
        uVar10 = (uVar7 >> uVar12 * 8 | uVar7 << uVar12 * -8 + 0x20) -
                 (uVar6 >> uVar9 * 8 | uVar6 << uVar9 * -8 + 0x20);
      }
      else {
        uVar10 = param_2 + 0x1c0U & 3;
        uVar12 = *(uint *)(param_2 + 0x1c0U & 0xfffffffc);
        uVar12 = uVar12 >> uVar10 * 8 | uVar12 << uVar10 * -8 + 0x20;
        uVar4 = *(uint *)(uVar12 & 0xfffffffc) >> (uVar12 & 3) * 8 |
                *(uint *)(uVar12 & 0xfffffffc) << (uVar12 & 3) * -8 + 0x20;
        uVar10 = uVar12 + 8 & 3;
        uVar12 = *(uint *)(uVar12 + 8 & 0xfffffffc);
        uVar10 = uVar12 >> uVar10 * 8 | uVar12 << uVar10 * -8 + 0x20;
      }
      uVar12 = param_2 + 0x18U & 3;
      uVar6 = *(uint *)(param_2 + 0x18U & 0xfffffffc);
      uVar9 = param_2 + 0x10U & 3;
      uVar7 = *(uint *)(param_2 + 0x10U & 0xfffffffc);
      lVar2 = (longlong)(int)uVar4 *
              (longlong)(int)(uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20) +
              (longlong)(int)(uVar6 >> uVar12 * 8 | uVar6 << uVar12 * -8 + 0x20) *
              (longlong)(int)uVar10;
      uVar10 = (int)((ulonglong)lVar2 >> 0x20) << 0x14;
      uVar12 = (uint)lVar2 >> 0xc | uVar10;
      uVar10 = (uVar12 << 9) >> 0xc | (((int)uVar12 >> 0x1f) << 9 | uVar10 >> 0x17) << 0x14;
      if ((int)uVar10 < 0x3001) {
        if ((int)uVar10 < 0x2800) {
          uVar10 = 0x2800;
        }
      }
      else {
        uVar10 = 0x3000;
      }
      *(uint *)(param_2 + 0x14) = uVar10;
    }
    else {
      uVar10 = param_2 + 0xe8U & 3;
      uVar12 = *(uint *)(param_2 + 0xe8U & 0xfffffffc);
      if ((uVar12 >> uVar10 * 8 | uVar12 << uVar10 * -8 + 0x20) == 0xd000) {
        *(undefined4 *)(param_2 + 0x14) = 0x2000;
        uVar10 = param_2 + 0xe8U & 3;
        uVar12 = *(uint *)(param_2 + 0xe8U & 0xfffffffc);
        *(uint *)(param_2 + 0xe8) = (uVar12 >> uVar10 * 8 | uVar12 << uVar10 * -8 + 0x20) + 0x1000;
      }
      else {
        *(undefined4 *)(param_2 + 0x14) = 0;
      }
    }
    if ((uVar8 != 0 || iVar1 != 0) && ((local_78 & uRam020dd6bc) != 0)) {
      uVar10 = param_2 + 0x18U & 3;
      uVar4 = *(uint *)(param_2 + 0x18U & 0xfffffffc);
      uVar12 = param_2 + 0x10U & 3;
      uVar9 = *(uint *)(param_2 + 0x10U & 0xfffffffc);
      lVar2 = (longlong)local_4c[0] *
              (longlong)(int)(uVar9 >> uVar12 * 8 | uVar9 << uVar12 * -8 + 0x20) +
              (longlong)(int)(uVar4 >> uVar10 * 8 | uVar4 << uVar10 * -8 + 0x20) *
              (longlong)local_44;
      uVar10 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
      if ((int)uVar10 < 0) {
        uVar10 = -uVar10;
        lVar2 = (ulonglong)uRam020dd6c0 * (ulonglong)uVar10;
        uVar12 = param_2 + 0x14U & 3;
        uVar4 = *(uint *)(param_2 + 0x14U & 0xfffffffc);
        *(uint *)(param_2 + 0x14) =
             (uVar4 >> uVar12 * 8 | uVar4 << uVar12 * -8 + 0x20) +
             ((uint)lVar2 >> 0xc |
             (((int)uVar10 >> 0x1f) * uRam020dd6c0 + (int)((ulonglong)lVar2 >> 0x20)) * 0x100000);
      }
      func_020d7b88((uint)(uintptr_t)(local_4c),(undefined4 *)(uintptr_t)(param_2 + 0xc4));
    }
    uVar10 = param_2 + 0xfcU & 3;
    uVar12 = *(uint *)(param_2 + 0xfcU & 0xfffffffc);
    if (((uVar12 >> uVar10 * 8 == 0 && uVar12 << uVar10 * -8 + 0x20 == 0) &&
        (uVar10 = param_2 + 0x78U & 3, uVar12 = *(uint *)(param_2 + 0x78U & 0xfffffffc),
        ((uVar12 >> uVar10 * 8 | uVar12 << uVar10 * -8 + 0x20) & 4) == 0)) && (bVar3)) {
      local_40 = *puRam020dd6c4;
      uStack_38 = puRam020dd6c4[2];
      local_3c = param_2 + 4;
      uVar10 = param_2 + 0x78U & 3;
      uVar12 = *(uint *)(param_2 + 0x78U & 0xfffffffc);
      local_34 = (uVar12 >> uVar10 * 8 | uVar12 << uVar10 * -8 + 0x20) & 0x3fffffe0;
      func_0210b7a8((uint)(uintptr_t)(&local_40));
    }
  }
  if (uVar8 != 0 || iVar1 != 0) {
    func_020d7938(param_2 + 0xc4,param_2 + 0xd4,(int *)(void *)(auStack_74));
  }
  uVar10 = param_2 + 0x14U & 3;
  uVar4 = *(uint *)(param_2 + 0x14U & 0xfffffffc);
  uVar12 = param_2 + 0xe4U & 3;
  uVar9 = *(uint *)(param_2 + 0xe4U & 0xfffffffc);
  uVar12 = uVar9 >> uVar12 * 8 | uVar9 << uVar12 * -8 + 0x20;
  *(uint *)(param_2 + 0xe4) =
       uVar12 + ((int)(((int)-(uVar4 >> uVar10 * 8 | uVar4 << uVar10 * -8 + 0x20) >> 1) - uVar12) >>
                4);
  if (uVar8 == 0 && iVar1 == 0) {
    uVar10 = param_2 + 0xe8U & 3;
    uVar4 = *(uint *)(param_2 + 0xe8U & 0xfffffffc);
    uVar12 = param_2 + 0xe4U & 3;
    uVar8 = *(uint *)(param_2 + 0xe4U & 0xfffffffc);
    func_020d76a8(param_2 + 0xd4,
                  (uVar4 >> uVar10 * 8 | uVar4 << uVar10 * -8 + 0x20) +
                  (uVar8 >> uVar12 * 8 | uVar8 << uVar12 * -8 + 0x20) & 0xffff,(int *)(void *)(auStack_74));
  }
  else {
    uVar10 = param_2 + 0xe8U & 3;
    uVar4 = *(uint *)(param_2 + 0xe8U & 0xfffffffc);
    uVar12 = param_2 + 0xe4U & 3;
    uVar8 = *(uint *)(param_2 + 0xe4U & 0xfffffffc);
    func_020d788c((int *)(void *)(auStack_74),
                  (uVar4 >> uVar10 * 8 | uVar4 << uVar10 * -8 + 0x20) +
                  (uVar8 >> uVar12 * 8 | uVar8 << uVar12 * -8 + 0x20) & 0xffff,(int *)(void *)(auStack_74));
  }
  uVar10 = param_2 + 0xecU & 3;
  uVar12 = *(uint *)(param_2 + 0xecU & 0xfffffffc);
  func_020d759c(param_2 + 0xb4,(uint)(uintptr_t)(auStack_74),(int *)(uintptr_t)(param_2 + 0xb4),
                uVar12 >> uVar10 * 8 | uVar12 << uVar10 * -8 + 0x20);
  func_020d73f0((int *)(uintptr_t)(param_2 + 0xb4),(int *)(uintptr_t)(param_2 + 0xb4));
  func_01ffccd0((int *)(uintptr_t)(param_2 + 0x28),param_2 + 0xb4);
  uVar10 = param_2 + 8U & 3;
  uVar12 = *(uint *)(param_2 + 8U & 0xfffffffc);
  if ((int)(uVar12 >> uVar10 * 8 | uVar12 << uVar10 * -8 + 0x20) < 0) {
    func_020dbf7c(param_2);
    return;
  }
  return;
}

