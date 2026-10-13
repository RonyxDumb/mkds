/* Decompiled C draft; module arm7; ROM address 06006228. No matching claim. */
#include "types.h"
#include "deps/06006228_FUN_06006228.h"

void FUN_06006228(void)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined2 *puVar4;
  uint uVar5;
  uint uVar6;
  uint uVar8;
  uint uVar9;
  bool bVar10;
  undefined8 uVar11;
  uint uVar7;
  
  iVar1 = FUN_06000680();
  uVar2 = iVar1 + 0x154cU & 3;
  uVar6 = *(uint *)(iVar1 + 0x154cU & 0xfffffffc);
  uVar7 = uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20;
  uVar2 = (*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
          *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + 0xc;
  uVar6 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20) == 1) {
    thunk_FUN_037fad34(uVar7 + 0xd0,200,DAT_0600634c,DAT_06006350,200);
    uVar6 = *(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
            *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20;
    uVar2 = uVar6 + 0x7b4;
    uVar9 = uVar2 & 3;
    uVar5 = *(uint *)(uVar2 & 0xfffffffc);
    uVar6 = uVar6 + 0x7b8;
    uVar2 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    if ((uVar6 >> uVar2 * 8 != 0 || uVar6 << uVar2 * -8 + 0x20 != 0) ||
        (uVar5 >> uVar9 * 8 != 0 || uVar5 << uVar9 * -8 + 0x20 != 0)) {
      uVar11 = thunk_FUN_037fa278();
      uVar5 = (uint)uVar11 | 1;
      uVar9 = *(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
              *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20;
      uVar2 = uVar9 + 0x734 & 3;
      uVar6 = *(uint *)(uVar9 + 0x734 & 0xfffffffc);
      uVar7 = uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20;
      uVar2 = uVar9 + 0x738 & 3;
      uVar6 = *(uint *)(uVar9 + 0x738 & 0xfffffffc);
      uVar2 = uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20;
      if (uVar2 != 0 || uVar7 != 0) {
        uVar8 = uVar5 - uVar7;
        uVar5 = (int)((ulonglong)uVar11 >> 0x20) - (uVar2 + (uVar5 < uVar7));
        uVar2 = uVar9 + 0x7b4 & 3;
        uVar6 = *(uint *)(uVar9 + 0x7b4 & 0xfffffffc);
        uVar7 = uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20;
        uVar2 = uVar9 + 0x7b8 & 3;
        uVar6 = *(uint *)(uVar9 + 0x7b8 & 0xfffffffc);
        uVar2 = uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20;
        bVar10 = uVar2 <= uVar5;
        if (uVar5 == uVar2) {
          bVar10 = uVar7 <= uVar8;
        }
        if (bVar10 && (uVar5 != uVar2 || uVar8 != uVar7)) {
          *(undefined4 *)(uVar9 + 0x734) = 0;
          *(undefined4 *)(uVar9 + 0x738) = 0;
          puVar3 = (undefined4 *)FUN_06000000();
          if (puVar3 == (undefined4 *)0x0) {
            iVar1 = 0;
          }
          else {
            *puVar3 = 0x25;
            puVar3[1] = 0;
            puVar3[2] = DAT_06006354;
            iVar1 = FUN_06000680();
            iVar1 = thunk_FUN_037f9854(iVar1 + 0x88,puVar3,0);
          }
          if (iVar1 != 0) {
            return;
          }
          puVar4 = (undefined2 *)thunk_FUN_03807424();
          *puVar4 = 0x80;
          puVar4[1] = 8;
          puVar4[2] = 0x16;
          puVar4[3] = 0x25;
          thunk_FUN_038074cc();
          return;
        }
      }
    }
    FUN_0600608c();
  }
  return;
}

