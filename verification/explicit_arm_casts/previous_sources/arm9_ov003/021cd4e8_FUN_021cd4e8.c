/* Decompiled C draft; module arm9_ov003; ROM address 021cd4e8. No matching claim. */
#include "types.h"
#include "deps/021cd4e8_FUN_021cd4e8.h"

void FUN_021cd4e8(int param_1)

{
  int iVar1;
  
  iVar1 = *DAT_021cd5d8 + DAT_021cd5dc;
  func_0x0214d168(iVar1,0,0xef);
  func_0x0214d1fc(param_1,iVar1 + 0xd1,5);
  func_0x0214d1fc(param_1 + 6,iVar1 + 0xd6,5);
  func_0x0214d1fc(param_1 + 0xc,iVar1 + 0xdb,5);
  func_0x0214d1fc(param_1 + 0x12,iVar1 + 0xe0,5);
  func_0x0214d1fc(param_1 + 0x18,iVar1 + 0x60,0x20);
  func_0x0214d1fc(param_1 + 0x39,iVar1 + 0x80,0xd);
  func_0x0214d1fc(param_1 + 0x47,iVar1 + 0x90,0xd);
  func_0x0214d1fc(param_1 + 0x55,iVar1 + 0xa0,0xd);
  func_0x0214d1fc(param_1 + 99,iVar1 + 0xb0,0xd);
  func_0x0214d1fc(param_1 + 0x71,iVar1 + 0x40,0x20);
  *(byte *)(iVar1 + 0xe6) = *(byte *)(iVar1 + 0xe6) & 0xfc | 2;
  *(byte *)(iVar1 + 0xe6) = *(byte *)(iVar1 + 0xe6) & 3;
  *(undefined1 *)(iVar1 + 0xe7) = 1;
  func_0x0214d168(iVar1 + 0xf0,0,4);
  *(undefined1 *)(iVar1 + 0xf5) = 1;
  *(undefined1 *)(iVar1 + 0xf6) = 1;
  FUN_021cd6d0();
  return;
}

