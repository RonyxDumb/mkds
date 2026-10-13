/* Decompiled C draft; module arm7; ROM address 03800610. No matching claim. */
#include "types.h"
#include "deps/03800610_FUN_03800610.h"

void FUN_03800610(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined2 local_28 [2];
  int local_24;
  undefined2 local_20 [2];
  int local_1c;
  
  iVar2 = 1;
  if (param_1 + param_2 != 0) {
    if (param_1 != 0) {
      local_28[0] = *DAT_038006e8;
      local_24 = param_1;
      while (iVar2 = FUN_0380076c(local_28), iVar2 != 0) {
        FUN_037fafd4(0);
      }
    }
    if (param_2 == 0) {
      iVar2 = FUN_03800700();
    }
    else {
      local_20[0] = *DAT_038006e8;
      local_1c = param_2 - param_1;
      iVar2 = 0;
      while ((iVar2 == 0 && (iVar1 = FUN_0380076c(local_20), iVar1 != 0))) {
        FUN_037fafd4(0);
        iVar2 = FUN_03800700();
      }
    }
  }
  if (iVar2 == 0) {
    *(undefined4 *)
     (*(uint *)(DAT_038006ec & 0xfffffffc) >> (DAT_038006ec & 3) * 8 |
     *(uint *)(DAT_038006ec & 0xfffffffc) << (DAT_038006ec & 3) * -8 + 0x20) = 4;
  }
  return;
}

