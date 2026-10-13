/* Decompiled C draft; module arm9_ov003; ROM address 021cf64c. No matching claim. */
#include "types.h"
#include "deps/021cf64c_FUN_021cf64c.h"

undefined4 FUN_021cf64c(void)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  
  piVar1 = DAT_021cf698;
  if (*(short *)(*DAT_021cf698 + 2) == 0) {
    return 0;
  }
  uVar3 = 1;
  while ((((uint)*(ushort *)(*piVar1 + 2) & 1 << (uVar3 & 0xff)) == 0 ||
         (iVar2 = func_0x02007df8(uVar3), iVar2 != 0))) {
    uVar3 = uVar3 + 1 & 0xffff;
    if (0xf < uVar3) {
      return 1;
    }
  }
  return 0;
}

