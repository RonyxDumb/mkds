/* Decompiled C draft; module arm9; ROM address 02134bd4. No matching claim. */
#include "types.h"
#include "deps/02134bd4_func_02134bd4.h"

uint func_02134bd4(undefined2 *param_1,char *param_2,uint param_3)

{
  size_t sVar1;
  int iVar2;
  uint uVar3;
  
  sVar1 = strlen(param_2);
  if (param_1 == (undefined2 *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = 0;
    if (param_3 != 0) {
      do {
        if (((*(uint *)((uint)param_2 & 0xfffffffc) >> ((uint)param_2 & 3) * 8 |
             *(uint *)((uint)param_2 & 0xfffffffc) << ((uint)param_2 & 3) * -8 + 0x20) & 0xff) == 0)
        {
          *param_1 = 0;
          return uVar3;
        }
        iVar2 = func_02134d08(param_1,param_2,sVar1);
        param_1 = param_1 + 1;
        if (iVar2 < 1) {
          return 0xffffffff;
        }
        param_2 = param_2 + iVar2;
        sVar1 = sVar1 - iVar2;
        uVar3 = uVar3 + 1;
      } while (uVar3 < param_3);
    }
  }
  return uVar3;
}

