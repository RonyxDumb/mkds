/* Decompiled C draft; module arm9; ROM address 0209fc38. No matching claim. */
#include "types.h"
#include "deps/0209fc38_func_0209fc38.h"

void func_0209fc38(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  puVar1 = puRam0209fc74;
  iVar3 = 0;
  do {
    puVar1[iVar3] = 0;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x13);
  uVar2 = func_0209bf8c();
  *puRam0209fc74 = uVar2;
  return;
}

