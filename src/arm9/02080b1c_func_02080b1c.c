/* Decompiled C draft; module arm9; ROM address 02080b1c. No matching claim. */
#include "types.h"
#include "deps/02080b1c_func_02080b1c.h"

void func_02080b1c(uint *param_1)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar11;
  
  uVar13 = 0;
  iVar2 = GetDriverEntry((short)param_1[7]);
  uVar12 = iVar2 + 0x4cU & 3;
  uVar3 = *(uint *)(iVar2 + 0x4cU & 0xfffffffc);
  if ((((uVar3 >> uVar12 * 8 | uVar3 << uVar12 * -8 + 0x20) & 0x10000000) == 0) &&
     (uVar12 = (uint)*(ushort *)
                      ((*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                       *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) +
                      0x24), 1 < uVar12)) {
    piVar4 = (int *)func_0208537c();
    if (uVar12 == 0) {
      uVar13 = 0;
    }
    else {
      uVar13 = (uint)(piVar4 + 2) & 3;
      uVar3 = *(uint *)((uint)(piVar4 + 2) & 0xfffffffc);
      uVar9 = uVar3 >> uVar13 * 8 | uVar3 << uVar13 * -8 + 0x20;
      uVar8 = *(uint *)((uint)piVar4 & 0xfffffffc) >> ((uint)piVar4 & 3) * 8 |
              *(uint *)((uint)piVar4 & 0xfffffffc) << ((uint)piVar4 & 3) * -8 + 0x20;
      uVar13 = (uint)(piVar4 + 1) & 3;
      uVar6 = *(uint *)((uint)(piVar4 + 1) & 0xfffffffc);
      lVar1 = (ulonglong)uVar8 * (ulonglong)uVar9;
      uVar14 = (uint)lVar1;
      uVar3 = (uint)(piVar4 + 3) & 3;
      uVar7 = *(uint *)((uint)(piVar4 + 3) & 0xfffffffc);
      uVar5 = (uint)(piVar4 + 4) & 3;
      uVar10 = *(uint *)((uint)(piVar4 + 4) & 0xfffffffc);
      uVar11 = uVar10 >> uVar5 * 8 | uVar10 << uVar5 * -8 + 0x20;
      uVar5 = (uint)(piVar4 + 5) & 3;
      uVar10 = *(uint *)((uint)(piVar4 + 5) & 0xfffffffc);
      *piVar4 = uVar11 + uVar14;
      piVar4[1] = (uVar10 >> uVar5 * 8 | uVar10 << uVar5 * -8 + 0x20) +
                  (uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20) * uVar8 +
                  uVar9 * (uVar6 >> uVar13 * 8 | uVar6 << uVar13 * -8 + 0x20) +
                  (int)((ulonglong)lVar1 >> 0x20) + (uint)CARRY4(uVar11,uVar14);
      if (uVar12 == 0) {
        uVar13 = (uint)(piVar4 + 1) & 3;
        uVar12 = *(uint *)((uint)(piVar4 + 1) & 0xfffffffc);
        uVar13 = uVar12 >> uVar13 * 8 | uVar12 << uVar13 * -8 + 0x20;
      }
      else {
        uVar13 = (uint)(piVar4 + 1) & 3;
        uVar3 = *(uint *)((uint)(piVar4 + 1) & 0xfffffffc);
        uVar13 = (uint)((ulonglong)uVar12 *
                        (ulonglong)(uVar3 >> uVar13 * 8 | uVar3 << uVar13 * -8 + 0x20) >> 0x20);
      }
    }
    uVar13 = uVar13 & 0xffff;
  }
  param_1[1] = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
               *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
  uVar13 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
           *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) + uVar13 * 4;
  uVar12 = uVar13 & 3;
  uVar13 = *(uint *)(uVar13 & 0xfffffffc);
  *param_1 = uVar13 >> uVar12 * 8 | uVar13 << uVar12 * -8 + 0x20;
  uVar12 = (uint)(param_1 + 1) & 3;
  uVar6 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
  uVar13 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
           *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) + 0x18;
  uVar3 = uVar13 & 3;
  uVar5 = *(uint *)(uVar13 & 0xfffffffc);
  uVar13 = (uVar6 >> uVar12 * 8 | uVar6 << uVar12 * -8 + 0x20) + 0x18;
  uVar12 = uVar13 & 3;
  uVar13 = *(uint *)(uVar13 & 0xfffffffc);
  VecFx32_Subtract(uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20,
                   uVar13 >> uVar12 * 8 | uVar13 << uVar12 * -8 + 0x20,param_1 + 2);
  Vector3_MaybeNormalize((uint)(uintptr_t)(param_1 + 2),param_1 + 2);
  return;
}

