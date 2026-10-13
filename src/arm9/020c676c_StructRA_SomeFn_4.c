/* Decompiled C draft; module arm9; ROM address 020c676c. No matching claim. */
#include "types.h"
#include "deps/020c676c_StructRA_SomeFn_4.h"

void StructRA_SomeFn_4(int param_1)

{
  uint uVar1;
  short sVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  short *psVar7;
  int iVar8;
  int local_3c [3];
  int local_30;
  int local_2c [2];
  
  uVar3 = GetB3C4_Cell_RaceNewRecordTaS(0);
  uVar5 = (*(uint *)(uRam020c6928 & 0xfffffffc) >> (uRam020c6928 & 3) * 8 |
          *(uint *)(uRam020c6928 & 0xfffffffc) << (uRam020c6928 & 3) * -8 + 0x20) + 0xe0;
  uVar6 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  local_3c[0] = ((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + 0x80) * 0x1000;
  local_3c[1] = 0xc000;
  sVar2 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                           0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,(ushort *)(uintptr_t)(uVar3),0,(uint)(uintptr_t)(local_3c),0,1);
  uVar6 = uRam020c6928;
  psVar7 = (short *)(param_1 + 0x400);
  uVar5 = 0;
  *psVar7 = *psVar7 + sVar2;
  do {
    uVar3 = GetB3C4_Cell_RaceNewRecordTaS(uVar5 + 1);
    iVar8 = uVar5 * 0x18 + 0x28;
    uVar4 = (*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
            *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0xe0;
    uVar1 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    local_30 = iVar8 * 0x1000;
    local_3c[2] = (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) << 0xc;
    sVar2 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                             0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,(ushort *)(uintptr_t)(uVar3),0,(uint)(uintptr_t)(local_3c + 2),0,1);
    *psVar7 = *psVar7 + sVar2;
    uVar4 = (*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
            *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0xe0;
    uVar1 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    StructRA_SomeFn_5(param_1,uVar5,uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20,iVar8);
    uVar5 = uVar5 + 1 & 0xffff;
  } while (uVar5 < 5);
  uVar3 = GetB3C4_Cell_RaceNewRecordTaS(6);
  uVar6 = (*(uint *)(uRam020c6928 & 0xfffffffc) >> (uRam020c6928 & 3) * 8 |
          *(uint *)(uRam020c6928 & 0xfffffffc) << (uRam020c6928 & 3) * -8 + 0x20) + 0xe0;
  uVar4 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  local_2c[0] = (uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) << 0xc;
  local_2c[1] = 0x9f000;
  sVar2 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                           0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,(ushort *)(uintptr_t)(uVar3),0,(uint)(uintptr_t)(local_2c),0,1);
  uVar4 = uRam020c6928;
  *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar2;
  uVar6 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar6 = (uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) + 0xe0;
  uVar4 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  StructRA_SomeFn_5(param_1,uVar5,(uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) + 1,0xb4);
  return;
}

