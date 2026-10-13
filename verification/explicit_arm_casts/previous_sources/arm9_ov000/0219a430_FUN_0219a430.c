/* Decompiled C draft; module arm9_ov000; ROM address 0219a430. No matching claim. */
#include "types.h"
#include "deps/0219a430_FUN_0219a430.h"

/* WARNING: Type propagation algorithm not settling */

undefined4 FUN_0219a430(undefined4 *param_1,undefined4 param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int *piVar2;
  ushort local_28 [2];
  undefined2 local_24;
  ushort uStack_22;
  int local_20;
  int local_1c [2];
  
  FUN_0218e8b8();
  if (param_4 == 0) {
    param_4 = DAT_0219a59c;
  }
  if (param_3 == 0) {
    param_3 = DAT_0219a59c;
  }
  iVar1 = FUN_0219a654(param_2,local_1c,local_28);
  if (iVar1 == 0) {
    return 4;
  }
  piVar2 = (int *)FUN_021a3690(0x44);
  if (piVar2 == (int *)0x0) {
    return 1;
  }
  func_0x02134de0(piVar2,0,0x44);
  *piVar2 = -1;
  piVar2[0xf] = param_4;
  piVar2[0xe] = param_3;
  piVar2[9] = param_5;
  iVar1 = FUN_0218e004(4,0x20,2,DAT_0219a5a4,DAT_0219a5a0,0);
  piVar2[3] = iVar1;
  if (piVar2[3] == 0) {
    FUN_021a3668(piVar2);
    return 1;
  }
  iVar1 = FUN_0218dc94(4,4,DAT_0219a5a8);
  piVar2[4] = iVar1;
  if (piVar2[4] == 0) {
    FUN_0218dfb4(piVar2[3]);
    FUN_021a3668(piVar2);
    return 1;
  }
  iVar1 = FUN_0218e554(2,2,0);
  *piVar2 = iVar1;
  if (*piVar2 == -1) {
    FUN_0218dfb4(piVar2[3]);
    FUN_0218dc48(piVar2[4]);
    FUN_021a3668(piVar2);
    return 3;
  }
  local_24 = 0x200;
  local_20 = local_1c[0];
  uStack_22 = local_28[0] >> 8 | local_28[0] << 8 & (ushort)DAT_0219a5ac;
  iVar1 = FUN_0218e4e4(*piVar2,&local_24,8);
  if (iVar1 == -1) {
    FUN_0218e53c(*piVar2);
    FUN_0218dfb4(piVar2[3]);
    FUN_0218dc48(piVar2[4]);
    FUN_021a3668(piVar2);
    return 3;
  }
  local_1c[1] = 8;
  FUN_0218e394(*piVar2,&local_24,local_1c + 1);
  piVar2[1] = local_20;
  *(ushort *)(piVar2 + 2) = uStack_22 >> 8 | uStack_22 << 8 & (ushort)DAT_0219a5ac;
  *param_1 = piVar2;
  return 0;
}

