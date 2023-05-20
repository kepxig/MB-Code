package com.orcl.jdbc;

import java.sql.*;

public class Insert {
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
        String sql = "   insert  into stu (stuName,sex,age,className,stuNo) " +
                "   values('赵六','女',22,'计科4班',20215);";
        //5.执行sql获得结果集
        int count = statement.executeUpdate(sql);//返回影响数据表中的条数
        if (count > 0) {
            System.out.println("添加成功");
        } else {
            System.out.println("添加失败");
        }
        //6.关闭资源 (后开先关)
        statement.close();
        con.close();
    }
}
