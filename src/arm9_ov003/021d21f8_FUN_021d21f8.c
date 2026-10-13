/* Decompiled C draft; module arm9_ov003; ROM address 021d21f8. No matching claim. */
#include "types.h"
#include "deps/021d21f8_FUN_021d21f8.h"

void FUN_021d21f8(undefined4 param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  
  if (*param_2 != '\0') {
    iVar1 = *DAT_021d2270;
    if (param_2 == (char *)(iVar1 + DAT_021d2274)) {
      iVar2 = (uint)DAT_021d2278[1] * (uint)*DAT_021d2278 * 0x20;
      func_0x0200ee74(*(undefined4 *)(iVar1 + DAT_021d227c),iVar2);
      func_0x0214bafc(*(undefined4 *)(*DAT_021d2270 + DAT_021d227c),(uint)*DAT_021d2280 << 5,iVar2);
    }
    else {
      iVar2 = (uint)DAT_021d2278[3] * (uint)DAT_021d2278[2] * 0x20;
      func_0x0200ee74(*(undefined4 *)(iVar1 + DAT_021d2284),iVar2);
      func_0x0214ba94(*(undefined4 *)(*DAT_021d2270 + DAT_021d2284),(uint)DAT_021d2280[1] << 5,iVar2
                     );
    }
    *param_2 = '\0';
  }
  return;
}

