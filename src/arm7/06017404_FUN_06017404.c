/* Decompiled C draft; module arm7; ROM address 06017404. No matching claim. */
#include "types.h"
#include "deps/06017404_FUN_06017404.h"

void FUN_06017404(int param_1)

{
  ushort uVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  ushort *puVar7;
  int local_44 [2];
  short local_3c;
  ushort local_3a;
  undefined2 local_2e;
  undefined4 local_28;
  
  uVar3 = *(uint *)(DAT_060175c8 & 0xfffffffc) >> (DAT_060175c8 & 3) * 8 |
          *(uint *)(DAT_060175c8 & 0xfffffffc) << (DAT_060175c8 & 3) * -8 + 0x20;
  uVar1 = *(ushort *)(param_1 + 6);
  puVar7 = (ushort *)(param_1 + 0x2c);
  if (((4 < uVar1) && (*(short *)(uVar3 + 0x350) == 1)) &&
     (iVar4 = FUN_06013528(param_1 + 0x1e,0x10), iVar4 == 0)) {
    sVar2 = *(short *)(param_1 + 2);
    if ((sVar2 == 0) || (uVar5 = FUN_0600e918(sVar2), uVar5 < 0x30)) {
      iVar4 = FUN_0601364c(param_1 + 0x1e,6);
      if (iVar4 != 0) {
        FUN_060143ac();
      }
    }
    else {
      iVar4 = FUN_0600e918(sVar2);
      if (iVar4 == 0x40) {
        FUN_0600ebbc(sVar2,0x30);
        FUN_0600f79c(param_1 + 0x1e,1);
      }
      else {
        iVar4 = FUN_0600e840(sVar2);
        if (iVar4 != 0) {
          return;
        }
      }
      thunk_FUN_037fb24c(0,local_44,0x2c);
      local_44[0] = param_1 + 0x30;
      local_3c = uVar1 - 4;
      FUN_060161b4((uint)(uintptr_t)(local_44));
      uVar5 = (uint)*puVar7;
      if ((((((DAT_060175cc & uVar5) == 0) && ((int)(uVar5 << 0x1f) < 0)) &&
           ((*(short *)(uVar3 + 0x334) != 0 || (-1 < (int)(uVar5 << 0x1b))))) &&
          ((*(short *)(uVar3 + 0x334) == 0 || ((int)((uint)*puVar7 << 0x1b) < 0)))) &&
         ((-1 < (int)((uint)*(ushort *)(uVar3 + 0x33a) << 0x1d) ||
          ((int)((uint)*puVar7 << 0x1a) < 0)))) {
        FUN_0600eac4(sVar2);
        if ((local_3a & 1) == 0) {
          uVar6 = 1;
        }
        else if ((local_3a & 4) == 0) {
          uVar6 = 0x12;
        }
        else {
          FUN_0600eaac(sVar2,local_2e);
          uVar6 = 0;
        }
      }
      else {
        uVar6 = 10;
      }
      iVar4 = FUN_06013a50(sVar2,uVar6,local_28);
      if (iVar4 != 0) {
        FUN_060143ac();
      }
    }
  }
  return;
}

