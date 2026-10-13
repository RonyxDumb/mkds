/* Decompiled C draft; module arm7; ROM address 06006868. No matching claim. */
#include "types.h"
#include "deps/06006868_FUN_06006868.h"

void FUN_06006868(void)

{
  uint uVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  short *psVar5;
  bool bVar6;
  
  iVar3 = FUN_06000680();
  uVar1 = iVar3 + 0x154cU & 3;
  uVar4 = *(uint *)(iVar3 + 0x154cU & 0xfffffffc);
  uVar4 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  uVar1 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  psVar5 = (short *)(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20);
  psVar5[0x65] = 0;
  psVar5[0x44] = 1;
  psVar5[0x5e] = psVar5[0x5e] + -1;
  if (psVar5[0x5e] == 0) {
    if ((ushort)psVar5[0x5d] != DAT_06006a0c) {
      FUN_06000250((ushort)psVar5[0x5d] & 0xff);
      sVar2 = FUN_060001dc();
      psVar5[0x5c] = sVar2;
      psVar5[0x5d] = (short)DAT_06006a0c;
    }
    psVar5[0x5e] = 4;
  }
  if (*psVar5 == 9) {
    thunk_FUN_037faf70();
    if (psVar5[0xbf] == 0) {
      psVar5[0x1b] = 0;
      thunk_FUN_037faf84();
    }
    else {
      bVar6 = true;
      if ((psVar5[0x1b] != 0) && (psVar5[0x1c] != 0)) {
        bVar6 = false;
      }
      psVar5[0x1b] = psVar5[0x1b] + psVar5[0x1a];
      if (0x100 < psVar5[0x1b]) {
        psVar5[0x1b] = 0x100;
      }
      if (psVar5[0x4b] == 0) {
        psVar5[0x1c] = 6;
      }
      else {
        psVar5[0x1c] = psVar5[0x1a];
      }
      if (((bVar6) && (0 < psVar5[0x1b])) && (0 < psVar5[0x1c])) {
        bVar6 = true;
      }
      else {
        bVar6 = false;
      }
      thunk_FUN_037faf84();
      if (bVar6) {
        FUN_06007980(DAT_06006a0c);
      }
      if ((psVar5[0x49] == 1) && (psVar5[0x4e] = psVar5[0x4e] + -1, psVar5[0x4e] == 0)) {
        psVar5[0x4d] = 1;
        psVar5[0x4e] = 0x3c;
      }
    }
  }
  else if (*psVar5 == 10) {
    thunk_FUN_037faf70();
    uVar1 = (uint)(psVar5 + 0x398) & 3;
    uVar4 = *(uint *)((uint)(psVar5 + 0x398) & 0xfffffffc);
    bVar6 = (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) != 1;
    if (bVar6) {
      psVar5[0x19] = 0;
    }
    thunk_FUN_037faf84();
    if (bVar6) {
      FUN_06007b28();
    }
  }
  return;
}

