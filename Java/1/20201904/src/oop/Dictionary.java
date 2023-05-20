package oop;

public class Dictionary {
    Word[] wds;
    Dictionary(){
        wds = new Word[3];
    }

    /**
     * 添加一个单词
     * @param w
     */
    void addWord(Word w){
        for(int i=0;i<wds.length;i++){
        	if(wds[i]==null){
        	    wds[i]=w;
        	    break;
        	}
        }
    }

    /**
     * 根据中文输出英文解释
     * @param chinese
     */
    void translate(String chinese){
        boolean you=false;
        for(int i=0;i<wds.length;i++){
            if(wds[i]!=null&&wds[i].chinese.equals(chinese)){
                you=true;
                System.out.println(wds[i].english);
            }
        }
        if(you==false){
            System.out.println("查无此字");
        }
    }

    public static void main(String[] args) {
        Dictionary d = new Dictionary();
        Word w1 = new Word("苹果","apple");
        Word w2 = new Word("香蕉","banana");
        Word w3 = new Word("狗","dog");
        d.addWord(w1);
        d.addWord(w2);
        d.addWord(w3);
        for(int i=0;i<d.wds.length;i++){
            Word w = d.wds[i];
            if(w!=null){
                System.out.println(w.chinese+w.english);
            }
        }
        d.translate("苹果1");
    }

}
