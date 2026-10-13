/* Decompiled C draft; module arm9; ROM address 0205786c. No matching claim. */
#include "types.h"
#include "deps/0205786c_func_0205786c.h"

void func_0205786c(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar2 = *piRam020578b0;
  if (*(int *)(iVar2 + 0xc) != 0) {
    if (param_1 == 0) {
      param_2 = param_2 << 0xc;
      uVar3 = *(undefined4 *)(iVar2 + 0x60);
      iVar1 = iRam020578bc;
      iVar4 = iRam020578c0;
      uVar5 = uRam020578c4;
    }
    else {
      param_2 = iRam020578b4 * param_2;
      uVar3 = *(undefined4 *)(iVar2 + 0x60);
      iVar1 = 0;
      iVar4 = iRam020578b4;
      uVar5 = uRam020578b8;
    }
    *(undefined4 *)(iVar2 + 0x68) = param_3;
    ReadSaveChunkImpl2_from_thumb(param_2 + iVar1 + iRam020578c8,uVar3,iVar4,uRam020578cc,uVar5);
  }
  return;
}

