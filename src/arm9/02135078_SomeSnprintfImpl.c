/* Decompiled C draft; module arm9; ROM address 02135078. No matching claim. */
#include "types.h"
#include "deps/02135078_SomeSnprintfImpl.h"

void SomeSnprintfImpl(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  int local_18;
  uint local_14;
  undefined4 local_10;
  
  local_10 = 0;
  local_18 = param_1;
  local_14 = param_2;
  uVar1 = SomeVsnprintf(uRam02135140,&local_18);
  if (param_1 == 0) {
    return;
  }
  if (param_2 <= uVar1) {
    if (param_2 != 0) {
      puVar3 = (uint *)(param_1 + param_2 + -1);
      uVar2 = (*(uint *)((uint)puVar3 & 0xfffffffc) >> ((uint)puVar3 & 3) * 8 |
              *(uint *)((uint)puVar3 & 0xfffffffc) << ((uint)puVar3 & 3) * -8 + 0x20) & 0xffffff00;
      uVar1 = (4 - ((uint)puVar3 & 3)) * 8 & 0x1f;
      *puVar3 = uVar2 >> uVar1 | uVar2 << 0x20 - uVar1;
      return;
    }
    return;
  }
  puVar3 = (uint *)(param_1 + uVar1);
  uVar2 = (*(uint *)((uint)puVar3 & 0xfffffffc) >> ((uint)puVar3 & 3) * 8 |
          *(uint *)((uint)puVar3 & 0xfffffffc) << ((uint)puVar3 & 3) * -8 + 0x20) & 0xffffff00;
  uVar1 = (4 - ((uint)puVar3 & 3)) * 8 & 0x1f;
  *puVar3 = uVar2 >> uVar1 | uVar2 << 0x20 - uVar1;
  return;
}

