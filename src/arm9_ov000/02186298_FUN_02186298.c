/* Decompiled C draft; module arm9_ov000; ROM address 02186298. No matching claim. */
#include "types.h"
#include "deps/02186298_FUN_02186298.h"

undefined4 FUN_02186298(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = func_0x0213a074(*DAT_0218633c,DAT_02186340);
  if (iVar2 != 0) {
    DAT_0218633c[6] = 1;
  }
  iVar2 = FUN_021873d4((undefined1 *)(uintptr_t)(*(undefined4 *)(*DAT_02186344 + DAT_02186348)),DAT_0218633c);
  if (iVar2 != 0) {
    return 4;
  }
  if (param_1 == 1) {
    func_0x02151910((undefined4 *)(uintptr_t)(DAT_0218634c));
  }
  iVar2 = *DAT_02186344;
  uVar3 = FUN_02185984(*(undefined4 *)(iVar2 + DAT_02186348),iVar2 + DAT_02186350,
                       iVar2 + DAT_02186354,(int *)(uintptr_t)(iVar2 + DAT_02186358),0x20,0);
  piVar1 = DAT_02186344;
  *(undefined4 *)(*DAT_02186344 + 4) = uVar3;
  if (*(int *)(*piVar1 + 4) != 0) {
    return 4;
  }
  iVar2 = FUN_0218735c(*(undefined4 *)(*piVar1 + DAT_02186348));
  if (iVar2 != 0) {
    return 4;
  }
  FUN_021872bc(*(undefined4 *)(*DAT_02186344 + DAT_02186348));
  return 0;
}

