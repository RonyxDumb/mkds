/* Decompiled C draft; module arm9; ROM address 02025a00. No matching claim. */
#include "types.h"
#include "deps/02025a00_func_02025a00.h"

undefined4
func_02025a00(undefined4 param_1,undefined4 param_2,int param_3,short *param_4,undefined4 param_5)

{
  undefined4 uVar1;
  
  uVar1 = func_021243ac(param_2,(int)*param_4,*(undefined4 *)(param_3 + 0x14),param_4[1],param_4[2],
                        (int)param_4[3],*(undefined4 *)(param_3 + 8),*(undefined4 *)(param_3 + 0xc),
                        *(undefined4 *)(param_3 + 0x18),param_5);
  func_021241c0(param_1,(int)*param_4,*(undefined4 *)(param_3 + 0x14),*(undefined4 *)(param_3 + 0xc)
                ,*(undefined4 *)(param_3 + 0x18));
  return uVar1;
}

