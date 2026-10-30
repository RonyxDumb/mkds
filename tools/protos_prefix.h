// Prefix for the -requireprotos compile only (tools/check_protos.py). CodeWarrior intrinsics have no declaration in
// the source, since declaring one makes it an ordinary call; declaring them here keeps them from being reported.
void __clear(void *p, unsigned int n);
