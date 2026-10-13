/* Decompiled C draft; module arm9; ROM address 020b48ec. No matching claim. */
#include "types.h"
#include "deps/020b48ec_LoadCellBankFrom.h"

void LoadCellBankFrom(int *param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == 0) {
    return;
  }
  iVar1 = Common_FindBlockByMagic(param_2,uRam020b4930);
  if (iVar1 != 0) {
    *param_1 = iVar1 + 8;
    CellBank_InitializeLoad
              (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
               *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20);
    return;
  }
  return;
}

