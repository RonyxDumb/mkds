/* Decompiled C draft; module arm9_ov003; ROM address 021cf284. No matching claim. */
#include "types.h"
#include "deps/021cf284_FUN_021cf284.h"

undefined4 FUN_021cf284(uint param_1)

{
  undefined4 uVar1;
  uint uVar2;
  undefined1 auStack_20 [4];
  ushort local_1c;
  ushort local_1a;
  ushort local_18;
  ushort local_16;
  ushort local_14;
  
  uVar1 = func_0x0200fca0();
  uVar2 = 1 << (param_1 & 0xff) & 0xffff;
  if ((*(ushort *)(*DAT_021cf328 + 2) & uVar2) == 0) {
    func_0x0200fcb4();
    return 0;
  }
  func_0x0214d1fc((ushort *)(uintptr_t)(*DAT_021cf328),(uint *)(void *)(auStack_20),0xe);
  func_0x0200fcb4(uVar1);
  if ((local_1c & uVar2) != 0) {
    return 2;
  }
  if ((local_1a & uVar2) != 0) {
    return 3;
  }
  if ((local_18 & uVar2) != 0) {
    return 4;
  }
  if ((local_16 & uVar2) != 0) {
    return 5;
  }
  if ((local_14 & uVar2) != 0) {
    return 6;
  }
  return 1;
}

