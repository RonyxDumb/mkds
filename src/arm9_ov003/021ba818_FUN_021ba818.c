/* Decompiled C draft; module arm9_ov003; ROM address 021ba818. No matching claim. */
#include "types.h"
#include "deps/021ba818_FUN_021ba818.h"

undefined4 FUN_021ba818(undefined4 param_1,int param_2,int param_3)

{
  uint *puVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  uVar2 = func_0x0200fca0();
  *DAT_021ba8ec = param_2;
  puVar1 = DAT_021ba8f0;
  uVar5 = param_2 + 0x53U & 0xfffffffc;
  *DAT_021ba8f0 = uVar5;
  uVar4 = uVar5 + 0x2f & 0xffffffe0;
  *DAT_021ba8f4 = uVar4;
  uVar4 = uVar4 + DAT_021ba8f8 & 0xffffffe0;
  *DAT_021ba8fc = uVar4;
  *(uint *)(uVar5 + 4) = uVar4 + 0xc0;
  *(int *)(*puVar1 + 8) = (param_2 + param_3) - *(int *)(*puVar1 + 4);
  *(undefined4 *)(*puVar1 + 0xc) = 0;
  *(undefined4 *)*puVar1 = 3;
  *DAT_021ba900 = param_1;
  if (*DAT_021ba904 == 0) {
    iVar3 = func_0x021a6470(*DAT_021ba8f4,DAT_021ba908);
    if (iVar3 != 0) {
      func_0x0200fcb4(uVar2);
      return 0;
    }
    *DAT_021ba904 = 1;
  }
  if (*DAT_021ba904 == 1) {
    iVar3 = func_0x021a629c(*DAT_021ba8f0,DAT_021ba90c);
    if (iVar3 != 3) {
      func_0x0200fcb4(uVar2);
      return 0;
    }
    *DAT_021ba904 = 4;
    func_0x0200fcb4(uVar2);
    return 1;
  }
  func_0x0200fcb4(uVar2);
  return 0;
}

