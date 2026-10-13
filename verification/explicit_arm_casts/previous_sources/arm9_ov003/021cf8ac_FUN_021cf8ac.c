/* Decompiled C draft; module arm9_ov003; ROM address 021cf8ac. No matching claim. */
#include "types.h"
#include "deps/021cf8ac_FUN_021cf8ac.h"

undefined4 FUN_021cf8ac(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 *puVar5;
  undefined1 auStack_58 [72];
  
  puVar5 = auStack_58;
  uVar4 = 0;
  if (*param_1 == 0) {
    puVar5 = (undefined1 *)0x0;
  }
  else {
    func_0x02004d80(auStack_58);
    iVar3 = func_0x02004a30(auStack_58,*param_1);
    if (iVar3 == 0) {
      return 0;
    }
  }
  iVar2 = func_0x02008880(puVar5);
  iVar3 = DAT_021cf934;
  piVar1 = DAT_021cf930;
  if (iVar2 != 0) {
    *(int *)(*DAT_021cf930 + DAT_021cf934) = *DAT_021cf930 + 0x2c;
    if (((*(int *)(*piVar1 + iVar3) != 0) &&
        (iVar3 = func_0x02008570(puVar5,*(int *)(*piVar1 + iVar3),DAT_021cf938), iVar3 != 0)) &&
       (iVar3 = func_0x02008310(param_1,*(undefined4 *)(*DAT_021cf930 + DAT_021cf934)), iVar3 != 0))
    {
      uVar4 = 1;
    }
  }
  if (puVar5 == auStack_58) {
    func_0x020049e8();
  }
  return uVar4;
}

