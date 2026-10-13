/* Decompiled C draft; module arm9; ROM address 0211a908. No matching claim. */
#include "types.h"
#include "deps/0211a908_func_0211a908.h"

void func_0211a908(int param_1)

{
  if (param_1 == 3) {
    if (*(int *)(*piRam0211a95c + 0x20) != 2) {
      func_0211a964(*(undefined2 *)(iRam0211a960 + 0xc));
    }
    func_0211a964(10);
    return;
  }
  if (param_1 == 4) {
    func_0211a964(*(undefined2 *)(iRam0211a960 + 0x10));
    func_0211a964(0xc);
    return;
  }
  func_0211a964(*(undefined2 *)(iRam0211a960 + param_1 * 4));
  return;
}

