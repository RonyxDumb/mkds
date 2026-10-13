/* Decompiled C draft; module arm9; ROM address 0208afe4. No matching claim. */
#include "types.h"
#include "deps/0208afe4_func_0208afe4.h"

void func_0208afe4(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  byte bVar4;
  short sVar5;
  short sVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  short *psVar12;
  short *psVar13;
  uint uVar15;
  uint uVar16;
  short local_7c [2];
  undefined4 local_78;
  undefined4 local_74;
  short local_70 [24];
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  short *psVar14;
  
  uVar15 = uRam0208b18c;
  psVar12 = local_70;
  iVar10 = 0xc;
  psVar13 = psRam0208b180;
  do {
    psVar14 = psVar13 + 1;
    sVar5 = *psVar13;
    psVar13 = psVar13 + 2;
    sVar6 = *psVar14;
    iVar10 = iVar10 + -1;
    psVar14 = psVar12 + 1;
    *psVar12 = sVar5;
    psVar12 = psVar12 + 2;
    *psVar14 = sVar6;
  } while (iVar10 != 0);
  uVar16 = uRam0208b188 + 4 & 3;
  uVar11 = *(uint *)(uRam0208b188 + 4 & 0xfffffffc);
  uVar3 = uRam0208b188 + 8 & 3;
  uVar9 = *(uint *)(uRam0208b188 + 8 & 0xfffffffc);
  local_7c[0] = *psRam0208b184;
  local_7c[1] = psRam0208b184[1];
  iVar10 = (int)(*(uint *)(uRam0208b188 & 0xfffffffc) >> (uRam0208b188 & 3) * 8 |
                *(uint *)(uRam0208b188 & 0xfffffffc) << (uRam0208b188 & 3) * -8 + 0x20) >> 4;
  iVar1 = (int)(uVar11 >> uVar16 * 8 | uVar11 << uVar16 * -8 + 0x20) >> 4;
  iVar2 = (int)(uVar9 >> uVar3 * 8 | uVar9 << uVar3 * -8 + 0x20) >> 4;
  uVar16 = 0;
  do {
    uVar3 = uVar15 & 3;
    uVar9 = *(uint *)(uVar15 & 0xfffffffc);
    uVar7 = (*(code *)(uVar9 >> uVar3 * 8 | uVar9 << uVar3 * -8 + 0x20))
                      (&local_78,(int)local_7c[uVar16]);
    local_40 = iVar10;
    local_3c = iVar1;
    local_38 = iVar2;
    iVar8 = func_02018600(uVar7,local_78,(undefined4)(uintptr_t)(&local_40));
    if (iVar8 != 0) {
      uVar3 = iVar8 + 0x20U & 3;
      uVar9 = *(uint *)(iVar8 + 0x20U & 0xfffffffc);
      uVar9 = uVar9 >> uVar3 * 8 | uVar9 << uVar3 * -8 + 0x20;
      uVar3 = uVar9 & 3;
      uVar9 = *(uint *)(uVar9 & 0xfffffffc);
      bVar4 = *(byte *)((uVar9 >> uVar3 * 8 | uVar9 << uVar3 * -8 + 0x20) + 0x54);
      if ((bVar4 & 0x80) == 0) {
        if ((bVar4 & 0x40) != 0) {
          uVar3 = iVar8 + 0x80U & 3;
          uVar9 = *(uint *)(iVar8 + 0x80U & 0xfffffffc);
          *(uint *)(iVar8 + 0x80) =
               (uVar9 >> uVar3 * 8 | uVar9 << uVar3 * -8 + 0x20) & 0xfff8ffff | 0x20000;
        }
      }
      else {
        uVar3 = iVar8 + 0x80U & 3;
        uVar9 = *(uint *)(iVar8 + 0x80U & 0xfffffffc);
        *(uint *)(iVar8 + 0x80) =
             (uVar9 >> uVar3 * 8 | uVar9 << uVar3 * -8 + 0x20) & 0xfff8ffff | 0x10000;
      }
    }
    uVar3 = uRam0208b18c;
    uVar16 = uVar16 + 1 & 0xffff;
  } while (uVar16 < 2);
  uVar15 = 0;
  do {
    uVar16 = uVar3 & 3;
    uVar9 = *(uint *)(uVar3 & 0xfffffffc);
    uVar7 = (*(code *)(uVar9 >> uVar16 * 8 | uVar9 << uVar16 * -8 + 0x20))
                      (&local_74,(int)local_70[uVar15]);
    local_34 = iVar10;
    local_30 = iVar1;
    local_2c = iVar2;
    iVar8 = func_02018600(uVar7,local_74,(undefined4)(uintptr_t)(&local_34));
    if (iVar8 != 0) {
      uVar16 = iVar8 + 0x20U & 3;
      uVar9 = *(uint *)(iVar8 + 0x20U & 0xfffffffc);
      uVar9 = uVar9 >> uVar16 * 8 | uVar9 << uVar16 * -8 + 0x20;
      uVar16 = uVar9 & 3;
      uVar9 = *(uint *)(uVar9 & 0xfffffffc);
      bVar4 = *(byte *)((uVar9 >> uVar16 * 8 | uVar9 << uVar16 * -8 + 0x20) + 0x54);
      if ((bVar4 & 0x80) == 0) {
        if ((bVar4 & 0x40) != 0) {
          uVar16 = iVar8 + 0x80U & 3;
          uVar9 = *(uint *)(iVar8 + 0x80U & 0xfffffffc);
          *(uint *)(iVar8 + 0x80) =
               (uVar9 >> uVar16 * 8 | uVar9 << uVar16 * -8 + 0x20) & 0xfff8ffff | 0x20000;
        }
      }
      else {
        uVar16 = iVar8 + 0x80U & 3;
        uVar9 = *(uint *)(iVar8 + 0x80U & 0xfffffffc);
        *(uint *)(iVar8 + 0x80) =
             (uVar9 >> uVar16 * 8 | uVar9 << uVar16 * -8 + 0x20) & 0xfff8ffff | 0x10000;
      }
    }
    uVar15 = uVar15 + 1 & 0xffff;
  } while (uVar15 < 0x18);
  return;
}

