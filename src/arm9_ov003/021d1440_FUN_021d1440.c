/* Decompiled C draft; module arm9_ov003; ROM address 021d1440. No matching claim. */
#include "types.h"
#include "deps/021d1440_FUN_021d1440.h"

undefined4 FUN_021d1440(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = func_0x0213a434();
  iVar2 = func_0x0213a434(param_2);
  if ((param_3 <= iVar1) && (param_3 <= iVar2)) {
    iVar1 = func_0x02134d30(param_1 + (iVar1 - param_3),param_2 + (iVar2 - param_3),param_3);
    if (iVar1 == 0) {
      return 1;
    }
    return 0;
  }
  return 0;
}

