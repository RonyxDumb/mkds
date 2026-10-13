/* Decompiled C draft; module arm9_ov003; ROM address 021bb328. No matching claim. */
#include "types.h"
#include "deps/021bb328_FUN_021bb328.h"

int FUN_021bb328(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = (*(code *)*DAT_021bb350)(param_2 * param_1);
  if (iVar1 != 0) {
    func_0x02134de0(iVar1,0,param_2 * param_1);
  }
  return iVar1;
}

