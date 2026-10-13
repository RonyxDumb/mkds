/* Decompiled C draft; module arm9; ROM address 02031960. No matching claim. */
#include "types.h"
#include "deps/02031960_func_02031960.h"

void func_02031960(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = DAT_02031b10;
  iVar2 = *DAT_02031b10;
  switch(*(undefined4 *)(iVar2 + 0x70)) {
  case 0:
    iVar2 = func_0205579c(1,(*(int *)(*DAT_02031b14 + 0x1c) << 0x1d) >> 0x1f);
    if (iVar2 == 1) {
      *(undefined4 *)(*DAT_02031b10 + 0x70) = 1;
      return;
    }
    break;
  case 1:
    if (*(int *)(iVar2 + 0x78) != 0) {
      *(undefined4 *)(iVar2 + 0x78) = 0;
      *(undefined4 *)(*piVar1 + 0x70) = 3;
      *(undefined4 *)(*piVar1 + 0x9c) = 0x78;
      Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*piVar1 + 0x68),0x79);
      TextSystem_DisplayProgressDialog_from_thumb();
      func_02025f14(*DAT_02031b10 + 0xa0,2);
      return;
    }
    if (*(int *)(iVar2 + 0x7c) != 0) {
      *(undefined4 *)(iVar2 + 0x7c) = 0;
      *(undefined4 *)(*piVar1 + 0x70) = 7;
      return;
    }
    func_020554e4();
    return;
  case 3:
    iVar2 = func_0204db6c();
    if (iVar2 == 1) {
      *(undefined4 *)(*DAT_02031b10 + 0x70) = 4;
      return;
    }
    if (iVar2 != 2) {
      return;
    }
    func_02032028();
    return;
  case 4:
    iVar2 = func_02058cac();
    if (iVar2 != 1) {
      if (iVar2 != 2) {
        return;
      }
      func_02032028();
      return;
    }
    if (*(int *)(*DAT_02031b10 + 0x9c) == 0) {
      if ((*(byte *)(*DAT_02031b18 + DAT_02031b1c) & ~*(byte *)(*DAT_02031b18 + DAT_02031b20) & 0xfe
          ) == 0) {
        TextSystem_CloseDialog_from_thumb();
      }
      else {
        Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*DAT_02031b10 + 0x68),0x81);
        TextSystem_DisplayProgressDialog_Simple_from_thumb();
        *(undefined4 *)(*DAT_02031b10 + 0x9c) = 0x78;
      }
      func_02108d80();
      func_0205e5c4(1);
      piVar1 = DAT_02031b10;
      *(undefined4 *)(*DAT_02031b10 + DAT_02031b24) = 0;
      *(undefined4 *)(*piVar1 + 0x70) = 6;
      return;
    }
    break;
  case 6:
    if (*(char *)(*DAT_02031b28 + 0x28) == '\0') {
      if (*(int *)(*DAT_02031b2c + 0xc) == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)(*DAT_02031b2c + 0x10);
      }
    }
    else {
      iVar3 = 1;
    }
    if ((iVar3 == 0) && (*(int *)(iVar2 + 0x9c) == 0)) {
      *(undefined4 *)(iVar2 + 0x70) = 0xb;
    }
    break;
  case 7:
  case 8:
    iVar2 = func_02054f58();
    if (iVar2 == 1) {
      *(undefined4 *)(*DAT_02031b10 + 0x70) = 0xb;
      return;
    }
  }
  return;
}

