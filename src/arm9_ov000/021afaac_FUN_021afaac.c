/* Decompiled C draft; module arm9_ov000; ROM address 021afaac. No matching claim. */
#include "types.h"
#include "deps/021afaac_FUN_021afaac.h"

void FUN_021afaac(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
                 ushort param_6)

{
  int iVar1;
  int iVar2;
  
  *(ushort *)(param_1 + -2) = param_6 >> 8 | param_6 << 8;
  iVar1 = FUN_021b0094(param_5);
  if (iVar1 == 0) {
    iVar1 = FUN_021b00e0(param_5);
    if (iVar1 == 0) {
      return;
    }
    iVar2 = FUN_021afd00();
    if (iVar2 == 0) {
      iVar2 = FUN_021afc20(iVar1);
    }
    if (iVar2 == 0) {
      return;
    }
    func_0x0214d1fc((ushort *)(uintptr_t)(iVar2),(uint *)(uintptr_t)(param_1 + -0xe),6);
  }
  else {
    *(undefined1 *)(param_1 + -0xe) = 1;
    *(undefined1 *)(param_1 + -0xd) = 0;
    *(undefined1 *)(param_1 + -0xc) = 0x5e;
    *(byte *)(param_1 + -0xb) = (byte)((uint)param_5 >> 0x10) & 0x7f;
    *(char *)(param_1 + -10) = (char)((uint)param_5 >> 8);
    *(char *)(param_1 + -9) = (char)param_5;
  }
  func_0x0214d1fc((ushort *)(uintptr_t)(DAT_021afb54),(uint *)(uintptr_t)(param_1 + -8),6);
  FUN_021affcc(param_1 + -0xe,param_2 + 0xe,param_3,param_4);
  return;
}

