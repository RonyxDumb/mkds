/* Decompiled C draft; module arm9; ROM address 021382a8. No matching claim. */
#include "types.h"
#include "deps/021382a8_func_021382a8.h"

void func_021382a8(int param_1,uint param_2,int param_3,code *param_4)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  uint *puVar7;
  uint uVar8;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  
  if (param_2 < 2) {
    return;
  }
  uStack_38 = (param_2 >> 1) + 1;
  uStack_34 = (uint *)(param_3 * (param_2 >> 1) + param_1);
  uStack_30 = (uint *)(param_3 * (param_2 - 1) + param_1);
  uStack_2c = uStack_38 * param_3;
  do {
    do {
      if (uStack_38 < 2) {
        iVar2 = param_3;
        puVar6 = uStack_34;
        puVar7 = uStack_30;
        if (param_3 != 0) {
          do {
            uVar4 = *(uint *)((uint)puVar6 & 0xfffffffc);
            iVar2 = iVar2 + -1;
            uVar1 = (*(uint *)((uint)puVar7 & 0xfffffffc) >> ((uint)puVar7 & 3) * 8 |
                    *(uint *)((uint)puVar7 & 0xfffffffc) << ((uint)puVar7 & 3) * -8 + 0x20) & 0xff |
                    (*(uint *)((uint)puVar6 & 0xfffffffc) >> ((uint)puVar6 & 3) * 8 |
                    *(uint *)((uint)puVar6 & 0xfffffffc) << ((uint)puVar6 & 3) * -8 + 0x20) &
                    0xffffff00;
            uVar8 = (4 - ((uint)puVar6 & 3)) * 8 & 0x1f;
            *puVar6 = uVar1 >> uVar8 | uVar1 << 0x20 - uVar8;
            uVar1 = (uVar4 >> ((uint)puVar6 & 3) * 8 | uVar4 << ((uint)puVar6 & 3) * -8 + 0x20) &
                    0xff | (*(uint *)((uint)puVar7 & 0xfffffffc) >> ((uint)puVar7 & 3) * 8 |
                           *(uint *)((uint)puVar7 & 0xfffffffc) << ((uint)puVar7 & 3) * -8 + 0x20) &
                           0xffffff00;
            uVar8 = (4 - ((uint)puVar7 & 3)) * 8 & 0x1f;
            *puVar7 = uVar1 >> uVar8 | uVar1 << 0x20 - uVar8;
            puVar6 = (uint *)((int)puVar6 + 1);
            puVar7 = (uint *)((int)puVar7 + 1);
          } while (iVar2 != 0);
        }
        param_2 = param_2 - 1;
        if (param_2 == 1) {
          return;
        }
        uStack_30 = (uint *)((int)uStack_30 - param_3);
      }
      else {
        uStack_2c = uStack_2c - param_3;
        uStack_38 = uStack_38 - 1;
        uStack_34 = (uint *)((int)uStack_34 - param_3);
      }
      puVar6 = (uint *)(param_1 + (uStack_2c - param_3));
      uVar8 = uStack_38;
    } while (param_2 < uStack_38 * 2);
    do {
      uVar8 = uVar8 * 2;
      puVar7 = (uint *)(param_3 * (uVar8 - 1) + param_1);
      if (uVar8 < param_2) {
        iVar2 = (*param_4)(puVar7,(uint *)((int)puVar7 + param_3));
        if (iVar2 < 0) {
          uVar8 = uVar8 + 1;
          puVar7 = (uint *)((int)puVar7 + param_3);
        }
      }
      iVar2 = (*param_4)(puVar6,puVar7);
      if (-1 < iVar2) break;
      iVar2 = param_3;
      puVar3 = puVar7;
      if (param_3 != 0) {
        do {
          uVar5 = *(uint *)((uint)puVar6 & 0xfffffffc);
          iVar2 = iVar2 + -1;
          uVar4 = (*(uint *)((uint)puVar3 & 0xfffffffc) >> ((uint)puVar3 & 3) * 8 |
                  *(uint *)((uint)puVar3 & 0xfffffffc) << ((uint)puVar3 & 3) * -8 + 0x20) & 0xff |
                  (*(uint *)((uint)puVar6 & 0xfffffffc) >> ((uint)puVar6 & 3) * 8 |
                  *(uint *)((uint)puVar6 & 0xfffffffc) << ((uint)puVar6 & 3) * -8 + 0x20) &
                  0xffffff00;
          uVar1 = (4 - ((uint)puVar6 & 3)) * 8 & 0x1f;
          *puVar6 = uVar4 >> uVar1 | uVar4 << 0x20 - uVar1;
          uVar4 = (uVar5 >> ((uint)puVar6 & 3) * 8 | uVar5 << ((uint)puVar6 & 3) * -8 + 0x20) & 0xff
                  | (*(uint *)((uint)puVar3 & 0xfffffffc) >> ((uint)puVar3 & 3) * 8 |
                    *(uint *)((uint)puVar3 & 0xfffffffc) << ((uint)puVar3 & 3) * -8 + 0x20) &
                    0xffffff00;
          uVar1 = (4 - ((uint)puVar3 & 3)) * 8 & 0x1f;
          *puVar3 = uVar4 >> uVar1 | uVar4 << 0x20 - uVar1;
          puVar3 = (uint *)((int)puVar3 + 1);
          puVar6 = (uint *)((int)puVar6 + 1);
        } while (iVar2 != 0);
      }
      puVar6 = puVar7;
    } while (uVar8 * 2 <= param_2);
  } while( true );
}

