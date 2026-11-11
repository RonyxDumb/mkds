#include "00/code_0218ae5c.h"
#include "00/code_0218a9bc.h"

void FIFOClear(SBServerFIFO *fifo) {
    fifo->mLast = NULL;
    fifo->mFirst = fifo->mLast;
    fifo->mCount = 0;
}
