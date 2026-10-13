/* Decompiled C draft; module arm9_ov001; ROM address 0219ca94. No matching claim. */
#include "types.h"
#include "deps/0219ca94_FUN_0219ca94.h"

void FUN_0219ca94(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  iVar2 = func_0x02128294();
  piVar1 = DAT_0219caec;
  if (iVar2 != 0) {
    *(undefined4 *)(*DAT_0219caec + 0x28) = 0xfffffffe;
    uVar3 = func_0x020b3f7c(*(undefined4 *)(*piVar1 + DAT_0219caf0),0x14);
    uVar4 = func_0x020b3f7c(*(undefined4 *)(*DAT_0219caec + DAT_0219caf0),0x15);
    func_0x021277f8(uVar3,uVar4,0);
    func_0x0212775c(0,5);
    func_0x0212775c(1,0xc);
    *(undefined4 *)(*DAT_0219caec + 4) = 5;
  }
  return;
}

