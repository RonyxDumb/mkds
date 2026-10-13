/* Decompiled C draft; module arm9_ov003; ROM address 021c7748. No matching claim. */
#include "types.h"
#include "deps/021c7748_FUN_021c7748.h"

void FUN_021c7748(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 local_28 [4];
  undefined1 local_24;
  int local_20;
  undefined4 local_1c [4];
  undefined4 local_c;
  
  local_1c[0] = *DAT_021c7828;
  local_1c[1] = DAT_021c7828[1];
  local_1c[2] = DAT_021c7828[2];
  local_1c[3] = DAT_021c7828[3];
  local_c = DAT_021c7828[4];
  local_28[0] = *DAT_021c782c;
  local_28[1] = DAT_021c782c[1];
  local_28[2] = DAT_021c782c[2];
  local_28[3] = DAT_021c782c[3];
  local_24 = DAT_021c782c[4];
  iVar2 = FUN_021d283c(0x18,4);
  *DAT_021c7830 = iVar2;
  FUN_021c20dc(&local_20,0);
  (*(code *)local_1c[local_20])(*DAT_021c7830 + 8);
  iVar4 = *DAT_021c7830;
  iVar2 = func_0x02134d30(iVar4 + 8,DAT_021c7834,3);
  if (iVar2 == 0) {
    func_0x0214d168((uint *)(uintptr_t)(iVar4 + 8),0,0xc);
    *(undefined1 *)(*DAT_021c7830 + 0x14) = 0;
  }
  else {
    *(undefined1 *)(iVar4 + 0x14) = 3;
  }
  FUN_021c76b4();
  FUN_021bf86c(local_20 + 0xb);
  FUN_021bf43c(local_28[local_20],0xffffffff);
  FUN_021bf5ec(2);
  uVar3 = FUN_021d2288(0,0);
  *(undefined4 *)*DAT_021c7830 = uVar3;
  uVar3 = FUN_021d1c18(0,0x3f);
  piVar1 = DAT_021c7830;
  *(undefined4 *)(*DAT_021c7830 + 4) = uVar3;
  *(ushort *)(*(int *)(*piVar1 + 4) + 4) =
       *(ushort *)(*(int *)(*piVar1 + 4) + 4) & (ushort)DAT_021c7838 | (ushort)DAT_021c783c;
  FUN_021c7160();
  FUN_021c71a0();
  FUN_021c212c(DAT_021c7840);
  return;
}

