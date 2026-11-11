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
                previous->mNext = current->mNext;
            }
            if (fifo->mFirst == current) {
                fifo->mFirst = current->mNext;
            }
            if (fifo->mLast == current) {
                fifo->mLast = previous;
            }
            fifo->mCount--;
            return 1;
        }
        previous = current;
        current = current->mNext;
    }
    return 0;
}
