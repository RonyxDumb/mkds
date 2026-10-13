/* Decompiled C draft; module arm9; ROM address 0204b458. No matching claim. */
#include "types.h"
#include "deps/0204b458_SV_MaybeCompressWriteImpl_from_thumb.h"

undefined4
SV_MaybeCompressWriteImpl_from_thumb
          (undefined4 param_1,int param_2,int param_3,undefined4 param_4,int param_5,int param_6)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  if ((*(int *)(*piRam0204b510 + 0xc) != 0) &&
     (iVar2 = CardIsNotBusy(), piVar1 = piRam0204b510, iVar2 != 0)) {
    *(undefined4 *)(*piRam0204b510 + 4) = 0;
    *(undefined4 *)(*piVar1 + 0x10) = 1;
    *(undefined4 *)*piVar1 = 1;
    *(undefined4 *)(*piVar1 + 0x44) = param_1;
    *(int *)(*piVar1 + 0x40) = param_2;
    *(int *)(*piVar1 + 0x48) = param_3;
    *(int *)(*piVar1 + 0x50) = param_6;
    *(undefined4 *)(*piVar1 + 0x54) = param_4;
    *(int *)(*piVar1 + 0x14) = param_5;
    if (param_5 == 2) {
      Card_RequestStreamCommand(param_2,param_1,param_3,uRam0204b514,param_4,1,7,10,2);
      return 1;
    }
    iVar2 = param_2;
    iVar4 = param_3;
    if (param_6 != 0) {
      iVar2 = param_2 + 8;
      iVar4 = param_3 + -8;
    }
    CalculateCRCChecksum_from_thumb(param_2,param_3,0);
    EncryptSaveData_from_thumb((uint *)(uintptr_t)(iVar2),iVar4);
    DC_SomeClean(param_2,param_3);
    uVar3 = func_0204b518();
    return uVar3;
  }
  return 0;
}

