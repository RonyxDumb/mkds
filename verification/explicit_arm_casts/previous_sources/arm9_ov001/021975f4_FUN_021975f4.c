/* Decompiled C draft; module arm9_ov001; ROM address 021975f4. No matching claim. */
#include "types.h"
#include "deps/021975f4_FUN_021975f4.h"

void FUN_021975f4(int param_1)

{
  ushort uVar1;
  undefined2 uVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined1 auStack_4c [4];
  undefined1 auStack_48 [32];
  undefined1 auStack_28 [20];
  
  if (param_1 != 0) {
    uVar7 = DAT_0219788c[param_1];
    iVar4 = func_0x020601e4(*(undefined4 *)(DAT_02197894 + *(int *)(*DAT_02197890 + 0x6c) * 4),uVar7
                           );
    uVar1 = DAT_02197898[param_1 * 2];
    *(undefined4 *)(*(int *)(*DAT_02197890 + 0x3c) + (uint)uVar1 * 0x40) = 1;
    uVar2 = *(undefined2 *)(DAT_0219789c + iVar4 * 2);
    iVar4 = *DAT_02197890;
    func_0x02124748(uVar2,*(undefined4 *)(iVar4 + 0x2c),*(undefined4 *)(iVar4 + 0x28),
                    *(undefined4 *)(iVar4 + 0x34),1,(uint)uVar1,*(undefined4 *)(iVar4 + 0x18),
                    *(undefined4 *)(iVar4 + 0x1c));
    iVar4 = *DAT_02197890;
    iVar8 = *(int *)(*(int *)(iVar4 + 0x30) + 0xc);
    iVar4 = func_0x02124a68(uVar2,*(undefined4 *)(iVar4 + 0x2c),*(undefined4 *)(iVar4 + 0x34));
    func_0x02016468(0x1e,(uint)DAT_021978a0[param_1] << 5,iVar8 + iVar4 * 0x20,0x20);
    uVar5 = func_0x020601a0(*(undefined4 *)(DAT_02197894 + *(int *)(*DAT_02197890 + 0x6c) * 4),uVar7
                           );
    piVar3 = DAT_02197890;
    uVar6 = (uint)*(ushort *)(DAT_021978ac + param_1 * 4);
    *(undefined4 *)(*(int *)(*DAT_02197890 + 0x3c) + uVar6 * 0x40) = 1;
    func_0x021171a0(uVar5,*(undefined4 *)(*piVar3 + 0x18),*(undefined4 *)(*piVar3 + 0x1c),uVar6,
                    *(undefined2 *)(DAT_021978b0 + param_1 * 2),1);
    uVar6 = (uint)*(ushort *)(*(int *)(*piVar3 + 0x1c) + 6);
    func_0x02060134(*(undefined4 *)(DAT_02197894 + *(int *)(*piVar3 + 0x6c) * 4),uVar7,auStack_4c);
    func_0x02116b8c(auStack_4c,auStack_48);
    uVar1 = DAT_021978a4[param_1];
    *(undefined4 *)(*(int *)(*piVar3 + 0x3c) + (uVar6 + uVar1) * 0x40) = 1;
    iVar4 = *piVar3;
    func_0x02124224(1,(uint)uVar1,*(undefined4 *)(iVar4 + 0x24),auStack_48,
                    *(undefined4 *)(iVar4 + 0x1c),*(undefined4 *)(iVar4 + 0x3c),7);
    func_0x020600d0(*(undefined4 *)(DAT_02197894 + *(int *)(*piVar3 + 0x6c) * 4),uVar7,auStack_28);
    func_0x0214d168(auStack_48,0,0x20);
    func_0x0214cffc(auStack_28,auStack_48,0x14);
    uVar1 = DAT_021978a8[param_1];
    *(undefined4 *)(*(int *)(*piVar3 + 0x3c) + (uVar6 + uVar1) * 0x40) = 1;
    iVar4 = *piVar3;
    func_0x0212426c(1,(uint)uVar1,*(undefined4 *)(iVar4 + 0x24),auStack_48,
                    *(undefined4 *)(iVar4 + 0x1c),*(undefined4 *)(iVar4 + 0x3c));
    return;
  }
  uVar7 = *DAT_0219788c;
  iVar4 = func_0x020601e4(*(undefined4 *)(DAT_02197894 + *(int *)(*DAT_02197890 + 0x6c) * 4),uVar7);
  piVar3 = DAT_02197890;
  uVar1 = *DAT_02197898;
  *(undefined4 *)(*(int *)(*DAT_02197890 + 0x38) + (uint)uVar1 * 0x40) = 1;
  uVar2 = *(undefined2 *)(DAT_0219789c + iVar4 * 2);
  iVar4 = *piVar3;
  func_0x02124748(uVar2,*(undefined4 *)(iVar4 + 0x2c),*(undefined4 *)(iVar4 + 0x28),
                  *(undefined4 *)(iVar4 + 0x34),0,(uint)uVar1,*(undefined4 *)(iVar4 + 4),
                  *(undefined4 *)(iVar4 + 8));
  iVar4 = *DAT_02197890;
  iVar8 = *(int *)(*(int *)(iVar4 + 0x30) + 0xc);
  iVar4 = func_0x02124a68(uVar2,*(undefined4 *)(iVar4 + 0x2c),*(undefined4 *)(iVar4 + 0x34));
  func_0x02016468(0xe,(uint)*DAT_021978a0 << 5,iVar8 + iVar4 * 0x20,0x20);
  uVar5 = func_0x020601a0(*(undefined4 *)(DAT_02197894 + *(int *)(*DAT_02197890 + 0x6c) * 4),uVar7);
  piVar3 = DAT_02197890;
  uVar1 = DAT_02197898[1];
  *(undefined4 *)(*(int *)(*DAT_02197890 + 0x38) + (uint)uVar1 * 0x40) = 1;
  func_0x021171a0(uVar5,*(undefined4 *)(*piVar3 + 4),*(undefined4 *)(*piVar3 + 8),(uint)uVar1,
                  DAT_021978a0[5],0);
  uVar6 = (uint)*(ushort *)(*(int *)(*DAT_02197890 + 8) + 6);
  func_0x02060134(*(undefined4 *)(DAT_02197894 + *(int *)(*DAT_02197890 + 0x6c) * 4),uVar7,
                  auStack_4c);
  func_0x02116b8c(auStack_4c,auStack_48);
  piVar3 = DAT_02197890;
  uVar1 = *DAT_021978a4;
  *(undefined4 *)(*(int *)(*DAT_02197890 + 0x38) + (uVar6 + uVar1) * 0x40) = 1;
  iVar4 = *piVar3;
  func_0x02124224(0,(uint)uVar1,*(undefined4 *)(iVar4 + 0x10),auStack_48,*(undefined4 *)(iVar4 + 8),
                  *(undefined4 *)(iVar4 + 0x38),7);
  func_0x020600d0(*(undefined4 *)(DAT_02197894 + *(int *)(*DAT_02197890 + 0x6c) * 4),uVar7,
                  auStack_28);
  func_0x0214d168(auStack_48,0,0x20);
  func_0x0214cffc(auStack_28,auStack_48,0x14);
  piVar3 = DAT_02197890;
  uVar1 = *DAT_021978a8;
  *(undefined4 *)(*(int *)(*DAT_02197890 + 0x38) + (uVar6 + uVar1) * 0x40) = 1;
  iVar4 = *piVar3;
  func_0x0212426c(0,(uint)uVar1,*(undefined4 *)(iVar4 + 0x10),auStack_48,*(undefined4 *)(iVar4 + 8),
                  *(undefined4 *)(iVar4 + 0x38));
  return;
}

