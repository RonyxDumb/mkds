/* Decompiled C draft; module arm9; ROM address 0202e4b0. No matching claim. */
#include "types.h"
#include "deps/0202e4b0_func_0202e4b0.h"

void func_0202e4b0(void)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = DAT_0202e524;
  piVar1 = DAT_0202e520;
  *(undefined4 *)(*DAT_0202e520 + DAT_0202e524) = 0;
  *(undefined4 *)(*piVar1 + DAT_0202e528) = *(undefined4 *)(*piVar1 + iVar2);
  func_0202eec0();
  func_0202ed04();
  switch(*(undefined4 *)(*DAT_0202e520 + DAT_0202e52c)) {
  case 0:
    func_0202e9f0();
    break;
  case 1:
    func_0202e9ac();
    break;
  case 2:
    func_0202e968();
    break;
  case 3:
    func_0202e84c();
    break;
  case 4:
    func_0202e72c();
    break;
  case 5:
    func_0202e6c4();
  }
  func_0202ee88();
  return;
}

