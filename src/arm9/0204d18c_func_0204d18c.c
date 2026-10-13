/* Decompiled C draft; module arm9; ROM address 0204d18c. No matching claim. */
#include "types.h"
#include "deps/0204d18c_func_0204d18c.h"

void func_0204d18c(int param_1,int param_2)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int *piVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  bool bVar11;
  
  uVar1 = Os_DisableIrq();
  uVar4 = iRam0204d27c + 0xcU & 3;
  uVar2 = *(uint *)(iRam0204d27c + 0xcU & 0xfffffffc);
  if (uVar2 >> uVar4 * 8 != 0 || uVar2 << uVar4 * -8 + 0x20 != 0) {
    uVar4 = param_2 + 0x88U & 3;
    uVar2 = *(uint *)(param_2 + 0x88U & 0xfffffffc);
    uVar10 = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20;
    iVar9 = 0;
    *(undefined4 *)(param_2 + 0x88) = 0;
    uVar4 = param_1 + 0x46ccU & 3;
    uVar2 = *(uint *)(param_1 + 0x46ccU & 0xfffffffc);
    *(uint *)(param_1 + 0x46cc) = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20 | uVar10;
    uVar4 = param_2 + 0x84U & 3;
    uVar2 = *(uint *)(param_2 + 0x84U & 0xfffffffc);
    if ((int)(uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) < 1) {
      uVar4 = param_2 + 0x60U & 3;
      uVar8 = *(uint *)(param_2 + 0x60U & 0xfffffffc);
      uVar2 = param_2 + 0x5cU & 3;
      uVar3 = *(uint *)(param_2 + 0x5cU & 0xfffffffc);
      uVar5 = param_2 + 0x8cU & 3;
      uVar6 = *(uint *)(param_2 + 0x8cU & 0xfffffffc);
      uVar4 = (uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20) -
              (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20);
      if (uVar4 < 0x401) {
        iVar9 = param_2 + 0xc0;
      }
      StructGO_SomeFn_from_thumb
                ((undefined4 *)(uintptr_t)(param_2 + 4),uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20,uRam0204d280,iVar9,
                 uVar4,0);
      func_0204d110((uint *)(uintptr_t)(param_1 + iRam0204d284),(undefined4 *)(uintptr_t)(param_1 + iRam0204d288),(uint *)(uintptr_t)(param_2));
      *(undefined4 *)(param_2 + 0x80) = 2;
    }
    uVar4 = 0;
    piVar7 = (int *)(param_2 + 0x84);
    while (uVar2 = 1 << (uVar4 & 0xff), (int)uVar2 <= (int)uVar10) {
      uVar2 = uVar2 & uVar10;
      bVar11 = uVar2 != 0;
      if (bVar11) {
        uVar2 = *(uint *)((uint)piVar7 & 0xfffffffc) >> ((uint)piVar7 & 3) * 8 |
                *(uint *)((uint)piVar7 & 0xfffffffc) << ((uint)piVar7 & 3) * -8 + 0x20;
      }
      uVar4 = uVar4 + 1;
      if (bVar11) {
        *piVar7 = uVar2 + 1;
        uVar2 = param_2 + 0x8cU & 3;
        uVar5 = *(uint *)(param_2 + 0x8cU & 0xfffffffc);
        *(uint *)(param_1 + 4) = uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20;
      }
      param_1 = param_1 + 0xc;
    }
  }
  Os_RestoreIrq(uVar1);
  return;
}

