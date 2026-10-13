/* Decompiled C draft; module arm9; ROM address 02110350. No matching claim. */
#include "types.h"
#include "deps/02110350_func_02110350.h"

void func_02110350(undefined4 param_1)

{
  longlong lVar1;
  int iVar2;
  
  iVar2 = func_0x02181528();
  lVar1 = (longlong)
          (int)(*(uint *)(uRam021103b8 & 0xfffffffc) >> (uRam021103b8 & 3) * 8 |
               *(uint *)(uRam021103b8 & 0xfffffffc) << (uRam021103b8 & 3) * -8 + 0x20) *
          (longlong)(0x1f000 - iVar2) + 0x800;
  iVar2 = (int)((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000) >> 0xc;
  if (iVar2 < 0) {
    iVar2 = 0;
  }
  else if (0x7f < iVar2) {
    iVar2 = 0x7f;
  }
  func_02109078(param_1,uRam021103bc,0x7fU - iVar2 & 0xff,0);
  return;
}

