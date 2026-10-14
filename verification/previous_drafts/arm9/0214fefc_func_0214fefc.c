/* Decompiled C draft; module arm9; ROM address 0214fefc. No matching claim. */
#include "types.h"
#include "deps/0214fefc_func_0214fefc.h"

undefined4 func_0214fefc(uint param_1,uint param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar3 = func_021501d8();
  uVar1 = uRam0214ffa0;
  if (iVar3 != 0) {
    *puRam0214ff9c = 0;
    func_0214fa7c(uVar1);
    puVar2 = puRam0214ffa4;
    do {
    } while (*(uint *)((uint)puRam0214ff9c & 0xfffffffc) >> ((uint)puRam0214ff9c & 3) * 8 == 0 &&
             *(uint *)((uint)puRam0214ff9c & 0xfffffffc) << ((uint)puRam0214ff9c & 3) * -8 + 0x20 ==
             0);
    *puRam0214ff9c = 0;
    *puVar2 = 0;
    PM_SetLCDPower(0,2,0,0);
    func_0214fa7c(param_1 & 0xff | uRam0214ffa8);
    func_0214fa7c(param_2 & uRam0214ffac | uRam0214ffb0);
    return 0;
  }
  return 1;
}

