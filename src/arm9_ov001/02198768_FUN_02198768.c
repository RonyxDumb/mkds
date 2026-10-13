/* Decompiled C draft; module arm9_ov001; ROM address 02198768. No matching claim. */
#include "types.h"
#include "deps/02198768_FUN_02198768.h"

void FUN_02198768(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  iVar2 = func_0x02036c5c();
  piVar1 = DAT_021987b8;
  if (iVar2 != 0) {
    *(undefined4 *)(*DAT_021987b8 + 4) = 1;
    uVar3 = func_0x020b3f7c(*(undefined4 *)(*piVar1 + 0x14),0xc);
    uVar4 = func_0x020b3f7c(*(undefined4 *)(*DAT_021987b8 + 0x14),0);
    uVar5 = func_0x020b3f7c(*(undefined4 *)(*DAT_021987b8 + 0x14),1);
    func_0x0212611c(uVar3,uVar4,uVar5,0);
  }
  return;
}

