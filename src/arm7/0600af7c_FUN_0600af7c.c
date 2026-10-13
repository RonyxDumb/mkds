/* Decompiled C draft; module arm7; ROM address 0600af7c. No matching claim. */
#include "types.h"
#include "deps/0600af7c_FUN_0600af7c.h"

undefined4 FUN_0600af7c(int param_1,int param_2)

{
  undefined2 uVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  code *pcVar8;
  uint local_30;
  undefined4 local_2c [2];
  
  pcVar8 = DAT_0600b1f4;
  if (param_2 == 0) {
    pcVar8 = DAT_0600b1f8;
  }
  iVar4 = FUN_0600a558(param_1);
  if (iVar4 == 0) {
    return 5;
  }
  uVar1 = *DAT_0600b1fc;
  *DAT_0600b1fc = (short)DAT_0600b200;
  uVar7 = DAT_0600b20c;
  do {
    do {
    } while ((int)(uint)*DAT_0600b204 >> 8 != 2);
  } while ((*DAT_0600b208 != 0) && (*DAT_0600b208 != 9));
  *(short *)((*(uint *)(DAT_0600b20c & 0xfffffffc) >> (DAT_0600b20c & 3) * 8 |
             *(uint *)(DAT_0600b20c & 0xfffffffc) << (DAT_0600b20c & 3) * -8 + 0x20) + 0x3be) =
       (short)param_1;
  uVar5 = *(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
          *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20;
  sVar2 = *(short *)(uVar5 + 0x5f8);
  if (sVar2 != 2) {
    if (sVar2 == 3) {
      iVar4 = *(ushort *)(uVar5 + 0x5fc) + 0xcf;
      for (uVar5 = 0; uVar3 = DAT_0600b20c,
          uVar5 < *(ushort *)
                   ((*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
                    *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + 0x600);
          uVar5 = uVar5 + 1) {
        local_30 = 0;
        local_2c[0] = 0;
        (*pcVar8)(iVar4,1,local_2c);
        (*pcVar8)(iVar4 + param_1,1,&local_30);
        FUN_06009e58(local_2c[0],local_30);
        iVar4 = iVar4 + 0xf;
      }
      for (uVar7 = 0; uVar5 = uVar3 & 3, uVar6 = *(uint *)(uVar3 & 0xfffffffc),
          uVar7 < *(ushort *)((uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) + 0x5fe);
          uVar7 = uVar7 + 1) {
        local_30 = 0;
        (*pcVar8)(iVar4,1,&local_30);
        local_30 = local_30 << 8;
        (*pcVar8)(iVar4 + param_1,1,&local_30);
        local_30 = local_30 | 0x50000;
        FUN_06009e30();
        iVar4 = iVar4 + 0xf;
      }
      goto LAB_0600b1d0;
    }
    if (sVar2 != 5) goto LAB_0600b1d0;
  }
  local_30 = 0;
  iVar4 = (param_1 + -1) * 6;
  (*pcVar8)(iVar4 + 0xf2,3,&local_30);
  FUN_06009e30(local_30);
  (*pcVar8)(iVar4 + 0xf5,3,&local_30);
  FUN_06009e30(local_30);
  local_30 = 0;
  uVar7 = (*(uint *)(DAT_0600b20c & 0xfffffffc) >> (DAT_0600b20c & 3) * 8 |
          *(uint *)(DAT_0600b20c & 0xfffffffc) << (DAT_0600b20c & 3) * -8 + 0x20) + 0x604;
  uVar5 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  uVar7 = uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20;
  if ((uVar7 & 0x10000) == 0) {
    (*pcVar8)(param_1 + -1 + DAT_0600b210,1,&local_30);
    FUN_06009e58(0x1e,local_30);
  }
  else if ((uVar7 & 0x8000) == 0) {
    (*pcVar8)(param_1 + 0x153,1,&local_30);
    uVar7 = (*(uint *)(DAT_0600b20c & 0xfffffffc) >> (DAT_0600b20c & 3) * 8 |
            *(uint *)(DAT_0600b20c & 0xfffffffc) << (DAT_0600b20c & 3) * -8 + 0x20) + 0x604;
    uVar5 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    local_30 = uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20 | (local_30 & 0x1f) << 10;
    FUN_06009e30();
  }
LAB_0600b1d0:
  *DAT_0600b1fc = uVar1;
  *DAT_0600b214 = 3;
  return 0;
}

