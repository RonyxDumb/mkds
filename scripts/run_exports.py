"""Requires the packed Ghidra programs from the first analysis archive."""
import pathlib,subprocess,os,argparse,sys
root=pathlib.Path(__file__).resolve().parents[1]
p=argparse.ArgumentParser();p.add_argument('--projects',type=pathlib.Path,required=True,help='Directory containing arm9.gzf, arm7.gzf and overlay GZF files');p.add_argument('--ghidra',type=pathlib.Path,default=os.environ.get('GHIDRA_HOME'));args=p.parse_args()
if not args.ghidra:p.error('Set GHIDRA_HOME or use --ghidra')
headless=args.ghidra/'support'/('analyzeHeadless.bat' if os.name=='nt' else 'analyzeHeadless');work=root/'ghidra_work';work.mkdir(exist_ok=True)
for module in ['arm9','arm9_ov000','arm9_ov001','arm9_ov002','arm9_ov003','arm7']:
 cmd=[str(headless),str(work),module,'-import',str(args.projects/f'{module}.gzf'),'-overwrite','-noanalysis','-scriptPath',str(root/'scripts'),'-postScript','RebuildC.java',str(root),module,'-max-cpu','2']
 with (root/'logs'/f'{module}.log').open('w') as log:subprocess.run(cmd,check=True,stdout=log,stderr=subprocess.STDOUT)
 if 'C_DONE' not in (root/'logs'/f'{module}.log').read_text():raise RuntimeError('Export failed: '+module)
 print('Exported',module,flush=True)
print('To reproduce the two recovered functions, Ghidra needs the ARM word-load model described in scripts/arm9-ldr-alignment.txt.')
