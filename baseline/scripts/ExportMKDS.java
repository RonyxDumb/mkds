import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import ghidra.app.util.exporter.GzfExporter;
import java.nio.file.*;
import java.io.*;
public class ExportMKDS extends GhidraScript {
 public void run() throws Exception {
  String[] args=getScriptArgs();Path root=Paths.get(args[0]);String module=args[1];Path out=root.resolve("pseudocode/"+module);Files.createDirectories(out);Files.createDirectories(root.resolve("projects"));
  if(module.equals("arm9") && !currentProgram.getMemory().contains(toAddr(0x0216f340L))) currentProgram.getMemory().createUninitializedBlock("main_bss",toAddr(0x0216f340L),0x111a0L,false);
  java.util.regex.Pattern pat=java.util.regex.Pattern.compile("^(\\S+) .*addr:0x([0-9a-fA-F]+)");
  for(String line:Files.readAllLines(root.resolve("symbols/"+module+".txt"))){
   java.util.regex.Matcher mat=pat.matcher(line);if(!mat.find())continue;
   var a=toAddr(Long.parseLong(mat.group(2),16));if(currentProgram.getMemory().contains(a) && currentProgram.getFunctionManager().getFunctionAt(a)==null){
    try{currentProgram.getSymbolTable().createLabel(a,mat.group(1),ghidra.program.model.symbol.SourceType.IMPORTED).setPrimary();}catch(Exception e){}
   }
  }
  DecompInterface d=new DecompInterface();d.openProgram(currentProgram);int ok=0,fail=0;
  try(PrintWriter index=new PrintWriter(Files.newBufferedWriter(out.resolve("index.tsv")))){
   index.println("address\tname\tbytes\tstatus\tmessage");
   for(Function f:currentProgram.getFunctionManager().getFunctions(true)){
    if(f.isExternal())continue;DecompileResults r=d.decompileFunction(f,30,monitor);String addr=f.getEntryPoint().toString();String name=f.getName().replaceAll("[^A-Za-z0-9_]","_");
    if(r.decompileCompleted()&&r.getDecompiledFunction()!=null){
     Files.writeString(out.resolve(addr+"_"+name+".c"),"/* Automatic Ghidra pseudocode. Not matching source. Module: "+module+"; address: "+addr+" */\n"+r.getDecompiledFunction().getC());ok++;
     index.println(addr+"\t"+f.getName()+"\t"+f.getBody().getNumAddresses()+"\tOK\t");
    }else{fail++;index.println(addr+"\t"+f.getName()+"\t"+f.getBody().getNumAddresses()+"\tFAILED\t"+r.getErrorMessage().replace('\n',' '));}
    if((ok+fail)%500==0)println("MKDS_EXPORT "+module+" ok="+ok+" failed="+fail);
   }
  }finally{d.dispose();}
  // PackMKDS.java exports the saved program in a separate headless pass.
  println("MKDS_DONE "+module+" ok="+ok+" failed="+fail);
 }
}
