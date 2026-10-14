/* Public C reconstruction; complete local function bytes verified. Full ROM remains unverified. */
#define data_0217b654 SDK_data_0217b7dc
#define data_021569fc SDK_data_02158e9c
#define Maybe_CreateObj_1569fc Maybe_CreateObj_158e9c
typedef unsigned int u32;

typedef struct Obj28 {
    u32 w[10];
} Obj28;

extern void *GetActiveExecutionContext(void);
extern void *ExecutionContext_GetHeapHandle(void *ctx);
extern void *Mem_AllocateHeap(void *heap, u32 size);
extern void func_020e6f50(void *arg);

extern Obj28 *data_0217b654;
extern const Obj28 data_021569fc;

void *Maybe_CreateObj_1569fc(void) {
    void *ctx = GetActiveExecutionContext();
    void *heap = ExecutionContext_GetHeapHandle(ctx);
    Obj28 *obj = (Obj28 *)Mem_AllocateHeap(heap, 0x28);
    data_0217b654 = obj;
    *obj = data_021569fc;
    func_020e6f50(&data_0217b654);
    return data_0217b654;
}
