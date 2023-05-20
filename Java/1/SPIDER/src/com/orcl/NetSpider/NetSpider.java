package com.orcl.NetSpider;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLConnection;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class NetSpider {
    /*
    基于Java原生api实现爬虫功能
    */
    //创建一个爬取网站的方法
    public String getContentByUrl(String url) throws IOException {
        //6.提高数据读取速度
        StringBuffer result = new StringBuffer();
        // 0.创建一个读取网络连接数据的缓冲流
        BufferedReader in = null;
        //1.与目标网站建立连接
        URL readUrl = new URL(url);
        //2.打开URL 与网站建立握手
        URLConnection connection = readUrl.openConnection();
        //3.创建连接
        connection.connect();
        //4.读取数据
        in = new BufferedReader(new InputStreamReader(connection.getInputStream()));
        //5.开始循环获取缓冲流中的网页数据信息
        String line = null;
        while ((line = in.readLine()) != null) {
            result.append(line);
        }
        return result.toString();
    }

    /*过滤数据的正则方法
     * targetStr 目标验证的字符串
     * regstr 正则字符串
     */
    public void reg(String targetString, String regString) {
        Pattern p = Pattern.compile(regString);//验证规则
        Matcher m = p.matcher(targetString);//带着规则去匹配目标字符串
        while (m.find()) {
            System.out.println(m.group(1));
        }

    }

    public static void main(String[] args) throws IOException {
        NetSpider ns = new NetSpider();
        String url = "https://www.nipic.com/topic/show_27587_1.html";
        //创建一个正则匹配规则
        String regstr="img src=\"?(.*?)\"";
        ns.reg(ns.getContentByUrl(url),regstr);
    }
}
