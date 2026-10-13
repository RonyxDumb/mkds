/* Decompiled C draft; module arm9_ov000; ROM address 02180d94. No matching claim. */
#include "types.h"
#include "deps/02180d94_FUN_02180d94.h"

void FUN_02180d94(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined1 auStack_27c [4];
  undefined1 auStack_278 [20];
  undefined1 auStack_264 [604];
  
  iVar2 = func_0x02125f54();
  if (iVar2 != 0) {
    func_0x02125fc0();
    return;
  }
  iVar2 = func_0x02125f88();
  piVar1 = DAT_02180e50;
  if (iVar2 != 0) {
    *(int *)(*DAT_02180e50 + 0x10) = *(int *)(*DAT_02180e50 + 0x10) + 1;
    iVar2 = FUN_0218151c(*(undefined4 *)(*piVar1 + 0x18),*(undefined4 *)(*piVar1 + 0x10),auStack_27c
                        );
    if (iVar2 != -1) {
      uVar3 = func_0x020b3f7c(*(undefined4 *)(*DAT_02180e50 + 0x38));
      uVar4 = func_0x020b3f7c(*(undefined4 *)(*DAT_02180e50 + 0x3c),6);
      func_0x02126570(uVar3,uVar4);
      return;
    }
    func_0x0214cfe4(0,auStack_278,0x14);
    func_0x02124fac(*(undefined4 *)(*DAT_02180e50 + 0x18),auStack_278);
    uVar3 = func_0x020b3f7c(*(undefined4 *)(*DAT_02180e50 + 0x38),0x30);
    func_0x0212513c(auStack_278,uVar3,auStack_264,DAT_02180e54);
    *(undefined4 *)(*DAT_02180e50 + 4) = 9;
    func_0x021266e4(auStack_264);
    func_0x02128374();
  }
  return;
}

