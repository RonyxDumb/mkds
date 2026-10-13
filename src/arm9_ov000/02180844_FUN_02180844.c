/* Decompiled C draft; module arm9_ov000; ROM address 02180844. No matching claim. */
#include "types.h"
#include "deps/02180844_FUN_02180844.h"

void FUN_02180844(undefined4 param_1,int param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  puVar2 = (undefined4 *)func_0x02036bec(param_1,0x3c);
  piVar1 = DAT_02180a48;
  *DAT_02180a48 = (int)puVar2;
  *puVar2 = param_1;
  *(undefined4 *)(*piVar1 + 0x14) = 0;
  func_0x02029a70(param_1);
  uVar3 = func_0x02125028(param_1);
  *(undefined4 *)(*DAT_02180a48 + 0x2c) = uVar3;
  uVar3 = func_ov000_021804f4();
  func_0x0212abdc(param_1,uVar3);
  local_38 = 1;
  local_34 = func_0x020b403c();
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 1;
  local_18 = 1;
  local_14 = 1;
  func_0x02125c2c();
  func_0x02125de0(param_1,&local_38);
  FUN_02180a54();
  uVar3 = func_ov000_021804f4();
  func_0x0202c65c(param_1,uVar3);
  func_0x020364e8();
  func_0x020364e0();
  func_0x02078d64();
  func_0x02078a9c(0xffffffff);
  func_0x02078a34(0xffffffff);
  func_0x020476ac();
  uVar3 = func_0x020369fc(param_1);
  *(undefined4 *)(*DAT_02180a48 + 4) = uVar3;
  FUN_02180be8();
  *(undefined2 *)(*DAT_02180a48 + 0x18) = 0xffff;
  if (*(int *)(*DAT_02180a4c + 0x58) != 0) {
    param_2 = 0;
    *(undefined4 *)(*DAT_02180a4c + 0x58) = 0;
  }
  piVar1 = DAT_02180a48;
  if (param_2 < 9) {
    if (7 < param_2) {
      if (*(int *)(*DAT_02180a4c + 0x50) == 0) {
        *(undefined4 *)(*DAT_02180a48 + 0x10) = 0xe;
        *(undefined4 *)(*piVar1 + 8) = 2;
        FUN_02181fcc();
      }
      else if (*(int *)(*DAT_02180a4c + 0x50) == 1) {
        *(undefined4 *)(*DAT_02180a48 + 0x10) = 0xe;
        *(undefined4 *)(*piVar1 + 8) = 8;
        FUN_02184ba8();
      }
      goto switchD_0218097e_default;
    }
    if ((2 < param_2) || (param_2 < 0)) goto switchD_0218097e_default;
    if (param_2 == 0) {
      *(undefined4 *)(*DAT_02180a48 + 0x10) = 10;
      *(undefined4 *)(*piVar1 + 8) = 1;
      FUN_02181714();
      func_0x021204d0();
      *(undefined4 *)(*DAT_02180a4c + 0x1c) = 0;
      goto switchD_0218097e_default;
    }
    if (param_2 != 2) goto switchD_0218097e_default;
  }
  else {
    if ((0xe < param_2) || (param_2 < 10)) goto switchD_0218097e_default;
    if (param_2 != 10) {
      if (param_2 == 0xc) {
        *(undefined4 *)(*DAT_02180a48 + 0x10) = 0xd;
        *(undefined4 *)(*piVar1 + 8) = 1;
        FUN_02181714();
      }
      else if (param_2 == 0xe) {
        *(undefined4 *)(*DAT_02180a48 + 0x10) = 0xb;
        *(undefined4 *)(*piVar1 + 8) = 8;
        FUN_02184ba8();
      }
      goto switchD_0218097e_default;
    }
  }
  switch(*(undefined4 *)(*DAT_02180a4c + 0x1c)) {
  case 0:
    *(undefined4 *)(*DAT_02180a48 + 8) = 1;
    FUN_02181714();
    break;
  case 1:
    iVar4 = *DAT_02180a50;
    *(undefined2 *)(iVar4 + 0x18) = 2;
    *(undefined2 *)(iVar4 + 0x1a) = 1;
    *(undefined4 *)(*DAT_02180a48 + 8) = 2;
    FUN_02181fcc();
    break;
  case 2:
    func_0x02123a48(1);
    *(undefined4 *)(*DAT_02180a48 + 8) = 4;
    FUN_021848c8();
    break;
  case 3:
    func_0x02123a48(2);
    func_0x020296f4();
    *(undefined4 *)(*DAT_02180a48 + 8) = 6;
    FUN_02184aa4();
  }
switchD_0218097e_default:
  piVar1 = DAT_02180a48;
  *(undefined4 *)(*DAT_02180a48 + 0xc) = 0xffffffff;
  (**(code **)(*piVar1 + 0x1c))(*(undefined4 *)(*piVar1 + 4));
  *(undefined4 *)(*DAT_02180a4c + 0x78) = 1;
  return;
}

