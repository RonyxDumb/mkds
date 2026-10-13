/* Decompiled C draft; module arm9; ROM address 020c692c. No matching claim. */
#include "types.h"
#include "deps/020c692c_StructRA_SomeFn_5.h"

void StructRA_SomeFn_5(int param_1,uint param_2,int param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  short sVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined2 *puVar8;
  int iVar9;
  uint uVar10;
  undefined2 *puVar11;
  undefined2 *puVar12;
  uint uVar13;
  bool bVar14;
  undefined2 auStack_44 [12];
  char local_2c;
  
  uVar13 = *(uint *)(uRam020c6ad8 & 0xfffffffc) >> (uRam020c6ad8 & 3) * 8 |
           *(uint *)(uRam020c6ad8 & 0xfffffffc) << (uRam020c6ad8 & 3) * -8 + 0x20;
  puVar11 = (undefined2 *)(uVar13 + param_2 * 0x20 + 0x1c);
  uVar1 = uVar13 + 0xe4 & 3;
  uVar10 = *(uint *)(uVar13 + 0xe4 & 0xfffffffc);
  puVar8 = auStack_44;
  bVar14 = false;
  iVar9 = 8;
  do {
    puVar12 = puVar11 + 1;
    uVar3 = *puVar11;
    puVar11 = puVar11 + 2;
    uVar4 = *puVar12;
    iVar9 = iVar9 + -1;
    puVar12 = puVar8 + 1;
    *puVar8 = uVar3;
    puVar8 = puVar8 + 2;
    *puVar12 = uVar4;
  } while (iVar9 != 0);
  if (param_2 == 5) {
    if (uVar13 == 0) {
      uVar13 = 0;
    }
    else {
      uVar2 = uVar13 + 0x10 & 3;
      uVar13 = *(uint *)(uVar13 + 0x10 & 0xfffffffc);
      uVar13 = uVar13 >> uVar2 * 8 | uVar13 << uVar2 * -8 + 0x20;
    }
    bVar14 = uVar13 != 0;
    if (bVar14) {
      param_2 = 0;
    }
    else {
      param_2 = 6;
    }
  }
  else {
    uVar2 = uVar13 + 8 & 3;
    uVar6 = *(uint *)(uVar13 + 8 & 0xfffffffc);
    if ((uVar6 >> uVar2 * 8 == 0 && uVar6 << uVar2 * -8 + 0x20 == 0) ||
       (uVar2 = uVar13 + 0xc & 3, uVar13 = *(uint *)(uVar13 + 0xc & 0xfffffffc),
       uVar13 = uVar13 >> uVar2 * 8 | uVar13 << uVar2 * -8 + 0x20, (int)param_2 < (int)uVar13)) {
      param_2 = param_2 + 1;
    }
    else if (param_2 == uVar13) {
      param_2 = 0;
      bVar14 = true;
    }
  }
  if (local_2c != '\0') {
    uVar7 = GetB3C4_Cell_RaceNewRecordTaS(param_2 + 7);
    sVar5 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                             0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar7);
    *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar5;
    uVar7 = GetB3C4_Cell_RaceNewRecordTaS(param_2 + 0x1a);
    sVar5 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                             0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar7);
    *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar5;
  }
  if ((bVar14) && (0xf < (int)(uVar10 >> uVar1 * 8 | uVar10 << uVar1 * -8 + 0x20))) {
    return;
  }
  StructRA_SomeFn_6(param_1,param_3 + 0xab,param_4,auStack_44);
  return;
}

