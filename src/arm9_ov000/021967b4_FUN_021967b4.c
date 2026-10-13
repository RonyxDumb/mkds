/* Decompiled C draft; module arm9_ov000; ROM address 021967b4. No matching claim. */
#include "types.h"
#include "deps/021967b4_FUN_021967b4.h"

undefined4 FUN_021967b4(int param_1,char *param_2,int param_3,int param_4)

{
  char cVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if (param_1 == 0) {
    func_0x0213442c(DAT_0219684c,DAT_02196850,0,DAT_02196854);
  }
  if (param_2 == (char *)0x0) {
    func_0x0213442c(DAT_02196858,DAT_02196850,0,DAT_0219685c);
  }
  if (param_3 == 0) {
    func_0x0213442c(DAT_02196860,DAT_02196850,0,DAT_02196864);
  }
  if (param_4 < 1) {
    func_0x0213442c(DAT_02196868,DAT_02196850,0,DAT_0219686c);
  }
  cVar1 = *param_2;
  iVar3 = func_0x02139f70(param_1,(uint)(uintptr_t)(param_2));
  if (iVar3 == 0) {
    return 0;
  }
  iVar4 = func_0x0213a434(param_2);
  for (iVar5 = 0;
      ((iVar5 < param_4 + -1 && (cVar2 = *(char *)(iVar3 + iVar4 + iVar5), cVar2 != '\0')) &&
      (cVar2 != cVar1)); iVar5 = iVar5 + 1) {
    *(char *)(param_3 + iVar5) = cVar2;
  }
  *(undefined1 *)(param_3 + iVar5) = 0;
  return 1;
}

