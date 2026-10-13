/* Decompiled C draft; module arm9; ROM address 0207fd28. No matching claim. */
#include "types.h"
#include "deps/0207fd28_func_0207fd28.h"

void func_0207fd28(uint *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  iVar3 = GetDriverEntry((short)param_1[7]);
  if ((*(ushort *)
        ((*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
         *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) + 0x24) < 2) ||
     (1 < *(byte *)((int)param_1 + 0x1e))) {
    uVar7 = 0;
  }
  else {
    if (*(byte *)((int)param_1 + 0x1e) == 0) {
      uVar7 = (uint)((ulonglong)((longlong)iRam0207fe64 * (longlong)(int)(uint)(ushort)param_1[7])
                    >> 0x20);
    }
    else {
      uVar7 = (uint)(ushort)param_1[7] -
              iRam0207fe68 *
              (int)((ulonglong)((longlong)iRam0207fe64 * (longlong)(int)(uint)(ushort)param_1[7]) >>
                   0x20);
    }
    uVar7 = uVar7 & 0xffff;
    *(char *)((int)param_1 + 0x1e) = *(char *)((int)param_1 + 0x1e) + '\x01';
  }
  iVar2 = iRam0207fe6c;
  param_1[1] = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
               *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
  uVar7 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
          *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) + uVar7 * 4;
  uVar5 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  *param_1 = uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20;
  uVar5 = iVar3 + 0x590U & 3;
  uVar4 = *(uint *)(iVar3 + 0x590U & 0xfffffffc);
  uVar7 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
          *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) + 0x20;
  uVar1 = uVar7 & 3;
  uVar6 = *(uint *)(uVar7 & 0xfffffffc);
  uVar7 = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + 8;
  uVar5 = uVar7 & 3;
  uVar4 = *(uint *)(uVar7 & 0xfffffffc);
  uVar7 = iVar2 + *(short *)((uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) + 4) * 4;
  uVar1 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  uVar7 = uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20;
  if (uVar7 != *(ushort *)((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + 0x1a)) {
    DriverContext_UpdateCharacterAnimation(iVar3,uVar7,1);
  }
  if ((short)param_1[7] != 0) {
    uVar7 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
            *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) + 0x20;
    uVar5 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    if (*(short *)((uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20) + 6) == 0) {
      uVar7 = iVar3 + 0x7cU & 3;
      uVar5 = *(uint *)(iVar3 + 0x7cU & 0xfffffffc);
      *(uint *)(iVar3 + 0x7c) = (uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) & 0xffffffbf;
    }
    else {
      uVar7 = iVar3 + 0x7cU & 3;
      uVar5 = *(uint *)(iVar3 + 0x7cU & 0xfffffffc);
      *(uint *)(iVar3 + 0x7c) = uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20 | 0x40;
    }
  }
  uVar5 = (uint)(param_1 + 1) & 3;
  uVar6 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
  uVar7 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
          *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) + 0x18;
  uVar1 = uVar7 & 3;
  uVar4 = *(uint *)(uVar7 & 0xfffffffc);
  uVar7 = (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) + 0x18;
  uVar5 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  VecFx32_Subtract(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20,
                   uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20,param_1 + 2);
  Vector3_MaybeNormalize(param_1 + 2,param_1 + 2);
  return;
}

