/* Decompiled C draft; module arm9; ROM address 0214dfbc. No matching claim. */
#include "types.h"
#include "deps/0214dfbc_Rtc_GetTimeAsync.h"

undefined4 Rtc_GetTimeAsync(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  Os_DisableIrq();
  if (*(uint *)((uint)puRam0214e034 & 0xfffffffc) >> ((uint)puRam0214e034 & 3) * 8 == 0 &&
      *(uint *)((uint)puRam0214e034 & 0xfffffffc) << ((uint)puRam0214e034 & 3) * -8 + 0x20 == 0) {
    *puRam0214e034 = 1;
    Os_RestoreIrq();
    puVar1 = puRam0214e034;
    puRam0214e034[5] = 1;
    puVar1[6] = 0;
    puVar1[2] = param_1;
    puVar1[1] = param_2;
    puVar1[4] = param_3;
    iVar2 = Rtc_ReadRawTimeAsync();
    if (iVar2 == 0) {
      uVar3 = 3;
    }
    else {
      uVar3 = 0;
    }
    return uVar3;
  }
  Os_RestoreIrq();
  return 1;
}

