/* Decompiled C draft; module arm9_ov000; ROM address 021823e4. No matching claim. */
#include "types.h"
#include "deps/021823e4_FUN_021823e4.h"

void FUN_021823e4(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  *(int *)(*DAT_02182468 + 0x10) = *(int *)(*DAT_02182468 + 0x10) + 1;
  iVar2 = func_0x02125fa4();
  if ((iVar2 != 0) && (*(int *)(*DAT_02182468 + 0x34) == 0)) {
    *(undefined4 *)(*DAT_02182468 + 0x34) = 1;
    func_0x0211fe18();
  }
  if ((((*(int *)(*DAT_02182468 + 0x34) != 0) && (iVar2 = func_0x0211fda8(), iVar2 != 0)) &&
      (0x5a < *(int *)(*DAT_02182468 + 0x10))) &&
     (iVar2 = func_0x02125fa4(), piVar1 = DAT_02182468, iVar2 != 0)) {
    *(undefined4 *)(*DAT_02182468 + 4) = 0xb;
    uVar3 = func_0x020b3f7c(*(undefined4 *)(*piVar1 + DAT_0218246c),0x19);
    uVar4 = func_0x020b3f7c(*(undefined4 *)(*DAT_02182468 + DAT_02182470),4);
    func_0x02126570(uVar3,uVar4);
    *(undefined4 *)(*DAT_02182468 + 0x10) = 0;
  }
  return;
}

