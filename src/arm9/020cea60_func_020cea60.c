/* Decompiled C draft; module arm9; ROM address 020cea60. No matching claim. */
#include "types.h"
#include "deps/020cea60_func_020cea60.h"

void func_020cea60(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 auStack_2c [9];
  
  puVar5 = auStack_2c + 3;
  iVar4 = 3;
  puVar6 = DAT_020ceaf4;
  do {
    uVar1 = *puVar6;
    uVar3 = puVar6[1];
    puVar6 = puVar6 + 2;
    *puVar5 = uVar1;
    puVar5[1] = uVar3;
    puVar5 = puVar5 + 2;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  iVar4 = func_0x0219c80c();
  switch(iVar4) {
  case 0:
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
    iVar2 = GetGlobalCA_from_thumb();
    *(undefined4 *)(iVar2 + 0xd0) = auStack_2c[iVar4 + 3];
    func_020ccc74(0x1d,0x1f);
    break;
  case -3:
    func_020ccc74(0x10,0x1f);
    break;
  case -2:
    func_020ccc74(0xe,0x1f);
    func_020ceb0c(0);
    func_020ceaf8(1);
    break;
  case -1:
    func_020ccc74(0x1b,0x1f);
    func_020ceb0c(0);
    func_020ceaf8(1);
  }
  return;
}

