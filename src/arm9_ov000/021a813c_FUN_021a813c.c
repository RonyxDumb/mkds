/* Decompiled C draft; module arm9_ov000; ROM address 021a813c. No matching claim. */
#include "types.h"
#include "deps/021a813c_FUN_021a813c.h"

int FUN_021a813c(int param_1,int param_2,int param_3,uint *param_4,int param_5)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_20;
  
  iVar2 = *(int *)(param_1 + 0x68);
  if (param_2 < param_3) {
    param_3 = param_2;
  }
  uVar1 = func_0x0200fca0();
  do {
    local_20 = FUN_021a8118(param_1);
    if (param_3 <= local_20) {
      if (param_2 <= local_20) {
        local_20 = param_2;
      }
      *param_4 = (uint)*(ushort *)(iVar2 + DAT_021a81a0);
LAB_021a818e:
      func_0x0200fcb4(uVar1);
      return local_20;
    }
    if (param_5 == 0) {
      local_20 = 0;
      goto LAB_021a818e;
    }
    func_0x0200e01c(iVar2 + DAT_021a81a4);
  } while( true );
}

