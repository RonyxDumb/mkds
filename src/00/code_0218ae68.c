#include "00/code_0218ae68.h"
#include "00/code_0218a9bc.h"

BOOL FIFORemove(SBServerFIFO *fifo, SbServer *server) {
    SbServer *current;
    SbServer *previous;
    previous = NULL;
    current = fifo->mFirst;
    while (current != NULL) {
        if (current == server) {
            if (previous != NULL) {
                previous->mUnk_20 = current->mUnk_20;
            }
            if (fifo->mFirst == current) {
                fifo->mFirst = current->mUnk_20;
            }
            if (fifo->mLast == current) {
                fifo->mLast = previous;
            }
            fifo->mCount--;
            return 1;
        }
        previous = current;
        current = current->mUnk_20;
    }
    return 0;
}
