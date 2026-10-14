/* Decompiled C draft; module arm7; ROM address 0600c0d4. No matching claim. */
#include "types.h"
#include "deps/0600c0d4_FUN_0600c0d4.h"

void FUN_0600c0d4(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  ushort *puVar4;
  uint uVar5;
  
  uVar5 = 0;
  uVar2 = DAT_0600c248;
  puVar4 = DAT_0600c244;
  do {
    *puVar4 = (ushort)uVar2;
    uVar5 = uVar5 + 2;
    uVar2 = uVar2 - 1 & 0xffff;
    puVar4 = puVar4 + 1;
  } while (uVar5 < 0x2000);
  uVar5 = 0;
  uVar2 = DAT_0600c248;
  puVar4 = DAT_0600c244;
  for (uVar3 = 0; uVar3 < 0x2000; uVar3 = uVar3 + 2) {
    uVar1 = uVar5;
    if ((*puVar4 != uVar2) && (uVar1 = uVar5 + 1, 0x20 < uVar5)) goto LAB_0600c220;
    puVar4 = puVar4 + 1;
    uVar2 = uVar2 - 1 & 0xffff;
    uVar5 = uVar1;
  }
  uVar3 = 0;
  uVar2 = DAT_0600c24c;
  puVar4 = DAT_0600c244;
  do {
    *puVar4 = (ushort)uVar2;
    uVar3 = uVar3 + 2;
    uVar2 = ~uVar2 & 0xffff;
    puVar4 = puVar4 + 1;
  } while (uVar3 < 0x2000);
  uVar2 = DAT_0600c24c;
  puVar4 = DAT_0600c244;
  for (uVar3 = 0; uVar3 < 0x2000; uVar3 = uVar3 + 2) {
    uVar1 = uVar5;
    if ((*puVar4 != uVar2) && (uVar1 = uVar5 + 1, 0x20 < uVar5)) goto LAB_0600c220;
    puVar4 = puVar4 + 1;
    uVar2 = ~uVar2 & 0xffff;
    uVar5 = uVar1;
  }
  uVar3 = 0;
  uVar2 = DAT_0600c250;
  puVar4 = DAT_0600c244;
  do {
    *puVar4 = (ushort)uVar2;
    uVar3 = uVar3 + 2;
    uVar2 = ~uVar2 & 0xffff;
    puVar4 = puVar4 + 1;
  } while (uVar3 < 0x2000);
  uVar3 = 0;
  uVar2 = DAT_0600c250;
  puVar4 = DAT_0600c244;
  while ((uVar1 = uVar5, uVar3 < 0x2000 && ((*puVar4 == uVar2 || (uVar1 = uVar5 + 1, uVar5 < 0x21)))
         )) {
    uVar3 = uVar3 + 2;
    puVar4 = puVar4 + 1;
    uVar2 = ~uVar2 & 0xffff;
    uVar5 = uVar1;
  }
LAB_0600c220:
  if (uVar1 == 0) {
    return;
  }
  uVar2 = *(uint *)(DAT_0600c254 & 0xfffffffc) >> (DAT_0600c254 & 3) * 8 |
          *(uint *)(DAT_0600c254 & 0xfffffffc) << (DAT_0600c254 & 3) * -8 + 0x20;
  *(ushort *)(uVar2 + 0x33e) = *(ushort *)(uVar2 + 0x33e) | 2;
  return;
}

