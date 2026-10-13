/* Decompiled C draft; module arm9; ROM address 021143b4. No matching claim. */
#include "types.h"
#include "deps/021143b4_func_021143b4.h"

short func_021143b4(void)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  
  sVar1 = 0;
  if ((short *)*puRam021143f0 == (short *)0x0) {
    uVar3 = 0;
    do {
      iVar2 = func_02060b34(uVar3 & 0xff);
      if (iVar2 != 0) {
        sVar1 = sVar1 + 1;
      }
      uVar3 = uVar3 + 1;
    } while ((int)uVar3 < 0x3c);
    return sVar1;
  }
  return *(short *)*puRam021143f0;
}

