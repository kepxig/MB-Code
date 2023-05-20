package com.orcl.BookSpider;

import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;

import java.io.IOException;

/**
 * 小说爬虫核心类文件
 * https://book.zongheng.com/chapter/1234799/69959365.html
 * https://huayu.zongheng.com/chapter/1239445/69944600.html
 */
public class BookSpider {

    /**
     * 爬取当前小说章节的方法
     * @param url 小说章节的当前网址URL
     * @return 返回下一章小说的连接
     */
    public String process(String url) throws IOException, IOException {

        //1.建立与当前小说章节的网站连接
        Document doc = Jsoup.connect(url).get();
        //2.获取小说章节的名称
        Element titleName = doc.select(".title_txtbox").get(0);
        //System.out.println(titleName);
        //3.在硬盘中创建小说文件的地址
        FileUtil file = new FileUtil("d://小说");//路径只要制定好，必须手动创建
        file.createNewFileWriter(titleName.text());//创建小说文件
        file.writeln(titleName.text());//将小说的章节名称写在小说文件第一行
        //4.爬取小说主体内容
        Elements contents = doc.select(".content p");
        //System.out.println(contents);
        // 5.循环取出元素标签小说内容 并写入小说文件中
        for (Element content : contents) {
            System.out.println(content.text());//逐行打印
            TestVoice.VoicePlay(content.text());//逐行朗读
            file.writeln(content.text());//将小说内容写入文件中
        }
        file.close();//关闭缓存通道

        //6.获取到下一章链接地址
        Elements hrefs = doc.select("a");
        for (Element href : hrefs) {
            //根据围堵值信息获取到下一章元素标签
            if ("下一章".equals(href.text())) {
                String nextLink = href.attr("href");
                if (nextLink.startsWith("http") || nextLink.startsWith("HTTP")) {
                    //System.out.println(nextLink);
                    return nextLink;//返回下一章地址
                }
            }
        }
        return null;
    }

    /**
     * 递归调用爬取小说的方法，直到没有下一章链接
     * @param url 初次爬取链接
     */
    public void storySpider(String url) throws IOException {
        String nextHref = this.process(url);
        while (nextHref != null) {
            nextHref = this.process(nextHref);
        }

    }

    public static void main(String[] args) throws IOException {
        BookSpider bs = new BookSpider();
        String url = "https://huayu.zongheng.com/chapter/1239445/69944600.html";
        bs.storySpider(url);
    }

}
