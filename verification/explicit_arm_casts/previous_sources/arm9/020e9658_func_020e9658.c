/* Decompiled C draft; module arm9; ROM address 020e9658. No matching claim. */
#include "types.h"
#include "deps/020e9658_func_020e9658.h"

void func_020e9658(void)

{
  undefined4 *puVar1;
  longlong lVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  uint uVar8;
  undefined4 uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  undefined4 *puVar15;
  
  puVar3 = puRam020e97e8;
  puVar1 = puRam020e97e4;
  uVar6 = puRam020e97e4[1];
  uVar7 = puRam020e97e4[2];
  uVar9 = puRam020e97e4[3];
  puVar15 = puRam020e97e4 + 4;
  *puRam020e97e8 = *puRam020e97e4;
  puVar3[1] = uVar6;
  puVar3[2] = uVar7;
  puVar3[3] = uVar9;
  uVar6 = puVar1[5];
  uVar7 = puVar1[6];
  uVar9 = puVar1[7];
  puVar3[4] = *puVar15;
  puVar3[5] = uVar6;
  puVar3[6] = uVar7;
  puVar3[7] = uVar9;
  uVar6 = puVar1[9];
  uVar7 = puVar1[10];
  uVar9 = puVar1[0xb];
  puVar3[8] = puVar1[8];
  puVar3[9] = uVar6;
  puVar3[10] = uVar7;
  puVar3[0xb] = uVar9;
  VecFx32_Subtract(puRam020e97ec,puRam020e97f0,uRam020e97f4);
  puVar4 = puRam020e9804;
  puVar15 = puRam020e9800;
  puVar3 = puRam020e97fc;
  puVar1 = puRam020e97f0;
  uVar10 = *(uint *)(uRam020e97f8 & 0xfffffffc) >> (uRam020e97f8 & 3) * 8 |
           *(uint *)(uRam020e97f8 & 0xfffffffc) << (uRam020e97f8 & 3) * -8 + 0x20;
  uVar6 = puRam020e97ec[1];
  uVar7 = puRam020e97ec[2];
  *puRam020e97f0 = *puRam020e97ec;
  puVar1[1] = uVar6;
  puVar1[2] = uVar7;
  puVar1 = puVar3 + 10;
  uVar8 = (uint)puVar1 & 3;
  uVar12 = *(uint *)((uint)puVar1 & 0xfffffffc);
  uVar13 = uVar10 + 0xa8;
  uVar14 = uVar13 & 3;
  uVar11 = *(uint *)(uVar13 & 0xfffffffc);
  uVar10 = uVar10 + 0x2b8;
  uVar13 = uVar10 & 3;
  uVar10 = *(uint *)(uVar10 & 0xfffffffc);
  uVar6 = *puVar15;
  uVar7 = puVar15[1];
  uVar9 = puVar15[2];
  puVar3[10] = (uVar12 >> uVar8 * 8 | uVar12 << uVar8 * -8 + 0x20) +
               ((uVar11 >> uVar14 * 8 | uVar11 << uVar14 * -8 + 0x20) -
               (uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20));
  *puVar4 = uVar6;
  puVar4[1] = uVar7;
  puVar4[2] = uVar9;
  iVar5 = func_0203c5e4();
  puVar1 = puRam020e97fc;
  if (iVar5 == 0) {
    iVar5 = func_020e6b38();
    puVar1 = puRam020e9808;
    uVar6 = *(undefined4 *)(iVar5 + 0x1c);
    uVar7 = *(undefined4 *)(iVar5 + 0x20);
    *puRam020e9808 = *(undefined4 *)(iVar5 + 0x18);
    puVar1[1] = uVar6;
    puVar1[2] = uVar7;
  }
  else {
    uVar8 = *(uint *)(uRam020e97f8 & 0xfffffffc) >> (uRam020e97f8 & 3) * 8 |
            *(uint *)(uRam020e97f8 & 0xfffffffc) << (uRam020e97f8 & 3) * -8 + 0x20;
    uVar13 = uVar8 + 0x50 & 3;
    uVar10 = *(uint *)(uVar8 + 0x50 & 0xfffffffc);
    puRam020e97fc[6] = -(uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20);
    uVar13 = uVar8 + 0x54 & 3;
    uVar10 = *(uint *)(uVar8 + 0x54 & 0xfffffffc);
    puVar1[7] = -(uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20);
    uVar13 = uVar8 + 0x58 & 3;
    uVar10 = *(uint *)(uVar8 + 0x58 & 0xfffffffc);
    puVar1[8] = -(uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20);
  }
  Vector3_Cross(puRam020e9804,puRam020e9808,puRam020e9808);
  uVar13 = (uint)(puRam020e97fc + 7) & 3;
  uVar10 = *(uint *)((uint)(puRam020e97fc + 7) & 0xfffffffc);
  uVar14 = uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20;
  uVar13 = (uint)(puRam020e97fc + 6) & 3;
  uVar10 = *(uint *)((uint)(puRam020e97fc + 6) & 0xfffffffc);
  uVar10 = uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20;
  uVar13 = (uint)(puRam020e97fc + 8) & 3;
  uVar8 = *(uint *)((uint)(puRam020e97fc + 8) & 0xfffffffc);
  uVar13 = uVar8 >> uVar13 * 8 | uVar8 << uVar13 * -8 + 0x20;
  iVar5 = 0;
  lVar2 = (longlong)(int)uVar13 * (longlong)(int)uVar13 +
          (longlong)(int)uVar10 * (longlong)(int)uVar10 +
          (longlong)(int)uVar14 * (longlong)(int)uVar14;
  if ((int)(uint)((uint)lVar2 < 0x10) <= (int)((ulonglong)lVar2 >> 0x20)) {
    iVar5 = Vector3_MaybeNormalize(puRam020e9808,puRam020e9808);
  }
  puVar1 = puRam020e97fc;
  if (iVar5 != 0) {
    uVar6 = puRam020e9808[1];
    uVar7 = puRam020e9808[2];
    *puRam020e97fc = *puRam020e9808;
    puVar1[1] = uVar6;
    puVar1[2] = uVar7;
  }
  Vector3_Cross(puRam020e97fc,puRam020e9804,puRam020e9808);
  func_02146d0c(puRam020e97fc,puRam020e97e4);
  MTX_MultVec33(puRam020e97f0,puRam020e97e4,uRam020e980c);
  puVar1 = puRam020e97e4;
  uVar13 = (uint)(puRam020e97e4 + 9) & 3;
  uVar12 = *(uint *)((uint)(puRam020e97e4 + 9) & 0xfffffffc);
  uVar10 = (uint)(puRam020e97e4 + 10) & 3;
  uVar11 = *(uint *)((uint)(puRam020e97e4 + 10) & 0xfffffffc);
  uVar8 = (uint)(puRam020e97e4 + 0xb) & 3;
  uVar14 = *(uint *)((uint)(puRam020e97e4 + 0xb) & 0xfffffffc);
  puRam020e97e4[9] = -(uVar12 >> uVar13 * 8 | uVar12 << uVar13 * -8 + 0x20);
  puVar1[10] = -(uVar11 >> uVar10 * 8 | uVar11 << uVar10 * -8 + 0x20);
  puVar1[0xb] = -(uVar14 >> uVar8 * 8 | uVar14 << uVar8 * -8 + 0x20);
  return;
}

