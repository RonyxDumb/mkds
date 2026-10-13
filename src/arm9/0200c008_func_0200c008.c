/* Decompiled C draft; module arm9; ROM address 0200c008. No matching claim. */
#include "types.h"
#include "deps/0200c008_func_0200c008.h"

void func_0200c008(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = piRam0200c088;
  *(undefined2 *)(*piRam0200c088 + 0x1a) = 0;
  *(undefined2 *)(*piVar1 + 0x1c) = 0;
  *(ushort *)(*piVar1 + 0x10) = *(short *)(param_1 + 0x4e) + 0x21U & 0xffe0;
  *(short *)(*piVar1 + 0x12) = (short)((*(ushort *)(param_1 + 0x4c) + 0x55 & 0xffffffe0) << 1);
  *(undefined2 *)(*piVar1 + 0x14) = *(undefined2 *)(param_1 + 0x4c);
  *(undefined2 *)(*piVar1 + 0x16) = *(undefined2 *)(param_1 + 0x4e);
  *(short *)(*piVar1 + 0x18) = *(short *)(*piVar1 + 0x14) + -6;
  func_0200c448(*(undefined2 *)(*piVar1 + 0x16));
  iVar2 = func_021437d8(uRam0200c08c,(ushort *)(uintptr_t)(param_1),0,1,0);
  if ((iVar2 != 2) && (*(code **)*piRam0200c088 != (code *)0x0)) {
    (**(code **)*piRam0200c088)(0xb,0);
  }
  return;
}

