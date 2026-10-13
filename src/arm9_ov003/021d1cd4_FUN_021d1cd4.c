/* Decompiled C draft; module arm9_ov003; ROM address 021d1cd4. No matching claim. */
#include "types.h"
#include "deps/021d1cd4_FUN_021d1cd4.h"

undefined4 FUN_021d1cd4(ushort *param_1)

{
  undefined1 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  uVar2 = func_0x0200ca9c(1);
  if ((uint)(byte)param_1[1] != (uint)*(byte *)((int)param_1 + 3)) {
    uVar1 = func_0x02147cd8((uint)*(byte *)((int)param_1 + 3) + (uint)*param_1 + -1);
    *(undefined1 *)((int)param_1 + 3) = uVar1;
    uVar3 = *(undefined4 *)(param_1 + (uint)*(byte *)((int)param_1 + 3) * 2 + 2);
  }
  func_0x0200cae4(uVar2);
  return uVar3;
}

