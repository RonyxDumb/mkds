/* Decompiled C draft; module arm9; ROM address 0203f334. No matching claim. */
#include "types.h"
#include "deps/0203f334_func_0203f334.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void func_0203f334(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  ushort *puVar6;
  int iVar7;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined1 auStack_4c [12];
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  uint uStack_34;
  uint uStack_30;
  uint uStack_2c;
  
  uVar4 = param_1 + 0x24U & 3;
  uVar1 = *(uint *)(param_1 + 0x24U & 0xfffffffc);
  uVar3 = (*(uint *)(uRam0203f540 & 0xfffffffc) >> (uRam0203f540 & 3) * 8 |
          *(uint *)(uRam0203f540 & 0xfffffffc) << (uRam0203f540 & 3) * -8 + 0x20) + 0x44;
  uVar5 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = (uint)*(short *)((uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) + 0x1c);
  iVar7 = 0;
  if ((int)(uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20) < 2) {
    return;
  }
  GetDriverMaybeSfxPosition(&uStack_58,((uint)*(ushort *)(param_1 + 0x3c) << 0x18) >> 0x1c);
  GetDriverLastPosition((undefined4 *)(void *)(auStack_4c),((uint)*(ushort *)(param_1 + 0x3c) << 0x18) >> 0x1c);
  VecFx32_Subtract((uint)(uintptr_t)(&uStack_58),(uint)(uintptr_t)(auStack_4c),&uStack_34);
  uStack_40 = uStack_58;
  uStack_3c = uStack_54;
  uStack_38 = uStack_50;
  uStack_34 = (uint)((ulonglong)uStack_34 * 0xffffff10) >> 0xc |
              (((int)uStack_34 >> 0x1f) * -0xf0 +
              ((int)((ulonglong)uStack_34 * 0xffffff10 >> 0x20) - uStack_34)) * 0x100000;
  uStack_30 = (uint)((ulonglong)uStack_30 * 0xffffff10) >> 0xc |
              (((int)uStack_30 >> 0x1f) * -0xf0 +
              ((int)((ulonglong)uStack_30 * 0xffffff10 >> 0x20) - uStack_30)) * 0x100000;
  if (uVar3 == 0xffffffff) {
    uVar3 = 1;
  }
  uStack_2c = (uint)((ulonglong)uStack_2c * 0xffffff10) >> 0xc |
              (((int)uStack_2c >> 0x1f) * -0xf0 +
              ((int)((ulonglong)uStack_2c * 0xffffff10 >> 0x20) - uStack_2c)) * 0x100000;
  do {
    iVar2 = func_0203fcac((uint)(uintptr_t)(&uStack_40),0,uVar3 & 0xffff);
    VecFx32_Add((uint)(uintptr_t)(&uStack_40),(uint)(uintptr_t)(&uStack_34),&uStack_40);
    iVar7 = iVar7 + 1;
    if (iVar2 < 1) break;
  } while (iVar7 < 0x11);
  uVar3 = param_1 + 0x24U & 3;
  uVar4 = *(uint *)(param_1 + 0x24U & 0xfffffffc);
  iVar2 = param_1 + 0xc + ((uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) - 2) * 4;
  MaybeConvertElapsedTime(iVar2 + 2,iVar2 + 3,iVar2,iVar7 * -0xf0);
  uVar5 = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  puVar6 = (ushort *)(param_1 + 0x20);
  *(undefined1 *)(param_1 + 0x22) = 0;
  *(undefined1 *)(param_1 + 0x23) = 0;
  *(undefined2 *)(param_1 + 0x20) = 0;
  uVar3 = param_1 + 0x24U & 3;
  uVar4 = *(uint *)(param_1 + 0x24U & 0xfffffffc);
  if (0 < (int)((uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) - 1)) {
    do {
      AddRCTimes((ushort *)(uintptr_t)(param_1 + 0xc + uVar5 * 4),puVar6,puVar6);
      uVar3 = param_1 + 0x24U & 3;
      uVar4 = *(uint *)(param_1 + 0x24U & 0xfffffffc);
      uVar5 = uVar5 + 1 & 0xff;
    } while ((int)uVar5 < (int)((uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) - 1));
  }
  if (param_2 == 0) {
    *(uint *)(param_1 + 0x2c) =
         ((uint)*(byte *)(param_1 + 0x22) * 0x3c + (uint)*(byte *)(param_1 + 0x23)) * 1000 +
         (uint)*puVar6;
    return;
  }
  return;
}

