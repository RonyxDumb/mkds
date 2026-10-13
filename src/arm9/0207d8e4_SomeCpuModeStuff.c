/* Decompiled C draft; module arm9; ROM address 0207d8e4. No matching claim. */
#include "types.h"
#include "deps/0207d8e4_SomeCpuModeStuff.h"

undefined2 SomeCpuModeStuff(int param_1)

{
  longlong lVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar10;
  undefined2 *puVar11;
  uint uVar12;
  uint uVar14;
  undefined2 local_28;
  undefined2 local_26;
  undefined2 local_24;
  undefined2 local_22;
  undefined2 local_20;
  undefined2 local_1e;
  undefined2 local_1c;
  undefined2 local_1a;
  undefined2 local_18;
  uint uVar9;
  uint uVar13;
  
  local_1e = puRam0207d9e4[2];
  local_28 = *puRam0207d9e0;
  local_26 = puRam0207d9e0[1];
  local_24 = puRam0207d9e0[2];
  local_22 = *puRam0207d9e4;
  local_20 = puRam0207d9e4[1];
  local_1c = *puRam0207d9e8;
  local_1a = puRam0207d9e8[1];
  local_18 = puRam0207d9e8[2];
  if (param_1 == 0) {
    piVar2 = (int *)func_0208537c();
    uVar3 = (uint)(piVar2 + 2) & 3;
    uVar8 = *(uint *)((uint)(piVar2 + 2) & 0xfffffffc);
    uVar9 = uVar8 >> uVar3 * 8 | uVar8 << uVar3 * -8 + 0x20;
    uVar7 = *(uint *)((uint)piVar2 & 0xfffffffc) >> ((uint)piVar2 & 3) * 8 |
            *(uint *)((uint)piVar2 & 0xfffffffc) << ((uint)piVar2 & 3) * -8 + 0x20;
    uVar3 = (uint)(piVar2 + 1) & 3;
    uVar5 = *(uint *)((uint)(piVar2 + 1) & 0xfffffffc);
    lVar1 = (ulonglong)uVar7 * (ulonglong)uVar9;
    uVar14 = (uint)lVar1;
    uVar8 = (uint)(piVar2 + 4) & 3;
    uVar12 = *(uint *)((uint)(piVar2 + 4) & 0xfffffffc);
    uVar13 = uVar12 >> uVar8 * 8 | uVar12 << uVar8 * -8 + 0x20;
    uVar8 = (uint)(piVar2 + 3) & 3;
    uVar6 = *(uint *)((uint)(piVar2 + 3) & 0xfffffffc);
    uVar12 = (uint)(piVar2 + 5) & 3;
    uVar10 = *(uint *)((uint)(piVar2 + 5) & 0xfffffffc);
    *piVar2 = uVar13 + uVar14;
    piVar2[1] = (uVar10 >> uVar12 * 8 | uVar10 << uVar12 * -8 + 0x20) +
                (uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20) * uVar7 +
                uVar9 * (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) +
                (int)((ulonglong)lVar1 >> 0x20) + (uint)CARRY4(uVar13,uVar14);
    uVar3 = (uint)(piVar2 + 1) & 3;
    uVar8 = *(uint *)((uint)(piVar2 + 1) & 0xfffffffc);
    iVar4 = (int)((ulonglong)(uVar8 >> uVar3 * 8 | uVar8 << uVar3 * -8 + 0x20) * 3 >> 0x20);
  }
  else {
    iVar4 = 2;
  }
  uVar3 = (*(uint *)(uRam0207d9ec & 0xfffffffc) >> (uRam0207d9ec & 3) * 8 |
          *(uint *)(uRam0207d9ec & 0xfffffffc) << (uRam0207d9ec & 3) * -8 + 0x20) + 0x14;
  uVar8 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20;
  puVar11 = &local_28;
  if ((uVar3 != 1) && (puVar11 = &local_1c, uVar3 == 2)) {
    puVar11 = &local_22;
  }
  return puVar11[iVar4];
}

