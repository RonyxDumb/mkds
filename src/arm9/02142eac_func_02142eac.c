/* Decompiled C draft; module arm9; ROM address 02142eac. No matching claim. */
#include "types.h"
#include "deps/02142eac_func_02142eac.h"

uint func_02142eac(void)

{
  uint uVar1;
  int iVar2;
  undefined1 auStack_10 [4];
  int local_c;
  int local_8;
  
  if ((*(uint *)((uint)puRam02142f20 & 0xfffffffc) >> ((uint)puRam02142f20 & 3) * 8 |
      *(uint *)((uint)puRam02142f20 & 0xfffffffc) << ((uint)puRam02142f20 & 3) * -8 + 0x20) ==
      0x10000) {
    Rtc_Initialize();
    iVar2 = Rtc_GetTime((undefined4)(uintptr_t)(auStack_10));
    if (iVar2 == 0) {
      *puRam02142f20 = local_8 + local_c * 0x100 & 0xffff;
    }
  }
  uVar1 = (*(uint *)((uint)puRam02142f20 & 0xfffffffc) >> ((uint)puRam02142f20 & 3) * 8 |
          *(uint *)((uint)puRam02142f20 & 0xfffffffc) << ((uint)puRam02142f20 & 3) * -8 + 0x20) + 1
          & 0xffff;
  *puRam02142f20 = uVar1;
  return uVar1;
}

