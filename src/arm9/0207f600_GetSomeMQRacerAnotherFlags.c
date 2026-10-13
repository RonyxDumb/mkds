/* Decompiled C draft; module arm9; ROM address 0207f600. No matching claim. */
#include "types.h"
#include "deps/0207f600_GetSomeMQRacerAnotherFlags.h"

bool GetSomeMQRacerAnotherFlags(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = GetDriverEntry();
  uVar1 = iVar2 + 0x7cU & 3;
  uVar3 = *(uint *)(iVar2 + 0x7cU & 0xfffffffc);
  return ((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & uRam0207f62c) == 0;
}

