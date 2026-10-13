/* Decompiled C draft; module arm7; ROM address 06002df0. No matching claim. */
#include "types.h"
#include "deps/06002df0_FUN_06002df0.h"

/* WARNING: Removing unreachable block (ram,0x06002f18) */

void FUN_06002df0(void)

{
  ushort uVar1;
  short sVar2;
  bool bVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  undefined2 *puVar8;
  uint uVar9;
  short *psVar10;
  uint uVar11;
  undefined1 auStack_224 [6];
  undefined1 auStack_21e [6];
  undefined1 auStack_218 [512];
  uint uVar12;
  
  iVar4 = FUN_06000680();
  uVar6 = iVar4 + 0x154cU & 3;
  uVar11 = *(uint *)(iVar4 + 0x154cU & 0xfffffffc);
  uVar12 = uVar11 >> uVar6 * 8 | uVar11 << uVar6 * -8 + 0x20;
  bVar3 = false;
  uVar5 = thunk_FUN_037faf70();
  uVar9 = *(uint *)(uVar12 & 0xfffffffc) >> (uVar12 & 3) * 8 |
          *(uint *)(uVar12 & 0xfffffffc) << (uVar12 & 3) * -8 + 0x20;
  uVar6 = uVar9 + 0xc;
  uVar11 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  if ((uVar6 >> uVar11 * 8 | uVar6 << uVar11 * -8 + 0x20) == 1) {
    *(undefined4 *)(uVar9 + 0xc) = 0;
    bVar3 = true;
    thunk_FUN_037fabc0(uVar12 + 0xd0);
    FUN_06000154();
    psVar10 = (short *)(*(uint *)(uVar12 & 0xfffffffc) >> (uVar12 & 3) * 8 |
                       *(uint *)(uVar12 & 0xfffffffc) << (uVar12 & 3) * -8 + 0x20);
    if (*psVar10 == 10) {
      *psVar10 = 8;
    }
    else if (*psVar10 == 9) {
      *psVar10 = 7;
    }
  }
  *(undefined2 *)
   ((*(uint *)(uVar12 & 0xfffffffc) >> (uVar12 & 3) * 8 |
    *(uint *)(uVar12 & 0xfffffffc) << (uVar12 & 3) * -8 + 0x20) + 0x17e) = 0;
  *(undefined2 *)
   ((*(uint *)(uVar12 & 0xfffffffc) >> (uVar12 & 3) * 8 |
    *(uint *)(uVar12 & 0xfffffffc) << (uVar12 & 3) * -8 + 0x20) + 0x86) = 0;
  *(undefined4 *)
   ((*(uint *)(uVar12 & 0xfffffffc) >> (uVar12 & 3) * 8 |
    *(uint *)(uVar12 & 0xfffffffc) << (uVar12 & 3) * -8 + 0x20) + 0x14) = 0;
  *(undefined4 *)
   ((*(uint *)(uVar12 & 0xfffffffc) >> (uVar12 & 3) * 8 |
    *(uint *)(uVar12 & 0xfffffffc) << (uVar12 & 3) * -8 + 0x20) + 0x10) = 0;
  *(undefined4 *)
   ((*(uint *)(uVar12 & 0xfffffffc) >> (uVar12 & 3) * 8 |
    *(uint *)(uVar12 & 0xfffffffc) << (uVar12 & 3) * -8 + 0x20) + 0x1c) = 0;
  *(undefined2 *)
   ((*(uint *)(uVar12 & 0xfffffffc) >> (uVar12 & 3) * 8 |
    *(uint *)(uVar12 & 0xfffffffc) << (uVar12 & 3) * -8 + 0x20) + 0xbe) = 0;
  thunk_FUN_037faf84(uVar5);
  if (bVar3) {
    FUN_06006d24(DAT_0600316c);
  }
  iVar4 = FUN_06002084(auStack_218);
  if (*(short *)(iVar4 + 4) != 0) {
    FUN_06002db8(0x308);
    return;
  }
  uVar1 = *(ushort *)(iVar4 + 6);
  iVar4 = FUN_0600213c(auStack_218);
  if (*(short *)(iVar4 + 4) != 0) {
    FUN_06002db8(0x284);
    return;
  }
  uVar6 = (uint)*(ushort *)(iVar4 + 6);
  if (uVar1 < 0x21) {
    if (0x1f < uVar1) goto LAB_06003030;
    if (uVar1 == 0) goto LAB_06003054;
    if ((0x12 < uVar1) || (uVar1 < 0x10)) goto LAB_06003138;
    if (uVar1 != 0x10) {
      if ((uVar1 != 0x11) && (uVar1 != 0x12)) goto LAB_06003138;
      if ((uVar6 == 0) && (iVar4 = FUN_06002010(auStack_218,0,0,0x14,1), *(short *)(iVar4 + 4) != 0)
         ) {
        FUN_06002db8(DAT_06003180);
        return;
      }
      iVar4 = FUN_0600210c(auStack_218);
      if (*(short *)(iVar4 + 4) != 0) {
        FUN_06002db8(DAT_06003178);
        return;
      }
      *(undefined2 *)
       (*(uint *)(uVar12 & 0xfffffffc) >> (uVar12 & 3) * 8 |
       *(uint *)(uVar12 & 0xfffffffc) << (uVar12 & 3) * -8 + 0x20) = 2;
      goto LAB_06003148;
    }
  }
  else {
    if (uVar1 < 0x31) {
      if (uVar1 != 0x30) {
LAB_06003138:
        FUN_06002db8(0x308,0);
        return;
      }
    }
    else if (uVar1 != 0x40) goto LAB_06003138;
    if ((uVar6 + DAT_06003170 & 0xffff) < 2) {
      thunk_FUN_037fb390((*(uint *)(uVar12 & 0xfffffffc) >> (uVar12 & 3) * 8 |
                         *(uint *)(uVar12 & 0xfffffffc) << (uVar12 & 3) * -8 + 0x20) + DAT_06003174,
                         auStack_224,6);
      for (iVar4 = 0; iVar4 < 2; iVar4 = iVar4 + 1) {
        iVar7 = FUN_060029f8(auStack_218,auStack_224,3);
        sVar2 = *(short *)(iVar7 + 4);
        if (sVar2 == 0) {
          *(undefined2 *)
           (*(uint *)(uVar12 & 0xfffffffc) >> (uVar12 & 3) * 8 |
           *(uint *)(uVar12 & 0xfffffffc) << (uVar12 & 3) * -8 + 0x20) = 3;
          break;
        }
        if ((sVar2 != 7) && (sVar2 != 0xc)) break;
      }
    }
    else if (uVar6 == 1) {
      thunk_FUN_037fb2fc(auStack_21e,0xff,6);
      iVar4 = FUN_060029f8(auStack_218,auStack_21e,3);
      if (*(short *)(iVar4 + 4) == 0) {
        *(undefined2 *)
         (*(uint *)(uVar12 & 0xfffffffc) >> (uVar12 & 3) * 8 |
         *(uint *)(uVar12 & 0xfffffffc) << (uVar12 & 3) * -8 + 0x20) = 3;
      }
    }
LAB_06003030:
    iVar4 = FUN_06002ca4(auStack_218,1);
    if (*(short *)(iVar4 + 4) != 0) {
      FUN_06002db8(0);
      return;
    }
LAB_06003054:
    iVar4 = FUN_0600210c(auStack_218);
    if (*(short *)(iVar4 + 4) != 0) {
      FUN_06002db8(DAT_06003178);
      return;
    }
  }
  if (*(short *)((*(uint *)(uVar12 & 0xfffffffc) >> (uVar12 & 3) * 8 |
                 *(uint *)(uVar12 & 0xfffffffc) << (uVar12 & 3) * -8 + 0x20) + 0x1ea) == 0) {
    iVar4 = FUN_06002400(auStack_218,1);
    if (*(short *)(iVar4 + 4) != 0) {
      FUN_06002db8(DAT_0600317c);
      return;
    }
    *(undefined2 *)
     ((*(uint *)(uVar12 & 0xfffffffc) >> (uVar12 & 3) * 8 |
      *(uint *)(uVar12 & 0xfffffffc) << (uVar12 & 3) * -8 + 0x20) + 0x1ea) = 1;
  }
  *(undefined2 *)
   (*(uint *)(uVar12 & 0xfffffffc) >> (uVar12 & 3) * 8 |
   *(uint *)(uVar12 & 0xfffffffc) << (uVar12 & 3) * -8 + 0x20) = 2;
LAB_06003148:
  puVar8 = (undefined2 *)thunk_FUN_03807424();
  *puVar8 = 1;
  puVar8[1] = 0;
  thunk_FUN_038074cc();
  return;
}

