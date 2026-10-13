import ghidra.app.script.GhidraScript;
import java.nio.file.*;
public class PackMKDS extends GhidraScript {
 public void run() throws Exception {
  String[] args=getScriptArgs();Path p=Paths.get(args[0],"projects",args[1]+".gzf");Files.createDirectories(p.getParent());Files.deleteIfExists(p);
  currentProgram.getDomainFile().packFile(p.toFile(),monitor);
  if(!Files.isRegularFile(p)||Files.size(p)==0)throw new Exception("Missing packed program: "+p);
  println("MKDS_PACKED "+p+" "+Files.size(p));
 }
}
