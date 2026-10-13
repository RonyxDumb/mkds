/* Decompiled C draft; module arm9; ROM address 0202c884. No matching claim. */
#include "types.h"
#include "deps/0202c884_func_0202c884.h"

void func_0202c884(int param_1,int param_2)

{
  int iVar1;
  undefined1 auStack_26 [22];
  
  iVar1 = *piRam0202c8d4;
  Mem_CpuFill16(0,auStack_26,0x16);
  *(undefined2 *)(param_2 + 0x14) = 0;
  GetClampedString10LengthForFontIndex0_from_thumb(param_2,auStack_26);
  func_0212426c(0,(int)*(short *)(*piRam0202c8d8 + param_1 * 8),*(undefined4 *)(iVar1 + 0x14),
                auStack_26,*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 0x18));
  return;
}

