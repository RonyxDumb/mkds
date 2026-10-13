/* Decompiled C draft; module arm9_ov003; ROM address 021d1290. No matching claim. */
#include "types.h"
#include "deps/021d1290_FUN_021d1290.h"

undefined4 FUN_021d1290(void)

{
  char cVar1;
  int *piVar2;
  char *pcVar3;
  int iVar4;
  
  iVar4 = *DAT_021d1348;
  pcVar3 = (char *)(iVar4 + DAT_021d134c);
  cVar1 = *pcVar3;
  if ((((cVar1 == '\x01') || (cVar1 == '\x14')) || (cVar1 == '\x17')) ||
     ((cVar1 == '\x1a' || (cVar1 == '\x1d')))) {
    *(undefined1 *)(iVar4 + DAT_021d134c) = 0x22;
    *(undefined1 *)(*DAT_021d1348 + DAT_021d1350) = 0;
    return 1;
  }
  if (((cVar1 != '\x04') && ((cVar1 != '\x05' && (cVar1 != '\x06')))) && (cVar1 != '\r')) {
    if ((byte)(cVar1 - 9U) < 2) {
      *pcVar3 = ' ';
      return 1;
    }
    if (cVar1 == '\f') {
      *pcVar3 = '\"';
      return 1;
    }
    if (cVar1 == '\x02') {
      return 0;
    }
    return 0;
  }
  if ((cVar1 == '\x04') && (*(uint *)(iVar4 + DAT_021d1354) < 6)) {
    return 0;
  }
  func_0x02009c04();
  piVar2 = DAT_021d1348;
  *(undefined1 *)(*DAT_021d1348 + DAT_021d134c) = 0x10;
  *(undefined1 *)(*piVar2 + DAT_021d1350) = 2;
  return 1;
}

