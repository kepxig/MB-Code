package com.orcl.jsoup;

import org.jsoup.Connection;
import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;

import java.io.IOException;
import java.io.StringReader;

public class JsoupSpider {
    public static void main(String[] args) throws IOException {
        //1.创建一个Jsoup对象
        String url = "https://www.nipic.com/topic/show_27587_1.html";
        Connection connect = Jsoup.connect(url);
        Document document = connect.get();
        System.out.println(document);
        //2.从网页对象中通过选择器 来找到想要的元素节点
        //class名的元素标签 .class名
        Elements els = document.select(".search-works-thumb.relative img");//所有图片的父级标签
        System.out.println(els);
        //3.遍历获取到的元素结果集
        for (Element imgs : els) {
            //获取到当前元素中的属性值
            String link =imgs.attr("src");
            System.out.println(link);
        }
    }
}
