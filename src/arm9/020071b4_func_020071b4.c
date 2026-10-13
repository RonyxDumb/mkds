/* Decompiled C draft; module arm9; ROM address 020071b4. No matching claim. */
#include "types.h"
#include "deps/020071b4_func_020071b4.h"

void func_020071b4(void)

{
  int iVar1;
  uint uVar2;
  ushort local_1e;
  ushort local_1c;
  ushort local_1a;
  ushort local_18;
  ushort local_16;
  
  Mem_CpuFill16(0,(int)(uintptr_t)(&local_1e),10);
  uVar2 = 1;
  do {
    switch(*(undefined4 *)(*DAT_020072b4 + (uVar2 - 1) * 4 + DAT_020072b8)) {
    case 2:
      local_1e = local_1e | (ushort)(1 << (uVar2 & 0xff));
      break;
    case 4:
      local_1a = local_1a | (ushort)(1 << (uVar2 & 0xff));
      break;
    case 5:
      local_1c = local_1c | (ushort)(1 << (uVar2 & 0xff));
      break;
    case 8:
      local_18 = local_18 | (ushort)(1 << (uVar2 & 0xff));
      break;
    case 0xb:
      local_16 = local_16 | (ushort)(1 << (uVar2 & 0xff));
    }
    uVar2 = uVar2 + 1 & 0xffff;
  } while (uVar2 < 0x10);
  if (local_18 == 0) {
    if (local_1e == 0) {
      if (local_16 == 0) {
        if (local_1a == 0) {
          if (local_1c == 0) {
            iVar1 = func_020072c0();
          }
          else {
            iVar1 = func_020074d8();
          }
        }
        else {
          iVar1 = func_020075f8(2);
        }
      }
      else {
        iVar1 = func_020075f8(6);
      }
    }
    else {
      iVar1 = func_020075f8(1);
    }
  }
  else {
    iVar1 = func_020075f8(5);
  }
  if (iVar1 == 0x15) {
    func_020075f8(0,DAT_020072bc);
  }
  return;
}

