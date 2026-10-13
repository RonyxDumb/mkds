/* Decompiled C draft; module arm7; ROM address 0600c95c. No matching claim. */
#include "types.h"
#include "deps/0600c95c_FUN_0600c95c.h"

void FUN_0600c95c(void)

{
  ushort *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = DAT_0600c9fc;
  iVar2 = (*(uint *)(DAT_0600c9fc & 0xfffffffc) >> (DAT_0600c9fc & 3) * 8 |
          *(uint *)(DAT_0600c9fc & 0xfffffffc) << (DAT_0600c9fc & 3) * -8 + 0x20) + DAT_0600ca00;
  *DAT_0600ca04 = 0x80;
  puVar1 = DAT_0600ca14;
  uVar4 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  if ((*(ushort *)((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 0x690) & 0x20) == 0) {
    return;
  }
  if ((*DAT_0600ca08 & 0xff) < 3) {
    return;
  }
  if (5 < (*DAT_0600ca08 & 0xff)) {
    return;
  }
  uVar4 = iVar2 + 0x58;
  uVar3 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  if ((uint)*DAT_0600ca0c < (DAT_0600ca10 & (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) >> 1))
  {
    return;
  }
  uVar4 = iVar2 + 0x30;
  uVar3 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  if ((DAT_0600ca10 & (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) >> 1) < (uint)*DAT_0600ca0c)
  {
    return;
  }
  *DAT_0600ca14 = *DAT_0600ca14 | 0x80;
  *puVar1 = *puVar1 & 0xff7f;
  return;
}

