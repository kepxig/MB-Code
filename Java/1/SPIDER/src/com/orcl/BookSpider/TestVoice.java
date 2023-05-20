package com.orcl.BookSpider;

import com.jacob.activeX.ActiveXComponent;
import com.jacob.com.Dispatch;
import com.jacob.com.Variant;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

public class TestVoice {


    public static void VoicePlay(String content) throws IOException {
        // 拿到音响
        ActiveXComponent sap = new ActiveXComponent("sapi.SpVoice");
        // 找到本地要朗读的文件
        //Path TextPath= Paths.get("D:\\小说\\第一章.这个大佬有点高冷.txt");
        //String Text= Files.readString(TextPath);
       // String TextString = txt2String(text);
        // 调节语速 音量大小
        sap.setProperty("Volume", new Variant(100));
        sap.setProperty("Rate", new Variant(1));
        Dispatch xj = sap.getObject();
        // 执行朗读 没有读完就继续读
        Dispatch.call(xj, "Speak", new Variant(content));
        xj.safeRelease();

    }
}
