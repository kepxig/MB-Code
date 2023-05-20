package 三性质训练;

public class 高个坚果 extends 植物{
    //state0种好1坚挺2挣扎
    高个坚果(int hang, int lie) {
        super(hang, lie);
        tuLuJing="images/植物/高个坚果/TallNut/Frame";
        zongTuShu=13;
        state=0;
        hp=100;
    }

    void jianTing(){
        state=1;
        tuHao=0;
        tuLuJing="images/植物/高个坚果/TallnutCracked1/Frame";
        zongTuShu=12;
    }
    void zhengZha(){
        state=2;
        tuHao=0;
        tuLuJing="images/植物/高个坚果/TallnutCracked2/Frame";
        zongTuShu=11;
    }

    @Override
    void dong() {
        super.dong();
        if(state==0&&hp<80){
            jianTing();
        }else if(state==1&&hp<40){
            zhengZha();
        }else if(state==2&&hp<=0){
            siLe=true;
            tuLuJing="";
        }
    }
}
