/* Decompiled C draft; module arm9; ROM address 0204b714. No matching claim. */
#include "types.h"
#include "deps/0204b714_func_0204b714.h"

undefined4
func_0204b714(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
             undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int *piVar1;
  int iVar2;
  
  if ((*(int *)(*piRam0204b7b0 + 0xc) != 0) && (iVar2 = CardIsNotBusy(), iVar2 != 0)) {
    iVar2 = AllocateLockCardBackupResource_from_thumb();
    piVar1 = piRam0204b7b0;
    if (iVar2 == 0) {
      return 0;
    }
    *(undefined4 *)(*piRam0204b7b0 + 4) = 0;
    *(undefined4 *)(*piVar1 + 0x10) = 1;
    *(undefined4 *)*piVar1 = 3;
    *(undefined4 *)(*piVar1 + 0x2c) = param_1;
    *(undefined4 *)(*piVar1 + 0x28) = param_2;
    *(undefined4 *)(*piVar1 + 0x30) = param_3;
    *(undefined4 *)(*piVar1 + 0x34) = param_6;
    *(undefined4 *)(*piVar1 + 0x38) = param_7;
    *(undefined4 *)(*piVar1 + 0x14) = param_5;
    DC_InvalidateRangeNoClean(param_2,param_3);
    Card_RequestStreamCommand(param_1,param_2,param_3,uRam0204b7b4,param_4,1,6,1,0);
    return 1;
  }
  return 0;
}

