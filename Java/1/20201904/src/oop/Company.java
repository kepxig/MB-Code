package oop;

public class Company {
    Emp[] emps;
    Company(){
        emps = new Emp[3];
    }

    /**
     * 招聘单个员工
     * @param e
     */
    void zhaoPin(Emp e){
        for(int i=0;i<emps.length;i++){
        	if(emps[i]==null){
        	    emps[i]=e;
        	    break;//跳出循环
        	}
        }
    }



    /**
     * 根据工龄增加薪资
     * @param money
     */
    void jiaXin(double money){
        for(int i=0;i<emps.length;i++){
            if(emps[i]!=null){
                emps[i].money=emps[i].money+emps[i].year*money;
            }
        }
    }

    /**
     * 开除指定姓名的员工
     * @param name
     */
    void liZhi(String name){
        boolean you =false;
        for(int i=0;i<emps.length;i++){
            if(emps[i]!=null&&emps[i].name.equals(name)){
                you=true;
                emps[i]=null;
            }
        }
        if(you==false){
            System.out.println("查无此人");
        }
    }

    public static void main(String[] args) {
        Company c = new Company();
        Emp e1 = new Emp("A",2,1000);
        Emp e2 = new Emp("B",3,1200);
        Emp e3 = new Emp("C",4,1300);
        c.zhaoPin(e1);
        c.zhaoPin(e2);
        c.zhaoPin(e3);
        c.jiaXin(100);
        c.liZhi("A");
        c.liZhi("B");
        for(int i=0;i<c.emps.length;i++){
            Emp e = c.emps[i];
            if(e!=null){
                System.out.println(e.name+" 工龄:"+e.year+" 工资:"+e.money);
            }
        }



    }


}
