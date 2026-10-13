/* Decompiled C draft; module arm9_ov001; ROM address 0219b3b4. No matching claim. */
#include "types.h"
#include "deps/0219b3b4_FUN_0219b3b4.h"

void FUN_0219b3b4(int param_1,undefined4 param_2)

{
  undefined1 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  
  uVar2 = FUN_0219b4d8(param_2);
  func_0x020364e8();
  uVar3 = func_0x020364e0();
  uVar3 = func_0x02036bec(uVar3,0x38);
  *(undefined4 *)(param_1 + 0x1c) = uVar3;
  iVar4 = func_0x02013a30(uVar2);
  uVar1 = *(undefined1 *)(iVar4 + 9);
  func_0x020364e8();
  uVar3 = func_0x020364e0();
  func_0x0208823c(0,*(undefined4 *)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0x10),uVar1,uVar3,
                  *(undefined4 *)(param_1 + 0x18));
  func_0x020364e8();
  uVar3 = func_0x020364e0();
  func_0x0208805c(*(undefined4 *)(param_1 + 0x1c),uVar2,uVar3);
  func_0x02087f84(*(undefined4 *)(param_1 + 0x1c),0);
  return;
}

