/* Decompiled C draft; module arm9_ov003; ROM address 021c8400. No matching claim. */
#include "types.h"
#include "deps/021c8400_FUN_021c8400.h"

uint FUN_021c8400(void)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined2 local_20;
  short local_1e;
  undefined2 local_1c;
  undefined2 local_1a;
  
  iVar2 = FUN_021d2a34((ushort *)(uintptr_t)(DAT_021c8584));
  if (iVar2 == 0) {
    return 0xe;
  }
  iVar2 = func_0x02147d30(*DAT_021c8588,0x1d);
  local_20 = *DAT_021c858c;
  local_1e = DAT_021c858c[1];
  local_1c = DAT_021c858c[2];
  local_1a = DAT_021c858c[3];
  iVar4 = 0;
  do {
    if (((iVar2 != 2) && (iVar2 != 6)) && (iVar3 = FUN_021d2970(&local_20), iVar3 != 0)) {
      return (uint)*(byte *)(DAT_021c8590 + iVar2);
    }
    iVar4 = iVar4 + 1;
    iVar2 = iVar2 + 1;
    local_1e = local_1e + 0x1d;
  } while (iVar4 < 4);
  iVar2 = func_0x02147d30(*DAT_021c8588,0x1d);
  iVar4 = 0;
  do {
    if (iVar2 == 2) {
      local_20 = *DAT_021c8594;
      local_1c = DAT_021c8594[2];
      local_1a = DAT_021c8594[3];
      sVar1 = (short)iVar4 * 0x1d;
      local_1e = DAT_021c8594[1] + sVar1;
      iVar2 = FUN_021d2970(&local_20);
      if (iVar2 != 0) {
        return 2;
      }
      local_20 = *DAT_021c8598;
      local_1c = DAT_021c8598[2];
      local_1a = DAT_021c8598[3];
      local_1e = DAT_021c8598[1] + sVar1;
      iVar2 = FUN_021d2970(&local_20);
      if (iVar2 != 0) {
        return 3;
      }
      break;
    }
    iVar4 = iVar4 + 1;
    iVar2 = iVar2 + 1;
  } while (iVar4 < 4);
  iVar2 = func_0x02147d30(*DAT_021c8588,0x1d);
  iVar4 = 0;
  do {
    if (iVar2 == 6) {
      local_20 = *DAT_021c8594;
      local_1c = DAT_021c8594[2];
      local_1a = DAT_021c8594[3];
      sVar1 = (short)iVar4 * 0x1d;
      local_1e = DAT_021c8594[1] + sVar1;
      iVar2 = FUN_021d2970(&local_20);
      if (iVar2 != 0) {
        return 7;
      }
      local_20 = *DAT_021c8598;
      local_1c = DAT_021c8598[2];
      local_1a = DAT_021c8598[3];
      local_1e = DAT_021c8598[1] + sVar1;
      iVar2 = FUN_021d2970(&local_20);
      if (iVar2 != 0) {
        return 8;
      }
      break;
    }
    iVar4 = iVar4 + 1;
    iVar2 = iVar2 + 1;
  } while (iVar4 < 4);
  iVar4 = 0;
  iVar2 = DAT_021c859c;
  do {
    iVar3 = FUN_021d2a34((ushort *)(uintptr_t)(iVar2));
    if (iVar3 != 0) {
      return iVar4 + 0xb;
    }
    iVar2 = iVar2 + 8;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 3);
  return 0xe;
}

