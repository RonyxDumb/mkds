/* Decompiled C draft; module arm9_ov003; ROM address 021c1fc8. No matching claim. */
#include "types.h"
#include "deps/021c1fc8_FUN_021c1fc8.h"

void FUN_021c1fc8(void)

{
  int *piVar1;
  int iVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  undefined2 local_110;
  undefined2 local_10e [2];
  undefined1 auStack_10a [258];
  
  puVar5 = &local_110;
  iVar2 = FUN_021d283c(DAT_021c2068,4);
  *DAT_021c206c = iVar2;
  *DAT_021c2070 = 0;
  local_110 = 0;
  func_0x0214cfe4(0,local_10e,DAT_021c2074);
  local_10e[0]._0_1_ = 0x50;
  local_10e[1] = 0xc;
  func_0x0214d1fc(DAT_021c2078,auStack_10a);
  piVar1 = DAT_021c206c;
  *(undefined2 *)*DAT_021c206c = 3;
  puVar4 = (undefined2 *)*piVar1;
  iVar2 = 0x82;
  puVar3 = puVar4;
  do {
    puVar5 = puVar5 + 1;
    puVar3 = puVar3 + 1;
    *puVar3 = *puVar5;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined2 *)((int)puVar4 + DAT_021c207c) = 1;
  piVar1 = DAT_021c206c;
  *(undefined2 *)(*DAT_021c206c + DAT_021c2080) = 0xffff;
  *(undefined2 *)(*piVar1 + DAT_021c2084) = 1;
  *(undefined2 *)(*piVar1 + DAT_021c2088) = 0xffff;
  *(undefined2 *)(*piVar1 + DAT_021c208c) = 0xffff;
  func_0x0200fe58(*piVar1 + DAT_021c2090);
  iVar2 = FUN_021ba61c(DAT_021c2094,DAT_021c2098);
  if (iVar2 != 0) {
    func_0x0200fd1c();
  }
  return;
}

