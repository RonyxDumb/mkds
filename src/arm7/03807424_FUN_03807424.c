/* Decompiled C draft; module arm7; ROM address 03807424. No matching claim. */
#include "types.h"
#include "deps/03807424_FUN_03807424.h"

uint FUN_03807424(void)

{
  ushort uVar1;
  ushort *puVar2;
  uint uVar3;
  uint uVar4;
  
  FUN_037f9a0c(DAT_03807474);
  puVar2 = DAT_03807478;
  while( true ) {
    uVar1 = *puVar2;
    if ((uVar1 & 1) == 0) break;
    thunk_FUN_038011a4(0x100);
  }
  *puVar2 = uVar1 | 1;
  uVar4 = DAT_0380747c + 0x54cU & 3;
  uVar3 = *(uint *)(DAT_0380747c + 0x54cU & 0xfffffffc);
  uVar4 = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 8;
  uVar3 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  return uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
}

