/* Public C reconstruction; complete local function bytes verified. Full ROM remains unverified. */
#define data_021581b8 SDK_data_02158abc
#define Maybe_CreateObj_1581b8 Maybe_CreateObj_158abc
typedef unsigned int u32;

typedef struct Obj40 {
    u32 w[0x10];
} Obj40;

extern void *GetActiveExecutionContext(void);
extern void *ExecutionContext_GetHeapHandle(void *ctx);
extern void *Mem_AllocateHeap(void *heap, u32 size);

extern const Obj40 data_021581b8;

void *Maybe_CreateObj_1581b8(void) {
    void *ctx = GetActiveExecutionContext();
    void *heap = ExecutionContext_GetHeapHandle(ctx);
    Obj40 *obj = (Obj40 *)Mem_AllocateHeap(heap, 0x40);
    *obj = data_021581b8;
    return obj;
}
