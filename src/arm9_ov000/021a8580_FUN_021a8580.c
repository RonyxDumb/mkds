/* Decompiled C draft; module arm9_ov000; ROM address 021a8580. No matching claim. */
#include "types.h"
#include "deps/021a8580_FUN_021a8580.h"

undefined4 FUN_021a8580(int param_1)

{
  undefined4 uVar1;
  bool bVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 4);
  bVar2 = true;
  if ((*(char *)(iVar3 + 0x73) != '\0') && (*(char *)(iVar3 + 0x73) != '\x04')) {
    bVar2 = false;
  }
  if (bVar2) {
    func_0x0200e084(*(int *)(iVar3 + 0x68) + 0x20);
    FUN_021ae094();
    FUN_021ae048();
    FUN_021ae258();
  }
  FUN_021ae2f4();
  *(ushort *)(iVar3 + 0x70) = *(ushort *)(iVar3 + 0x70) & 0xfff9;
  if (*(char *)(iVar3 + 0x73) == '\x02') {
    uVar1 = *(undefined4 *)(iVar3 + 0x68);
  }
  else {
    uVar1 = *(undefined4 *)(iVar3 + 100);
  }
  FUN_021a7008(uVar1,0);
  uVar1 = func_0x0200fca0();
  FUN_021a8ae8(iVar3);
  FUN_021a8af8(iVar3);
  func_0x0200fcb4(uVar1);
  *(ushort *)(iVar3 + 0x70) = *(ushort *)(iVar3 + 0x70) | 0x20;
  return 0;
}

