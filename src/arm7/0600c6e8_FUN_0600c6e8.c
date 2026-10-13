/* Decompiled C draft; module arm7; ROM address 0600c6e8. No matching claim. */
#include "types.h"
#include "deps/0600c6e8_FUN_0600c6e8.h"

void FUN_0600c6e8(void)

{
  short sVar1;
  undefined2 *puVar2;
  uint uVar3;
  int iVar4;
  ushort *puVar5;
  short *psVar6;
  short *psVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  
  uVar3 = DAT_0600c918;
  uVar8 = *(uint *)(DAT_0600c918 & 0xfffffffc) >> (DAT_0600c918 & 3) * 8 |
          *(uint *)(DAT_0600c918 & 0xfffffffc) << (DAT_0600c918 & 3) * -8 + 0x20;
  iVar9 = uVar8 + DAT_0600c91c;
  *DAT_0600c920 = 0x40;
  uVar10 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  if ((*(ushort *)((uVar3 >> uVar10 * 8 | uVar3 << uVar10 * -8 + 0x20) + 0x690) & 0x20) == 0) {
    return;
  }
  if (*(ushort *)(iVar9 + 0xa4) != DAT_0600c924) {
    return;
  }
  if ((*DAT_0600c928 & 3) != 3) {
    return;
  }
  if ((uint)*DAT_0600c92c < (DAT_0600c934 & *DAT_0600c930 >> 1)) {
    return;
  }
  uVar10 = (uint)*DAT_0600c938;
  iVar4 = FUN_0600c580(DAT_0600c93c + uVar10 * 2 + 8);
  puVar5 = (ushort *)FUN_0600c580(iVar4 + 4);
  if ((DAT_0600c940 & *puVar5) != 0x228) {
    return;
  }
  iVar4 = FUN_0600c580((uint)(uintptr_t)(puVar5 + 1));
  sVar1 = *DAT_0600c944;
  while( true ) {
    uVar3 = *DAT_0600c92c - uVar10 & 0xffff;
    if ((*DAT_0600c92c - uVar10 & 0x8000) != 0) {
      uVar3 = uVar3 + (*(ushort *)(uVar8 + 0x3de) >> 1) & 0xffff;
    }
    if (0xe < uVar3) break;
    if (0x40 < (ushort)(*DAT_0600c944 - sVar1)) {
      return;
    }
  }
  psVar6 = (short *)(iVar4 + 8);
  uVar3 = 0;
  while( true ) {
    if (2 < uVar3) {
      puVar5 = (ushort *)FUN_0600c580((uint)(uintptr_t)(psVar6 + 5));
      while( true ) {
        uVar3 = *DAT_0600c92c - uVar10 & 0xffff;
        if ((*DAT_0600c92c - uVar10 & 0x8000) != 0) {
          uVar3 = uVar3 + (*(ushort *)(uVar8 + 0x3de) >> 1) & 0xffff;
        }
        if (0x14 < uVar3) break;
        if (0x70 < (ushort)(*DAT_0600c944 - sVar1)) {
          return;
        }
      }
      if (((uint)*puVar5 & 1 << (*DAT_0600c948 & 0xff)) != 0) {
        return;
      }
      *(undefined2 *)(iVar9 + 0xa4) = *DAT_0600c94c;
      *DAT_0600c950 = 0x40;
      *(short *)(uVar8 + 0x402) = *(short *)(uVar8 + 0x402) + 1;
      puVar5 = DAT_0600c954;
      do {
      } while ((*DAT_0600c928 & 3) == 3);
      *DAT_0600c954 = *DAT_0600c954 | 0x40;
      *puVar5 = *puVar5 & 0xffbf;
      puVar2 = DAT_0600c958;
      *DAT_0600c958 = 8;
      *puVar2 = 0;
      FUN_0600c514();
      return;
    }
    psVar7 = (short *)FUN_0600c580((uint)(uintptr_t)(psVar6));
    psVar6 = psVar7 + 1;
    if (*psVar7 != *(short *)(uVar8 + uVar3 * 2 + 0x3a8)) break;
    uVar3 = uVar3 + 1;
  }
  return;
}

