package com.orcl.BookSpider;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class FileUtil {
    private FileWriter writer;
    private String basePath;
    private String prefix;

    public FileUtil(String bathPath){
        this(bathPath,"txt");
    }
    public FileUtil(String bathPath,String prefix){
        this.basePath = bathPath;
        this.prefix = prefix;
    }
    public void createNewFileWriter(String fileName){
        try {
            writer = new FileWriter(new File(this.basePath+"//"+fileName+"."+this.prefix));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    public void writeln(String value){
        try {
            writer.write(value);
            writer.write("\n");
        } catch (IOException e) {
            e.printStackTrace();
        }

    }
    public void close(){
        if (this.writer != null){
            try {
                this.writer.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

    }
}
