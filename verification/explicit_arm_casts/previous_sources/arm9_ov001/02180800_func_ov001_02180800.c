/* Decompiled C draft; module arm9_ov001; ROM address 02180800. No matching claim. */
#include "types.h"
#include "deps/02180800_func_ov001_02180800.h"

void func_ov001_02180800(void)

{
  undefined2 uVar1;
  bool bVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  int extraout_r1;
  int extraout_r1_00;
  int iVar6;
  undefined2 *puVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined2 *puVar10;
  int iVar11;
  int unaff_r4;
  undefined4 *puVar12;
  int iVar13;
  undefined1 auStack_104 [16];
  undefined4 local_f4 [8];
  undefined2 local_d4 [96];
  
  if (*(int *)(*piRam02180a78 + 8) != 0) {
    func_ov001_02180ca4();
    func_ov001_02180c88(auStack_104);
    if (*(uint *)(*piRam02180a78 + 4) < 4) {
                    /* WARNING: Could not recover jumptable at 0x0218082e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(*(short *)(*(uint *)(*piRam02180a78 + 4) * 2 + 0x2180830) + 0x2180830))();
      return;
    }
  }
  if (*(int *)(*piRam02180a78 + 4) == 0) {
    func_0x020ca9e4();
  }
  else if (*(int *)(*piRam02180a78 + 4) - 1U < 3) {
    puVar9 = local_f4;
    iVar6 = 4;
    puVar12 = puRam02180ab8;
    do {
      uVar3 = *puVar12;
      uVar5 = puVar12[1];
      puVar12 = puVar12 + 2;
      *puVar9 = uVar3;
      puVar9[1] = uVar5;
      puVar9 = puVar9 + 2;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    puVar7 = local_d4;
    iVar6 = 0x5f;
    puVar10 = puRam02180abc;
    do {
      uVar1 = *puVar10;
      puVar10 = puVar10 + 1;
      *puVar7 = uVar1;
      puVar7 = puVar7 + 1;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    uVar3 = func_ov001_021805ec();
    bVar2 = false;
    iVar6 = *(int *)(*piRam02180a78 + 4);
    if (iVar6 == 1) {
      unaff_r4 = 0;
    }
    else if (iVar6 == 2) {
      unaff_r4 = 1;
    }
    else if (iVar6 == 3) {
      unaff_r4 = 2;
    }
    iVar6 = func_ov001_021805bc(uVar3,0x20);
    if (iVar6 == 0) {
      iVar6 = func_ov001_021805bc(uVar3,0x10);
      if (iVar6 != 0) {
        func_0x02133068(*piRam02180ac0 + 1,9);
        *piRam02180ac0 = extraout_r1_00;
        func_ov001_02180af8(*piRam02180a78 + 0x18 + unaff_r4 * 0x20,0);
        bVar2 = true;
      }
    }
    else {
      func_0x02133068(*piRam02180ac0 + 8,9);
      *piRam02180ac0 = extraout_r1;
      func_ov001_02180af8(*piRam02180a78 + 0x18 + unaff_r4 * 0x20,0);
      bVar2 = true;
    }
    if (bVar2) {
      iVar6 = 0;
      iVar11 = 0;
      iVar4 = *piRam02180ac0;
      do {
        iVar13 = 0;
        do {
          iVar8 = iVar6;
          if (iVar4 == 8) {
            *(undefined2 *)(iRam02180ac4 + iVar8 * 2) = local_d4[iVar13 + iVar11 * 0x10];
          }
          else {
            *(short *)(iRam02180ac4 + iVar8 * 2) =
                 (short)iVar13 + (short)(iVar11 * 0x10) + (short)local_f4[iVar4];
          }
          iVar13 = iVar13 + 1;
          iVar6 = iVar8 + 1;
        } while (iVar13 < 0x10);
        iVar6 = iVar8 + 2;
        *(undefined2 *)(iRam02180ac4 + (iVar8 + 1) * 2) = 10;
        iVar11 = iVar11 + 1;
      } while (iVar11 < 6);
      if (*(int *)(*piRam02180a78 + 4) == 3) {
        uVar3 = 6;
      }
      else {
        uVar3 = 7;
      }
      func_ov001_02180ad0(*piRam02180a78 + 0x78 + unaff_r4 * 0x10,0x80,0x62,uVar3,uRam02180ac8,
                          iRam02180ac4);
    }
    func_0x0214b9c4(*piRam02180a78 + 0xa8,0,uRam02180acc);
  }
  if (3 < *(uint *)(*piRam02180a78 + 8)) {
    *(undefined4 *)(*piRam02180a78 + 8) = 0;
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x02180a4a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(*(short *)(*(uint *)(*piRam02180a78 + 8) * 2 + 0x2180a4c) + 0x2180a4c))();
  return;
}

