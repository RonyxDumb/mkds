/* Decompiled C draft; module arm9; ROM address 02039a1c. No matching claim. */
#include "types.h"
#include "deps/02039a1c_SomeVramConfig.h"

void SomeVramConfig(void)

{
  int iVar1;
  
  if ((*(uint *)((uint)puRam02039ab0 & 0xfffffffc) >> ((uint)puRam02039ab0 & 3) * 8 != 0 ||
       *(uint *)((uint)puRam02039ab0 & 0xfffffffc) << ((uint)puRam02039ab0 & 3) * -8 + 0x20 != 0) &&
     ((*(uint *)((uint)puRam02039ab0 & 0xfffffffc) >> ((uint)puRam02039ab0 & 3) * 8 |
      *(uint *)((uint)puRam02039ab0 & 0xfffffffc) << ((uint)puRam02039ab0 & 3) * -8 + 0x20) != 3)) {
    *puRam02039ab0 = 2;
    GX_SetBankForLCDC(8);
    Mem_CpuFastMemorySet(0,uRam02039ab4,0x20000);
    GX_DisableBankForLCDC();
    iVar1 = func_0201e7a8(8,uRam02039ab8,0);
    if (iVar1 != 1) {
      Os_Terminate();
    }
  }
  do {
  } while ((*(uint *)((uint)puRam02039ab0 & 0xfffffffc) >> ((uint)puRam02039ab0 & 3) * 8 |
           *(uint *)((uint)puRam02039ab0 & 0xfffffffc) << ((uint)puRam02039ab0 & 3) * -8 + 0x20) ==
           2);
  return;
}

