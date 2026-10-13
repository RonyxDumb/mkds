/* Decompiled C draft; module arm9; ROM address 021400ec. No matching claim. */
#include "types.h"
#include "deps/021400ec_func_021400ec.h"

undefined8 func_021400ec(int param_1,uint param_2,int *param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined4 local_10;
  
  iVar1 = iRam02140198;
  uVar4 = CONCAT44(param_2,param_1);
  uVar3 = param_2 & 0x7fffffff;
  *param_3 = 0;
  if (((int)uVar3 < iVar1) && (uVar3 != 0 || param_1 != 0)) {
    if (uVar3 < 0x100000) {
      uVar4 = func_02130380(param_1,param_2,0,uRam0214019c);
      *param_3 = -0x36;
      uVar3 = (uint)((ulonglong)uVar4 >> 0x20) & 0x7fffffff;
    }
    uVar2 = uRam021401a4;
    local_10 = (undefined4)uVar4;
    *param_3 = (*(uint *)((uint)param_3 & 0xfffffffc) >> ((uint)param_3 & 3) * 8 |
               *(uint *)((uint)param_3 & 0xfffffffc) << ((uint)param_3 & 3) * -8 + 0x20) +
               iRam021401a0 + ((int)uVar3 >> 0x14);
    return CONCAT44((uint)((ulonglong)uVar4 >> 0x20) & uVar2 | uRam021401a8,local_10);
  }
  return CONCAT44(param_2,param_1);
}

