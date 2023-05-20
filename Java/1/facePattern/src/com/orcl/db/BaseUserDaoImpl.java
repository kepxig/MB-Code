package com.orcl.db;

import com.orcl.bean.User;

import java.io.IOException;
import java.sql.*;
import java.util.Map;

public class BaseUserDaoImpl implements BaseUserDao{

    @Override
    public int insert(User user) throws SQLException, IOException, ClassNotFoundException {
        //加载驱动
        Class.forName("com.mysql.jdbc.Driver");
        //获得连接
        String url="jdbc:mysql://localhost:3306/facepattern?useUnicode=true&characterEncoding=utf-8";
        String username="root";
        String password="123456";
        Connection conn = DriverManager.getConnection(url,username,password);
        //执行添加
        String sql="insert into user(face_id,city,logintime,count,description,userName) values ( ? , ? , ?, ? , ? , ?) ";
        //创建声明
        PreparedStatement state = conn.prepareStatement(sql);
        state.setString(1,user.getFace_id());
        state.setString(2,user.getCity());
        state.setString(3,user.getLoginTime());
        state.setInt(4,user.getCount());
        state.setString(5,user.getDescription());
        state.setString(6,user.getUserName());
        int tiao = state.executeUpdate();

        //关闭声明
        state.close();
        //关闭连接
        conn.close();
        return tiao;
    }

    @Override
    public User count(String face_id) throws SQLException, IOException, ClassNotFoundException {
        //1. 查询信息
        User user = findUserByFaceId(face_id);
        System.out.println("user===="+user);
        //判断时间间隔，是否符合要求，符合则收录
        //TODO 60000:表示间隔60秒收录一次，如需修改间隔时间，更改数字即可
        if(System.currentTimeMillis()-Long.valueOf(user.getLoginTime())>10000&&user!=null){
            user.setCount(user.getCount()+1);
            //2. 修改次数-
            updateCountByFaceId(face_id,user.getCount());
        }
        return user;
    }

    @Override
    public int updateUserByFaceId(String face_id, User user) throws SQLException, IOException, ClassNotFoundException {

        //加载驱动
        Class.forName("com.mysql.jdbc.Driver");
        //获得连接
//        String url="jdbc:mysql://47.94.169.235:3306/support?useUnicode=true&characterEncoding=utf-8";
//        String username="support";
//        String password="support123$";
        String url="jdbc:mysql://localhost:3306/facepattern?useUnicode=true&characterEncoding=utf-8";
        String username="root";
        String password="123456";
        Connection conn = DriverManager.getConnection(url,username,password);
        //执行修改
        String sql="  update user set userName =?  , description= ? where face_id=  ?";
        //创建声明
        System.out.println("UpdateDao");
        System.out.println(face_id);
        System.out.println(user.getUserName());
        PreparedStatement state = conn.prepareStatement(sql);
        state.setString(1,user.getUserName());
        state.setString(2,user.getDescription());
        state.setString(3,face_id);
        int tiao = state.executeUpdate();
        //关闭声明
        state.close();
        //关闭连接
        state.close();
        return tiao;
    }

    @Override
    public int updateCountByFaceId(String face_id, int count) throws SQLException, IOException, ClassNotFoundException {
        //加载驱动
        Class.forName("com.mysql.jdbc.Driver");
        //获得连接
//        String url="jdbc:mysql://47.94.169.235:3306/support?useUnicode=true&characterEncoding=utf-8";
//        String username="support";
//        String password="support123$";
        String url="jdbc:mysql://localhost:3306/facepattern?useUnicode=true&characterEncoding=utf-8";
        String username="root";
        String password="123456";
        Connection conn = DriverManager.getConnection(url,username,password);
        //执行修改
        String sql = "update user set count = ?, logintime= ? where face_id = ?";
        //创建声明
        PreparedStatement state = conn.prepareStatement(sql);
        state.setInt(1,count);
        state.setString(2,System.currentTimeMillis()+"");
        state.setString(3,face_id);
        int tiao = state.executeUpdate();
        //关闭声明
        state.close();
        //关闭连接
        state.close();
        return tiao;
    }

    @Override
    public User findUserByFaceId(String face_id) throws SQLException, IOException, ClassNotFoundException {

        //加载驱动
        Class.forName("com.mysql.jdbc.Driver");
        //获得连接
//        String url="jdbc:mysql://47.94.169.235:3306/support?useUnicode=true&characterEncoding=utf-8";
//        String username="support";
//        String password="support123$";
        String url="jdbc:mysql://localhost:3306/facepattern?useUnicode=true&characterEncoding=utf-8";
        String username="root";
        String password="123456";
        Connection conn = DriverManager.getConnection(url, username, password);
        //创建声明
        Statement state = conn.createStatement();
        //执行查询
        String sql="  select * from user where face_id="+face_id;
        ResultSet rs = state.executeQuery(sql);
        //遍历结果集
        User user = new User();
        while(rs.next()) {
            String id=rs.getString("id");
            String faceid=rs.getString("face_id");
            String userName=rs.getString("userName");
            String city = rs.getString("city");
            String  description= rs.getString("description");
            String count=rs.getString("count");
            String logintime=rs.getString("logintime");
           user.setId(Integer.parseInt(id));
           user.setFace_id(faceid);
           user.setUserName(userName);
           user.setCity(city);
           user.setDescription(description);
           user.setCount(Integer.parseInt(count));
           user.setLoginTime(logintime);

        }
        //关闭结果集
        rs.close();
        //关闭声明
        state.close();
        //关闭连接
        conn.close();
        return user;
    }
}
