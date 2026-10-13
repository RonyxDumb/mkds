/* Decompiled C draft; module arm9_ov001; ROM address 02180ce8. No matching claim. */
#include "types.h"
#include "deps/02180ce8_func_ov001_02180ce8.h"

undefined4 func_ov001_02180ce8(undefined1 param_1,undefined1 param_2,uint param_3)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte *pbVar4;
  byte *pbVar5;
  int *piVar6;
  int iVar7;
  undefined1 *puVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  int *piVar12;
  undefined4 local_4c;
  int local_48;
  int local_44;
  undefined4 *local_40;
  undefined4 *local_38;
  int local_30;
  byte local_2c;
  byte local_2b;
  byte local_2a [6];
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_4c = 0;
  pbVar4 = (byte *)func_ov001_02181200(param_1,param_2);
  piVar12 = piRam02180ee4;
  if ((pbVar4 != (byte *)0x0) && (uVar11 = (uint)*pbVar4, uVar11 != param_3)) {
    local_48 = 1;
    puVar8 = *(undefined1 **)(*piRam02180ee4 + 0x2c);
    *puVar8 = param_1;
    puVar8[1] = param_2;
    local_1c = 0;
    iVar9 = *(int *)*piVar12;
    func_0x0214d05c(0,((int *)*piVar12)[10],iVar9 * iVar9);
    do {
      local_24 = *puRam02180ee8;
      local_20 = puRam02180ee8[1];
      local_48 = local_48 + -1;
      bVar3 = *(byte *)(*(int *)(*piRam02180ee4 + 0x2c) + local_48 * 2);
      bVar1 = *(byte *)(*(int *)(*piRam02180ee4 + 0x2c) + local_48 * 2 + 1);
      local_44 = 0;
      pbVar4 = local_2a;
      local_38 = &local_24;
      do {
        *pbVar4 = bVar3;
        while( true ) {
          pbVar5 = (byte *)func_ov001_02181200(*pbVar4,(uint)bVar1);
          iVar7 = ((int *)*piRam02180ee4)[10];
          bVar2 = *pbVar4;
          iVar9 = *(int *)*piRam02180ee4;
          if ((pbVar5 == (byte *)0x0) || (*pbVar5 != uVar11)) break;
          *pbVar4 = bVar2 + (char)*local_38;
          *(undefined1 *)(iVar7 + (uint)bVar2 + iVar9 * (uint)bVar1) = 1;
        }
        *pbVar4 = *pbVar4 - (char)*local_38;
        bVar2 = local_2a[1];
        pbVar4 = pbVar4 + 1;
        local_38 = local_38 + 1;
        local_44 = local_44 + 1;
      } while (local_44 < 2);
      local_30 = 0;
      local_40 = &local_24;
      do {
        local_2a[3] = bVar1 + (char)*local_40;
        local_2a[2] = local_2a[0];
        while (local_2a[2] <= bVar2) {
          uVar10 = (uint)local_2a[3];
          pbVar4 = (byte *)func_ov001_02181200(local_2a[2],uVar10);
          if (((pbVar4 != (byte *)0x0) && (*pbVar4 == uVar11)) &&
             (*(char *)(((int *)*piRam02180ee4)[10] +
                       (uint)local_2a[2] + *(int *)*piRam02180ee4 * uVar10) == '\0')) {
            do {
              local_2a[2] = local_2a[2] + 1;
              uVar10 = (uint)local_2a[3];
              pbVar4 = (byte *)func_ov001_02181200(local_2a[2],uVar10);
              piVar12 = (int *)*piRam02180ee4;
              if ((pbVar4 == (byte *)0x0) || (*pbVar4 != uVar11)) break;
            } while (*(char *)(piVar12[10] + (uint)local_2a[2] + *piVar12 * uVar10) == '\0');
            local_2a[2] = local_2a[2] - 1;
            iVar7 = piVar12[0xb];
            iVar9 = local_48 * 2;
            local_48 = local_48 + 1;
            *(byte *)(iVar7 + iVar9) = local_2a[2];
            *(byte *)(iVar7 + iVar9 + 1) = local_2a[3];
          }
          local_2a[2] = local_2a[2] + 1;
        }
        local_40 = local_40 + 1;
        local_30 = local_30 + 1;
      } while (local_30 < 2);
    } while (0 < local_48);
    local_4c = 1;
    func_ov001_021811c8();
    piVar12 = piRam02180ee4;
    local_2b = 0;
    piVar6 = (int *)*piRam02180ee4;
    iVar9 = *piVar6;
    if (0 < iVar9) {
      do {
        local_2c = 0;
        uVar11 = 0;
        if (0 < iVar9) {
          do {
            if (*(char *)(piVar6[10] + uVar11 + iVar9 * (uint)local_2b) != '\0') {
              puVar8 = (undefined1 *)func_ov001_02181200(local_2c,(uint)local_2b);
              *puVar8 = (char)param_3;
            }
            local_2c = local_2c + 1;
            piVar6 = (int *)*piVar12;
            iVar9 = *piVar6;
            uVar11 = (uint)local_2c;
          } while ((int)uVar11 < iVar9);
        }
        local_2b = local_2b + 1;
      } while ((int)(uint)local_2b < iVar9);
    }
  }
  return local_4c;
}

