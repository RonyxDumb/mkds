/* Decompiled C draft; module arm9; ROM address 02046968. No matching claim. */
#include "types.h"
#include "deps/02046968_MaybeSetRacerCount.h"

void MaybeSetRacerCount(int param_1)

{
  undefined1 uVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  char cVar5;
  int iVar6;
  uint uVar7;
  char *pcVar8;
  uint uVar9;
  uint uVar10;
  char local_18 [8];
  uint uVar11;
  
  uVar2 = uRam02046a38;
  pcVar8 = local_18;
  cVar5 = '\0';
  local_18[0] = '\0';
  cVar3 = '\0';
  iVar6 = 0;
  local_18[1] = 0;
  if (0 < param_1) {
    uVar7 = *(uint *)(uRam02046a38 & 0xfffffffc) >> (uRam02046a38 & 3) * 8 |
            *(uint *)(uRam02046a38 & 0xfffffffc) << (uRam02046a38 & 3) * -8 + 0x20;
    uVar9 = uVar7;
    do {
      uVar11 = uVar9 + 0x70 & 3;
      uVar10 = *(uint *)(uVar9 + 0x70 & 0xfffffffc);
      uVar11 = uVar10 >> uVar11 * 8 | uVar10 << uVar11 * -8 + 0x20;
      if (uVar11 != 4) {
        if ((uVar11 == 0) || (uVar11 == 3)) {
          cVar5 = cVar5 + '\x01';
        }
        cVar3 = cVar3 + '\x01';
        if (*(char *)(uVar7 + 0x58) != '\0') {
          uVar11 = uVar9 + 0x74 & 3;
          uVar10 = *(uint *)(uVar9 + 0x74 & 0xfffffffc);
          uVar11 = uVar10 >> uVar11 * 8 | uVar10 << uVar11 * -8 + 0x20;
          local_18[uVar11] = local_18[uVar11] + '\x01';
        }
      }
      iVar6 = iVar6 + 1;
      uVar9 = uVar9 + 0x30;
    } while (iVar6 < param_1);
  }
  iVar6 = 0;
  *(char *)((*(uint *)(uRam02046a38 & 0xfffffffc) >> (uRam02046a38 & 3) * 8 |
            *(uint *)(uRam02046a38 & 0xfffffffc) << (uRam02046a38 & 3) * -8 + 0x20) + 0x3d0) = cVar3
  ;
  *(char *)((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
            *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x3d1) = cVar5;
  do {
    uVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    iVar4 = (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
            *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + iVar6;
    iVar6 = iVar6 + 1;
    *(undefined1 *)(iVar4 + 0x3d2) = uVar1;
  } while (iVar6 < 2);
  return;
}

