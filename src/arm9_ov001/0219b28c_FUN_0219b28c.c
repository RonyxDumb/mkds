/* Decompiled C draft; module arm9_ov001; ROM address 0219b28c. No matching claim. */
#include "types.h"
#include "deps/0219b28c_FUN_0219b28c.h"

void FUN_0219b28c(int param_1,undefined4 param_2)

{
  undefined1 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  func_0x020364e8();
  uVar2 = func_0x020364e0();
  uVar2 = func_0x02036bec(uVar2,0x38);
  *(undefined4 *)(param_1 + 0x1c) = uVar2;
  iVar3 = func_0x02013a30(param_2);
  uVar1 = *(undefined1 *)(iVar3 + 9);
  func_0x020364e8();
  uVar2 = func_0x020364e0();
  func_0x0208823c(0,*(undefined4 *)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0x10),uVar1,uVar2,
                  *(undefined4 *)(param_1 + 0x18));
  func_0x020364e8();
  uVar2 = func_0x020364e0();
  func_0x0208805c(*(undefined4 *)(param_1 + 0x1c),param_2,uVar2);
  func_0x02087f84(*(undefined4 *)(param_1 + 0x1c),0);
  return;
}

