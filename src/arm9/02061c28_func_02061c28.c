/* Decompiled C draft; module arm9; ROM address 02061c28. No matching claim. */
#include "types.h"
#include "deps/02061c28_func_02061c28.h"

void func_02061c28(void)

{
  char cVar1;
  ushort uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined2 *puVar5;
  int iVar6;
  ushort *puVar7;
  uint *puVar8;
  uint *puVar9;
  int *piVar10;
  ushort *puVar11;
  ushort *puVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar17;
  int iVar18;
  uint local_98 [33];
  uint uVar16;
  
  func_02061944(0x48,1);
  puVar5 = puRam02061f4c;
  puVar4 = puRam02061f48;
  puVar3 = puRam02061f44;
  uVar15 = uRam02061f3c;
  uVar13 = 0;
  uVar14 = uRam02061f3c & 3;
  uVar17 = *(uint *)(uRam02061f3c & 0xfffffffc);
  *puRam02061f40 = 0x48;
  *puVar3 = 0;
  *puVar4 = 0;
  *puVar5 = 0;
  *(undefined4 *)((uVar17 >> uVar14 * 8 | uVar17 << uVar14 * -8 + 0x20) + 0x24) = 0;
  uVar17 = uRam02061f50;
  uVar14 = uVar15 & 3;
  uVar15 = *(uint *)(uVar15 & 0xfffffffc);
  uVar16 = uVar15 >> uVar14 * 8 | uVar15 << uVar14 * -8 + 0x20;
  uVar14 = uVar16 + 0x24;
  uVar15 = uVar14 & 3;
  uVar14 = *(uint *)(uVar14 & 0xfffffffc);
  *(uint *)(uVar16 + 0x20) = uVar14 >> uVar15 * 8 | uVar14 << uVar15 * -8 + 0x20;
  iVar6 = iRam02061f54;
  uVar14 = uVar17 & 3;
  uVar15 = *(uint *)(uVar17 & 0xfffffffc);
  uVar15 = uVar15 >> uVar14 * 8 | uVar15 << uVar14 * -8 + 0x20;
  uVar14 = uVar15 + 0x18;
  uVar17 = uVar14 & 3;
  uVar14 = *(uint *)(uVar14 & 0xfffffffc);
  uVar14 = uVar14 >> uVar17 * 8 | uVar14 << uVar17 * -8 + 0x20;
  if (*(char *)(uVar14 + 5) != '\0') {
    cVar1 = *(char *)(uVar14 + 6);
    if (cVar1 == '\0') {
      do {
        uVar14 = uVar13 * 0x10;
        *(uint *)(iVar6 + uVar13 * 4) =
             uVar14 | (uVar14 + 4) * 0x100 | (uVar14 + 8) * 0x10000 | (uVar14 + 0xc) * 0x1000000;
        uVar13 = uVar13 + 1 & 0xffff;
      } while (uVar13 < 8);
    }
    else if (cVar1 == '\x01') {
      do {
        iVar18 = (uVar13 + 1) * (uVar13 + 1);
        local_98[uVar13] = (int)(iVar18 + ((uint)(iVar18 >> 2) >> 0x1d)) >> 3;
        uVar14 = uVar13 + 1 & 0xffff;
        if (0x7f < local_98[uVar13]) {
          local_98[uVar13] = 0x7f;
        }
        uVar13 = uVar14;
      } while (uVar14 < 0x20);
      uVar13 = 0;
      local_98[0] = 0;
      do {
        iVar18 = uVar13 * 4;
        *(uint *)(iVar6 + uVar13 * 4) =
             local_98[uVar13 * 4] | local_98[iVar18 + 1] << 8 | local_98[iVar18 + 2] << 0x10 |
             local_98[iVar18 + 3] << 0x18;
        uVar13 = uVar13 + 1 & 0xffff;
      } while (uVar13 < 8);
    }
    else if (cVar1 == '\x02') {
      do {
        iVar18 = 0x20 - (uVar13 + 1);
        iVar18 = iVar18 * iVar18;
        local_98[uVar13] = 0x80 - ((int)(iVar18 + ((uint)(iVar18 >> 2) >> 0x1d)) >> 3);
        uVar14 = uVar13 + 1 & 0xffff;
        if (0x7f < local_98[uVar13]) {
          local_98[uVar13] = 0x7f;
        }
        uVar13 = uVar14;
      } while (uVar14 < 0x20);
      uVar13 = 0;
      local_98[0] = 0;
      do {
        iVar18 = uVar13 * 4;
        *(uint *)(iVar6 + uVar13 * 4) =
             local_98[uVar13 * 4] | local_98[iVar18 + 1] << 8 | local_98[iVar18 + 2] << 0x10 |
             local_98[iVar18 + 3] << 0x18;
        uVar13 = uVar13 + 1 & 0xffff;
      } while (uVar13 < 8);
    }
    puVar9 = puRam02061f64;
    puVar8 = puRam02061f60;
    puVar7 = puRam02061f5c;
    uVar17 = *(uint *)(uRam02061f50 & 0xfffffffc) >> (uRam02061f50 & 3) * 8 |
             *(uint *)(uRam02061f50 & 0xfffffffc) << (uRam02061f50 & 3) * -8 + 0x20;
    uVar13 = uVar17 + 0x18 & 3;
    uVar14 = *(uint *)(uVar17 + 0x18 & 0xfffffffc);
    uVar13 = (uVar14 >> uVar13 * 8 | uVar14 << uVar13 * -8 + 0x20) + 0x14;
    uVar14 = uVar13 & 3;
    uVar13 = *(uint *)(uVar13 & 0xfffffffc);
    *puRam02061f5c =
         (ushort)uRam02061f58 &
         ((ushort)(uVar13 >> uVar14 * 8) | (ushort)(uVar13 << uVar14 * -8 + 0x20));
    piVar10 = piRam02061f68;
    uVar13 = uVar17 + 0x18 & 3;
    uVar14 = *(uint *)(uVar17 + 0x18 & 0xfffffffc);
    uVar2 = *puVar7;
    uVar13 = (uVar14 >> uVar13 * 8 | uVar14 << uVar13 * -8 + 0x20) + 0x14;
    uVar14 = uVar13 & 3;
    uVar13 = *(uint *)(uVar13 & 0xfffffffc);
    *puVar8 = (uVar13 >> uVar14 * 8 | uVar13 << uVar14 * -8 + 0x20) >> 0xf & 0x1f;
    puVar7 = puRam02061f6c;
    uVar13 = uVar17 + 0x18 & 3;
    uVar14 = *(uint *)(uVar17 + 0x18 & 0xfffffffc);
    *puVar9 = (uint)*(byte *)((uVar14 >> uVar13 * 8 | uVar14 << uVar13 * -8 + 0x20) + 7);
    puVar12 = puRam02061f74;
    puVar11 = puRam02061f70;
    uVar13 = uVar17 + 0x18 & 3;
    uVar14 = *(uint *)(uVar17 + 0x18 & 0xfffffffc);
    uVar13 = (uVar14 >> uVar13 * 8 | uVar14 << uVar13 * -8 + 0x20) + 0x10;
    uVar14 = uVar13 & 3;
    uVar13 = *(uint *)(uVar13 & 0xfffffffc);
    uVar13 = uVar13 >> uVar14 * 8 | uVar13 << uVar14 * -8 + 0x20;
    *piVar10 = (int)(uVar13 + ((uint)((int)uVar13 >> 8) >> 0x17)) >> 9;
    *puVar7 = uVar2 & 0x1f;
    *puVar11 = (ushort)((int)(uint)uVar2 >> 5) & 0x1f;
    *puVar12 = (ushort)((int)(uint)uVar2 >> 10) & 0x1f;
  }
  uVar15 = uVar15 + 0x18;
  uVar13 = uVar15 & 3;
  uVar14 = *(uint *)(uVar15 & 0xfffffffc);
  if (*(char *)((uVar14 >> uVar13 * 8 | uVar14 << uVar13 * -8 + 0x20) + 5) == '\0') {
    G3X_SetFog(0,0,5,0);
    return;
  }
  G3X_SetFog(1,0,*(uint *)((uint)puRam02061f64 & 0xfffffffc) >> ((uint)puRam02061f64 & 3) * 8 |
                 *(uint *)((uint)puRam02061f64 & 0xfffffffc) <<
                 ((uint)puRam02061f64 & 3) * -8 + 0x20,
             *(uint *)((uint)piRam02061f68 & 0xfffffffc) >> ((uint)piRam02061f68 & 3) * 8 |
             *(uint *)((uint)piRam02061f68 & 0xfffffffc) << ((uint)piRam02061f68 & 3) * -8 + 0x20);
  iVar6 = iRam02061f54;
  *puRam02061f78 =
       (uint)*puRam02061f5c |
       (*(uint *)((uint)puRam02061f60 & 0xfffffffc) >> ((uint)puRam02061f60 & 3) * 8 |
       *(uint *)((uint)puRam02061f60 & 0xfffffffc) << ((uint)puRam02061f60 & 3) * -8 + 0x20) << 0x10
  ;
  G3X_SetFogTable(iVar6);
  return;
}

