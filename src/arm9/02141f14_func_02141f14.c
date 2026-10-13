/* Decompiled C draft; module arm9; ROM address 02141f14. No matching claim. */
#include "types.h"
#include "deps/02141f14_func_02141f14.h"

void func_02141f14(uint *param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  uint *puVar5;
  uint uVar6;
  undefined4 uVar7;
  longlong lVar8;
  
  lVar8 = CONCAT44(param_3,param_2);
  uVar1 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
          *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) & 0xffffff00;
  uVar3 = (4 - ((uint)param_1 & 3)) * 8 & 0x1f;
  *param_1 = uVar1 >> uVar3 | uVar1 << 0x20 - uVar3;
  puVar5 = param_1 + 1;
  uVar1 = (*(uint *)((uint)puVar5 & 0xfffffffc) >> ((uint)puVar5 & 3) * 8 |
          *(uint *)((uint)puVar5 & 0xfffffffc) << ((uint)puVar5 & 3) * -8 + 0x20) & 0xffffff00;
  uVar3 = (4 - ((uint)puVar5 & 3)) * 8 & 0x1f;
  *puVar5 = uVar1 >> uVar3 | uVar1 << 0x20 - uVar3;
  if (param_3 != 0 || param_2 != 0) {
    do {
      uVar7 = (undefined4)((ulonglong)lVar8 >> 0x20);
      uVar1 = (uint)(param_1 + 1) & 3;
      uVar6 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
      uVar2 = ((*(uint *)((uint)puVar5 & 0xfffffffc) >> ((uint)puVar5 & 3) * 8 |
               *(uint *)((uint)puVar5 & 0xfffffffc) << ((uint)puVar5 & 3) * -8 + 0x20) & 0xff) + 1 &
              0xff | (*(uint *)((uint)puVar5 & 0xfffffffc) >> ((uint)puVar5 & 3) * 8 |
                     *(uint *)((uint)puVar5 & 0xfffffffc) << ((uint)puVar5 & 3) * -8 + 0x20) &
                     0xffffff00;
      uVar3 = (4 - ((uint)puVar5 & 3)) * 8 & 0x1f;
      *puVar5 = uVar2 >> uVar3 | uVar2 << 0x20 - uVar3;
      uVar3 = _ull_mod((int)lVar8,uVar7,10,0);
      puVar4 = (uint *)((int)param_1 +
                       ((uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) & 0xff) + 5);
      uVar1 = uVar3 & 0xff |
              (*(uint *)((uint)puVar4 & 0xfffffffc) >> ((uint)puVar4 & 3) * 8 |
              *(uint *)((uint)puVar4 & 0xfffffffc) << ((uint)puVar4 & 3) * -8 + 0x20) & 0xffffff00;
      uVar3 = (4 - ((uint)puVar4 & 3)) * 8 & 0x1f;
      *puVar4 = uVar1 >> uVar3 | uVar1 << 0x20 - uVar3;
      lVar8 = _ll_udiv((int)lVar8,uVar7,10,0);
    } while (lVar8 != 0);
  }
  puVar4 = (uint *)((int)param_1 + 5);
  uVar3 = (uint)(param_1 + 1) & 3;
  uVar1 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
  puVar5 = (uint *)((int)puVar4 + (((uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) & 0xff) - 1));
  if (puVar4 < puVar5) {
    do {
      uVar2 = *(uint *)((uint)puVar4 & 0xfffffffc);
      uVar1 = (*(uint *)((uint)puVar5 & 0xfffffffc) >> ((uint)puVar5 & 3) * 8 |
              *(uint *)((uint)puVar5 & 0xfffffffc) << ((uint)puVar5 & 3) * -8 + 0x20) & 0xff |
              (*(uint *)((uint)puVar4 & 0xfffffffc) >> ((uint)puVar4 & 3) * 8 |
              *(uint *)((uint)puVar4 & 0xfffffffc) << ((uint)puVar4 & 3) * -8 + 0x20) & 0xffffff00;
      uVar3 = (4 - ((uint)puVar4 & 3)) * 8 & 0x1f;
      *puVar4 = uVar1 >> uVar3 | uVar1 << 0x20 - uVar3;
      uVar1 = (uVar2 >> ((uint)puVar4 & 3) * 8 | uVar2 << ((uint)puVar4 & 3) * -8 + 0x20) & 0xff |
              (*(uint *)((uint)puVar5 & 0xfffffffc) >> ((uint)puVar5 & 3) * 8 |
              *(uint *)((uint)puVar5 & 0xfffffffc) << ((uint)puVar5 & 3) * -8 + 0x20) & 0xffffff00;
      uVar3 = (4 - ((uint)puVar5 & 3)) * 8 & 0x1f;
      *puVar5 = uVar1 >> uVar3 | uVar1 << 0x20 - uVar3;
      puVar4 = (uint *)((int)puVar4 + 1);
      puVar5 = (uint *)((int)puVar5 + -1);
    } while (puVar4 < puVar5);
  }
  uVar3 = (uint)(param_1 + 1) & 3;
  uVar1 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
  *(ushort *)((int)param_1 + 2) =
       (((ushort)(uVar1 >> uVar3 * 8) | (ushort)(uVar1 << uVar3 * -8 + 0x20)) & 0xff) - 1;
  return;
}

