/* Decompiled C draft; module arm9; ROM address 020399a8. No matching claim. */
#include "types.h"
#include "deps/020399a8_MaybeInitializeSomeWirelessShit.h"

void MaybeInitializeSomeWirelessShit(void)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = uRam02039a18;
  if (((*(uint *)((uint)puRam02039a14 & 0xfffffffc) >> ((uint)puRam02039a14 & 3) * 8 |
       *(uint *)((uint)puRam02039a14 & 0xfffffffc) << ((uint)puRam02039a14 & 3) * -8 + 0x20) != 1)
     && ((*(uint *)((uint)puRam02039a14 & 0xfffffffc) >> ((uint)puRam02039a14 & 3) * 8 |
         *(uint *)((uint)puRam02039a14 & 0xfffffffc) << ((uint)puRam02039a14 & 3) * -8 + 0x20) != 3)
     ) {
    *puRam02039a14 = 2;
    iVar2 = SetWvrFifoShit(uVar1,1);
    if (iVar2 != 1) {
      Os_Terminate();
    }
  }
  do {
  } while ((*(uint *)((uint)puRam02039a14 & 0xfffffffc) >> ((uint)puRam02039a14 & 3) * 8 |
           *(uint *)((uint)puRam02039a14 & 0xfffffffc) << ((uint)puRam02039a14 & 3) * -8 + 0x20) ==
           2);
  return;
}

