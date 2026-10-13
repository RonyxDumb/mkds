/* Decompiled C draft; module arm9_ov000; ROM address 02189134. No matching claim. */
#include "types.h"
#include "deps/02189134_FUN_02189134.h"

undefined4 FUN_02189134(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = param_1 + DAT_0218920c + (uint)*(byte *)(param_1 + DAT_02189210) * 0xc0;
  uVar1 = FUN_02188ee0();
  *(undefined1 *)(param_1 + DAT_02189214) = uVar1;
  func_0x0214d168((uint *)(uintptr_t)(param_1 + DAT_02189218),0,0x52);
  iVar2 = FUN_02188de4(param_1,*(undefined1 *)(param_1 + DAT_02189214),(byte *)(uintptr_t)(param_1 + DAT_02189218));
  if (iVar2 == 0) {
    *(byte *)(param_1 + DAT_0218921c) = *(byte *)(param_1 + DAT_0218921c) & 0xf3;
    if (((int)(uint)*(ushort *)(iVar3 + 0x2c) >> 4 & 1U) == 1) {
      *(undefined1 *)(param_1 + (uint)*(byte *)(param_1 + DAT_02189210) * 4 + DAT_02189220) = 3;
      return 9;
    }
  }
  else {
    *(byte *)(param_1 + DAT_0218921c) = *(byte *)(param_1 + DAT_0218921c) & 0xf3 | 4;
    if (((int)(uint)*(ushort *)(iVar3 + 0x2c) >> 4 & 1U) == 0) {
      *(undefined1 *)(param_1 + (uint)*(byte *)(param_1 + DAT_02189210) * 4 + DAT_02189220) = 3;
      return 9;
    }
    if ((*(char *)(param_1 + DAT_02189214) == '\x06') && (*(char *)(iVar3 + 0x15) == '\0')) {
      *(undefined1 *)(param_1 + (uint)*(byte *)(param_1 + DAT_02189210) * 4 + DAT_02189220) = 3;
      return 9;
    }
  }
  *(undefined1 *)(param_1 + DAT_02189224) = 0;
  *(undefined1 *)(param_1 + DAT_02189228) = 0;
  return 8;
}

