/* Decompiled C draft; module arm9; ROM address 02095544. No matching claim. */
#include "types.h"
#include "deps/02095544_func_02095544.h"

void func_02095544(undefined4 param_1,int param_2)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined4 uStack_28;
  int iStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  int iStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  uVar7 = param_2 + 0xb0U & 3;
  uVar2 = *(uint *)(param_2 + 0xb0U & 0xfffffffc);
  switch(uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) {
  case 0:
    break;
  case 1:
    uVar7 = param_2 + 0x14U & 3;
    uVar2 = *(uint *)(param_2 + 0x14U & 0xfffffffc);
    *(uint *)(param_2 + 0x14) = (uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) - 0x400;
    VecFx32_Add(param_2 + 4,param_2 + 0x10,param_2 + 4);
    uVar7 = param_2 + 0x9cU & 3;
    uVar5 = *(uint *)(param_2 + 0x9cU & 0xfffffffc);
    uVar2 = param_2 + 8U & 3;
    uVar6 = *(uint *)(param_2 + 8U & 0xfffffffc);
    uVar7 = (uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) + 4;
    uVar5 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    if ((int)(uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20) <
        (int)(uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20)) {
      return;
    }
    MaybeRecreateExplosionInstance(3,param_2 + 4,1);
    iStack_24 = param_2 + 4;
    uStack_28 = DAT_020957e0;
    uStack_20 = 4;
    uStack_1c = func_020d4ef4();
    func_0210b7a8(&uStack_28);
    *(undefined4 *)(param_2 + 0xb0) = 2;
    return;
  case 2:
    uVar7 = param_2 + 0x14U & 3;
    uVar2 = *(uint *)(param_2 + 0x14U & 0xfffffffc);
    *(uint *)(param_2 + 0x14) = (uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) - 0x400;
    VecFx32_Add(param_2 + 4,param_2 + 0x10,param_2 + 4);
    uVar7 = param_2 + 0x9cU & 3;
    uVar5 = *(uint *)(param_2 + 0x9cU & 0xfffffffc);
    uVar2 = param_2 + 8U & 3;
    uVar6 = *(uint *)(param_2 + 8U & 0xfffffffc);
    uVar7 = (uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) + 4;
    uVar5 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    if ((int)(uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20) <
        (int)(uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20)) {
      return;
    }
    MaybeRecreateExplosionInstance(3,param_2 + 4,1);
    iStack_14 = param_2 + 4;
    uStack_18 = DAT_020957e4;
    uStack_10 = 2;
    uStack_c = func_020d4ef4();
    func_0210b7a8(&uStack_18);
    *(undefined4 *)(param_2 + 0xb0) = 3;
    return;
  case 3:
    uVar7 = param_2 + 0x14U & 3;
    uVar2 = *(uint *)(param_2 + 0x14U & 0xfffffffc);
    *(uint *)(param_2 + 0x14) = (uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) - 0x400;
    VecFx32_Add(param_2 + 4,param_2 + 0x10,param_2 + 4);
    uVar7 = param_2 + 0x9cU & 3;
    uVar5 = *(uint *)(param_2 + 0x9cU & 0xfffffffc);
    uVar2 = param_2 + 8U & 3;
    uVar6 = *(uint *)(param_2 + 8U & 0xfffffffc);
    uVar7 = (uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) + 4;
    uVar5 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    if ((int)(uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20) <=
        (int)((uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20) - 0x32000)) {
      *(undefined4 *)(param_2 + 0xa0) = DAT_020957e8;
      *(undefined4 *)(param_2 + 0xb0) = 4;
    }
    return;
  case 4:
    uVar7 = param_2 + 0xa0U & 3;
    uVar2 = *(uint *)(param_2 + 0xa0U & 0xfffffffc);
    uVar7 = uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20;
    *(uint *)(param_2 + 0xa0) = uVar7 - 1;
    if ((int)uVar7 < 1) {
      *(undefined4 *)(param_2 + 0xb0) = 0;
    }
  default:
    return;
  }
  iVar3 = func_02061818();
  if ((iVar3 != 2) &&
     (iVar3 = GetDriverEntry((short)*(char *)((*(uint *)(DAT_020957d8 & 0xfffffffc) >>
                                               (DAT_020957d8 & 3) * 8 |
                                              *(uint *)(DAT_020957d8 & 0xfffffffc) <<
                                              (DAT_020957d8 & 3) * -8 + 0x20) + 0x62)),
     uVar7 = iVar3 + 0x88U & 3, uVar8 = *(uint *)(iVar3 + 0x88U & 0xfffffffc),
     uVar2 = param_2 + 0xacU & 3, uVar6 = *(uint *)(param_2 + 0xacU & 0xfffffffc),
     uVar5 = iVar3 + 0x80U & 3, uVar9 = *(uint *)(iVar3 + 0x80U & 0xfffffffc),
     iVar3 = (uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20) -
             (uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20), uVar7 = param_2 + 0xa4U & 3,
     uVar2 = *(uint *)(param_2 + 0xa4U & 0xfffffffc),
     iVar4 = (uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20) -
             (uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20),
     DAT_020957dc <=
     (int)((ulonglong)((longlong)iVar4 * (longlong)iVar4 + (longlong)iVar3 * (longlong)iVar3) >>
          0x20))) {
    return;
  }
  uVar7 = param_2 + 0x9cU & 3;
  uVar2 = *(uint *)(param_2 + 0x9cU & 0xfffffffc);
  uVar2 = uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20;
  uVar7 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  *(uint *)(param_2 + 4) = uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20;
  uVar7 = param_2 + 0x9cU & 3;
  uVar2 = *(uint *)(param_2 + 0x9cU & 0xfffffffc);
  uVar7 = (uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) + 4;
  uVar2 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  *(uint *)(param_2 + 8) = (uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20) - 0x32000;
  uVar7 = param_2 + 0x9cU & 3;
  uVar2 = *(uint *)(param_2 + 0x9cU & 0xfffffffc);
  uVar7 = (uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) + 8;
  uVar2 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  *(uint *)(param_2 + 0xc) = uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20;
  uVar7 = param_2 + 0x40U & 3;
  uVar2 = *(uint *)(param_2 + 0x40U & 0xfffffffc);
  lVar1 = (ulonglong)(uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) * 0xc000;
  *(uint *)(param_2 + 0x10) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000;
  *(undefined4 *)(param_2 + 0x14) = 0xc000;
  uVar7 = param_2 + 0x48U & 3;
  uVar2 = *(uint *)(param_2 + 0x48U & 0xfffffffc);
  lVar1 = (ulonglong)(uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) * 0xc000;
  *(uint *)(param_2 + 0x18) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000;
  *(undefined4 *)(param_2 + 0xb0) = 1;
  return;
}

