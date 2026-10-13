/* Decompiled C draft; module arm9; ROM address 020feb44. No matching claim. */
#include "types.h"
#include "deps/020feb44_func_020feb44.h"

void func_020feb44(void)

{
  char cVar1;
  byte bVar2;
  undefined1 uVar3;
  byte *pbVar4;
  undefined1 *puVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  
  uVar8 = GetSomeTimeOrDuration();
  iVar7 = iRam020fec28;
  iVar6 = iRam020fec24;
  puVar5 = puRam020fec20;
  pbVar4 = pbRam020fec1c;
  uVar9 = (uint)*pbRam020fec1c;
  uVar14 = 0xff;
  if (uVar9 == 0xff) {
    return;
  }
  do {
    iVar13 = iVar7 + uVar9 * 2;
    cVar1 = *(char *)(iVar13 + 1);
    bVar2 = *(byte *)(iVar7 + uVar9 * 2);
    *(char *)(iVar13 + 1) = *(char *)(iVar13 + 1) + -1;
    uVar10 = uVar9;
    if (cVar1 == '\0') {
      uVar3 = *puVar5;
      if (uVar14 == 0xff) {
        *pbVar4 = bVar2;
      }
      *(undefined1 *)(iVar7 + uVar9 * 2) = uVar3;
      *puVar5 = (char)uVar9;
      if (uVar14 != 0xff) {
        *(byte *)(iVar7 + uVar14 * 2) = bVar2;
      }
      iVar13 = iVar6 + uVar9 * 0x20;
      uVar9 = iVar13 + 0x1cU & 3;
      uVar10 = *(uint *)(iVar13 + 0x1cU & 0xfffffffc);
      uVar9 = uVar10 >> uVar9 * 8 | uVar10 << uVar9 * -8 + 0x20;
      uVar10 = uVar14;
      if ((uVar9 == 0) || (uVar8 <= uVar9 + 0x100)) {
        uVar9 = iVar13 + 0x14U & 3;
        uVar12 = *(uint *)(iVar13 + 0x14U & 0xfffffffc);
        uVar14 = iVar13 + 0x18U & 3;
        uVar11 = *(uint *)(iVar13 + 0x18U & 0xfffffffc);
        func_020f0758((uVar12 >> uVar9 * 8 | uVar12 << uVar9 * -8 + 0x20) * 0x44 +
                      (*(uint *)(uRam020fec2c & 0xfffffffc) >> (uRam020fec2c & 3) * 8 |
                      *(uint *)(uRam020fec2c & 0xfffffffc) << (uRam020fec2c & 3) * -8 + 0x20),
                      uVar11 >> uVar14 * 8 | uVar11 << uVar14 * -8 + 0x20,0);
      }
    }
    uVar9 = (uint)bVar2;
    uVar14 = uVar10;
  } while (bVar2 != 0xff);
  return;
}

