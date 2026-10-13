/* Decompiled C draft; module arm9_ov003; ROM address 021c735c. No matching claim. */
#include "types.h"
#include "deps/021c735c_FUN_021c735c.h"

undefined4 FUN_021c735c(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  char local_10 [8];
  
  pcVar4 = local_10;
  iVar3 = *DAT_021c73c8 + 8;
  iVar2 = (uint)*(byte *)(*DAT_021c73c8 + 0x14) * 3;
  cVar1 = *(char *)(iVar3 + iVar2);
  if ((cVar1 != '\0') && (cVar1 != ' ')) {
    return 1;
  }
  func_0x0214d1fc((ushort *)(uintptr_t)(iVar3 + iVar2),(uint *)(void *)(local_10),3);
  iVar2 = 0;
  local_10[3] = 0;
  do {
    if (*pcVar4 != '\0') break;
    *pcVar4 = ' ';
    pcVar4 = pcVar4 + 1;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 3);
  iVar2 = func_0x0213bf90((undefined4)(uintptr_t)(local_10));
  if (param_1 <= iVar2) {
    return 1;
  }
  return 0;
}

