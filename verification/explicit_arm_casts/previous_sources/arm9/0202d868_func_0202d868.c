/* Decompiled C draft; module arm9; ROM address 0202d868. No matching claim. */
#include "types.h"
#include "deps/0202d868_func_0202d868.h"

void func_0202d868(int param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined2 local_30;
  undefined1 local_2e;
  undefined1 local_2d;
  undefined1 auStack_2c [24];
  
  iVar3 = *piRam0202d98c;
  if (param_1 == 1) {
    func_0202db04(param_3);
    uVar1 = func_02025d74();
    uVar1 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*piRam0202d98c + 0xac),uVar1);
    func_0212426c(1,param_2,*(undefined4 *)(iVar3 + 0x80),uVar1,*(undefined4 *)(iVar3 + 0x78),
                  *(undefined4 *)(iVar3 + 0x84));
    func_0202dcf4(param_3,&local_30);
    func_02025cd0(auStack_2c,local_2e,local_2d,local_30);
    func_02124224(1,param_2 + 7,*(undefined4 *)(iVar3 + 0x80),auStack_2c,
                  *(undefined4 *)(iVar3 + 0x78),*(undefined4 *)(iVar3 + 0x84),7);
    iVar2 = func_0202dd80(param_3);
    *(uint *)(*(int *)(iVar3 + 0x84) + param_2 * 0x40) = (uint)(iVar2 == 0);
    *(uint *)(*(int *)(iVar3 + 0x84) + (param_2 + 7) * 0x40) = (uint)((iVar2 == 0) == 0);
    return;
  }
  if (param_1 == 0) {
    iVar2 = 0;
    do {
      if (iVar2 == param_4) {
        uVar1 = 0xe;
      }
      else {
        uVar1 = 0xf;
      }
      func_02124100(iVar2,uVar1,*(undefined4 *)(iVar3 + 0x80),*(undefined4 *)(iVar3 + 0x84),
                    *(undefined4 *)(iVar3 + 0x78));
      func_02124100(iVar2 + 7,uVar1,*(undefined4 *)(iVar3 + 0x80),*(undefined4 *)(iVar3 + 0x84),
                    *(undefined4 *)(iVar3 + 0x78));
      iVar2 = iVar2 + 1;
    } while (iVar2 < 7);
    return;
  }
  if (((param_1 == 2) && (-1 < param_3)) && (iVar2 = func_0202ddc4(), param_3 < iVar2)) {
    iVar2 = func_0202dd80(param_3);
    *(uint *)(*(int *)(iVar3 + 0x84) + param_2 * 0x40) = (uint)(iVar2 == 0);
    *(uint *)(*(int *)(iVar3 + 0x84) + (param_2 + 7) * 0x40) = (uint)((iVar2 == 0) == 0);
  }
  return;
}

