/* Decompiled C draft; module arm9; ROM address 0204a340. No matching claim. */
#include "types.h"
#include "deps/0204a340_ShouldPauseBgmInSceneChange.h"

bool ShouldPauseBgmInSceneChange(undefined4 param_1,int param_2)

{
  int iVar1;
  bool bVar2;
  
  bVar2 = true;
  switch(param_1) {
  case 0:
    bVar2 = param_2 != 2;
    break;
  case 1:
    break;
  case 2:
    if (param_2 == 0) {
      bVar2 = false;
    }
    else if (param_2 == 0xf) {
      iVar1 = func_0x0219e0b8();
      if (iVar1 != 0) {
        func_0204ab64(0x78);
      }
      bVar2 = false;
    }
    break;
  case 3:
    bVar2 = param_2 != 7;
    break;
  case 4:
    break;
  case 5:
    break;
  case 6:
    break;
  case 7:
    if ((param_2 == 3) || (param_2 == 0xe)) {
      bVar2 = false;
    }
    break;
  case 8:
    break;
  case 9:
    break;
  case 10:
    break;
  case 0xb:
    bVar2 = param_2 != 0xe;
    break;
  case 0xc:
    break;
  case 0xd:
    break;
  case 0xe:
    if ((param_2 == 3) || (param_2 == 7)) {
      bVar2 = false;
    }
  }
  return bVar2;
}

