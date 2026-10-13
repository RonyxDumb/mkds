/* Decompiled C draft; module arm9; ROM address 020f0950. No matching claim. */
#include "types.h"
#include "deps/020f0950_func_020f0950.h"

undefined4 func_020f0950(uint param_1,uint param_2,int param_3)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar11;
  undefined4 local_44;
  uint uVar6;
  uint uVar10;
  
  uVar3 = DAT_020f0afc;
  uVar1 = param_1 + 0x14 & 3;
  uVar9 = *(uint *)(param_1 + 0x14 & 0xfffffffc);
  uVar10 = uVar9 >> uVar1 * 8 | uVar9 << uVar1 * -8 + 0x20;
  local_44 = 0;
  iVar8 = 0;
  uVar1 = ((param_2 & 0xf0) << 0xc) >> 0x10;
  uVar9 = param_1 + 4 & 3;
  uVar11 = *(uint *)(param_1 + 4 & 0xfffffffc);
  if (0 < (int)uVar10) {
    do {
      uVar7 = (uVar11 >> uVar9 * 8 | uVar11 << uVar9 * -8 + 0x20) + iVar8 * 4;
      uVar6 = uVar7 & 3;
      uVar7 = *(uint *)(uVar7 & 0xfffffffc);
      uVar7 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
      if (param_3 == *(short *)(uVar7 + 0x4e)) {
        local_44 = 1;
        if ((param_2 & 0xf) < 4) {
          uVar6 = uVar7 + 0x5c & 3;
          uVar5 = *(uint *)(uVar7 + 0x5c & 0xfffffffc);
          uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
          lVar2 = (ulonglong)uVar3 * (ulonglong)uVar6;
          *(uint *)(uVar7 + 0x5c) =
               (uint)lVar2 >> 0xc |
               (((int)uVar6 >> 0x1f) * uVar3 + (int)((ulonglong)lVar2 >> 0x20)) * 0x100000;
          uVar6 = uVar7 + 0x60 & 3;
          uVar5 = *(uint *)(uVar7 + 0x60 & 0xfffffffc);
          uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
          lVar2 = (ulonglong)uVar3 * (ulonglong)uVar6;
          *(uint *)(uVar7 + 0x60) =
               (uint)lVar2 >> 0xc |
               (((int)uVar6 >> 0x1f) * uVar3 + (int)((ulonglong)lVar2 >> 0x20)) * 0x100000;
          uVar6 = uVar7 + 100 & 3;
          uVar5 = *(uint *)(uVar7 + 100 & 0xfffffffc);
          uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
          lVar2 = (ulonglong)uVar3 * (ulonglong)uVar6;
          *(uint *)(uVar7 + 100) =
               (uint)lVar2 >> 0xc |
               (((int)uVar6 >> 0x1f) * uVar3 + (int)((ulonglong)lVar2 >> 0x20)) * 0x100000;
        }
        switch(param_2 & 0xf) {
        case 0:
          func_020f7104(uVar7,0);
          break;
        case 1:
          func_020f7070(uVar7,0);
          break;
        case 2:
          func_020f6fc4(uVar7,0);
          break;
        case 3:
          if (((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
               *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) != 1) ||
             (iVar4 = func_020f5324(uVar7,uVar1), iVar4 != 0)) {
            func_020f6f10(uVar7,0,uVar1);
          }
          break;
        case 4:
          func_020f7658(uVar7,0);
          break;
        case 5:
          func_020f7430(uVar7,0);
        }
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < (int)uVar10);
  }
  return local_44;
}

