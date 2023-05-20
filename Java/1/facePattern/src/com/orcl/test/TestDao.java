package com.orcl.test;

import com.orcl.bean.User;
import com.orcl.service.UserService;

import java.io.IOException;
import java.sql.SQLException;

public class TestDao {
    public static void main(String[] args) throws SQLException, IOException, ClassNotFoundException {
     String sql="  update user set userName = ?  , description= ? where face_id=  ?   ";
    //添加方法
//        User   u=new User();
//        u.setUserName("A");
//        u.setDescription("B");
//        u.setCount(3);
//        UserService.updateUserByFaceId("1647248682488",u);
        System.out.println(111);
    }
}
