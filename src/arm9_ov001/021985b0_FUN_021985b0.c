/* Decompiled C draft; module arm9_ov001; ROM address 021985b0. No matching claim. */
#include "types.h"
#include "deps/021985b0_FUN_021985b0.h"

void FUN_021985b0(void)

{
  int iVar1;
  
  iVar1 = func_0x02125f54();
  if (iVar1 != 0) {
    func_0x02125fc0();
    return;
  }
  iVar1 = func_0x02125f88();
  if (iVar1 != 0) {
    if (*(char *)(*DAT_02198618 + 0x28) == '\0') {
      if (*(int *)(*DAT_0219861c + 0xc) == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = *(int *)(*DAT_0219861c + 0x10);
      }
    }
    else {
      iVar1 = 1;
    }
    if (iVar1 == 0) {
      iVar1 = func_0x02125f60();
      if (iVar1 == 0) {
        *(undefined2 *)(*DAT_02198620 + 0xe) = 3;
        return;
      }
      *(undefined2 *)(*DAT_02198620 + 0xe) = 0;
    }
  }
  return;
}

