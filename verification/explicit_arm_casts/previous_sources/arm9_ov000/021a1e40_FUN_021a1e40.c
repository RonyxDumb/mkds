/* Decompiled C draft; module arm9_ov000; ROM address 021a1e40. No matching claim. */
#include "types.h"
#include "deps/021a1e40_FUN_021a1e40.h"

undefined4 FUN_021a1e40(undefined4 param_1,undefined4 param_2,int param_3,char *param_4,int param_5)

{
  char cVar1;
  int iVar2;
  undefined1 uStack_20;
  undefined1 local_1f;
  ushort local_1e;
  undefined4 local_1c;
  undefined4 local_18;
  
  if ((param_5 != 0) && (param_4 != (char *)0x0)) {
    local_18 = 0;
    func_0x0214d018(0,&uStack_20,8);
    local_1f = 2;
    local_1e = (ushort)((uint)param_3 >> 8) & 0xff | (ushort)(param_3 << 8) & (ushort)DAT_021a1ee8;
    cVar1 = *param_4;
    local_1c = param_2;
    if (((cVar1 == -2) && (param_4[1] == -3)) || (cVar1 == '\\')) {
      if (*(int *)(*DAT_021a1eec + 0x10) != 0) {
        FUN_021a3c14(*(int *)(*DAT_021a1eec + 0x10),param_4,param_5,&uStack_20);
      }
    }
    else {
      iVar2 = func_0x02134d30(param_4,DAT_021a1ef0,6);
      if (iVar2 != 0) {
        if (cVar1 == -2) {
          return 0;
        }
        return 0;
      }
      FUN_0219a7e4(param_4,param_5,&uStack_20);
    }
    return 1;
  }
  return 0;
}

