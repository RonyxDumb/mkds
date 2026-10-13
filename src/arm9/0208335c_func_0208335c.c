/* Decompiled C draft; module arm9; ROM address 0208335c. No matching claim. */
#include "types.h"
#include "deps/0208335c_func_0208335c.h"

void func_0208335c(int param_1,int param_2)

{
  char cVar1;
  byte bVar2;
  undefined2 uVar3;
  byte bVar4;
  int iVar5;
  uint uVar6;
  uint *puVar7;
  uint uVar8;
  int iVar9;
  char cVar10;
  uint uVar11;
  uint uVar12;
  
  if (param_2 == 0) {
    uVar12 = param_1 + 0x94U & 3;
    uVar11 = *(uint *)(param_1 + 0x94U & 0xfffffffc);
    uVar12 = uVar11 >> uVar12 * 8 | uVar11 << uVar12 * -8 + 0x20;
    iVar9 = (uint)*(ushort *)(uVar12 + 0x74) * 0x58 +
            (*(uint *)(uRam0208347c & 0xfffffffc) >> (uRam0208347c & 3) * 8 |
            *(uint *)(uRam0208347c & 0xfffffffc) << (uRam0208347c & 3) * -8 + 0x20);
    cVar10 = *(char *)(param_1 + 0x9a);
    cVar1 = *(char *)(param_1 + 0x99);
    bVar2 = *(byte *)(param_1 + 0x9b);
    bVar4 = 1;
    iVar5 = StructMQRacerEntry_SomeFn_51(uVar12);
    if ((iVar5 == 0) &&
       (uVar11 = uVar12 + 0x2a4 & 3, uVar12 = *(uint *)(uVar12 + 0x2a4 & 0xfffffffc),
       iRam02083480 <= (int)(uVar12 >> uVar11 * 8 | uVar12 << uVar11 * -8 + 0x20))) {
      bVar4 = 0;
    }
    uVar12 = param_1 + 0x24U & 3;
    uVar11 = *(uint *)(param_1 + 0x24U & 0xfffffffc);
    *(uint *)(param_1 + 0x24) =
         (uVar11 >> uVar12 * 8 | uVar11 << uVar12 * -8 + 0x20) & 0xfffffffd | (uint)bVar4 << 1;
    puVar7 = (uint *)(param_1 + 0x24);
    if ((cVar1 != '\0') && (cVar10 = cVar10 + '\x01', cVar10 == '\n')) {
      *puVar7 = (*(uint *)((uint)puVar7 & 0xfffffffc) >> ((uint)puVar7 & 3) * 8 |
                *(uint *)((uint)puVar7 & 0xfffffffc) << ((uint)puVar7 & 3) * -8 + 0x20) & 0xfffffffe
                | 1;
    }
    iVar5 = (uint)bVar2 * 6 + iVar9;
    *(char *)(param_1 + 0x9a) = cVar10;
    uVar3 = *(undefined2 *)(iVar5 + 0x4e);
    iVar9 = (uint)bVar2 * 0xc + iVar9;
    *(undefined2 *)(param_1 + 0x50) = *(undefined2 *)(iVar5 + 0x4c);
    *(undefined2 *)(param_1 + 0x52) = uVar3;
    *(undefined2 *)(param_1 + 0x54) = *(undefined2 *)(iVar5 + 0x50);
    uVar12 = param_1 + 0x20U & 3;
    uVar11 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
    uVar6 = uVar11 >> uVar12 * 8 | uVar11 << uVar12 * -8 + 0x20;
    uVar11 = iVar9 + 0x34U & 3;
    uVar8 = *(uint *)(iVar9 + 0x34U & 0xfffffffc);
    uVar12 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    uVar12 = (uVar6 >> uVar12 * 8 | uVar6 << uVar12 * -8 + 0x20) + 4;
    uVar6 = uVar12 & 3;
    uVar12 = *(uint *)(uVar12 & 0xfffffffc);
    *(uint *)(param_1 + 0x28) =
         (uVar8 >> uVar11 * 8 | uVar8 << uVar11 * -8 + 0x20) +
         (uVar12 >> uVar6 * 8 | uVar12 << uVar6 * -8 + 0x20);
    uVar12 = param_1 + 0x20U & 3;
    uVar11 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
    uVar6 = uVar11 >> uVar12 * 8 | uVar11 << uVar12 * -8 + 0x20;
    uVar11 = iVar9 + 0x38U & 3;
    uVar8 = *(uint *)(iVar9 + 0x38U & 0xfffffffc);
    uVar12 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    uVar12 = (uVar6 >> uVar12 * 8 | uVar6 << uVar12 * -8 + 0x20) + 8;
    uVar6 = uVar12 & 3;
    uVar12 = *(uint *)(uVar12 & 0xfffffffc);
    *(uint *)(param_1 + 0x2c) =
         (uVar8 >> uVar11 * 8 | uVar8 << uVar11 * -8 + 0x20) +
         (uVar12 >> uVar6 * 8 | uVar12 << uVar6 * -8 + 0x20);
    uVar12 = param_1 + 0x20U & 3;
    uVar11 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
    uVar6 = uVar11 >> uVar12 * 8 | uVar11 << uVar12 * -8 + 0x20;
    uVar11 = iVar9 + 0x3cU & 3;
    uVar8 = *(uint *)(iVar9 + 0x3cU & 0xfffffffc);
    uVar12 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    uVar12 = (uVar6 >> uVar12 * 8 | uVar6 << uVar12 * -8 + 0x20) + 0xc;
    uVar6 = uVar12 & 3;
    uVar12 = *(uint *)(uVar12 & 0xfffffffc);
    *(uint *)(param_1 + 0x30) =
         (uVar8 >> uVar11 * 8 | uVar8 << uVar11 * -8 + 0x20) +
         (uVar12 >> uVar6 * 8 | uVar12 << uVar6 * -8 + 0x20);
    return;
  }
  return;
}

