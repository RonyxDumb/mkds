/* Decompiled C draft; module arm9; ROM address 020cae8c. No matching claim. */
#include "types.h"
#include "deps/020cae8c_func_020cae8c.h"

void func_020cae8c(void)

{
  int *piVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 local_30 [10];
  
  puVar6 = local_30;
  iVar5 = 5;
  puVar7 = puRam020caef0;
  do {
    uVar3 = *puVar7;
    uVar4 = puVar7[1];
    puVar7 = puVar7 + 2;
    *puVar6 = uVar3;
    puVar6[1] = uVar4;
    puVar6 = puVar6 + 2;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  iVar5 = func_020ccccc();
  uVar2 = func_020ae488();
  piVar1 = piRam020caef4;
  *(undefined2 *)(*piRam020caef4 + iRam020caef8) = uVar2;
  if (9 < iVar5) {
    func_020ccc74(2,local_30[*(int *)(*piVar1 + iRam020caefc) * 2]);
    DoInitializeGlobalCA_from_thumb();
    iVar5 = GetGlobalCA_from_thumb();
    *(undefined4 *)(iVar5 + 200) = local_30[*(int *)(*piRam020caef4 + iRam020caefc) * 2 + 1];
  }
  func_020cb2d4();
  return;
}

