/* Decompiled C draft; module arm9_ov000; ROM address 02185ef4. No matching claim. */
#include "types.h"
#include "deps/02185ef4_FUN_02185ef4.h"

undefined4 FUN_02185ef4(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = FUN_021866fc(*DAT_02186078 + DAT_0218607c,0x20,0,
                       *(undefined4 *)(*(int *)(*DAT_02186078 + DAT_02186080) + DAT_02186084));
  if (iVar2 != 1) {
    *(int *)(*DAT_02186078 + 8) = DAT_02186088;
    return 0xd;
  }
  iVar2 = FUN_02185d54();
  uVar1 = DAT_02186090;
  if (iVar2 != 0) {
    return 0xd;
  }
  iVar3 = *DAT_02186078;
  iVar2 = *(int *)(iVar3 + 8);
  if (iVar2 < DAT_02186088) {
    if (iVar2 == DAT_0218608c) {
      iVar2 = (**(code **)(iVar3 + DAT_02186098))(DAT_02186090,DAT_02186094);
      if (iVar2 == 0) {
        *(int *)(*DAT_02186078 + 8) = DAT_02186088;
        return 2;
      }
      iVar3 = func_0x02151f48(DAT_0218609c,iVar2 + 0x1fU & 0xffffffe0);
      if (iVar3 != 1) {
        (**(code **)(*DAT_02186078 + DAT_021860a0))(uVar1,iVar2,0);
        *(int *)(*DAT_02186078 + 8) = DAT_02186088;
        return 0xe;
      }
      (**(code **)(*DAT_02186078 + DAT_021860a0))(uVar1,iVar2,0);
    }
    return 0x14;
  }
  if (iVar2 == DAT_021860a4) {
    iVar2 = func_0x02151e20(DAT_0218609c);
    if (iVar2 == 0) {
      *(int *)(*DAT_02186078 + 8) = DAT_021860a4;
      return 0xe;
    }
    *(int *)(*DAT_02186078 + 8) = DAT_021860a4;
    return 0xf;
  }
  if (iVar2 != DAT_021860a8) {
    return 0x11;
  }
  iVar2 = (**(code **)(iVar3 + DAT_02186098))(DAT_02186090,DAT_02186094);
  if (iVar2 == 0) {
    *(int *)(*DAT_02186078 + 8) = DAT_021860a8;
    return 2;
  }
  iVar3 = func_0x02151f88(iVar2 + 0x1fU & 0xffffffe0);
  if (iVar3 != 1) {
    (**(code **)(*DAT_02186078 + DAT_021860a0))(uVar1,iVar2,0);
    *(int *)(*DAT_02186078 + 8) = DAT_021860a8;
    return 0xe;
  }
  (**(code **)(*DAT_02186078 + DAT_021860a0))(uVar1,iVar2,0);
  *(int *)(*DAT_02186078 + 8) = DAT_021860a8;
  return 0x10;
}

