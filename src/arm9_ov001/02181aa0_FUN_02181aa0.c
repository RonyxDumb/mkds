/* Decompiled C draft; module arm9_ov001; ROM address 02181aa0. No matching claim. */
#include "types.h"
#include "deps/02181aa0_FUN_02181aa0.h"

void FUN_02181aa0(void)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  
  if (*(int *)(*DAT_02181b28 + 8) == 4) {
    iVar2 = func_0x020a126c();
  }
  else {
    iVar2 = 0;
  }
  if (iVar2 == 0) {
    iVar2 = *DAT_02181b2c;
    uVar3 = func_ov001_0218180c();
    uVar1 = *(ushort *)(iVar2 + 4);
    if (uVar1 < uVar3) {
      *(ushort *)(iVar2 + 4) = uVar1 + 1;
      uVar4 = func_ov001_0218180c();
      func_0x02108edc(*(undefined2 *)(*DAT_02181b2c + 4),uVar4);
      switch(*(undefined1 *)(*DAT_02181b28 + 0x2f)) {
      case 0:
      case 1:
      case 3:
      case 5:
      case 7:
        uVar3 = func_ov001_0218180c();
        if (uVar3 <= *(ushort *)(*DAT_02181b2c + 4)) {
          func_0x0203e74c((short)*(char *)(*DAT_02181b28 + 0x62));
        }
      }
    }
  }
  return;
}

