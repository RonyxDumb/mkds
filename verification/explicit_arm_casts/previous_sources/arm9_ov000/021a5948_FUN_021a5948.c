/* Decompiled C draft; module arm9_ov000; ROM address 021a5948. No matching claim. */
#include "types.h"
#include "deps/021a5948_FUN_021a5948.h"

void FUN_021a5948(int param_1,char *param_2,undefined4 param_3)

{
  int *piVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  
  FUN_021a5b3c(param_3);
  piVar1 = DAT_021a5a34;
  *(int *)(*DAT_021a5a34 + DAT_021a5a3c) = *DAT_021a5a34 + DAT_021a5a38;
  *(short *)(*piVar1 + DAT_021a5a44) = (short)DAT_021a5a40;
  uVar3 = FUN_021a58dc(0);
  piVar1 = DAT_021a5a34;
  *(short *)(*DAT_021a5a34 + DAT_021a5a48) = (short)((1 << (uVar3 & 0xff)) >> 1);
  sVar2 = *(short *)(*piVar1 + DAT_021a5a4c);
  if (sVar2 == 0) {
    sVar2 = func_0x02143090();
  }
  piVar1 = DAT_021a5a34;
  *(short *)(*DAT_021a5a34 + DAT_021a5a50) = sVar2;
  *(ushort *)(*piVar1 + DAT_021a5a5c) =
       (ushort)((*(uint *)(*piVar1 + DAT_021a5a54) & DAT_021a5a58) != DAT_021a5a58);
  if (param_1 == 0) {
    func_0x0214d1fc(DAT_021a5a60,*DAT_021a5a34 + DAT_021a5a64,6);
  }
  else {
    func_0x0214d1fc(param_1,*DAT_021a5a34 + DAT_021a5a64,6);
  }
  if ((param_2 == (char *)0x0) || (param_2 == DAT_021a5a68)) {
    func_0x0214d1fc(DAT_021a5a68,*DAT_021a5a34 + DAT_021a5a6c,0x20);
    *(undefined2 *)(*DAT_021a5a34 + DAT_021a5a70) = 0;
  }
  else {
    func_0x0214d1fc(param_2,*DAT_021a5a34 + DAT_021a5a6c,0x20);
    iVar4 = 0;
    do {
      if (*param_2 == '\0') break;
      param_2 = param_2 + 1;
      iVar4 = iVar4 + 1;
    } while (iVar4 < 0x20);
    *(short *)(*DAT_021a5a34 + DAT_021a5a70) = (short)iVar4;
  }
  *(undefined4 *)(*DAT_021a5a34 + DAT_021a5a74) = 0;
  return;
}

