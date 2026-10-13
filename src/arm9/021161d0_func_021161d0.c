/* Decompiled C draft; module arm9; ROM address 021161d0. No matching claim. */
#include "types.h"
#include "deps/021161d0_func_021161d0.h"

void func_021161d0(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = (*(short *)(*piRam02116214 + 0x74) + 1) * 0x10000 >> 0x10;
  iVar1 = func_02116844(iVar2);
  if ((iVar1 == 0) || (4 < iVar2)) {
    iVar2 = 0;
  }
  if (*(short *)(*piRam02116214 + 0x74) != iVar2) {
    NNSi_MaybeSndPlayerStartSeq(uRam02116218,0,0);
  }
  *(short *)(*piRam02116214 + 0x74) = (short)iVar2;
  return;
}

