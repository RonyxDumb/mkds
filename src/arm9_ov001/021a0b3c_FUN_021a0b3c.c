/* Decompiled C draft; module arm9_ov001; ROM address 021a0b3c. No matching claim. */
#include "types.h"
#include "deps/021a0b3c_FUN_021a0b3c.h"

void FUN_021a0b3c(void)

{
  ushort uVar1;
  int *piVar2;
  int *piVar3;
  undefined1 uVar4;
  uint uVar5;
  ushort *puVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  ushort *puVar11;
  int local_5c;
  ushort *local_54;
  ushort *local_50;
  ushort *local_4c;
  ushort *local_40;
  int local_3c;
  undefined1 auStack_38 [36];
  
  piVar2 = DAT_021a0dec;
  uVar1 = *(ushort *)(*(int *)(*DAT_021a0dec + 4) + 6);
  uVar5 = (uint)*(ushort *)(*(int *)(*DAT_021a0dec + 0x10) + 6);
  local_5c = 0;
  local_40 = DAT_021a0df0;
  local_50 = DAT_021a0df4;
  local_4c = DAT_021a0df8;
  iVar9 = 0;
  do {
    iVar8 = 0;
    *(undefined4 *)(*(int *)(*piVar2 + 0x40) + (uint)*local_40 * 0x40) = 0;
    puVar6 = local_50;
    do {
      *(undefined4 *)(*(int *)(*piVar2 + 0x44) + (uint)*puVar6 * 0x40) = 0;
      puVar6 = puVar6 + 1;
      iVar8 = iVar8 + 1;
      iVar10 = iVar9;
      puVar11 = local_4c;
    } while (iVar8 < 9);
    do {
      *(undefined4 *)(*(int *)(*piVar2 + 0x44) + (uVar5 + *puVar11) * 0x40) = 0;
      piVar3 = DAT_021a0dec;
      iVar10 = iVar10 + 1;
      puVar11 = puVar11 + 1;
    } while (iVar10 < 2);
    local_40 = local_40 + 1;
    local_50 = local_50 + 9;
    local_4c = local_4c + 2;
    local_5c = local_5c + 1;
  } while (local_5c < 9);
  iVar8 = 0;
  puVar6 = DAT_021a0dfc;
  do {
    *(undefined4 *)(*(int *)(*piVar3 + 0x40) + (uint)*puVar6 * 0x40) = 0;
    puVar6 = puVar6 + 1;
    iVar9 = iVar9 + 1;
  } while (iVar9 < 7);
  *(undefined4 *)(*(int *)(*piVar3 + 0x40) + (uint)uVar1 * 0x40) = 1;
  piVar2 = DAT_021a0dec;
  local_54 = DAT_021a0df8;
  puVar6 = DAT_021a0df4;
  do {
    if (iVar8 == 8) {
      iVar9 = *piVar2;
      if (*(int *)(iVar9 + 0xa0) == 0) {
        *(undefined4 *)(*(int *)(iVar9 + 0x44) + (uint)puVar6[4] * 0x40) = 1;
        iVar10 = *piVar2;
        iVar9 = func_0x02029608();
        FUN_021a6430((iVar9 + -1) * 0x10000 >> 0x10,0,*(undefined4 *)(iVar10 + 0xc),
                     *(undefined4 *)(iVar10 + 0x10),0x2d,8,1);
      }
      else {
        *(undefined4 *)(*(int *)(iVar9 + 0x44) + (uint)puVar6[1] * 0x40) = 1;
        iVar10 = *piVar2;
        iVar9 = func_0x02029608();
        FUN_021a6430((iVar9 + -1) * 0x10000 >> 0x10,1,*(undefined4 *)(iVar10 + 0xc),
                     *(undefined4 *)(iVar10 + 0x10),0x2d,8,1);
      }
    }
    else {
      *(undefined4 *)(*(int *)(*piVar2 + 0x44) + (uint)puVar6[1] * 0x40) = 1;
    }
    *(undefined4 *)(*(int *)(*piVar2 + 0x44) + (uint)*puVar6 * 0x40) = 1;
    *(undefined4 *)(*(int *)(*piVar2 + 0x44) + (uint)puVar6[2] * 0x40) = 0;
    *(undefined4 *)(*(int *)(*piVar2 + 0x44) + (uint)puVar6[3] * 0x40) = 0;
    uVar4 = func_0x02029608();
    iVar9 = func_0x0205fd78(uVar4,iVar8 + 1U & 0xff,&local_3c);
    if (iVar9 != 0) {
      if (local_3c < 5) {
        *(undefined4 *)(*(int *)(*piVar2 + 0x44) + (uint)puVar6[5] * 0x40) = 1;
        *(undefined4 *)(*(int *)(*piVar2 + 0x44) + (uVar5 + *local_54) * 0x40) = 1;
        iVar9 = *piVar2;
        func_0x0212426c(1,*local_54,*(undefined4 *)(iVar9 + 0x18),
                        *(undefined4 *)(DAT_021a0e00 + local_3c * 4),*(undefined4 *)(iVar9 + 0x10),
                        *(undefined4 *)(iVar9 + 0x44));
      }
      else if (local_3c < 8) {
        *(undefined4 *)(*(int *)(*piVar2 + 0x44) + (uint)puVar6[local_3c + 1] * 0x40) = 1;
      }
      if (iVar8 == 8) {
        *(undefined4 *)(*piVar2 + 0xa4) = 1;
      }
    }
    uVar7 = func_0x02029608();
    func_0x021057f0(0,uVar7);
    if (iVar8 == 8) {
      func_0x02124a20(puVar6[2],2,*(undefined4 *)(*piVar2 + 0xc),*(undefined4 *)(*piVar2 + 0x10));
      func_0x02124a20(puVar6[1],5,*(undefined4 *)(*piVar2 + 0xc),*(undefined4 *)(*piVar2 + 0x10));
      if (*(int *)(*piVar2 + 0xa0) != 0) {
        iVar9 = func_0x020cccb4();
        if (iVar9 == 0x12) {
          *(undefined2 *)(*piVar2 + 0x9e) = 8;
        }
        if (*(int *)(*piVar2 + 0xa4) == 0) {
          *(undefined2 *)(*piVar2 + 0x9e) = 8;
          func_0x02124a20(puVar6[2],0xb,*(undefined4 *)(*piVar2 + 0xc),
                          *(undefined4 *)(*piVar2 + 0x10));
          func_0x02124a20(puVar6[1],0xe,*(undefined4 *)(*piVar2 + 0xc),
                          *(undefined4 *)(*piVar2 + 0x10));
          uVar7 = func_0x02029608();
          func_0x021057f0(3,uVar7);
        }
      }
    }
    *(undefined4 *)(*(int *)(*piVar2 + 0x44) + (uVar5 + local_54[1]) * 0x40) = 1;
    FUN_021a0e08((int)(short)iVar8,(int)(uintptr_t)(auStack_38));
    iVar9 = *piVar2;
    func_0x0212426c(1,local_54[1],*(undefined4 *)(iVar9 + 0x18),auStack_38,
                    *(undefined4 *)(iVar9 + 0x10),*(undefined4 *)(iVar9 + 0x44));
    func_0x02124a98(*puVar6,1,*(undefined4 *)(*piVar2 + 0xc),*(undefined4 *)(*piVar2 + 0x10));
    puVar6 = puVar6 + 9;
    local_54 = local_54 + 2;
    iVar8 = iVar8 + 1;
  } while (iVar8 < 9);
  *(undefined4 *)(*(int *)(*DAT_021a0dec + 0x44) + DAT_021a0e04) = 1;
  return;
}

