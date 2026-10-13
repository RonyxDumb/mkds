/* Decompiled C draft; module arm9; ROM address 02113940. No matching claim. */
#include "types.h"
#include "deps/02113940_func_02113940.h"

void func_02113940(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = (*(short *)(*piRam02113984 + 0x68) + 1) * 0x10000 >> 0x10;
  iVar1 = func_02113ef0(iVar2);
  if ((iVar1 == 0) || (4 < iVar2)) {
    iVar2 = 0;
  }
  if (*(short *)(*piRam02113984 + 0x68) != iVar2) {
    NNSi_MaybeSndPlayerStartSeq(uRam02113988,0,0);
  }
  *(short *)(*piRam02113984 + 0x68) = (short)iVar2;
  return;
}

