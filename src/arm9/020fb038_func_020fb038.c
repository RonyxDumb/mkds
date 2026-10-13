/* Decompiled C draft; module arm9; ROM address 020fb038. No matching claim. */
#include "types.h"
#include "deps/020fb038_func_020fb038.h"

void func_020fb038(int param_1)

{
  longlong lVar1;
  uint uVar2;
  undefined2 uVar3;
  uint uVar4;
  uint uVar5;
  undefined1 auStack_28 [12];
  undefined1 auStack_1c [20];
  uint uVar6;
  
  func_020f8e78();
  uVar6 = param_1 + 0x21cU & 3;
  uVar2 = *(uint *)(param_1 + 0x21cU & 0xfffffffc);
  if (uVar2 >> uVar6 * 8 == 0 && uVar2 << uVar6 * -8 + 0x20 == 0) {
    uVar6 = param_1 + 0x74U & 3;
    uVar2 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
    if (((uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20) & 0x8000000) == 0) {
      func_020fcb9c(param_1,(short)*(char *)((*(uint *)(uRam020fb204 & 0xfffffffc) >>
                                              (uRam020fb204 & 3) * 8 |
                                             *(uint *)(uRam020fb204 & 0xfffffffc) <<
                                             (uRam020fb204 & 3) * -8 + 0x20) + 0x474));
      uVar6 = param_1 + 0x228U & 3;
      uVar4 = *(uint *)(param_1 + 0x228U & 0xfffffffc);
      uVar2 = param_1 + 0x74U & 3;
      uVar5 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
      uVar6 = (uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) + 0x1fc;
      uVar4 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      if ((((uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) & 0x40000000) == 0) &&
         (uVar6 = (uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) + 0x48, uVar2 = uVar6 & 3,
         uVar6 = *(uint *)(uVar6 & 0xfffffffc),
         ((uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20) & 1) == 0)) {
        uVar3 = 3;
      }
      else {
        uVar3 = 2;
      }
      *(undefined2 *)(param_1 + 0x2f8) = uVar3;
      *(undefined2 *)(param_1 + 0x2fa) = 1;
      uVar6 = param_1 + 0x74U & 3;
      uVar2 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
      if (((uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20) & 0x8000000) != 0) {
        uVar6 = param_1 + 0x228U & 3;
        uVar2 = *(uint *)(param_1 + 0x228U & 0xfffffffc);
        func_020fe71c(5,*(undefined2 *)((uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20) + 0x1f8),
                      (int)*(short *)(param_1 + 0x4e));
      }
    }
    else {
      uVar6 = param_1 + 0x228U & 3;
      uVar2 = *(uint *)(param_1 + 0x228U & 0xfffffffc);
      if (uVar2 >> uVar6 * 8 == 0 && uVar2 << uVar6 * -8 + 0x20 == 0) {
        func_020fcb9c(param_1,(short)*(char *)((*(uint *)(uRam020fb204 & 0xfffffffc) >>
                                                (uRam020fb204 & 3) * 8 |
                                               *(uint *)(uRam020fb204 & 0xfffffffc) <<
                                               (uRam020fb204 & 3) * -8 + 0x20) + 0x474));
        uVar6 = param_1 + 0x228U & 3;
        uVar4 = *(uint *)(param_1 + 0x228U & 0xfffffffc);
        uVar2 = param_1 + 0x74U & 3;
        uVar5 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
        uVar6 = (uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) + 0x1fc;
        uVar4 = uVar6 & 3;
        uVar6 = *(uint *)(uVar6 & 0xfffffffc);
        if ((((uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) & 0x40000000) == 0) &&
           (uVar6 = (uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) + 0x48, uVar2 = uVar6 & 3,
           uVar6 = *(uint *)(uVar6 & 0xfffffffc),
           ((uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20) & 1) == 0)) {
          uVar3 = 3;
        }
        else {
          uVar3 = 2;
        }
        *(undefined2 *)(param_1 + 0x2f8) = uVar3;
        *(undefined2 *)(param_1 + 0x2fa) = 1;
      }
    }
  }
  else {
    uVar6 = param_1 + 0x2fcU & 3;
    uVar2 = *(uint *)(param_1 + 0x2fcU & 0xfffffffc);
    func_020ec8bc(param_1,0x14,0xcc,1,0,uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20,
                  (short)*(char *)((*(uint *)(uRam020fb204 & 0xfffffffc) >> (uRam020fb204 & 3) * 8 |
                                   *(uint *)(uRam020fb204 & 0xfffffffc) <<
                                   (uRam020fb204 & 3) * -8 + 0x20) + 0x474),1);
    StateDualHandler_SetState(param_1 + 0x2e8,1);
  }
  func_020fc94c(param_1);
  uVar6 = param_1 + 0x60U & 3;
  uVar2 = *(uint *)(param_1 + 0x60U & 0xfffffffc);
  uVar4 = uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20;
  uVar6 = param_1 + 0x5cU & 3;
  uVar2 = *(uint *)(param_1 + 0x5cU & 0xfffffffc);
  uVar2 = uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20;
  uVar6 = param_1 + 100U & 3;
  uVar5 = *(uint *)(param_1 + 100U & 0xfffffffc);
  uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  lVar1 = (longlong)(int)uVar6 * (longlong)(int)uVar6 +
          (longlong)(int)uVar2 * (longlong)(int)uVar2 + (longlong)(int)uVar4 * (longlong)(int)uVar4;
  if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
    Vector3_MaybeNormalize(param_1 + 0x5c,(int *)(void *)(auStack_28));
  }
  func_020d7b88((uint)(uintptr_t)(auStack_28),(undefined4 *)(void *)(auStack_1c));
  func_01ffccd0((int *)(uintptr_t)(param_1 + 0x94),(uint)(uintptr_t)(auStack_1c));
  return;
}

