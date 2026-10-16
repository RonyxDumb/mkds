/* Decompiled C draft; module arm9; ROM address 020270fc. No matching claim. */
#include "types.h"
#include "deps/020270fc_func_020270fc.h"

void func_020270fc(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  piVar1 = DAT_02027184;
  *(undefined4 *)(*DAT_02027184 + 100) = param_1;
  switch(*(undefined4 *)(*piVar1 + 0x7c)) {
  case 8:
    func_02027be0();
    break;
  case 9:
    func_02027a58();
    break;
  case 10:
    func_02027850();
    break;
  case 0xb:
    func_02027648();
    break;
  case 0xc:
    func_02027448();
  }
  func_02027188();
  func_0202721c();
  func_02025f54((undefined4 *)(uintptr_t)(*DAT_02027184 + 0xf8),0);
  piVar1 = DAT_02027184;
  iVar3 = *DAT_02027184;
  *(undefined4 *)(iVar3 + 0xf0) = *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x60) * 8 + 0x90);
  uVar2 = func_02025e60(*(undefined4 *)(*piVar1 + 0xf0));
  *(undefined4 *)(*DAT_02027184 + 0xf4) = uVar2;
  return;
}

