package com.orcl.jdbc;

import java.sql.*;

public class CreateTable {
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
        String sql = "   Create table    ";
        //5.执行sql获得结果集
        ResultSet result = statement.executeQuery(sql);
        while (result.next()) {
            //根据字段名称获取字段值
            int id = result.getInt("id");
            String stuName = result.getString("stuName");
            String sex = result.getString("sex");
            int age = result.getInt("age");
            String className = result.getString("className");
            int stuNo = result.getInt("stuNo");
            int TEL = result.getInt("TEL");
            System.out.println("id=" + id + "  学生姓名：" + stuName + "  性别：" + sex + "  年龄:" + age + "  班级：" + className +
                    "  学号：" + stuNo + "  电话：" + TEL);
        }
        //6.关闭资源 (后开先关)
        result.close();
        statement.close();
        con.close();
    }
}
