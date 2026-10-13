import ghidra.app.script.GhidraScript;
import ghidra.app.cmd.disassemble.DisassembleCommand;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.SourceType;
import java.nio.file.*;
import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.util.regex.*;
public class PrepareMKDS extends GhidraScript {
 public void run() throws Exception {
  String[] args=getScriptArgs(); Path root=Paths.get(args[0]);String module=args[1];
  for(String line:Files.readAllLines(root.resolve("symbols/"+module+".blocks.tsv"))){
   if(line.trim().isEmpty())continue;String[] v=line.split("\t");long base=Long.parseLong(v[1],16),bss=Long.parseLong(v[2],16);
   if(v[0].equals("BSS")){if(bss>0)currentProgram.getMemory().createUninitializedBlock("bss",toAddr(base),bss,false);continue;}
   byte[] data=Files.readAllBytes(root.resolve("binaries/"+v[0]));
   var block=currentProgram.getMemory().createInitializedBlock(v[0],toAddr(base),new ByteArrayInputStream(data),data.length,monitor,false);block.setExecute(true);
   if(bss>0)currentProgram.getMemory().createUninitializedBlock(v[0]+"_bss",toAddr(base+data.length),bss,false);
  }
  Pattern pat=Pattern.compile("^(\\S+) kind:function\\((arm|thumb),size=0x([0-9a-fA-F]+)\\) addr:0x([0-9a-fA-F]+)");
  List<String[]> funcs=new ArrayList<>();
  for(String line:Files.readAllLines(root.resolve("symbols/"+module+".txt"))){Matcher m=pat.matcher(line);if(m.find())funcs.add(new String[]{m.group(1),m.group(2),m.group(3),m.group(4)});}
  for(String[] f:funcs){Address a=toAddr(Long.parseLong(f[3],16));int size=Integer.parseInt(f[2],16);if(size<=0||!currentProgram.getMemory().contains(a))continue;
   currentProgram.getProgramContext().setValue(currentProgram.getRegister("TMode"),a,a.add(size-1),f[1].equals("thumb")?BigInteger.ONE:BigInteger.ZERO);
  }
  int added=0;
  for(String[] f:funcs){Address a=toAddr(Long.parseLong(f[3],16));int size=Integer.parseInt(f[2],16);if(size<=0||!currentProgram.getMemory().contains(a))continue;
   AddressSet body=new AddressSet(a,a.add(size-1));new DisassembleCommand(a,body,true).applyTo(currentProgram,monitor);
   try {Function fn=currentProgram.getFunctionManager().getFunctionAt(a);if(fn==null)currentProgram.getFunctionManager().createFunction(f[0],a,body,SourceType.IMPORTED);else fn.setName(f[0],SourceType.IMPORTED);added++;}catch(Exception e){println("SEED_ERROR "+f[0]+" "+e);}
  }
  println("MKDS_SEEDED "+module+" "+added);
 }
}
