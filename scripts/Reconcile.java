import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.pcode.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.SourceType;
import java.util.*;
import java.nio.file.*;
public class Reconcile extends GhidraScript {
 public void run() throws Exception {
  Path log=Paths.get(getScriptArgs()[0]);List<String> rows=new ArrayList<>();rows.add("address\tbefore\tafter\tstatus");
  List<Function> fs=new ArrayList<>();for(Function f:currentProgram.getFunctionManager().getFunctions(true))if(!f.isExternal())fs.add(f);
  // Infer each callee independently before committing, to avoid order-dependent signatures.
  DecompInterface d=new DecompInterface();d.openProgram(currentProgram);List<HighFunction> hs=new ArrayList<>();int n=0;
  for(Function f:fs){DecompileResults r=d.decompileFunction(f,30,monitor);if(r.decompileCompleted()&&r.getHighFunction()!=null)hs.add(r.getHighFunction());if(++n%1000==0)println("INFER "+n);}
  for(HighFunction h:hs){Function f=h.getFunction();String before=f.getPrototypeString(false,false);try{HighFunctionDBUtil.commitParamsToDatabase(h,true,HighFunctionDBUtil.ReturnCommitOption.COMMIT,SourceType.ANALYSIS);rows.add(f.getEntryPoint()+"\t"+before+"\t"+f.getPrototypeString(false,false)+"\tINFERRED");}catch(Exception e){rows.add(f.getEntryPoint()+"\t"+before+"\t\tFAILED "+e);}}
  d.dispose();Files.write(log,rows);println("RECONCILED "+hs.size());
 }
}
