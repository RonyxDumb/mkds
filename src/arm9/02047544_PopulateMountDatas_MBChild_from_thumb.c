/* Decompiled C draft; module arm9; ROM address 02047544. No matching claim. */
#include "types.h"
#include "deps/02047544_PopulateMountDatas_MBChild_from_thumb.h"

void PopulateMountDatas_MBChild_from_thumb(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  
  SetMountData_from_thumb(param_3,2,0x3c,0,1);
  SetMountData_from_thumb(param_3,3,0x32,0,1);
  SetMountData_from_thumb(param_3,4,5,0,1);
  SetMountData_from_thumb(param_3,5,5,0,1);
  SetMountData_from_thumb(param_3,0,0x14,0,1);
  SetMountData_from_thumb(param_3,1,0x14,0,1);
  SetMountData_from_thumb(param_3,0xe,0x46,0,1);
  SetMountData_from_thumb(param_3,0xf,0x46,0,1);
  SetMountData_from_thumb(param_2,6,200,1,1);
  SetMountData_from_thumb(param_2,7,200,0,1);
  SetMountData_from_thumb(param_1,8,0x46,1,0);
  SetMountData_from_thumb(param_1,0xd,0x1e,0,0);
  piVar1 = piRam02047624;
  *(undefined4 *)(*piRam02047624 + iRam02047628) = param_1;
  *(undefined4 *)(*piVar1 + iRam0204762c) = param_2;
  *(undefined4 *)(*piVar1 + iRam02047630) = param_3;
  return;
}

