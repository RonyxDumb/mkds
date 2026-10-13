/* Decompiled C draft; module arm9; ROM address 020ee2e4. No matching claim. */
#include "types.h"
#include "deps/020ee2e4_func_020ee2e4.h"

void func_020ee2e4(uint *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  code *pcVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  code *pcVar11;
  
  uVar8 = *(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
          *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20;
  iVar6 = uVar8 * 0x1c;
  uVar4 = *(uint *)(uRam020ee518 & 0xfffffffc) >> (uRam020ee518 & 3) * 8 |
          *(uint *)(uRam020ee518 & 0xfffffffc) << (uRam020ee518 & 3) * -8 + 0x20;
  uVar9 = (*(uint *)(uRam020ee514 & 0xfffffffc) >> (uRam020ee514 & 3) * 8 |
          *(uint *)(uRam020ee514 & 0xfffffffc) << (uRam020ee514 & 3) * -8 + 0x20) + 8;
  uVar2 = uVar9 & 3;
  uVar5 = *(uint *)(uVar9 & 0xfffffffc);
  uVar10 = param_2 + 0xc & 3;
  uVar1 = *(uint *)(param_2 + 0xc & 0xfffffffc);
  uVar9 = uVar4 + iVar6 + 0x14;
  uVar3 = uVar9 & 3;
  uVar9 = *(uint *)(uVar9 & 0xfffffffc);
  uVar9 = uVar9 >> uVar3 * 8 | uVar9 << uVar3 * -8 + 0x20;
  if ((uVar1 >> uVar10 * 8 != 0 || uVar1 << uVar10 * -8 + 0x20 != 0) &&
     (*(short *)(param_2 + 0x12) < *(short *)(param_2 + 0x10))) {
    return;
  }
  uVar10 = iRam020ee51c + uVar9 * 4;
  uVar3 = uVar10 & 3;
  uVar10 = *(uint *)(uVar10 & 0xfffffffc);
  pcVar11 = (code *)(uVar10 >> uVar3 * 8 | uVar10 << uVar3 * -8 + 0x20);
  uVar10 = uVar4 + iVar6 + 0x18;
  uVar3 = uVar10 & 3;
  uVar10 = *(uint *)(uVar10 & 0xfffffffc);
  pcVar7 = (code *)(uVar10 >> uVar3 * 8 | uVar10 << uVar3 * -8 + 0x20);
  if ((uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) != 5) {
    uVar2 = param_2 + 8 & 3;
    uVar10 = *(uint *)(param_2 + 8 & 0xfffffffc);
    func_020be8e4((short)param_1[10],uVar8,uVar10 >> uVar2 * 8 | uVar10 << uVar2 * -8 + 0x20);
  }
  uVar2 = uRam020ee518;
  if (uVar9 != 0) {
    uVar10 = (*(uint *)(uRam020ee518 & 0xfffffffc) >> (uRam020ee518 & 3) * 8 |
             *(uint *)(uRam020ee518 & 0xfffffffc) << (uRam020ee518 & 3) * -8 + 0x20) + iVar6 + 8;
    uVar3 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    *param_1 = uVar10 >> uVar3 * 8 | uVar10 << uVar3 * -8 + 0x20;
    uVar10 = (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
             *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + iVar6 + 0xc;
    uVar3 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    param_1[8] = uVar10 >> uVar3 * 8 | uVar10 << uVar3 * -8 + 0x20;
    param_1[2] = uVar9;
    param_1[1] = uVar8;
    param_1[0x5c] = 0;
    uVar10 = uRam020ee520;
    uVar9 = (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
            *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + iVar6 + 8;
    uVar2 = uVar9 & 3;
    uVar3 = *(uint *)(uVar9 & 0xfffffffc);
    uVar9 = uRam020ee524;
    if ((uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) == 8) {
      uVar9 = 0xb400;
    }
    param_1[0x3a] = uVar9;
    uVar3 = uVar10 & 3;
    uVar4 = *(uint *)(uVar10 & 0xfffffffc);
    uVar9 = (uint)(param_1 + 4) & 3;
    uVar10 = *(uint *)((uint)(param_1 + 4) & 0xfffffffc);
    uVar2 = (uint)(param_1 + 8) & 3;
    uVar1 = *(uint *)((uint)(param_1 + 8) & 0xfffffffc);
    func_020f1048((*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                  *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) * 0x44 +
                  (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20),
                  uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20,param_1 + 5,
                  *(undefined2 *)((uVar10 >> uVar9 * 8 | uVar10 << uVar9 * -8 + 0x20) + 0x74));
    func_020ee528((int)(uintptr_t)(param_1));
    if (pcVar11 != (code *)0x0) {
      (*pcVar11)(param_1);
    }
    if (pcVar7 != (code *)0x0) {
      (*pcVar7)(param_1,param_2);
    }
    uVar9 = (uint)(param_1 + 4) & 3;
    uVar2 = *(uint *)((uint)(param_1 + 4) & 0xfffffffc);
    StructMQRacerEntry_SomeFn_87(uVar2 >> uVar9 * 8 | uVar2 << uVar9 * -8 + 0x20);
    func_020f4718((undefined4 *)(uintptr_t)(param_2));
    uVar9 = (uint)(param_1 + 0x5c) & 3;
    uVar2 = *(uint *)((uint)(param_1 + 0x5c) & 0xfffffffc);
    if (uVar2 >> uVar9 * 8 != 0 || uVar2 << uVar9 * -8 + 0x20 != 0) {
      uVar9 = (uint)(param_1 + 3) & 3;
      uVar10 = *(uint *)((uint)(param_1 + 3) & 0xfffffffc);
      uVar2 = (uint)(param_1 + 1) & 3;
      uVar3 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
      func_020f81b8(uVar10 >> uVar9 * 8 | uVar10 << uVar9 * -8 + 0x20,
                    uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20);
    }
    uVar9 = (uint)(param_1 + 4) & 3;
    uVar10 = *(uint *)((uint)(param_1 + 4) & 0xfffffffc);
    uVar2 = (uint)(param_1 + 8) & 3;
    uVar3 = *(uint *)((uint)(param_1 + 8) & 0xfffffffc);
    uVar3 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
    uVar9 = (uVar10 >> uVar9 * 8 | uVar10 << uVar9 * -8 + 0x20) + 0x590;
    uVar2 = uVar9 & 3;
    uVar9 = *(uint *)(uVar9 & 0xfffffffc);
    iVar6 = 0;
    if (0 < (int)uVar3) {
      do {
        uVar10 = (uint)(param_1 + iVar6 + 5) & 3;
        uVar1 = *(uint *)((uint)(param_1 + iVar6 + 5) & 0xfffffffc);
        uVar8 = uVar1 >> uVar10 * 8 | uVar1 << uVar10 * -8 + 0x20;
        *(undefined4 *)(uVar8 + 0x11c) = 0;
        *(undefined4 *)(uVar8 + 0xe4) = *(undefined4 *)(uVar8 + 0x50);
        *(undefined4 *)(uVar8 + 0xe8) = *(undefined4 *)(uVar8 + 0x54);
        *(undefined4 *)(uVar8 + 0xec) = *(undefined4 *)(uVar8 + 0x58);
        uVar10 = param_1[0x18];
        uVar1 = param_1[0x19];
        *(uint *)(uVar8 + 0x5c) = param_1[0x17];
        *(uint *)(uVar8 + 0x60) = uVar10;
        *(uint *)(uVar8 + 100) = uVar1;
        uVar10 = (uint)(param_1 + 0x21) & 3;
        uVar4 = *(uint *)((uint)(param_1 + 0x21) & 0xfffffffc);
        uVar1 = (uint)(param_1 + 0x22) & 3;
        uVar5 = *(uint *)((uint)(param_1 + 0x22) & 0xfffffffc);
        func_020f9f08(uVar8,uVar4 >> uVar10 * 8 | uVar4 << uVar10 * -8 + 0x20,
                      uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20);
        *(uint *)(uVar8 + 0x90) = (uVar9 >> uVar2 * 8 | uVar9 << uVar2 * -8 + 0x20) + 0x40;
        uVar10 = uVar8 + 0x74 & 3;
        uVar1 = *(uint *)(uVar8 + 0x74 & 0xfffffffc);
        iVar6 = iVar6 + 1;
        *(uint *)(uVar8 + 0x74) = uVar1 >> uVar10 * 8 | uVar1 << uVar10 * -8 + 0x20 | 0x1000;
      } while (iVar6 < (int)uVar3);
      return;
    }
    return;
  }
  if (pcVar11 != (code *)0x0) {
    (*pcVar11)(param_1);
  }
  if (pcVar7 != (code *)0x0) {
    (*pcVar7)(param_1,param_2);
  }
  uVar9 = (uint)(param_1 + 4) & 3;
  uVar2 = *(uint *)((uint)(param_1 + 4) & 0xfffffffc);
  DriverContext_SomeFn_0(uVar2 >> uVar9 * 8 | uVar2 << uVar9 * -8 + 0x20);
  return;
}

