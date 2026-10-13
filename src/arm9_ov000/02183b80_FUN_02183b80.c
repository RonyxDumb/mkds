/* Decompiled C draft; module arm9_ov000; ROM address 02183b80. No matching claim. */
#include "types.h"
#include "deps/02183b80_FUN_02183b80.h"

void FUN_02183b80(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  bool bVar6;
  int extraout_r1;
  bool bVar7;
  byte *pbVar8;
  int iVar9;
  int iVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  uint local_74;
  int local_68;
  int local_64;
  undefined1 auStack_58 [20];
  undefined2 local_44;
  undefined1 auStack_42 [20];
  undefined1 auStack_2e [26];
  
  if (0x77 < *(int *)(*DAT_02183ef4 + 8)) {
    *(undefined4 *)(*DAT_02183ef4 + 8) = 0x78;
  }
  *(int *)(*DAT_02183ef4 + 8) = *(int *)(*DAT_02183ef4 + 8) + 1;
  iVar3 = func_0x021213a0();
  if (iVar3 == 0) {
    func_0x021282c8();
  }
  else {
    func_0x02128374();
  }
  if ((*(int *)(*DAT_02183ef4 + 0x3c) != 0) &&
     (iVar3 = func_0x02121434(), piVar1 = DAT_02183ef4, iVar3 == 0)) {
    *(undefined4 *)(*DAT_02183ef4 + 0x3c) = 0;
    uVar4 = func_0x020b3f7c(*(undefined4 *)(*piVar1 + DAT_02183ef8),0xc);
    func_0x02126638(uVar4,0,0,1,0,1,0);
  }
  iVar3 = func_0x02125fa4();
  if (((iVar3 == 0) || (iVar3 = func_0x02128294(), iVar3 == 0)) ||
     ((*(ushort *)(DAT_02183efc + 0x2e0) & 2) == 0)) {
    bVar7 = false;
    bVar6 = false;
    if ((*(short *)(DAT_02183f00 + 0x2e0) == 0) && (*(ushort *)(DAT_02183f04 + 0x2e0) < 5)) {
      bVar6 = true;
    }
    if (((!bVar6) && (*(short *)(DAT_02183f08 + 0x2e0) == 0)) &&
       (*(short *)(DAT_02183f00 + 0x2e0) != 0)) {
      bVar7 = true;
    }
    if (((!bVar7) ||
        (iVar3 = func_0x02128210(*(undefined2 *)(DAT_02183f0c + 0x2e0),
                                 *(undefined2 *)(DAT_02183f10 + 0x2e0)), iVar3 == 0)) ||
       (iVar3 = func_0x021213a0(), iVar3 == 0)) {
      iVar3 = func_0x02125fa4();
      if (((iVar3 != 0) && (0x77 < *(int *)(*DAT_02183ef4 + 8))) &&
         (iVar3 = func_0x0212111c(), iVar3 == -1)) {
        FUN_021840c8();
        piVar1 = DAT_02183ef4;
        *(undefined4 *)(*DAT_02183ef4 + 4) = 9;
        *(undefined4 *)(*piVar1 + 0x40) = 1;
        iVar9 = 0;
        *(undefined4 *)(*piVar1 + 8) = 0;
        iVar3 = DAT_02183f18;
        pbVar8 = DAT_02183f14;
        do {
          *(undefined4 *)(*(int *)(*piVar1 + iVar3) + (uint)*pbVar8 * 0x40) = 0;
          pbVar8 = pbVar8 + 1;
          iVar9 = iVar9 + 1;
        } while (iVar9 < 3);
        func_0x02125fc0();
        func_0x02128374();
        func_0x02108990();
        return;
      }
      iVar3 = func_0x02125fa4();
      if ((iVar3 != 0) && (iVar3 = func_0x0212111c(), piVar1 = DAT_02183ef4, iVar3 == 1)) {
        iVar3 = 0;
        *(undefined4 *)(*DAT_02183ef4 + 8) = 0;
        if (1 < *(byte *)(*DAT_02183f1c + DAT_02183f20)) {
          *(uint *)(*piVar1 + 0x30) = *(byte *)(*DAT_02183f1c + DAT_02183f20) - 1;
          iVar9 = 0;
          if (*(char *)(*DAT_02183f1c + DAT_02183f20) != '\0') {
            iVar10 = 0;
            do {
              iVar5 = FUN_0219bb50();
              if (iVar9 != iVar5) {
                *(char *)(*piVar1 + iVar3 + 0x34) = (char)iVar9;
                *(undefined4 *)(*piVar1 + iVar10 + 0x24) = 1;
                iVar10 = iVar10 + 4;
                iVar3 = iVar3 + 1;
              }
              iVar9 = iVar9 + 1;
            } while (iVar9 < (int)(uint)*(byte *)(*DAT_02183f1c + DAT_02183f20));
          }
          piVar1 = DAT_02183ef4;
          iVar9 = 0;
          iVar3 = *DAT_02183ef4;
          if (0 < *(int *)(iVar3 + 0x30)) {
            local_68 = 0;
            local_64 = 0;
            puVar11 = DAT_02183f28;
            puVar12 = DAT_02183f24;
            do {
              uVar4 = func_0x021202b0(*(undefined1 *)(iVar3 + iVar9 + 0x34));
              func_0x0214cffc(uVar4,(int)(uintptr_t)(auStack_58),0x14);
              local_44 = 0;
              iVar3 = *piVar1;
              func_0x0212426c(1,*puVar12,*(undefined4 *)(iVar3 + DAT_02183f30),auStack_58,
                              *(undefined4 *)(iVar3 + DAT_02183f2c),
                              *(undefined4 *)(iVar3 + DAT_02183f18));
              local_74 = func_0x02120240(*(undefined1 *)(*piVar1 + iVar9 + 0x34));
              if (DAT_02183f34 < local_74) {
                local_74 = DAT_02183f34;
              }
              uVar4 = func_0x0212025c(*(undefined1 *)(*piVar1 + iVar9 + 0x34));
              func_0x02124fac(uVar4,(int)(uintptr_t)(auStack_42));
              func_0x02124fac(local_74,(int)(uintptr_t)(auStack_2e));
              iVar3 = *piVar1;
              func_0x0212426c(1,*puVar11,*(undefined4 *)(iVar3 + DAT_02183f30),auStack_42,
                              *(undefined4 *)(iVar3 + DAT_02183f2c),
                              *(undefined4 *)(iVar3 + DAT_02183f18));
              iVar3 = *piVar1;
              func_0x0212426c(1,puVar11[1],*(undefined4 *)(iVar3 + DAT_02183f30),auStack_2e,
                              *(undefined4 *)(iVar3 + DAT_02183f2c),
                              *(undefined4 *)(iVar3 + DAT_02183f18));
              iVar3 = *piVar1 + DAT_02183f38;
              uVar4 = func_0x02120294(*(undefined1 *)(*piVar1 + iVar9 + 0x34));
              func_0x020ac2fc(uVar4,iVar3 + local_68,0x20);
              uVar4 = func_0x02120278(*(undefined1 *)(*piVar1 + iVar9 + 0x34));
              *(undefined4 *)(*piVar1 + local_64 + DAT_02183f3c) = uVar4;
              puVar12 = puVar12 + 1;
              puVar11 = puVar11 + 2;
              local_68 = local_68 + DAT_02183f40;
              local_64 = local_64 + 4;
              iVar9 = iVar9 + 1;
              iVar3 = *piVar1;
            } while (iVar9 < *(int *)(iVar3 + 0x30));
          }
          iVar3 = DAT_02183f18;
          piVar1 = DAT_02183ef4;
          iVar9 = 0;
          iVar10 = 0;
          pbVar8 = DAT_02183f14;
          do {
            *(undefined4 *)(*(int *)(*piVar1 + iVar3) + (uint)*pbVar8 * 0x40) = 0;
            iVar5 = DAT_02183f18;
            piVar2 = DAT_02183ef4;
            pbVar8 = pbVar8 + 1;
            iVar9 = iVar9 + 1;
          } while (iVar9 < 3);
          iVar3 = *piVar1;
          pbVar8 = DAT_02183f14;
          if (0 < *(int *)(iVar3 + 0x30)) {
            do {
              *(undefined4 *)(*(int *)(iVar3 + iVar5) + (uint)*pbVar8 * 0x40) = 1;
              iVar10 = iVar10 + 1;
              iVar3 = *piVar2;
              pbVar8 = pbVar8 + 1;
            } while (iVar10 < *(int *)(iVar3 + 0x30));
          }
          *(undefined4 *)(iVar3 + 4) = 2;
          func_0x021282c8();
          func_0x02125fc0();
          func_0x0202b604();
          func_0x02108a40();
          *(undefined4 *)(*DAT_02183ef4 + 0x44) = 0;
          return;
        }
        FUN_021840c8();
        *(undefined4 *)(*piVar1 + 4) = 9;
        *(undefined4 *)(*piVar1 + 0x40) = 1;
        iVar3 = DAT_02183f18;
        iVar9 = 0;
        pbVar8 = DAT_02183f14;
        do {
          *(undefined4 *)(*(int *)(*piVar1 + iVar3) + (uint)*pbVar8 * 0x40) = 0;
          pbVar8 = pbVar8 + 1;
          iVar9 = iVar9 + 1;
        } while (iVar9 < 3);
        func_0x02125fc0();
        func_0x02128374();
        func_0x02108990();
        return;
      }
      iVar3 = func_0x02121418();
      piVar1 = DAT_02184010;
      iVar3 = iVar3 + -1;
      bVar6 = false;
      if (3 < iVar3) {
        iVar3 = 3;
      }
      *(int *)(*DAT_02184010 + 0xc) = *(int *)(*DAT_02184010 + 0xc) + 1;
      if (0x4f < *(int *)(*piVar1 + 0xc)) {
        *(undefined4 *)(*piVar1 + 0xc) = 0;
      }
      if (0 < iVar3) {
        iVar9 = 0x50 >> (iVar3 - 1U & 0xff);
        func_0x02133068(*(undefined4 *)(*DAT_02184010 + 0xc),iVar9);
        iVar9 = func_0x02133068(iVar9,2);
        if (iVar9 <= extraout_r1) {
          bVar6 = true;
        }
      }
      piVar1 = DAT_02184010;
      iVar9 = 0;
      pbVar8 = DAT_02184014;
      do {
        if ((iVar9 < iVar3) && (bVar6)) {
          *(undefined4 *)(*(int *)(*piVar1 + DAT_02184018) + (uint)*pbVar8 * 0x40) = 1;
          if (*(int *)(*piVar1 + 0x38) <= iVar9) {
            func_0x02108adc();
            *(int *)(*piVar1 + 0x38) = *(int *)(*piVar1 + 0x38) + 1;
          }
        }
        else {
          *(undefined4 *)(*(int *)(*piVar1 + DAT_02184018) + (uint)*pbVar8 * 0x40) = 0;
        }
        piVar2 = DAT_02184010;
        pbVar8 = pbVar8 + 1;
        iVar9 = iVar9 + 1;
      } while (iVar9 < 3);
      iVar9 = *DAT_02184010;
      iVar10 = *(int *)(iVar9 + 0x38);
      if (iVar3 < iVar10) {
        do {
          func_0x02108a8c();
          iVar10 = iVar10 + -1;
          iVar3 = iVar3 + 1;
          iVar9 = *piVar2;
        } while (iVar3 < *(int *)(iVar9 + 0x38));
      }
      *(int *)(iVar9 + 0x38) = iVar10;
      return;
    }
  }
  func_0x021213e8();
  func_0x02128310(0);
  piVar1 = DAT_02183ef4;
  *(undefined4 *)(*DAT_02183ef4 + 4) = 10;
  *(undefined4 *)(*piVar1 + 0x20) = 2;
  *(undefined4 *)(*piVar1 + 8) = 0;
  func_0x02125fc0();
  func_0x0210895c();
  return;
}

