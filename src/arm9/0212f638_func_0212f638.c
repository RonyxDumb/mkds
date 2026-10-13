/* Decompiled C draft; module arm9; ROM address 0212f638. No matching claim. */
#include "types.h"
#include "deps/0212f638_func_0212f638.h"

void func_0212f638(uint param_1)

{
  uint *puVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar2 = *(uint *)((uint)DAT_0212f718 & 0xfffffffc) >> ((uint)DAT_0212f718 & 3) * 8 |
          *(uint *)((uint)DAT_0212f718 & 0xfffffffc) << ((uint)DAT_0212f718 & 3) * -8 + 0x20;
  if (param_1 == uVar2) {
    return;
  }
  if (uVar2 == 1) {
    func_02020844(0);
  }
  uVar3 = Os_DisableIrq();
  Mem_CpuFill16(0,DAT_0212f71c,0xc0);
  puVar1 = DAT_0212f718;
  *DAT_0212f718 = param_1;
  switch(param_1) {
  case 0:
    puVar1[1] = DAT_0212f72c;
    break;
  case 1:
    puVar1[1] = DAT_0212f720;
    break;
  case 2:
    puVar1[1] = DAT_0212f724;
    break;
  case 3:
    puVar1[1] = DAT_0212f728;
    break;
  default:
    DAT_0212f718[1] = DAT_0212f72c;
  }
  Os_RestoreIrq(uVar3);
  if (param_1 != 1) {
    return;
  }
  func_02020844(0x3000);
  return;
}

