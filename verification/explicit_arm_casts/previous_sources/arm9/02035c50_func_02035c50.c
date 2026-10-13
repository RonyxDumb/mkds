/* Decompiled C draft; module arm9; ROM address 02035c50. No matching claim. */
#include "types.h"
#include "deps/02035c50_func_02035c50.h"

void func_02035c50(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined2 local_30;
  undefined1 local_2e;
  undefined1 local_2d;
  undefined1 auStack_2c [24];
  
  iVar3 = *piRam02035d14;
  if (param_1 == 1) {
    iVar1 = func_0202ddb0();
    func_0202db04(param_3 + iVar1);
    uVar2 = func_02025d74();
    uVar2 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*piRam02035d14 + 0x88),uVar2);
    func_0212426c(1,param_2,*(undefined4 *)(iVar3 + 0x5c),uVar2,*(undefined4 *)(iVar3 + 0x54),
                  *(undefined4 *)(iVar3 + 0x60));
    func_0202dcf4(param_3 + iVar1,&local_30);
    func_02025cd0(auStack_2c,local_2e,local_2d,local_30);
    func_02124224(1,param_2 + 7,*(undefined4 *)(iVar3 + 0x5c),auStack_2c,
                  *(undefined4 *)(iVar3 + 0x54),*(undefined4 *)(iVar3 + 0x60),7);
    return;
  }
  if (param_1 == 0) {
    iVar1 = 0;
    do {
      if (iVar1 == param_4) {
        uVar2 = 0xe;
      }
      else {
        uVar2 = 0xf;
      }
      func_02124100(iVar1,uVar2,*(undefined4 *)(iVar3 + 0x5c),*(undefined4 *)(iVar3 + 0x60),
                    *(undefined4 *)(iVar3 + 0x54));
      func_02124100(iVar1 + 7,uVar2,*(undefined4 *)(iVar3 + 0x5c),*(undefined4 *)(iVar3 + 0x60),
                    *(undefined4 *)(iVar3 + 0x54));
      iVar1 = iVar1 + 1;
    } while (iVar1 < 7);
  }
  return;
}

