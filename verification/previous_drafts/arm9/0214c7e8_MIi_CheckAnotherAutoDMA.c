/* Decompiled C draft; module arm9; ROM address 0214c7e8. No matching claim. */
#include "types.h"
#include "deps/0214c7e8_MIi_CheckAnotherAutoDMA.h"

void MIi_CheckAnotherAutoDMA(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 0;
  uVar2 = uRam0214c898;
  do {
    if (((((iVar3 != param_1) &&
          (uVar1 = *(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                   *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20,
          (uVar1 & 0x80000000) != 0)) && (uVar1 = uVar1 & 0x38000000, uVar1 != param_2)) &&
        (((uVar1 != 0x8000000 || (param_2 != 0x10000000)) &&
         ((uVar1 != 0x10000000 || (param_2 != 0x8000000)))))) &&
       ((((uVar1 == 0x18000000 || (uVar1 == 0x20000000)) ||
         ((uVar1 == 0x28000000 ||
          (((uVar1 == 0x30000000 || (uVar1 == 0x38000000)) || (uVar1 == 0x8000000)))))) ||
        (uVar1 == 0x10000000)))) {
      Os_Terminate();
    }
    iVar3 = iVar3 + 1;
    uVar2 = uVar2 + 0xc;
  } while (iVar3 < 3);
  return;
}

