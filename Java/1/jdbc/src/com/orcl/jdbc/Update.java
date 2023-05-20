package com.orcl.jdbc;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;

public class Update {
    public static void main(String[] args) throws ClassNotFoundException, SQLException {
        //1.加载驱动
        Class.forName("com.mysql.jdbc.Driver");
        //2.创建声明
        String url = "jdbc:mysql://127.0.0.1/hgc";//数据库连接地址
        String name = "root";//数据库账号
        String password = "123456";//数据库密码
        //3.打开连接
        Connection con = DriverManager.getConnection(url);
        Statement statement = con.createStatement();
        //4.创建sql语句
        String sql = "   update  stu   " +"   set stuName='赵六新',   "+"   className='计科新4班',   "
                +"   age=18   "
                +"   where id =4   ;";
        //5.执行sql获得结果集
        int count = statement.executeUpdate(sql);//返回影响数据表中的条数
        if (count > 0) {
            System.out.println("修改成功");
        } else {
            System.out.println("修改失败");
        }
        //6.关闭资源 (后开先关)
        statement.close();
        con.close();
    }
}
