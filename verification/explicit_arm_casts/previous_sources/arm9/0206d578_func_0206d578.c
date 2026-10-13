/* Decompiled C draft; module arm9; ROM address 0206d578. No matching claim. */
#include "types.h"
#include "deps/0206d578_func_0206d578.h"

void func_0206d578(uint param_1)

{
  longlong lVar1;
  bool bVar2;
  short *psVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  undefined1 auStack_34 [16];
  
  uVar7 = param_1 + 0x510 & 3;
  uVar5 = *(uint *)(param_1 + 0x510 & 0xfffffffc);
  uVar10 = 0;
  bVar2 = false;
  func_01ffc064(param_1 + 0x1f0,uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20,0x400,param_1);
  uVar7 = param_1 + 0x1d0 & 3;
  uVar5 = *(uint *)(param_1 + 0x1d0 & 0xfffffffc);
  uVar7 = uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20;
  lVar1 = (ulonglong)uVar7 * 0xffffc000;
  VecFx32_AddScale1((uint)lVar1 >> 0xc | ((int)((ulonglong)lVar1 >> 0x20) - uVar7) * 0x100000,
                    param_1 + 0x50,param_1 + 0x1f0,param_1 + 0x1f0);
  uVar5 = func_02061f90();
  uVar7 = uRam0206d7b4;
  psVar3 = psRam0206d7b0;
  if ((*(ushort *)(param_1 + 0x74) == uVar5) &&
     (uVar5 = param_1 + 0x4c & 3, uVar6 = *(uint *)(param_1 + 0x4c & 0xfffffffc),
     ((uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) & uRam0206d7ac) == 0)) {
    uVar5 = param_1 + 0x2a4 & 3;
    uVar6 = *(uint *)(param_1 + 0x2a4 & 0xfffffffc);
    if ((0x4000 < (int)(uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20)) &&
       ((uVar5 = param_1 + 0x180 & 3, uVar6 = *(uint *)(param_1 + 0x180 & 0xfffffffc),
        uVar6 >> uVar5 * 8 == 0 && uVar6 << uVar5 * -8 + 0x20 == 0 &&
        (iVar9 = 0, 0 < *psRam0206d7b0)))) {
      do {
        uVar5 = (*(uint *)(uRam0206d7b8 & 0xfffffffc) >> (uRam0206d7b8 & 3) * 8 |
                *(uint *)(uRam0206d7b8 & 0xfffffffc) << (uRam0206d7b8 & 3) * -8 + 0x20) + iVar9 * 4;
        uVar6 = uVar5 & 3;
        uVar5 = *(uint *)(uVar5 & 0xfffffffc);
        uVar8 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
        uVar5 = uVar8 + 0x2a4 & 3;
        uVar6 = *(uint *)(uVar8 + 0x2a4 & 0xfffffffc);
        if ((((0x1fff < (int)(uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20)) &&
             ((*(ushort *)
                ((*(uint *)(uRam0206d7bc & 0xfffffffc) >> (uRam0206d7bc & 3) * 8 |
                 *(uint *)(uRam0206d7bc & 0xfffffffc) << (uRam0206d7bc & 3) * -8 + 0x20) + iVar9 * 2
                ) & 0x800) != 0)) && (uVar8 != param_1)) &&
           (uVar5 = uVar8 + 0x7c & 3, uVar6 = *(uint *)(uVar8 + 0x7c & 0xfffffffc),
           ((uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) & uRam0206d7c0) == 0)) {
          VecFx32_Subtract(uVar8 + 0x80,param_1 + 0x80,auStack_34);
          uVar10 = VecFx32_Norm(auStack_34);
          iVar4 = VecFx32_CrossProduct_0(uVar8 + 0x50,auStack_34);
          lVar1 = (ulonglong)uVar7 * (ulonglong)uVar10;
          if ((int)((uint)lVar1 >> 0xc |
                   (((int)uVar10 >> 0x1f) * uVar7 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000) <
              iVar4) {
            bVar2 = true;
            *(short *)(param_1 + 0x540) = *(short *)(param_1 + 0x540) + 1;
            break;
          }
        }
        iVar9 = iVar9 + 1;
      } while (iVar9 < *psVar3);
    }
    uVar7 = param_1 + 0x7c & 3;
    uVar5 = *(uint *)(param_1 + 0x7c & 0xfffffffc);
    if (((uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) & 0x400) == 0) {
      if (bVar2) {
        uVar7 = param_1 + 0x4c & 3;
        uVar5 = *(uint *)(param_1 + 0x4c & 0xfffffffc);
        *(uint *)(param_1 + 0x4c) = uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20 | 0x4000;
        func_02081060(param_1);
        if ((0xf < *(short *)(param_1 + 0x540)) && ((int)uVar10 < 0x3c000)) {
          StructMQRacerEntry_SomeFn_39(param_1);
        }
      }
      else {
        *(undefined2 *)(param_1 + 0x540) = 0;
        uVar7 = param_1 + 0x4c & 3;
        uVar5 = *(uint *)(param_1 + 0x4c & 0xfffffffc);
        *(uint *)(param_1 + 0x4c) = (uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) & 0xffffbfff;
        uVar7 = param_1 + 0x4c & 3;
        uVar5 = *(uint *)(param_1 + 0x4c & 0xfffffffc);
        if (((uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) & 0x2000) == 0) {
          *(undefined4 *)(param_1 + 0xd8) = 0x1000;
        }
        StructMQRacerEntry_SomeFn_69(param_1);
      }
    }
  }
  iVar9 = iRam0206d7c4;
  uVar7 = param_1 + 0x4c & 3;
  uVar5 = *(uint *)(param_1 + 0x4c & 0xfffffffc);
  if (((uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) & 0x4000) != 0) {
    uVar7 = param_1 + 0xd8 & 3;
    uVar5 = *(uint *)(param_1 + 0xd8 & 0xfffffffc);
    *(uint *)(param_1 + 0xd8) = (uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) + 7;
    uVar7 = param_1 + 0xd8 & 3;
    uVar5 = *(uint *)(param_1 + 0xd8 & 0xfffffffc);
    if (iVar9 < (int)(uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20)) {
      *(int *)(param_1 + 0xd8) = iVar9;
    }
    return;
  }
  return;
}

