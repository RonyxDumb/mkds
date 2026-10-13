/* Decompiled C draft; module arm7; ROM address 03805088. No matching claim. */
#include "types.h"
#include "deps/03805088_FUN_03805088.h"

void FUN_03805088(void)

{
  int iVar1;
  uint uVar2;
  undefined4 in_r3;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  undefined1 auStack_28 [4];
  
  iVar1 = DAT_0380553c;
  uVar3 = 0x10;
  uVar4 = 0x11;
  uVar5 = 0x12;
  uVar6 = 0x15;
  uVar7 = 0x16;
  uVar8 = 0x17;
  uVar9 = 0x18;
  uVar10 = 0x19;
  uVar11 = 0x20;
  uVar12 = 0x21;
  uVar13 = 0x22;
  uVar14 = 0x23;
  uVar15 = 0x24;
  uVar16 = 0x25;
  uVar17 = 0x26;
  uVar18 = 0x27;
  uVar19 = 0x28;
  uVar20 = 0x29;
  while( true ) {
    FUN_037f97b4(iVar1,auStack_28,1,in_r3,uVar3,uVar4,uVar5,uVar6,uVar7,uVar8,uVar9,uVar10,uVar11,
                 uVar12,uVar13,uVar14,uVar15,uVar16,uVar17,uVar18,uVar19,uVar20);
    uVar2 = (uint)*(ushort *)(DAT_03805540 + 0xd8);
                    /* WARNING: Could not recover jumptable at 0x0380515c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    if (uVar2 < 0x2a) break;
    *(undefined4 *)(iVar1 + 0x1d4) = 0;
    FUN_03805544(uVar2,1);
  }
  (*(code *)(&UNK_03805164 + uVar2 * 4))();
  return;
}

