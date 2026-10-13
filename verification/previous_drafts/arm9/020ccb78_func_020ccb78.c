/* Decompiled C draft; module arm9; ROM address 020ccb78. No matching claim. */
#include "types.h"
#include "deps/020ccb78_func_020ccb78.h"

void func_020ccb78(void)

{
  byte bVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar2 = (undefined4 *)GetGlobalCA_from_thumb();
  iVar3 = GetGlobalCA_from_thumb();
  StructCO_ConfigureRacerDefault(0,*puVar2,*(undefined4 *)(iVar3 + 4),0,0xffffffff,3);
  bVar1 = 1;
  do {
    func_020ccb48(bVar1);
    bVar1 = bVar1 + 1;
  } while (bVar1 < 8);
  return;
}

