/* Decompiled C draft; module arm9_ov000; ROM address 0218bc08. No matching claim. */
#include "types.h"
#include "deps/0218bc08_FUN_0218bc08.h"

int FUN_0218bc08(int param_1)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = 0;
  if (2 < *(int *)(param_1 + 0x80)) {
    while( true ) {
      uVar1 = **(ushort **)(param_1 + 0x7c) >> 8 |
              (**(ushort **)(param_1 + 0x7c) & (ushort)DAT_0218bd44 >> 8) << 8;
      uVar3 = (uint)uVar1;
      if (DAT_0218bd48 < uVar3) break;
      if (*(int *)(param_1 + 0x80) < (int)uVar3) {
        return 0;
      }
      iVar2 = *(int *)(param_1 + 0x7c);
      switch(*(undefined1 *)(iVar2 + 2)) {
      case 1:
        iVar4 = FUN_0218c0bc(param_1,(byte *)(uintptr_t)(iVar2 + 3),uVar3 - 3);
        break;
      case 2:
        iVar4 = FUN_0218bd5c(param_1,iVar2 + 3,uVar3 - 3);
        break;
      case 3:
        iVar2 = FUN_0218e420(*(undefined4 *)(param_1 + DAT_0218bd4c),iVar2,uVar3,0);
        if (iVar2 < 1) {
          return 3;
        }
        break;
      case 4:
        iVar4 = FUN_0218be10(param_1,(undefined4 *)(uintptr_t)(iVar2 + 3),uVar3 - 3);
        break;
      case 5:
        iVar4 = FUN_0218be68(param_1,(undefined4 *)(uintptr_t)(iVar2 + 3),uVar3 - 3);
        break;
      case 6:
        iVar4 = FUN_0218bf78(param_1,(char *)(uintptr_t)(iVar2 + 3),uVar3 - 3);
      }
      *(uint *)(param_1 + 0x80) = *(int *)(param_1 + 0x80) - (uint)uVar1;
      if (*(int *)(param_1 + 0x80) < 0) {
        func_0x0213442c(DAT_0218bd50,DAT_0218bd54,0,DAT_0218bd58);
      }
      if ((*(int *)(param_1 + 0x80) != 0) && (iVar2 = *(int *)(param_1 + 0x7c), iVar2 != 0)) {
        func_0x02134df8(iVar2,iVar2 + (uint)uVar1);
      }
      if ((iVar4 != 0) || (*(int *)(param_1 + 0x80) < 3)) goto LAB_0218bd2e;
    }
    iVar4 = 4;
  }
LAB_0218bd2e:
  if (iVar4 != 0) {
    FUN_0218cf30(param_1);
  }
  return iVar4;
}

