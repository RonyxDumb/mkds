/* Decompiled C draft; module arm9; ROM address 0207b734. No matching claim. */
#include "types.h"
#include "deps/0207b734_StructMQRacerEntry_SomeFn_20.h"

void StructMQRacerEntry_SomeFn_20(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar5;
  uint uVar6;
  bool bVar8;
  uint uVar4;
  uint uVar7;
  
  uVar2 = param_1 + 0x44U & 3;
  uVar1 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  uVar7 = param_1 + 0x590U & 3;
  uVar6 = *(uint *)(param_1 + 0x590U & 0xfffffffc);
  uVar7 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
  uVar2 = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 8;
  bVar8 = uVar2 != 0;
  puVar5 = (uint *)(uVar7 + 0x24);
  if (bVar8) {
    uVar2 = 0x2000;
  }
  uVar1 = param_1 + 0x48U & 3;
  uVar6 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  uVar1 = uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20;
  if (!bVar8) {
    uVar2 = 0x1000;
  }
  uVar6 = uVar7 + 8 & 3;
  uVar3 = *(uint *)(uVar7 + 8 & 0xfffffffc);
  uVar4 = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
  uVar6 = uVar7 + 0x2c & 3;
  uVar3 = *(uint *)(uVar7 + 0x2c & 0xfffffffc);
  uVar6 = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
  if ((uVar1 & 8) == 0) {
    if ((uVar1 & 0x10) == 0) {
      uVar1 = *(uint *)((uint)puVar5 & 0xfffffffc) >> ((uint)puVar5 & 3) * 8 |
              *(uint *)((uint)puVar5 & 0xfffffffc) << ((uint)puVar5 & 3) * -8 + 0x20;
      if (uVar1 != 0) {
        if ((int)uVar1 < 1) {
          *puVar5 = uVar1 + uVar2;
          if (0 < (int)(*(uint *)((uint)puVar5 & 0xfffffffc) >> ((uint)puVar5 & 3) * 8 |
                       *(uint *)((uint)puVar5 & 0xfffffffc) << ((uint)puVar5 & 3) * -8 + 0x20)) {
            *puVar5 = 0;
          }
        }
        else {
          *puVar5 = uVar1 - uVar2;
          if ((int)(*(uint *)((uint)puVar5 & 0xfffffffc) >> ((uint)puVar5 & 3) * 8 |
                   *(uint *)((uint)puVar5 & 0xfffffffc) << ((uint)puVar5 & 3) * -8 + 0x20) < 0) {
            *puVar5 = 0;
          }
        }
      }
    }
    else {
      uVar1 = (*(uint *)(uRam0207b8bc & 0xfffffffc) >> (uRam0207b8bc & 3) * 8 |
              *(uint *)(uRam0207b8bc & 0xfffffffc) << (uRam0207b8bc & 3) * -8 + 0x20) + 0xc;
      uVar3 = uVar1 & 3;
      uVar1 = *(uint *)(uVar1 & 0xfffffffc);
      if ((uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) != 6) {
        *puVar5 = (*(uint *)((uint)puVar5 & 0xfffffffc) >> ((uint)puVar5 & 3) * 8 |
                  *(uint *)((uint)puVar5 & 0xfffffffc) << ((uint)puVar5 & 3) * -8 + 0x20) - uVar2;
        uVar2 = *(uint *)((uint)puVar5 & 0xfffffffc) >> ((uint)puVar5 & 3) * 8 |
                *(uint *)((uint)puVar5 & 0xfffffffc) << ((uint)puVar5 & 3) * -8 + 0x20;
        if ((int)(uVar2 + uVar6) < 0 != SBORROW4(uVar2,-uVar6)) {
          *puVar5 = -uVar6;
        }
      }
    }
  }
  else {
    uVar1 = (*(uint *)(uRam0207b8bc & 0xfffffffc) >> (uRam0207b8bc & 3) * 8 |
            *(uint *)(uRam0207b8bc & 0xfffffffc) << (uRam0207b8bc & 3) * -8 + 0x20) + 0xc;
    uVar3 = uVar1 & 3;
    uVar1 = *(uint *)(uVar1 & 0xfffffffc);
    if (((uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) != 6) &&
       (*puVar5 = (*(uint *)((uint)puVar5 & 0xfffffffc) >> ((uint)puVar5 & 3) * 8 |
                  *(uint *)((uint)puVar5 & 0xfffffffc) << ((uint)puVar5 & 3) * -8 + 0x20) + uVar2,
       (int)uVar6 <
       (int)(*(uint *)((uint)puVar5 & 0xfffffffc) >> ((uint)puVar5 & 3) * 8 |
            *(uint *)((uint)puVar5 & 0xfffffffc) << ((uint)puVar5 & 3) * -8 + 0x20))) {
      *puVar5 = uVar6;
    }
  }
  if (*(short *)(uVar4 + 0x1a) == 0) {
    uVar2 = uVar7 + 0x2c & 3;
    uVar7 = *(uint *)(uVar7 + 0x2c & 0xfffffffc);
    *(uint *)(uVar4 + 0xc) =
         (*(uint *)((uint)puVar5 & 0xfffffffc) >> ((uint)puVar5 & 3) * 8 |
         *(uint *)((uint)puVar5 & 0xfffffffc) << ((uint)puVar5 & 3) * -8 + 0x20) +
         (uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20);
    Animation_UpdateBlend(uVar4);
    return;
  }
  Animation_Update(uVar4);
  uVar2 = uVar7 + 0x38 & 3;
  uVar1 = *(uint *)(uVar7 + 0x38 & 0xfffffffc);
  if (uVar1 >> uVar2 * 8 == 0 && uVar1 << uVar2 * -8 + 0x20 == 0) {
    return;
  }
  if (*(short *)(uVar4 + 2) != 1) {
    return;
  }
  Animation_SetLoop(uVar4,*(undefined2 *)(uVar4 + 0x1a),1);
  uVar2 = uVar7 + 8 & 3;
  uVar1 = *(uint *)(uVar7 + 8 & 0xfffffffc);
  Animation_SetWithBlendAt
            (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20,*(undefined2 *)(uVar7 + 0x3c));
  uVar2 = uVar7 + 0xc & 3;
  uVar1 = *(uint *)(uVar7 + 0xc & 0xfffffffc);
  uVar3 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  *(uint *)(uVar3 + 0xc) =
       *(uint *)(uRam0207b8c0 & 0xfffffffc) >> (uRam0207b8c0 & 3) * 8 |
       *(uint *)(uRam0207b8c0 & 0xfffffffc) << (uRam0207b8c0 & 3) * -8 + 0x20;
  uVar2 = uVar3 + 0x1c & 3;
  uVar6 = *(uint *)(uVar3 + 0x1c & 0xfffffffc);
  uVar1 = uVar3 + 0xc & 3;
  uVar4 = *(uint *)(uVar3 + 0xc & 0xfffffffc);
  uVar2 = (uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20) + (uint)*(ushort *)(uVar3 + 0x1a) * 4;
  uVar6 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  *(uint *)(uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20) =
       uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  *(undefined4 *)(uVar7 + 0x38) = 0;
  return;
}

