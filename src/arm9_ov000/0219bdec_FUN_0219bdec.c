/* Decompiled C draft; module arm9_ov000; ROM address 0219bdec. No matching claim. */
#include "types.h"
#include "deps/0219bdec_FUN_0219bdec.h"

undefined4
FUN_0219bdec(char *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  if ((*DAT_0219be9c != 0) && (iVar2 = FUN_0219c39c(), iVar2 == 0)) {
    iVar4 = *DAT_0219be9c;
    iVar2 = *(int *)(iVar4 + 0x24);
    if ((2 < iVar2) && (iVar2 != 4)) {
      if ((param_1 == (char *)0x0) || (*param_1 == '\0')) {
        iVar2 = 0;
      }
      else {
        uVar3 = func_0x0213a434(param_1);
        if (uVar3 < 0x20) {
          iVar2 = func_0x0213a434(param_1);
        }
        else {
          iVar2 = 0x1f;
        }
        func_0x0214d1fc((ushort *)(void *)(param_1),(uint *)(uintptr_t)(iVar4 + 0x34),iVar2);
      }
      piVar1 = DAT_0219be9c;
      *(undefined1 *)(*DAT_0219be9c + iVar2 + 0x34) = 0;
      *(undefined4 *)(*piVar1 + 100) = param_2;
      *(undefined4 *)(*piVar1 + 0x68) = param_3;
      FUN_0219b8a8(4);
      FUN_0219d770(*DAT_0219be9c + 0xd0,*DAT_0219be9c + DAT_0219bea0,DAT_0219bea4,0,param_4,param_5,
                   param_6,param_7);
      return 1;
    }
  }
  return 0;
}

