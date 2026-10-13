/* Decompiled C draft; module arm7; ROM address 037ff908. No matching claim. */
#include "types.h"
#include "deps/037ff908_FUN_037ff908.h"

void FUN_037ff908(void)

{
  uint *puVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  int local_38;
  int *local_34;
  undefined4 local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  uint local_20;
  
  uVar4 = DAT_037ffd7c;
  uVar3 = DAT_037ffd78;
  uVar2 = DAT_037ffd74;
  puVar1 = DAT_037ffd70;
  while (iVar5 = FUN_037f97b4(uVar2,&local_38,0), piVar6 = (int *)local_38, iVar5 != 0) {
    while (piVar6 != (int *)0x0) {
      local_34 = (int *)*piVar6;
      local_30 = piVar6[1];
      local_2c = piVar6[2];
      local_28 = piVar6[3];
      local_24 = piVar6[4];
      local_20 = piVar6[5];
      piVar6 = local_34;
      switch(local_30) {
      case 0:
        FUN_037fed24(local_2c,local_28,local_24,local_20);
        piVar6 = local_34;
        break;
      case 1:
        FUN_037fecc8(local_2c);
        piVar6 = local_34;
        break;
      case 2:
        FUN_037fed60(local_2c,local_28,local_24,local_20);
        piVar6 = local_34;
        break;
      case 3:
        FUN_037fed40(local_2c);
        piVar6 = local_34;
        break;
      case 4:
        FUN_037fec44(local_2c,local_28);
        piVar6 = local_34;
        break;
      case 5:
        FUN_037feb78(local_2c,local_28);
        piVar6 = local_34;
        break;
      case 6:
        FUN_037fe91c(local_2c,local_28,local_24,local_20);
        piVar6 = local_34;
        break;
      case 7:
        FUN_037fe878(local_2c & 0xffffff,local_28,local_24,local_20,local_2c >> 0x18);
        piVar6 = local_34;
        break;
      case 8:
        FUN_037feadc(local_2c,local_28,local_24);
        piVar6 = local_34;
        break;
      case 9:
        FUN_037fea64(local_2c,local_28,local_24);
        piVar6 = local_34;
        break;
      case 10:
        FUN_037ff3b0(local_2c,local_28,(int)(short)local_24);
        piVar6 = local_34;
        break;
      case 0xb:
        FUN_037ff394(local_2c,(int)(short)local_28);
        piVar6 = local_34;
        break;
      case 0xc:
        FUN_037ff6c0(local_2c,local_28,local_24,local_20);
        piVar6 = local_34;
        break;
      case 0xd:
        FUN_037ff5fc(local_2c,local_28,local_24,local_20);
        piVar6 = local_34;
        break;
      case 0xe:
        FUN_037fbea0(local_2c & uVar3,local_28 & 0x7ffffff,local_20 >> 0x18 & 3,local_20 >> 0x1a & 3
                     ,local_20 & uVar3,local_24 & uVar4,local_24 >> 0x18 & 0x7f,local_24 >> 0x16 & 3
                     ,uVar3 & local_2c >> 0x10,local_20 >> 0x10 & 0x7f);
        piVar6 = local_34;
        break;
      case 0xf:
        FUN_037fbde8(local_2c,local_20,local_28 & 0x7f,local_28 >> 8 & 3,uVar3 & local_24 >> 8,
                     local_24 & 0x7f);
        piVar6 = local_34;
        break;
      case 0x10:
        FUN_037fbd38(local_2c,local_28 & 0x7f,local_28 >> 8 & 3,uVar3 & local_24 >> 8,
                     local_24 & 0x7f);
        piVar6 = local_34;
        break;
      case 0x11:
        FUN_037fc420(local_24 >> 0x1f,local_24 >> 0x1e & 1,local_2c,local_28,local_24 >> 0x1d & 1,
                     local_24 >> 0x1c & 1,local_24 >> 0x1b & 1);
        piVar6 = local_34;
        break;
      case 0x12:
        FUN_037ff508(local_2c,local_28,0,local_24,0,local_20);
        piVar6 = local_34;
        break;
      case 0x13:
        FUN_037ff854(local_2c,local_28);
        piVar6 = local_34;
        break;
      case 0x14:
        FUN_037ff7fc(local_2c,local_28,local_24);
        piVar6 = local_34;
        break;
      case 0x15:
        FUN_037ff7b4(local_2c,local_28);
        piVar6 = local_34;
        break;
      case 0x16:
        FUN_037fbb00(local_2c);
        piVar6 = local_34;
        break;
      case 0x17:
        FUN_037fb95c(local_2c);
        piVar6 = local_34;
        break;
      case 0x18:
        FUN_037fbb74(local_2c);
        piVar6 = local_34;
        break;
      case 0x19:
        FUN_037fb924(local_2c,local_28,local_24,local_20);
        piVar6 = local_34;
        break;
      case 0x1a:
        FUN_037fc908(local_2c,local_28);
        piVar6 = local_34;
        break;
      case 0x1b:
        FUN_037fc8cc(local_2c,local_28);
        piVar6 = local_34;
        break;
      case 0x1c:
        FUN_037fca00(local_2c,local_28);
        piVar6 = local_34;
        break;
      case 0x1d:
        *puVar1 = local_2c;
        break;
      case 0x1e:
        FUN_037fe9c8(local_2c,local_28);
        piVar6 = local_34;
        break;
      case 0x1f:
        FUN_037fe968(local_2c,local_28);
        piVar6 = local_34;
        break;
      case 0x20:
        FUN_037fc824(local_2c,local_28);
        piVar6 = local_34;
        break;
      case 0x21:
        FUN_037ff590(local_2c);
        piVar6 = local_34;
      }
    }
    piVar6 = (int *)(*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                    *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20);
    *piVar6 = (*(uint *)((uint)piVar6 & 0xfffffffc) >> ((uint)piVar6 & 3) * 8 |
              *(uint *)((uint)piVar6 & 0xfffffffc) << ((uint)piVar6 & 3) * -8 + 0x20) + 1;
  }
  return;
}

