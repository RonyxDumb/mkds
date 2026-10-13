/* Decompiled C draft; module arm9; ROM address 0204dab8. No matching claim. */
#include "types.h"
#include "deps/0204dab8_UnkStruct_ExtraFileOperationHandler_Unk.h"

undefined4 UnkStruct_ExtraFileOperationHandler_Unk(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  if (param_2 != 0) {
    if (param_2 == 1) {
      return 4;
    }
    return 8;
  }
  uVar1 = iRam0204db3c + 0xcU & 3;
  uVar2 = *(uint *)(iRam0204db3c + 0xcU & 0xfffffffc);
  if ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) == 2) {
    uVar1 = param_1 + 0x38U & 3;
    uVar2 = *(uint *)(param_1 + 0x38U & 0xfffffffc);
    if (uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0) {
      SomeFileAsyncReadFunc(param_1);
      return 6;
    }
    return 0;
  }
  return 5;
}

