package 三性质训练;

public class 吃人植物 extends 植物{
    普通僵尸 js;
    //state=0//种好1咬2咀嚼
    吃人植物(int hang, int lie) {
        super(hang, lie);
        tuLuJing="images/植物/吃人植物/Chomper/Frame";
        zongTuShu=12;
        state=0;
    }

    void yao(普通僵尸 js){
        this.js=js;
        state=1;
        tuHao=0;
        tuLuJing="images/植物/吃人植物/ChomperAttack/Frame";
        zongTuShu=8;
    }
    void jueJue(){
        state=2;
        tuHao=0;
        tuLuJing="images/植物/吃人植物/ChomperDigest/Frame";
        zongTuShu=5;
    }


    @Override
    void dong() {
        super.dong();
        if(state==1&&tuHao==zongTuShu){
            jueJue();
        }
        if(state==2){
            js.tuLuJing="";
            js.hp--;
            System.out.println(js.hp);
            if(js.hp<=0){
                js.siLe=true;
                tuHao=0;
                state=0;
                tuLuJing="images/植物/吃人植物/Chomper/Frame";
                zongTuShu=12;
            }
        }
    }
}
