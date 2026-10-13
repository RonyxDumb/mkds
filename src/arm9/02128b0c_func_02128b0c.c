/* Decompiled C draft; module arm9; ROM address 02128b0c. No matching claim. */
#include "types.h"
#include "deps/02128b0c_func_02128b0c.h"

void func_02128b0c(void)

{
  int *piVar1;
  byte *pbVar2;
  int iVar3;
  
  piVar1 = piRam02128b50;
  iVar3 = 0;
  pbVar2 = pbRam02128b4c;
  do {
    if (*pbVar2 != 0xff) {
      *(undefined4 *)(*(int *)(*piVar1 + 0x80) + (uint)*pbVar2 * 0x40) = 0;
    }
    pbVar2 = pbVar2 + 1;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 6);
  *(undefined4 *)
   (*(int *)(*piRam02128b50 + 0x80) + (uint)pbRam02128b4c[*(int *)(*piRam02128b50 + 8)] * 0x40) = 1;
  return;
}

