/* Decompiled C draft; module arm9; ROM address 0200f4f0. No matching claim. */
#include "types.h"
#include "deps/0200f4f0_Os_InitializeExceptionHandler.h"

void Os_InitializeExceptionHandler(void)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = *(uint *)((uint)puRam0200f56c & 0xfffffffc) >> ((uint)puRam0200f56c & 3) * 8 |
          *(uint *)((uint)puRam0200f56c & 0xfffffffc) << ((uint)puRam0200f56c & 3) * -8 + 0x20;
  if ((uVar3 < 0x2600000) || (0x27fffff < uVar3)) {
    *puRam0200f570 = 0;
  }
  else {
    *puRam0200f570 = uVar3;
  }
  if ((*(uint *)((uint)puRam0200f570 & 0xfffffffc) >> ((uint)puRam0200f570 & 3) * 8 == 0 &&
       *(uint *)((uint)puRam0200f570 & 0xfffffffc) << ((uint)puRam0200f570 & 3) * -8 + 0x20 == 0) ||
     (uVar3 = Os_GetSystemFlags(), (uVar3 & 0x40000000) == 0)) {
    iVar2 = iRam0200f578;
    uVar1 = uRam0200f574;
    *puRam0200f56c = uRam0200f574;
    *(undefined4 *)(iVar2 + 0xfdc) = uVar1;
  }
  *puRam0200f57c = 0;
  return;
}

