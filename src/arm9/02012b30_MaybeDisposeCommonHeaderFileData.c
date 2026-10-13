/* Decompiled C draft; module arm9; ROM address 02012b30. No matching claim. */
#include "types.h"
#include "deps/02012b30_MaybeDisposeCommonHeaderFileData.h"

uint MaybeDisposeCommonHeaderFileData(uint param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iStack_18;
  int aiStack_14 [2];
  
  uVar4 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  if (uVar4 <= uRam02012c98) {
    if (uRam02012c98 <= uVar4) {
      return param_1;
    }
    if (uVar4 <= uRam02012c9c) {
      if (uVar4 < uRam02012c9c) {
        return uRam02012ca0;
      }
      return uRam02012c9c;
    }
    return uRam02012ca4;
  }
  if (uRam02012ca8 < uVar4) {
    if (uVar4 != uRam02012cb0) {
      return uRam02012cb0;
    }
  }
  else {
    if (uRam02012ca8 <= uVar4) {
      return param_1;
    }
    if (uVar4 != uRam02012cac) {
      return param_1;
    }
    uVar1 = Nsbmd_GetMDL0Block();
    iVar2 = Nsbtx_GetTEX0Block(param_1);
    if (iVar2 != 0) {
      func_020100fc(uVar1);
    }
  }
  iVar2 = Nsbtx_GetTEX0Block(param_1);
  if (iVar2 == 0) {
    return 0;
  }
  iVar3 = func_020107e4();
  Tex0_CleanGetKeys(iVar2,&iStack_18,aiStack_14);
  if (iVar3 != 0) {
    (*(code *)(*(uint *)(uRam02012cb4 & 0xfffffffc) >> (uRam02012cb4 & 3) * 8 |
              *(uint *)(uRam02012cb4 & 0xfffffffc) << (uRam02012cb4 & 3) * -8 + 0x20))(iVar3);
  }
  if (aiStack_14[0] != 0) {
    (*(code *)(*(uint *)(uRam02012cb8 & 0xfffffffc) >> (uRam02012cb8 & 3) * 8 |
              *(uint *)(uRam02012cb8 & 0xfffffffc) << (uRam02012cb8 & 3) * -8 + 0x20))();
  }
  if (iStack_18 != 0) {
    uVar4 = (*(code *)(*(uint *)(uRam02012cb8 & 0xfffffffc) >> (uRam02012cb8 & 3) * 8 |
                      *(uint *)(uRam02012cb8 & 0xfffffffc) << (uRam02012cb8 & 3) * -8 + 0x20))();
    return uVar4;
  }
  return 0;
}

