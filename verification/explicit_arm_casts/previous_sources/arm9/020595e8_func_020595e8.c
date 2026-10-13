/* Decompiled C draft; module arm9; ROM address 020595e8. No matching claim. */
#include "types.h"
#include "deps/020595e8_func_020595e8.h"

undefined4 func_020595e8(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  iVar3 = *DAT_020596e4;
  puVar2 = (undefined4 *)(iVar3 + DAT_020596e8);
  switch(*puVar2) {
  case 0:
    if ((*(ushort *)(iVar3 + DAT_020596ec) & 1) != 0) {
      *puVar2 = 2;
    }
    break;
  case 1:
    if ((*(byte *)(iVar3 + DAT_020596fc) & 2) != 0) {
      uVar4 = 1;
    }
    break;
  case 2:
    if (*DAT_020596f0 == 2) {
      switch(param_1) {
      case 0:
        Maybe_data_KartModelMainA();
        break;
      case 1:
        Maybe_data_Scene_Race(param_2,param_3);
        break;
      case 2:
        Maybe_data_Scene_ResultDL();
        break;
      case 3:
        Maybe_data_Scene_MenuDL();
      }
      piVar1 = DAT_020596e4;
      *(undefined4 *)(*DAT_020596e4 + 0xc) = 0x27;
      *(undefined4 *)(*piVar1 + 0x10) = 1;
      *(undefined2 *)(*piVar1 + DAT_020596f4) = 0;
      Fs_File_Initialize(*piVar1 + DAT_020596f8);
      *(undefined4 *)(*DAT_020596e4 + DAT_020596e8) = 3;
    }
    else {
      *puVar2 = 5;
    }
    func_020505a8(3,1);
    break;
  case 3:
    iVar3 = func_0204f644();
    if (iVar3 != 0) {
      *(undefined4 *)(*DAT_020596e4 + DAT_020596e8) = 5;
    }
    break;
  case 5:
    iVar3 = func_020505a8(4,1);
    if (iVar3 != 0) {
      *(undefined4 *)(*DAT_020596e4 + DAT_020596e8) = 1;
    }
  }
  return uVar4;
}

