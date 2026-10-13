/* Decompiled C draft; module arm9_ov000; ROM address 021a6470. No matching claim. */
#include "types.h"
#include "deps/021a6470_FUN_021a6470.h"

undefined4 FUN_021a6470(uint param_1,uint param_2)

{
  uint *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = func_0x0200fca0();
  puVar1 = DAT_021a6530;
  if (*DAT_021a6530 != 0) {
    func_0x0200fcb4();
    return 1;
  }
  if (param_1 == 0) {
    func_0x0200fcb4();
    return 1;
  }
  if ((param_1 & 0x1f) != 0) {
    func_0x0200fcb4();
    return 1;
  }
  if (param_2 < DAT_021a6534) {
    func_0x0200fcb4();
    return 6;
  }
  *DAT_021a6530 = param_1;
  *(undefined4 *)(param_1 + DAT_021a6538) = 1;
  *(undefined2 *)(*puVar1 + DAT_021a653c) = 0;
  *(undefined2 *)(*puVar1 + DAT_021a6540) = 0;
  *(undefined1 *)(*puVar1 + DAT_021a6544) = 0;
  *(undefined1 *)(*puVar1 + DAT_021a6548) = 0;
  *(undefined2 *)(*puVar1 + DAT_021a654c) = 0;
  *(undefined2 *)(*puVar1 + DAT_021a6550) = 0;
  FUN_021a5930();
  FUN_021a6bdc();
  iVar3 = func_0x0200f6e4();
  if (iVar3 == 0) {
    func_0x0200f6f4();
  }
  iVar3 = func_0x0200fb18();
  if (iVar3 == 0) {
    func_0x0200fb28();
  }
  func_0x0200fb08(*DAT_021a6530 + DAT_021a6554);
  func_0x0200fcb4(uVar2);
  return 0;
}

