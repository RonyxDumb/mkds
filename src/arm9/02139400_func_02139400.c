/* Decompiled C draft; module arm9; ROM address 02139400. No matching claim. */
#include "types.h"
#include "deps/02139400_func_02139400.h"

int func_02139400(int param_1,undefined4 *param_2)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  undefined1 local_40;
  undefined1 uStack_3f;
  undefined1 uStack_3e;
  undefined1 uStack_3d;
  undefined1 local_3c;
  undefined1 uStack_3b;
  undefined1 uStack_3a;
  undefined1 uStack_39;
  undefined4 local_38;
  uint local_34;
  undefined4 local_30;
  undefined4 uStack_2c;
  uint uStack_28;
  uint uStack_24;
  uint local_20;
  uint uStack_1c;
  
  uVar2 = *DAT_02139e18;
  local_38 = DAT_02139e18[2];
  local_34 = DAT_02139e18[3];
  local_40 = (undefined1)uVar2;
  uStack_3f = (undefined1)(uVar2 >> 8);
  uStack_3e = (undefined1)(uVar2 >> 0x10);
  uStack_3d = (undefined1)(uVar2 >> 0x18);
  uStack_39 = (undefined1)(DAT_02139e18[1] >> 0x18);
  local_30 = DAT_02139e18[4];
  uStack_2c = DAT_02139e18[5];
  uStack_28 = DAT_02139e18[6];
  uStack_24 = DAT_02139e18[7];
  local_20 = DAT_02139e18[8];
  uStack_1c = DAT_02139e18[9];
  uVar8 = param_1 + 1;
  uVar4 = param_1 + 1U & 3;
  uVar3 = *(uint *)(param_1 + 1U & 0xfffffffc);
  uVar4 = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & 0xff;
  if (uVar4 == 0x25) {
    uVar4 = (uint)&uStack_3d & 3;
    uVar8 = (uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) & 0xffffff00 | 0x25;
    uVar4 = (4 - ((uint)&uStack_3d & 3)) * 8 & 0x1f;
    uVar4 = uVar8 >> uVar4 | uVar8 << 0x20 - uVar4;
    uStack_3d = (undefined1)uVar4;
    *param_2 = CONCAT13(uStack_3d,(int3)uVar2);
    param_2[1] = CONCAT13(uStack_39,(int3)(uVar4 >> 8));
    param_2[2] = local_38;
    param_2[3] = local_34;
    param_2[4] = local_30;
    param_2[5] = uStack_2c;
    param_2[6] = uStack_28;
    param_2[7] = uStack_24;
    param_2[8] = local_20;
    param_2[9] = uStack_1c;
    return param_1 + 2;
  }
  if (uVar4 == 0x2a) {
    uVar2 = uVar2 & 0xffffff00;
    local_40 = 1;
    uStack_3f = (undefined1)(uVar2 >> 8);
    uStack_3e = (undefined1)(uVar2 >> 0x10);
    uStack_3d = (undefined1)(uVar2 >> 0x18);
    uVar8 = param_1 + 2;
    uVar4 = (*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
            *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20) & 0xff;
  }
  if (uVar4 < 0x80) {
    uVar1 = *(ushort *)(DAT_02139e1c + uVar4 * 2) & 8;
  }
  else {
    uVar1 = 0;
  }
  if (uVar1 != 0) {
    local_3c = 0;
    uStack_3b = 0;
    uStack_3a = 0;
    uStack_39 = 0;
    do {
      uVar2 = uVar8;
      iVar5 = CONCAT13(uStack_39,CONCAT12(uStack_3a,CONCAT11(uStack_3b,local_3c))) * 10 +
              (uVar4 - 0x30);
      local_3c = (undefined1)iVar5;
      uStack_3b = (undefined1)((uint)iVar5 >> 8);
      uStack_3a = (undefined1)((uint)iVar5 >> 0x10);
      uStack_39 = (undefined1)((uint)iVar5 >> 0x18);
      uVar8 = uVar2 + 1;
      uVar4 = (*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
              *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20) & 0xff;
      if (uVar4 < 0x80) {
        uVar1 = *(ushort *)(DAT_02139e1c + uVar4 * 2) & 8;
      }
      else {
        uVar1 = 0;
      }
    } while (uVar1 != 0);
    if (iVar5 == 0) {
      uVar4 = (uint)&uStack_3d & 3;
      uVar8 = CONCAT13(uStack_3d,CONCAT12(uStack_3e,CONCAT11(uStack_3f,local_40)));
      uVar8 = (uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20) & 0xffffff00 | 0xff;
      uVar4 = (4 - ((uint)&uStack_3d & 3)) * 8 & 0x1f;
      uVar4 = uVar8 >> uVar4 | uVar8 << 0x20 - uVar4;
      uStack_3d = (undefined1)uVar4;
      *param_2 = CONCAT13(uStack_3d,CONCAT12(uStack_3e,CONCAT11(uStack_3f,local_40)));
      param_2[1] = CONCAT13(uStack_39,(int3)(uVar4 >> 8));
      param_2[2] = local_38;
      param_2[3] = local_34;
      param_2[4] = local_30;
      param_2[5] = uStack_2c;
      param_2[6] = uStack_28;
      param_2[7] = uStack_24;
      param_2[8] = local_20;
      param_2[9] = uStack_1c;
      return uVar2 + 2;
    }
    uVar2 = (uint)&uStack_3f & 3;
    uVar3 = CONCAT13(uStack_3d,CONCAT12(uStack_3e,CONCAT11(uStack_3f,local_40)));
    uVar3 = (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) & 0xffffff00 | 1;
    uVar2 = (4 - ((uint)&uStack_3f & 3)) * 8 & 0x1f;
    uVar2 = uVar3 >> uVar2 | uVar3 << 0x20 - uVar2;
    uStack_3f = (undefined1)uVar2;
    uStack_3e = (undefined1)(uVar2 >> 8);
    uStack_3d = (undefined1)(uVar2 >> 0x10);
  }
  bVar9 = true;
  if (uVar4 < 0x6d) {
    if (uVar4 < 0x68) {
      if (uVar4 != 0x4c) goto LAB_021397d8;
      uVar2 = (uint)&uStack_3e & 3;
      uVar3 = CONCAT13(uStack_3d,CONCAT12(uStack_3e,CONCAT11(uStack_3f,local_40)));
      uVar3 = (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) & 0xffffff00 | 9;
      uVar2 = (4 - ((uint)&uStack_3e & 3)) * 8 & 0x1f;
      uVar2 = uVar3 >> uVar2 | uVar3 << 0x20 - uVar2;
      uStack_3e = (undefined1)uVar2;
      uStack_3d = (undefined1)(uVar2 >> 8);
    }
    else if (uVar4 == 0x68) {
      uVar2 = (uint)&uStack_3e & 3;
      uVar3 = CONCAT13(uStack_3d,CONCAT12(uStack_3e,CONCAT11(uStack_3f,local_40)));
      uVar3 = (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) & 0xffffff00 | 2;
      uVar2 = (4 - ((uint)&uStack_3e & 3)) * 8 & 0x1f;
      uVar2 = uVar3 >> uVar2 | uVar3 << 0x20 - uVar2;
      uStack_3e = (undefined1)uVar2;
      uStack_3d = (undefined1)(uVar2 >> 8);
      uVar2 = uVar8 + 1 & 3;
      uVar3 = *(uint *)(uVar8 + 1 & 0xfffffffc);
      if (((uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) & 0xff) == 0x68) {
        uVar4 = (uint)&uStack_3e & 3;
        uVar2 = CONCAT13(uStack_3d,CONCAT12(uStack_3e,CONCAT11(uStack_3f,local_40)));
        uVar2 = (uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) & 0xffffff00 | 1;
        uVar4 = (4 - ((uint)&uStack_3e & 3)) * 8 & 0x1f;
        uVar4 = uVar2 >> uVar4 | uVar2 << 0x20 - uVar4;
        uStack_3e = (undefined1)uVar4;
        uStack_3d = (undefined1)(uVar4 >> 8);
        uVar8 = uVar8 + 1;
        uVar4 = (*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
                *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20) & 0xff;
      }
    }
    else if (uVar4 == 0x6a) {
      uVar2 = (uint)&uStack_3e & 3;
      uVar3 = CONCAT13(uStack_3d,CONCAT12(uStack_3e,CONCAT11(uStack_3f,local_40)));
      uVar3 = (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) & 0xffffff00 | 4;
      uVar2 = (4 - ((uint)&uStack_3e & 3)) * 8 & 0x1f;
      uVar2 = uVar3 >> uVar2 | uVar3 << 0x20 - uVar2;
      uStack_3e = (undefined1)uVar2;
      uStack_3d = (undefined1)(uVar2 >> 8);
    }
    else {
      if (uVar4 != 0x6c) goto LAB_021397d8;
      uVar2 = (uint)&uStack_3e & 3;
      uVar3 = CONCAT13(uStack_3d,CONCAT12(uStack_3e,CONCAT11(uStack_3f,local_40)));
      uVar3 = (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) & 0xffffff00 | 3;
      uVar2 = (4 - ((uint)&uStack_3e & 3)) * 8 & 0x1f;
      uVar2 = uVar3 >> uVar2 | uVar3 << 0x20 - uVar2;
      uStack_3e = (undefined1)uVar2;
      uStack_3d = (undefined1)(uVar2 >> 8);
      uVar2 = uVar8 + 1 & 3;
      uVar3 = *(uint *)(uVar8 + 1 & 0xfffffffc);
      if (((uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) & 0xff) == 0x6c) {
        uVar4 = (uint)&uStack_3e & 3;
        uVar2 = CONCAT13(uStack_3d,CONCAT12(uStack_3e,CONCAT11(uStack_3f,local_40)));
        uVar2 = (uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) & 0xffffff00 | 7;
        uVar4 = (4 - ((uint)&uStack_3e & 3)) * 8 & 0x1f;
        uVar4 = uVar2 >> uVar4 | uVar2 << 0x20 - uVar4;
        uStack_3e = (undefined1)uVar4;
        uStack_3d = (undefined1)(uVar4 >> 8);
        uVar8 = uVar8 + 1;
        uVar4 = (*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
                *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20) & 0xff;
      }
    }
  }
  else if (uVar4 < 0x75) {
    if (uVar4 == 0x74) {
      uVar2 = (uint)&uStack_3e & 3;
      uVar3 = CONCAT13(uStack_3d,CONCAT12(uStack_3e,CONCAT11(uStack_3f,local_40)));
      uVar3 = (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) & 0xffffff00 | 6;
      uVar2 = (4 - ((uint)&uStack_3e & 3)) * 8 & 0x1f;
      uVar2 = uVar3 >> uVar2 | uVar3 << 0x20 - uVar2;
      uStack_3e = (undefined1)uVar2;
      uStack_3d = (undefined1)(uVar2 >> 8);
    }
    else {
LAB_021397d8:
      bVar9 = false;
    }
  }
  else {
    if (uVar4 != 0x7a) goto LAB_021397d8;
    uVar2 = (uint)&uStack_3e & 3;
    uVar3 = CONCAT13(uStack_3d,CONCAT12(uStack_3e,CONCAT11(uStack_3f,local_40)));
    uVar3 = (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) & 0xffffff00 | 5;
    uVar2 = (4 - ((uint)&uStack_3e & 3)) * 8 & 0x1f;
    uVar2 = uVar3 >> uVar2 | uVar3 << 0x20 - uVar2;
    uStack_3e = (undefined1)uVar2;
    uStack_3d = (undefined1)(uVar2 >> 8);
  }
  if (bVar9) {
    uVar8 = uVar8 + 1;
    uVar4 = *(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
            *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20;
  }
  if (bVar9) {
    uVar4 = uVar4 & 0xff;
  }
  uVar2 = (uint)&uStack_3d & 3;
  uVar3 = CONCAT13(uStack_3d,CONCAT12(uStack_3e,CONCAT11(uStack_3f,local_40)));
  uVar3 = uVar4 & 0xff | (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) & 0xffffff00;
  uVar2 = (4 - ((uint)&uStack_3d & 3)) * 8 & 0x1f;
  uVar2 = uVar3 >> uVar2 | uVar3 << 0x20 - uVar2;
  uStack_3d = (undefined1)uVar2;
  local_3c = (undefined1)(uVar2 >> 8);
  uStack_3b = (undefined1)(uVar2 >> 0x10);
  uStack_3a = (undefined1)(uVar2 >> 0x18);
  if ((int)uVar4 < 0x5c) {
    if (0x5a < (int)uVar4) {
      uVar4 = CONCAT13(uStack_3d,CONCAT12(uStack_3e,CONCAT11(uStack_3f,local_40)));
      uVar4 = (uVar4 >> ((uint)&uStack_3e & 3) * 8 | uVar4 << ((uint)&uStack_3e & 3) * -8 + 0x20) &
              0xff;
      if (uVar4 == 3) {
        uVar4 = (uint)&uStack_3e & 3;
        uVar2 = CONCAT13(uStack_3d,CONCAT12(uStack_3e,CONCAT11(uStack_3f,local_40)));
        uVar2 = (uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) & 0xffffff00 | 10;
        uVar4 = (4 - ((uint)&uStack_3e & 3)) * 8 & 0x1f;
        uVar4 = uVar2 >> uVar4 | uVar2 << 0x20 - uVar4;
        uStack_3e = (undefined1)uVar4;
        uStack_3d = (undefined1)(uVar4 >> 8);
        local_3c = (undefined1)(uVar4 >> 0x10);
        uStack_3b = (undefined1)(uVar4 >> 0x18);
      }
      else if (uVar4 != 0) {
        uVar4 = (uint)&uStack_3d & 3;
        uVar2 = CONCAT13(uStack_3d,CONCAT12(uStack_3e,CONCAT11(uStack_3f,local_40)));
        uVar2 = (uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) & 0xffffff00 | 0xff;
        uVar4 = (4 - ((uint)&uStack_3d & 3)) * 8 & 0x1f;
        uVar4 = uVar2 >> uVar4 | uVar2 << 0x20 - uVar4;
        uStack_3d = (undefined1)uVar4;
        local_3c = (undefined1)(uVar4 >> 8);
        uStack_3b = (undefined1)(uVar4 >> 0x10);
        uStack_3a = (undefined1)(uVar4 >> 0x18);
      }
      uVar4 = uVar8 + 1;
      uVar2 = (*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
              *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) & 0xff;
      bVar9 = uVar2 == 0x5e;
      if (bVar9) {
        uVar4 = uVar8 + 2;
        uVar2 = (*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
                *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) & 0xff;
      }
      uVar8 = uVar4;
      if (uVar2 == 0x5d) {
        uVar4 = (int)&local_30 + 3U & 3;
        uVar2 = (int)&local_30 + 3U & 3;
        uVar2 = (local_30 >> uVar4 * 8 | local_30 << uVar4 * -8 + 0x20) & 0xff | 0x20 |
                (local_30 >> uVar2 * 8 | local_30 << uVar2 * -8 + 0x20) & 0xffffff00;
        uVar4 = (4 - ((int)&local_30 + 3U & 3)) * 8 & 0x1f;
        uVar4 = uVar2 >> uVar4 | uVar2 << 0x20 - uVar4;
        MKDS_SLICE_1(local_30,3) = (undefined1)uVar4;
        uVar2 = uStack_2c >> 0x18;
        MKDS_SLICE_1(uStack_2c,3) = (undefined1)uVar2;
        uStack_2c._0_3_ = (undefined3)(uVar4 >> 8);
        uVar8 = uVar8 + 1;
        uVar2 = (*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
                *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20) & 0xff;
      }
      while ((uVar2 != 0 && (uVar2 != 0x5d))) {
        uVar4 = (int)&local_38 + ((int)uVar2 >> 3);
        uVar3 = uVar4 & 3;
        uVar4 = *(uint *)(uVar4 & 0xfffffffc);
        puVar6 = (uint *)((int)&local_38 + ((int)uVar2 >> 3));
        uVar3 = (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) & 0xff | 1 << (uVar2 & 7) & 0xffU
                | (*(uint *)((uint)puVar6 & 0xfffffffc) >> ((uint)puVar6 & 3) * 8 |
                  *(uint *)((uint)puVar6 & 0xfffffffc) << ((uint)puVar6 & 3) * -8 + 0x20) &
                  0xffffff00;
        uVar4 = (4 - ((uint)puVar6 & 3)) * 8 & 0x1f;
        *puVar6 = uVar3 >> uVar4 | uVar3 << 0x20 - uVar4;
        uVar4 = uVar8 + 1 & 3;
        uVar3 = *(uint *)(uVar8 + 1 & 0xfffffffc);
        if ((((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & 0xff) == 0x2d) &&
           ((uVar4 = uVar8 + 2 & 3, uVar3 = *(uint *)(uVar8 + 2 & 0xfffffffc),
            uVar4 = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & 0xff, uVar4 != 0 &&
            (uVar4 != 0x5d)))) {
          uVar2 = uVar2 + 1;
          if (uVar2 <= uVar4) {
            do {
              iVar5 = (int)(uVar2 & 0xff) >> 3;
              uVar3 = (int)&local_38 + iVar5;
              uVar7 = uVar3 & 3;
              uVar3 = *(uint *)(uVar3 & 0xfffffffc);
              puVar6 = (uint *)((int)&local_38 + iVar5);
              uVar7 = (uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) & 0xff |
                      1 << (uVar2 & 7) & 0xffU |
                      (*(uint *)((uint)puVar6 & 0xfffffffc) >> ((uint)puVar6 & 3) * 8 |
                      *(uint *)((uint)puVar6 & 0xfffffffc) << ((uint)puVar6 & 3) * -8 + 0x20) &
                      0xffffff00;
              uVar3 = (4 - ((uint)puVar6 & 3)) * 8 & 0x1f;
              uVar2 = uVar2 + 1;
              *puVar6 = uVar7 >> uVar3 | uVar7 << 0x20 - uVar3;
            } while ((int)uVar2 <= (int)uVar4);
          }
          uVar8 = uVar8 + 3;
          uVar2 = (*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
                  *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20) & 0xff;
        }
        else {
          uVar8 = uVar8 + 1;
          uVar2 = (*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
                  *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20) & 0xff;
        }
      }
      if (uVar2 == 0) {
        uVar4 = (uint)&uStack_3d & 3;
        uVar2 = CONCAT13(uStack_3d,CONCAT12(uStack_3e,CONCAT11(uStack_3f,local_40)));
        uVar2 = (uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) & 0xffffff00 | 0xff;
        uVar4 = (4 - ((uint)&uStack_3d & 3)) * 8 & 0x1f;
        uVar4 = uVar2 >> uVar4 | uVar2 << 0x20 - uVar4;
        uStack_3d = (undefined1)uVar4;
        local_3c = (undefined1)(uVar4 >> 8);
        uStack_3b = (undefined1)(uVar4 >> 0x10);
        uStack_3a = (undefined1)(uVar4 >> 0x18);
      }
      else if (bVar9) {
        puVar6 = &local_38;
        iVar5 = 0x20;
        do {
          uVar2 = ~((*(uint *)((uint)puVar6 & 0xfffffffc) >> ((uint)puVar6 & 3) * 8 |
                    *(uint *)((uint)puVar6 & 0xfffffffc) << ((uint)puVar6 & 3) * -8 + 0x20) & 0xff)
                  & 0xff | (*(uint *)((uint)puVar6 & 0xfffffffc) >> ((uint)puVar6 & 3) * 8 |
                           *(uint *)((uint)puVar6 & 0xfffffffc) << ((uint)puVar6 & 3) * -8 + 0x20) &
                           0xffffff00;
          uVar4 = (4 - ((uint)puVar6 & 3)) * 8 & 0x1f;
          iVar5 = iVar5 + -1;
          *puVar6 = uVar2 >> uVar4 | uVar2 << 0x20 - uVar4;
          puVar6 = (uint *)((int)puVar6 + 1);
        } while (0 < iVar5);
      }
      goto LAB_02139dec;
    }
    if ((int)uVar4 < 0x48) {
                    /* WARNING: Could not recover jumptable at 0x0213982c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      if (-1 < (int)(uVar4 - 0x41)) {
        iVar5 = (*(code *)((uVar4 - 0x41) * 4 + 0x2139834))();
        return iVar5;
      }
    }
    else if (uVar4 == 0x58) goto LAB_021398d8;
    goto switchD_02139878_default;
  }
  if ((int)uVar4 < 0x62) {
    if (uVar4 != 0x61) goto switchD_02139878_default;
    goto LAB_02139918;
  }
  switch(uVar4) {
  case 99:
    uVar4 = CONCAT13(uStack_3d,CONCAT12(uStack_3e,CONCAT11(uStack_3f,local_40)));
    uVar4 = (uVar4 >> ((uint)&uStack_3e & 3) * 8 | uVar4 << ((uint)&uStack_3e & 3) * -8 + 0x20) &
            0xff;
    if (uVar4 == 3) {
      uVar4 = (uint)&uStack_3e & 3;
      uVar2 = CONCAT13(uStack_3d,CONCAT12(uStack_3e,CONCAT11(uStack_3f,local_40)));
      uVar2 = (uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) & 0xffffff00 | 10;
      uVar4 = (4 - ((uint)&uStack_3e & 3)) * 8 & 0x1f;
      uVar4 = uVar2 >> uVar4 | uVar2 << 0x20 - uVar4;
      uStack_3e = (undefined1)uVar4;
      uStack_3d = (undefined1)(uVar4 >> 8);
      local_3c = (undefined1)(uVar4 >> 0x10);
      uStack_3b = (undefined1)(uVar4 >> 0x18);
    }
    else if (uVar4 != 0) {
      uVar4 = (uint)&uStack_3d & 3;
      uVar2 = CONCAT13(uStack_3d,CONCAT12(uStack_3e,CONCAT11(uStack_3f,local_40)));
      uVar2 = (uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) & 0xffffff00 | 0xff;
      uVar4 = (4 - ((uint)&uStack_3d & 3)) * 8 & 0x1f;
      uVar4 = uVar2 >> uVar4 | uVar2 << 0x20 - uVar4;
      uStack_3d = (undefined1)uVar4;
      local_3c = (undefined1)(uVar4 >> 8);
      uStack_3b = (undefined1)(uVar4 >> 0x10);
      uStack_3a = (undefined1)(uVar4 >> 0x18);
    }
    goto LAB_02139dec;
  case 100:
    goto LAB_021398d8;
  case 0x65:
    goto LAB_02139918;
  case 0x66:
    goto LAB_02139918;
  case 0x67:
LAB_02139918:
    uVar4 = CONCAT13(uStack_3d,CONCAT12(uStack_3e,CONCAT11(uStack_3f,local_40)));
    uVar4 = (uVar4 >> ((uint)&uStack_3e & 3) * 8 | uVar4 << ((uint)&uStack_3e & 3) * -8 + 0x20) &
            0xff;
    if (((uVar4 == 1) || (uVar4 == 2)) || ((uVar4 + 0xfc & 0xff) < 4)) {
      uVar4 = (uint)&uStack_3d & 3;
      uVar2 = CONCAT13(uStack_3d,CONCAT12(uStack_3e,CONCAT11(uStack_3f,local_40)));
      uVar2 = (uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) & 0xffffff00 | 0xff;
      uVar4 = (4 - ((uint)&uStack_3d & 3)) * 8 & 0x1f;
      uVar4 = uVar2 >> uVar4 | uVar2 << 0x20 - uVar4;
      uStack_3d = (undefined1)uVar4;
      local_3c = (undefined1)(uVar4 >> 8);
      uStack_3b = (undefined1)(uVar4 >> 0x10);
      uStack_3a = (undefined1)(uVar4 >> 0x18);
    }
    else if (uVar4 == 3) {
      uVar4 = (uint)&uStack_3e & 3;
      uVar2 = CONCAT13(uStack_3d,CONCAT12(uStack_3e,CONCAT11(uStack_3f,local_40)));
      uVar2 = (uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) & 0xffffff00 | 8;
      uVar4 = (4 - ((uint)&uStack_3e & 3)) * 8 & 0x1f;
      uVar4 = uVar2 >> uVar4 | uVar2 << 0x20 - uVar4;
      uStack_3e = (undefined1)uVar4;
      uStack_3d = (undefined1)(uVar4 >> 8);
      local_3c = (undefined1)(uVar4 >> 0x10);
      uStack_3b = (undefined1)(uVar4 >> 0x18);
    }
    goto LAB_02139dec;
  case 0x68:
    break;
  case 0x69:
    goto LAB_021398d8;
  case 0x6a:
    break;
  case 0x6b:
    break;
  case 0x6c:
    break;
  case 0x6d:
    break;
  case 0x6e:
    goto LAB_02139dec;
  case 0x6f:
    goto LAB_021398d8;
  case 0x70:
    uVar4 = (uint)&uStack_3e & 3;
    uVar2 = CONCAT13(uStack_3d,CONCAT12(uStack_3e,CONCAT11(uStack_3f,local_40)));
    uVar2 = (uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) & 0xffffff00 | 3;
    uVar4 = (4 - ((uint)&uStack_3e & 3)) * 8 & 0x1f;
    uVar4 = uVar2 >> uVar4 | uVar2 << 0x20 - uVar4;
    uStack_3e = (undefined1)uVar4;
    uStack_3d = (undefined1)(uVar4 >> 8);
    uVar4 = (uint)&uStack_3d & 3;
    uVar2 = CONCAT13(uStack_3d,CONCAT12(uStack_3e,CONCAT11(uStack_3f,local_40)));
    uVar2 = (uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) & 0xffffff00 | 0x78;
    uVar4 = (4 - ((uint)&uStack_3d & 3)) * 8 & 0x1f;
    uVar4 = uVar2 >> uVar4 | uVar2 << 0x20 - uVar4;
    uStack_3d = (undefined1)uVar4;
    local_3c = (undefined1)(uVar4 >> 8);
    uStack_3b = (undefined1)(uVar4 >> 0x10);
    uStack_3a = (undefined1)(uVar4 >> 0x18);
    goto LAB_02139dec;
  case 0x71:
    break;
  case 0x72:
    break;
  case 0x73:
    uVar4 = CONCAT13(uStack_3d,CONCAT12(uStack_3e,CONCAT11(uStack_3f,local_40)));
    uVar4 = (uVar4 >> ((uint)&uStack_3e & 3) * 8 | uVar4 << ((uint)&uStack_3e & 3) * -8 + 0x20) &
            0xff;
    if (uVar4 == 3) {
      uVar4 = (uint)&uStack_3e & 3;
      uVar2 = CONCAT13(uStack_3d,CONCAT12(uStack_3e,CONCAT11(uStack_3f,local_40)));
      uVar2 = (uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) & 0xffffff00 | 10;
      uVar4 = (4 - ((uint)&uStack_3e & 3)) * 8 & 0x1f;
      uVar4 = uVar2 >> uVar4 | uVar2 << 0x20 - uVar4;
      uStack_3e = (undefined1)uVar4;
      uStack_3d = (undefined1)(uVar4 >> 8);
      local_3c = (undefined1)(uVar4 >> 0x10);
      uStack_3b = (undefined1)(uVar4 >> 0x18);
    }
    else if (uVar4 != 0) {
      uVar4 = (uint)&uStack_3d & 3;
      uVar2 = CONCAT13(uStack_3d,CONCAT12(uStack_3e,CONCAT11(uStack_3f,local_40)));
      uVar2 = (uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) & 0xffffff00 | 0xff;
      uVar4 = (4 - ((uint)&uStack_3d & 3)) * 8 & 0x1f;
      uVar4 = uVar2 >> uVar4 | uVar2 << 0x20 - uVar4;
      uStack_3d = (undefined1)uVar4;
      local_3c = (undefined1)(uVar4 >> 8);
      uStack_3b = (undefined1)(uVar4 >> 0x10);
      uStack_3a = (undefined1)(uVar4 >> 0x18);
    }
    iVar5 = 0x20;
    puVar6 = &local_38;
    do {
      iVar5 = iVar5 + -1;
      uVar2 = (*(uint *)((uint)puVar6 & 0xfffffffc) >> ((uint)puVar6 & 3) * 8 |
              *(uint *)((uint)puVar6 & 0xfffffffc) << ((uint)puVar6 & 3) * -8 + 0x20) & 0xffffff00 |
              0xff;
      uVar4 = (4 - ((uint)puVar6 & 3)) * 8 & 0x1f;
      *puVar6 = uVar2 >> uVar4 | uVar2 << 0x20 - uVar4;
      uVar4 = local_38;
      puVar6 = (uint *)((int)puVar6 + 1);
    } while (0 < iVar5);
    uVar2 = (int)&local_38 + 1U & 3;
    uVar3 = (local_38 >> uVar2 * 8 | local_38 << uVar2 * -8 + 0x20) & 0xffffff00 | 0xc1;
    uVar2 = (4 - ((int)&local_38 + 1U & 3)) * 8 & 0x1f;
    local_38._1_3_ = (uint3)(uVar3 >> uVar2) | (uint3)(uVar3 << 0x20 - uVar2);
    MKDS_SLICE_1(local_38,0) = (undefined1)uVar4;
    local_34 = local_34 & 0xffffff00 | 0xfe;
    goto LAB_02139dec;
  case 0x74:
    break;
  case 0x75:
    goto LAB_021398d8;
  case 0x76:
    break;
  case 0x77:
    break;
  case 0x78:
LAB_021398d8:
    uVar4 = CONCAT13(uStack_3d,CONCAT12(uStack_3e,CONCAT11(uStack_3f,local_40)));
    if (((uVar4 >> ((uint)&uStack_3e & 3) * 8 | uVar4 << ((uint)&uStack_3e & 3) * -8 + 0x20) & 0xff)
        == 9) {
      uVar4 = (uint)&uStack_3d & 3;
      uVar2 = CONCAT13(uStack_3d,CONCAT12(uStack_3e,CONCAT11(uStack_3f,local_40)));
      uVar2 = (uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) & 0xffffff00 | 0xff;
      uVar4 = (4 - ((uint)&uStack_3d & 3)) * 8 & 0x1f;
      uVar4 = uVar2 >> uVar4 | uVar2 << 0x20 - uVar4;
      uStack_3d = (undefined1)uVar4;
      local_3c = (undefined1)(uVar4 >> 8);
      uStack_3b = (undefined1)(uVar4 >> 0x10);
      uStack_3a = (undefined1)(uVar4 >> 0x18);
    }
    goto LAB_02139dec;
  }
switchD_02139878_default:
  uVar4 = (uint)&uStack_3d & 3;
  uVar2 = CONCAT13(uStack_3d,CONCAT12(uStack_3e,CONCAT11(uStack_3f,local_40)));
  uVar2 = (uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) & 0xffffff00 | 0xff;
  uVar4 = (4 - ((uint)&uStack_3d & 3)) * 8 & 0x1f;
  uVar4 = uVar2 >> uVar4 | uVar2 << 0x20 - uVar4;
  uStack_3d = (undefined1)uVar4;
  local_3c = (undefined1)(uVar4 >> 8);
  uStack_3b = (undefined1)(uVar4 >> 0x10);
  uStack_3a = (undefined1)(uVar4 >> 0x18);
LAB_02139dec:
  *param_2 = CONCAT13(uStack_3d,CONCAT12(uStack_3e,CONCAT11(uStack_3f,local_40)));
  param_2[1] = CONCAT13(uStack_39,CONCAT12(uStack_3a,CONCAT11(uStack_3b,local_3c)));
  param_2[2] = local_38;
  param_2[3] = local_34;
  param_2[4] = local_30;
  param_2[5] = uStack_2c;
  param_2[6] = uStack_28;
  param_2[7] = uStack_24;
  param_2[8] = local_20;
  param_2[9] = uStack_1c;
  return uVar8 + 1;
}

