/* Decompiled C draft; module arm9_ov000; ROM address 021885ec. No matching claim. */
#include "types.h"
#include "deps/021885ec_FUN_021885ec.h"

void FUN_021885ec(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_02188584(1);
  if ((*(byte *)(iVar1 + 8) & 0x10) != 0) {
    uVar2 = FUN_02188584();
    *(byte *)(iVar1 + 8) = *(byte *)(iVar1 + 8) & 0xef;
    (**(code **)(iVar1 + 4))(0x10,uVar2,DAT_0218868c);
  }
  if ((*(byte *)(iVar1 + 8) & 8) != 0) {
    uVar2 = FUN_02188584();
    *(byte *)(iVar1 + 8) = *(byte *)(iVar1 + 8) & 0xf7;
    (**(code **)(iVar1 + 4))(8,uVar2,0xc);
  }
  if ((*(byte *)(iVar1 + 8) & 4) != 0) {
    uVar2 = FUN_02188584();
    *(byte *)(iVar1 + 8) = *(byte *)(iVar1 + 8) & 0xfb;
    (**(code **)(iVar1 + 4))(4,uVar2,0x58);
  }
  if ((*(byte *)(iVar1 + 8) & 2) != 0) {
    uVar2 = FUN_02188584();
    *(byte *)(iVar1 + 8) = *(byte *)(iVar1 + 8) & 0xfd;
    (**(code **)(iVar1 + 4))(2,uVar2,DAT_02188690);
  }
  if ((*(byte *)(iVar1 + 8) & 1) != 0) {
    *(byte *)(iVar1 + 8) = *(byte *)(iVar1 + 8) & 0xfe;
    (**(code **)(iVar1 + 4))(1,iVar1,0x18);
  }
  return;
}

