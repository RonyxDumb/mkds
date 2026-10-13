/* Decompiled C draft; module arm9; ROM address 02057800. No matching claim. */
#include "types.h"
#include "deps/02057800_func_02057800.h"

void func_02057800(int param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  
  iVar4 = *piRam02057848;
  if (*(int *)(iVar4 + 0xc) != 0) {
    if (param_1 == 0) {
      param_2 = param_2 << 0xc;
      uVar5 = *(undefined4 *)(iVar4 + 0x60);
      uVar1 = uRam02057860;
      iVar2 = iRam0205785c;
      uVar3 = uRam02057864;
      iVar6 = iRam02057858;
    }
    else {
      param_2 = iRam0205784c * param_2;
      uVar5 = *(undefined4 *)(iVar4 + 0x60);
      uVar1 = uRam02057850;
      iVar2 = iRam0205784c;
      uVar3 = uRam02057854;
      iVar6 = 0;
    }
    *(undefined4 *)(iVar4 + 0x68) = param_3;
    ReadSaveChunkImpl2_from_thumb(param_2 + iVar6 + iRam02057868,uVar5,iVar2,uVar3,uVar1);
  }
  return;
}

