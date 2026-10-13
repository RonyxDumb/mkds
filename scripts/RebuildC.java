import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.data.*;
import ghidra.program.model.pcode.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.SourceType;
import java.nio.file.*;
import java.io.*;
import java.util.*;
public class RebuildC extends GhidraScript {
 String decl(DataType t,String name){
  if(t instanceof Pointer){DataType b=((Pointer)t).getDataType();if(b==null)return "void *"+name;return decl(b,(b instanceof Array||b instanceof FunctionDefinition)?"(*"+name+")":"*"+name);}
  if(t instanceof Array){Array a=(Array)t;return decl(a.getDataType(),name+"["+a.getNumElements()+"]");}
  if(t instanceof FunctionDefinition){FunctionDefinition f=(FunctionDefinition)t;List<String> p=new ArrayList<>();for(ParameterDefinition a:f.getArguments())p.add(decl(a.getDataType(),a.getName()==null?"":a.getName()));if(f.hasVarArgs())p.add("...");return decl(f.getReturnType(),name+"("+(p.isEmpty()?"void":String.join(",",p))+")");}
  String type=t.getName();if(t instanceof Structure)type="struct "+type;if(t instanceof Union)type="union "+type;if(t instanceof ghidra.program.model.data.Enum)type="enum "+type;
  return type+" "+name;
 }
 public void run() throws Exception {
  String[] args=getScriptArgs();Path root=Paths.get(args[0]);String module=args[1];Path out=root.resolve("src/"+module);Files.createDirectories(out);Files.createDirectories(out.resolve("deps"));
  if(module.equals("arm9"))for(long a:new long[]{0x0213d398L,0x0213deecL}){
   Function f=getFunctionAt(toAddr(a));f.replaceParameters(Function.FunctionUpdateType.DYNAMIC_STORAGE_ALL_PARAMS,true,SourceType.ANALYSIS,new Variable[0]);for(Variable v:f.getLocalVariables())f.removeVariable(v);f.setReturnType(Undefined4DataType.dataType,SourceType.ANALYSIS);f.setSignatureSource(SourceType.DEFAULT);
  }
  TreeSet<String> defined=new TreeSet<>();for(Function f:currentProgram.getFunctionManager().getFunctions(true))defined.add(f.getName());
  TreeSet<String> prototypes=new TreeSet<>();List<DataType> needed=new ArrayList<>();int ok=0,fail=0;
  DecompInterface d=new DecompInterface();d.openProgram(currentProgram);
  try(PrintWriter idx=new PrintWriter(Files.newBufferedWriter(out.resolve("index.tsv")));PrintWriter map=new PrintWriter(Files.newBufferedWriter(out.resolve("globals.tsv")))){
   idx.println("address\tname\tstatus\tfile\tmessage");map.println("function\tname\taddress\ttype\tdeclaration");
   for(Function f:currentProgram.getFunctionManager().getFunctions(true)){
    if(f.isExternal())continue;DecompileResults r=d.decompileFunction(f,30,monitor);String addr=f.getEntryPoint().toString();String name=f.getName().replaceAll("[^A-Za-z0-9_]","_");
    if(r.decompileCompleted()&&r.getDecompiledFunction()!=null){
     String filename=addr+"_"+name+".c";String sig=r.getDecompiledFunction().getSignature().trim();prototypes.add(sig.endsWith(";")?sig:sig+";");TreeMap<String,String> globals=new TreeMap<>();
     var tokens=r.getCCodeMarkup().tokenIterator(true);while(tokens.hasNext()){
      var token=tokens.next();if(!(token instanceof ClangVariableToken))continue;var v=(ClangVariableToken)token;var h=v.getHighVariable();if(!(h instanceof HighGlobal))continue;
      String n=token.getText();if(n==null||!n.matches("[A-Za-z_][A-Za-z0-9_]*")||defined.contains(n))continue;DataType t=h.getDataType();needed.add(t);var address=h.getRepresentative().getAddress();if(!address.isMemoryAddress())continue;
      String dec="#define "+n+" (*("+decl(new PointerDataType(t),"")+")(uintptr_t)0x"+Long.toHexString(address.getOffset())+"u)";
      globals.put(n,dec);map.println(addr+"\t"+n+"\t"+address+"\t"+t.getDisplayName()+"\t"+dec);
     }
     Files.writeString(out.resolve("deps/"+filename.replace(".c",".globals.h")),String.join("\n",globals.values())+"\n");
     Files.writeString(out.resolve(filename),"/* Decompiled C draft; module "+module+"; ROM address "+addr+". No matching claim. */\n#include \"types.h\"\n#include \"deps/"+filename.replace(".c",".h")+"\"\n"+r.getDecompiledFunction().getC());ok++;
     idx.println(addr+"\t"+f.getName()+"\tOK\t"+filename+"\t"+r.getErrorMessage().replace('\n',' '));
    }else{fail++;idx.println(addr+"\t"+f.getName()+"\tFAILED\t\t"+r.getErrorMessage().replace('\n',' '));}
    if((ok+fail)%1000==0)println("C_PROGRESS "+module+" "+ok+" "+fail);
   }
   if(idx.checkError()||map.checkError())throw new IOException("Failed writing index");
  }finally{d.dispose();}
  try(PrintWriter h=new PrintWriter(Files.newBufferedWriter(out.resolve("types.h")))){h.println("#pragma once\n#include \"../ghidra_compat.h\"");DataTypeWriter writer=new DataTypeWriter(currentProgram.getDataTypeManager(),h);writer.write(currentProgram.getDataTypeManager(),monitor);writer.write(needed,monitor,false);}
  Files.writeString(out.resolve("prototypes.h"),String.join("\n",prototypes)+"\n");println("C_DONE "+module+" "+ok+" "+fail);
 }
}
