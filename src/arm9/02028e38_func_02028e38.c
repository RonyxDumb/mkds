/* Decompiled C draft; module arm9; ROM address 02028e38. No matching claim. */
#include "types.h"
#include "deps/02028e38_func_02028e38.h"

void func_02028e38(void)

{
  int iVar1;
  short *psVar2;
  
  iVar1 = func_020280dc();
  if (iVar1 == 0) {
    psVar2 = (short *)func_02078b04(*(undefined4 *)(*piRam02028ebc + 0xa8),
                                    *(undefined4 *)(*piRam02028ebc + 0xa4));
    iVar1 = *piRam02028ebc + 100;
    func_02028ec0(10,0x10,(int)*psVar2,iVar1);
    func_02028ec0(9,0xf,(int)psVar2[1],iVar1);
    func_02028ec0(8,0xe,(int)psVar2[2],iVar1);
    func_02028ec0(7,0xd,(int)psVar2[3],iVar1);
    func_02028ec0(6,0xc,(int)psVar2[4],iVar1);
    func_02028ec0(5,0xb,(int)psVar2[5],iVar1);
  }
  return;
}

