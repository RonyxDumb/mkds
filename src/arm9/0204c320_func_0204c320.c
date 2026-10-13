/* Decompiled C draft; module arm9; ROM address 0204c320. No matching claim. */
#include "types.h"
#include "deps/0204c320_func_0204c320.h"

void func_0204c320(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  code *pcVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uStack_20;
  uint uStack_1c;
  undefined1 uStack_18;
  
  iVar1 = func_02006fdc(*(undefined2 *)(param_1 + 10));
  iVar5 = iRam0204c7d8;
  iVar6 = iRam0204c7d4;
  uVar7 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  if (6 < (int)uVar7) {
    if (uVar7 != 0xc) {
      return;
    }
    uVar7 = param_1 + 4 & 3;
    uVar8 = *(uint *)(param_1 + 4 & 0xfffffffc);
    if ((uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20) != 10) {
      return;
    }
    uVar7 = param_1 + 0x14 & 3;
    uVar8 = *(uint *)(param_1 + 0x14 & 0xfffffffc);
    uVar8 = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
    uVar7 = uVar8 & 0xf;
    if (uVar7 == 1) {
      if (uVar8 >> 8 != 0) {
        uVar7 = param_1 + 0x18 & 3;
        uVar8 = *(uint *)(param_1 + 0x18 & 0xfffffffc);
        *(uint *)(iRam0204c7d4 + 0xb08) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
        uVar7 = iVar5 + 0x1cU & 3;
        uVar8 = *(uint *)(iVar5 + 0x1cU & 0xfffffffc);
        uVar7 = (uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20) + 0x30;
        uVar8 = uVar7 & 3;
        uVar7 = *(uint *)(uVar7 & 0xfffffffc);
        *(uint *)(iVar6 + iVar1 * 4 + 0x40) = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
        uVar7 = iVar5 + 0x1cU & 3;
        uVar3 = *(uint *)(iVar5 + 0x1cU & 0xfffffffc);
        uVar8 = iVar6 + 0xb08U & 3;
        uVar10 = *(uint *)(iVar6 + 0xb08U & 0xfffffffc);
        uVar7 = (uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) + 0x38;
        uVar3 = uVar7 & 3;
        uVar7 = *(uint *)(uVar7 & 0xfffffffc);
        func_02006d78(1,uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20,iVar6 + 0x40,
                      uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20);
        return;
      }
      func_02006ddc(1,uRam0204c7dc);
      return;
    }
    if (uVar7 == 3) {
      uVar7 = iRam0204c7d8 + 0x1cU & 3;
      uVar8 = *(uint *)(iRam0204c7d8 + 0x1cU & 0xfffffffc);
      uVar12 = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar7 = uVar12 + 8 & 3;
      uVar10 = *(uint *)(uVar12 + 8 & 0xfffffffc);
      *(undefined4 *)(iRam0204c7d8 + 0x1c) = 0;
      uVar8 = uVar12 + 0x2c & 3;
      uVar11 = *(uint *)(uVar12 + 0x2c & 0xfffffffc);
      uVar3 = uVar12 + 0x38 & 3;
      uVar13 = *(uint *)(uVar12 + 0x38 & 0xfffffffc);
      *(uint *)(uVar12 + 0x2c) =
           (uVar11 >> uVar8 * 8 | uVar11 << uVar8 * -8 + 0x20) +
           (uVar13 >> uVar3 * 8 | uVar13 << uVar3 * -8 + 0x20);
      Fs_Archive_NotifyAsyncEnded(uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20);
      return;
    }
    return;
  }
  if ((int)uVar7 < 2) {
    return;
  }
  if (uVar7 == 2) {
    if (*(short *)(param_1 + 8) != 0) {
      return;
    }
    *(int *)(iRam0204c7d8 + 0x28) = *(short *)(param_1 + 0x16) + 0xe;
    uVar7 = iVar5 + 0x20U & 3;
    uVar8 = *(uint *)(iVar5 + 0x20U & 0xfffffffc);
    *(int *)(iVar5 + 0x2c) = *(short *)(param_1 + 0x18) + 0xe;
    if (uVar8 >> uVar7 * 8 != 0 || uVar8 << uVar7 * -8 + 0x20 != 0) {
      uVar7 = iVar5 + 0x1cU & 3;
      uVar8 = *(uint *)(iVar5 + 0x1cU & 0xfffffffc);
      if (uVar8 >> uVar7 * 8 != 0 || uVar8 << uVar7 * -8 + 0x20 != 0) {
        uVar7 = iVar6 + 0xb04U & 3;
        uVar8 = *(uint *)(iVar6 + 0xb04U & 0xfffffffc);
        uVar3 = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
        *(undefined4 *)(iVar6 + 0xb04) = 0;
        uVar7 = iVar6 + 0xb04U & 3;
        uVar8 = *(uint *)(iVar6 + 0xb04U & 0xfffffffc);
        if ((uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20) < uVar3) {
          *(uint *)(iVar6 + 0xb04) = uVar3;
          uVar7 = iVar6 + 0xafcU & 3;
          uVar8 = *(uint *)(iVar6 + 0xafcU & 0xfffffffc);
          uVar7 = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
          if (uVar7 != 0) {
            uVar2 = Os_DisableIrq();
            uVar8 = iRam0204c7d8 + 0x18U & 3;
            uVar10 = *(uint *)(iRam0204c7d8 + 0x18U & 0xfffffffc);
            uVar3 = iRam0204c7d8 + 0x14U & 3;
            uVar13 = *(uint *)(iRam0204c7d8 + 0x14U & 0xfffffffc);
            (*(code *)(uVar13 >> uVar3 * 8 | uVar13 << uVar3 * -8 + 0x20))
                      (uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20,0,uVar7);
            Os_RestoreIrq(uVar2);
          }
          uVar7 = iVar6 + 0xb04U & 3;
          uVar10 = *(uint *)(iVar6 + 0xb04U & 0xfffffffc);
          uVar8 = iRam0204c7d8 + 0x28U & 3;
          uVar3 = *(uint *)(iRam0204c7d8 + 0x28U & 0xfffffffc);
          iVar5 = MaybeBoundsCheck((uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20) +
                                   (uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20) + -0xf);
          uVar2 = Os_DisableIrq();
          uVar7 = iRam0204c7d8 + 0x18U & 3;
          uVar3 = *(uint *)(iRam0204c7d8 + 0x18U & 0xfffffffc);
          uVar8 = iRam0204c7d8 + 0x14U & 3;
          uVar10 = *(uint *)(iRam0204c7d8 + 0x14U & 0xfffffffc);
          uVar4 = (*(code *)(uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20))
                            (uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20,
                             (iVar5 + 0x1fU >> 2) << 4,0);
          Os_RestoreIrq(uVar2);
          *(undefined4 *)(iVar6 + 0xafc) = uVar4;
          uVar7 = iVar6 + 0xafcU & 3;
          uVar8 = *(uint *)(iVar6 + 0xafcU & 0xfffffffc);
          *(uint *)(iVar6 + 0x80) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
        }
        uVar7 = iRam0204c7d8 + 0x1cU & 3;
        uVar8 = *(uint *)(iRam0204c7d8 + 0x1cU & 0xfffffffc);
        SomeFileAsyncReadFunc(uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20);
        return;
      }
      return;
    }
    func_02006db0(1,0,iVar6,uRam0204c7dc);
    return;
  }
  if (uVar7 != 4) {
    if (uVar7 == 6) {
      uVar7 = iRam0204c7d4 + iVar1 * 4;
      uVar8 = uVar7 & 3;
      uVar7 = *(uint *)(uVar7 & 0xfffffffc);
      uVar7 = (uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) + 4;
      uVar8 = uVar7 & 3;
      uVar7 = *(uint *)(uVar7 & 0xfffffffc);
      uVar13 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
      *(uint *)(iRam0204c7d8 + 0x24) = uVar13;
      uVar2 = Os_DisableIrq();
      uVar7 = iRam0204c7d8 + 0x18U & 3;
      uVar3 = *(uint *)(iRam0204c7d8 + 0x18U & 0xfffffffc);
      uVar8 = iRam0204c7d8 + 0x14U & 3;
      uVar10 = *(uint *)(iRam0204c7d8 + 0x14U & 0xfffffffc);
      uVar4 = (*(code *)(uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20))
                        (uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20,uVar13,0);
      Os_RestoreIrq(uVar2);
      uVar7 = iRam0204c7d8 + 0x24U & 3;
      uVar8 = *(uint *)(iRam0204c7d8 + 0x24U & 0xfffffffc);
      uVar7 = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      *(undefined4 *)(iRam0204c7d8 + 0x20) = uVar4;
      if ((int)uVar7 < 0) {
        uVar7 = iVar6 + 0xb04U & 3;
        uVar8 = *(uint *)(iVar6 + 0xb04U & 0xfffffffc);
        uVar7 = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
        *(undefined4 *)(iVar6 + 0xb04) = 0;
      }
      uVar8 = iVar6 + 0xb04U & 3;
      uVar3 = *(uint *)(iVar6 + 0xb04U & 0xfffffffc);
      if ((uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20) < uVar7) {
        *(uint *)(iVar6 + 0xb04) = uVar7;
        uVar7 = iVar6 + 0xafcU & 3;
        uVar8 = *(uint *)(iVar6 + 0xafcU & 0xfffffffc);
        uVar7 = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
        if (uVar7 != 0) {
          uVar2 = Os_DisableIrq();
          uVar8 = iRam0204c7d8 + 0x18U & 3;
          uVar10 = *(uint *)(iRam0204c7d8 + 0x18U & 0xfffffffc);
          uVar3 = iRam0204c7d8 + 0x14U & 3;
          uVar13 = *(uint *)(iRam0204c7d8 + 0x14U & 0xfffffffc);
          (*(code *)(uVar13 >> uVar3 * 8 | uVar13 << uVar3 * -8 + 0x20))
                    (uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20,0,uVar7);
          Os_RestoreIrq(uVar2);
        }
        uVar7 = iVar6 + 0xb04U & 3;
        uVar10 = *(uint *)(iVar6 + 0xb04U & 0xfffffffc);
        uVar8 = iRam0204c7d8 + 0x28U & 3;
        uVar3 = *(uint *)(iRam0204c7d8 + 0x28U & 0xfffffffc);
        iVar5 = MaybeBoundsCheck((uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20) +
                                 (uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20) + -0xf);
        uVar2 = Os_DisableIrq();
        uVar7 = iRam0204c7d8 + 0x18U & 3;
        uVar3 = *(uint *)(iRam0204c7d8 + 0x18U & 0xfffffffc);
        uVar8 = iRam0204c7d8 + 0x14U & 3;
        uVar10 = *(uint *)(iRam0204c7d8 + 0x14U & 0xfffffffc);
        uVar4 = (*(code *)(uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20))
                          (uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20,(iVar5 + 0x1fU >> 2) << 4
                           ,0);
        Os_RestoreIrq(uVar2);
        *(undefined4 *)(iVar6 + 0xafc) = uVar4;
        uVar7 = iVar6 + 0xafcU & 3;
        uVar8 = *(uint *)(iVar6 + 0xafcU & 0xfffffffc);
        *(uint *)(iVar6 + 0x80) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      }
      iVar5 = iRam0204c7d8;
      uVar7 = iRam0204c7d8 + 0x20U & 3;
      uVar8 = *(uint *)(iRam0204c7d8 + 0x20U & 0xfffffffc);
      *(uint *)(iVar6 + iVar1 * 4 + 0x40) = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar7 = iVar5 + 0x24U & 3;
      uVar8 = *(uint *)(iVar5 + 0x24U & 0xfffffffc);
      func_02006d78(1,0x20000,iVar6 + 0x40,uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20);
      return;
    }
    return;
  }
  if (*(short *)(param_1 + 8) == 0) {
    uVar7 = iRam0204c7d8 + 0xcU & 3;
    uVar8 = *(uint *)(iRam0204c7d8 + 0xcU & 0xfffffffc);
    if ((uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20) == 2) {
      uVar7 = iRam0204c7d4 + 0xb08U & 3;
      uVar8 = *(uint *)(iRam0204c7d4 + 0xb08U & 0xfffffffc);
      uStack_1c = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uVar7 = iRam0204c7d8 + 0x28U & 3;
      uVar8 = *(uint *)(iRam0204c7d8 + 0x28U & 0xfffffffc);
      uVar7 = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      uStack_20 = ((int)uVar7 >> 8 & 0xfU) << 4 | 0x102;
      uStack_18 = (undefined1)uVar7;
      iVar6 = func_02006d3c(1,(undefined4)(uintptr_t)(&uStack_20),9,uRam0204c7e0);
      if (iVar6 == 0) {
        Os_Terminate();
        return;
      }
      return;
    }
    uVar7 = iRam0204c7d8 + 0x20U & 3;
    uVar3 = *(uint *)(iRam0204c7d8 + 0x20U & 0xfffffffc);
    uVar8 = iRam0204c7d8 + 0x24U & 3;
    uVar10 = *(uint *)(iRam0204c7d8 + 0x24U & 0xfffffffc);
    Arm_FlushRange(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20,
                   uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20);
    uVar7 = iRam0204c7d8 + 0x20U & 3;
    uVar8 = *(uint *)(iRam0204c7d8 + 0x20U & 0xfffffffc);
    uVar2 = SomeRomUnkFatFntReload(uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20);
    *(undefined4 *)(iVar6 + 0xb00) = uVar2;
    uVar7 = iRam0204c7d8 + 0x10U & 3;
    uVar8 = *(uint *)(iRam0204c7d8 + 0x10U & 0xfffffffc);
    pcVar9 = (code *)(uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20);
    *(undefined4 *)(iRam0204c7d8 + 0xc) = 2;
    if (pcVar9 != (code *)0x0) {
      (*pcVar9)(0);
      return;
    }
    return;
  }
  return;
}

