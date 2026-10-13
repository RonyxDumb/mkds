/* Decompiled C draft; module arm9_ov003; ROM address 021cd42c. No matching claim. */
#include "types.h"
#include "deps/021cd42c_FUN_021cd42c.h"

void FUN_021cd42c(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 auStack_2c [24];
  
  func_0x0214cfe4(0,*DAT_021cd4a0,DAT_021cd4a4);
  iVar4 = DAT_021cd4a8;
  piVar1 = DAT_021cd4a0;
  iVar5 = 0;
  iVar3 = 0;
  do {
    *(undefined1 *)(*piVar1 + iVar3 + 0xe7) = 0xff;
    iVar3 = iVar3 + iVar4;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 3);
  func_0x02151fc4((undefined4 *)(void *)(auStack_2c));
  uVar2 = func_0x021510a4((int)(uintptr_t)(auStack_2c));
  piVar1 = DAT_021cd4a0;
  iVar4 = 0;
  iVar3 = 0;
  do {
    func_0x0214d1fc((ushort *)(uintptr_t)(uVar2),(uint *)(uintptr_t)(*piVar1 + iVar3 + 0xf0),0xe);
    iVar3 = iVar3 + DAT_021cd4a8;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 2);
  iVar4 = 0;
  do {
    FUN_021cd338(iVar4);
    iVar4 = iVar4 + 1;
  } while (iVar4 < 4);
  return;
}

