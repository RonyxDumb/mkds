/* Decompiled C draft; module arm9_ov001; ROM address 0218a6b0. No matching claim. */
#include "types.h"
#include "deps/0218a6b0_FUN_0218a6b0.h"

void FUN_0218a6b0(int param_1)

{
  longlong *plVar1;
  uint extraout_r1;
  uint uVar2;
  longlong lVar3;
  
  uVar2 = *(uint *)(*(int *)(param_1 + 0xa0) + DAT_0218a754) & 0xffff;
  if (uVar2 == DAT_0218a758) {
    plVar1 = (longlong *)func_0x020d22d0();
    lVar3 = func_0x02133048((int)plVar1[1],*(undefined4 *)((int)plVar1 + 0xc),(int)*plVar1,
                            *(undefined4 *)((int)plVar1 + 4));
    *plVar1 = lVar3 + plVar1[2];
    uVar2 = *(uint *)((int)plVar1 + 4) >> 0x10;
  }
  else {
    plVar1 = (longlong *)func_0x020d22d0();
    if (uVar2 == 0) {
      uVar2 = 0;
    }
    else {
      lVar3 = func_0x02133048((int)plVar1[1],*(undefined4 *)((int)plVar1 + 0xc),(int)*plVar1,
                              *(undefined4 *)((int)plVar1 + 4));
      *plVar1 = lVar3 + plVar1[2];
      if (uVar2 == 0) {
        uVar2 = *(uint *)((int)plVar1 + 4);
      }
      else {
        func_0x02133048(*(undefined4 *)((int)plVar1 + 4),0,uVar2,0);
        uVar2 = extraout_r1;
      }
    }
    uVar2 = uVar2 & 0xffff;
  }
  if (uVar2 != 0) {
    FUN_0218aaac(param_1);
    return;
  }
  FUN_0218a970(param_1);
  return;
}

