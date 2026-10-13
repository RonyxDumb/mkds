/* Decompiled C draft; module arm9; ROM address 0207a990. No matching claim. */
#include "types.h"
#include "deps/0207a990_DisposeDrivers.h"

void DisposeDrivers(void)

{
  uint uVar1;
  ushort *puVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  iVar4 = iRam0207a9f0;
  puVar3 = puRam0207a9ec;
  puVar2 = puRam0207a9e8;
  iVar6 = 0;
  if (*puRam0207a9e8 != 0) {
    iVar7 = 0;
    do {
      uVar1 = (uint)puVar3 & 3;
      uVar5 = *(uint *)((uint)puVar3 & 0xfffffffc);
      DriverContext_Dispose((uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) + iVar7);
      iVar6 = iVar6 + 1;
      iVar7 = iVar7 + iVar4;
    } while (iVar6 < (int)(uint)*puVar2);
  }
  *puRam0207a9ec = 0;
  return;
}

