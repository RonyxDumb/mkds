/* Decompiled C draft; module arm9; ROM address 0203fa60. No matching claim. */
#include "types.h"
#include "deps/0203fa60_DriverStatus_SomeFn_0.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4
DriverStatus_SomeFn_0(int param_1,int *param_2,undefined4 param_3,int param_4,uint param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  undefined4 local_34;
  
  iVar6 = iRam0203fca4;
  uVar3 = uRam0203fca0;
  iVar1 = (int)param_5 >> 5;
  iVar9 = param_5 * 0x24;
  uVar2 = 1 << (param_5 & 0x1f);
  uVar4 = param_1 + iVar1 * 4 + 0x4c;
  uVar7 = uVar4 & 3;
  uVar11 = *(uint *)(uVar4 & 0xfffffffc);
  uVar10 = *(uint *)(uRam0203fca0 & 0xfffffffc) >> (uRam0203fca0 & 3) * 8 |
           *(uint *)(uRam0203fca0 & 0xfffffffc) << (uRam0203fca0 & 3) * -8 + 0x20;
  uVar4 = uVar10 + 0x44;
  uVar8 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  local_34 = 0;
  if (((uVar11 >> uVar7 * 8 | uVar11 << uVar7 * -8 + 0x20) & uVar2) != 0) {
    return 0;
  }
  if (*(short *)((uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20) + iVar9 + 0x1c) == -1) {
    iVar6 = func_0203fcac(param_3,param_5,param_5 + 1 & 0xffff);
    *param_2 = iVar6;
    uVar4 = *(uint *)((uint)param_2 & 0xfffffffc) >> ((uint)param_2 & 3) * 8 |
            *(uint *)((uint)param_2 & 0xfffffffc) << ((uint)param_2 & 3) * -8 + 0x20;
    if ((-3 < (int)uVar4) && ((int)uVar4 <= iRam0203fca4)) {
      uVar4 = (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
              *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x44;
      uVar10 = uVar4 & 3;
      uVar4 = *(uint *)(uVar4 & 0xfffffffc);
      if ((*(byte *)((uVar4 >> uVar10 * 8 | uVar4 << uVar10 * -8 + 0x20) + iVar9 + 0x23) & 1) != 0)
      {
        *param_2 = (*(ushort *)(param_1 + 0x3c) & 0xf) * -400 + 0x1000;
      }
      if ((int)(*(uint *)((uint)param_2 & 0xfffffffc) >> ((uint)param_2 & 3) * 8 |
               *(uint *)((uint)param_2 & 0xfffffffc) << ((uint)param_2 & 3) * -8 + 0x20) < 0) {
        *param_2 = 0;
      }
      if (0x1000 < (int)(*(uint *)((uint)param_2 & 0xfffffffc) >> ((uint)param_2 & 3) * 8 |
                        *(uint *)((uint)param_2 & 0xfffffffc) << ((uint)param_2 & 3) * -8 + 0x20)) {
        *param_2 = 0x1000;
      }
      local_34 = 1;
    }
  }
  else {
    uVar10 = uVar10 + 0x4c;
    uVar4 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    iVar12 = 0;
    do {
      uVar7 = (uint)*(char *)(param_4 * 0xc + (uVar10 >> uVar4 * 8 | uVar10 << uVar4 * -8 + 0x20) +
                              iVar12 + 4);
      if (uVar7 != 0xffffffff) {
        uVar8 = (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x4c;
        uVar11 = uVar8 & 3;
        uVar8 = *(uint *)(uVar8 & 0xfffffffc);
        iVar5 = func_0203fcac(param_3,param_5,
                              *(undefined2 *)
                               ((uVar8 >> uVar11 * 8 | uVar8 << uVar11 * -8 + 0x20) +
                               (uVar7 & 0xffff) * 0xc));
        *param_2 = iVar5;
        uVar7 = *(uint *)((uint)param_2 & 0xfffffffc) >> ((uint)param_2 & 3) * 8 |
                *(uint *)((uint)param_2 & 0xfffffffc) << ((uint)param_2 & 3) * -8 + 0x20;
        if ((-3 < (int)uVar7) && ((int)uVar7 <= iVar6)) {
          uVar4 = (*(uint *)(uRam0203fca0 & 0xfffffffc) >> (uRam0203fca0 & 3) * 8 |
                  *(uint *)(uRam0203fca0 & 0xfffffffc) << (uRam0203fca0 & 3) * -8 + 0x20) + 0x44;
          uVar10 = uVar4 & 3;
          uVar4 = *(uint *)(uVar4 & 0xfffffffc);
          if ((*(byte *)((uVar4 >> uVar10 * 8 | uVar4 << uVar10 * -8 + 0x20) + iVar9 + 0x23) & 1) !=
              0) {
            uVar4 = (*(uint *)(uRam0203fca8 & 0xfffffffc) >> (uRam0203fca8 & 3) * 8 |
                    *(uint *)(uRam0203fca8 & 0xfffffffc) << (uRam0203fca8 & 3) * -8 + 0x20) + 8;
            uVar10 = uVar4 & 3;
            uVar4 = *(uint *)(uVar4 & 0xfffffffc);
            if ((uVar4 >> uVar10 * 8 | uVar4 << uVar10 * -8 + 0x20) == 5) {
              iVar6 = func_0x0219bb50();
              *param_2 = (iVar6 + 1) * -400 + 0x1000;
            }
            else {
              *param_2 = (*(ushort *)(param_1 + 0x3c) & 0xf) * -400 + 0x1000;
            }
          }
          local_34 = 1;
          break;
        }
      }
      iVar12 = iVar12 + 1;
    } while (iVar12 < 3);
  }
  uVar4 = param_1 + 0x4c + iVar1 * 4;
  uVar10 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  *(uint *)(param_1 + 0x4c + iVar1 * 4) = uVar4 >> uVar10 * 8 | uVar4 << uVar10 * -8 + 0x20 | uVar2;
  return local_34;
}

