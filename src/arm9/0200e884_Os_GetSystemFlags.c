/* Decompiled C draft; module arm9; ROM address 0200e884. No matching claim. */
#include "types.h"
#include "deps/0200e884_Os_GetSystemFlags.h"

uint Os_GetSystemFlags(void)

{
  uint uVar1;
  int iVar2;
  
  if ((*(uint *)((uint)puRam0200e8f4 & 0xfffffffc) >> ((uint)puRam0200e8f4 & 3) * 8 |
      *(uint *)((uint)puRam0200e8f4 & 0xfffffffc) << ((uint)puRam0200e8f4 & 3) * -8 + 0x20) ==
      0xffffffff) {
    uVar1 = Os_GetDebugSystemFlags();
    iVar2 = Os_IsEmulator();
    if (iVar2 == 0) {
      iVar2 = Os_ExistsSioConnection();
      if (iVar2 == 0) {
        if ((uVar1 & 0x1000000) == 0) {
          uVar1 = uVar1 | 0x80000000;
        }
        else {
          uVar1 = uVar1 | 0x20000000;
        }
      }
      else {
        uVar1 = uVar1 | 0x40000000;
      }
    }
    else {
      uVar1 = uVar1 | 0x10000000;
    }
    *puRam0200e8f4 = uVar1 | *puRam0200e8f8;
  }
  return *(uint *)((uint)puRam0200e8f4 & 0xfffffffc) >> ((uint)puRam0200e8f4 & 3) * 8 |
         *(uint *)((uint)puRam0200e8f4 & 0xfffffffc) << ((uint)puRam0200e8f4 & 3) * -8 + 0x20;
}

