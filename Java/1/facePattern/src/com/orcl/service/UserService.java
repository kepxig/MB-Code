package com.orcl.service;


import com.orcl.bean.User;
import com.orcl.db.BaseUserDao;
import com.orcl.db.BaseUserDaoImpl;

import java.io.IOException;
import java.sql.SQLException;

public class UserService {
    private static BaseUserDao dao = new BaseUserDaoImpl();

    /**
     * 用于新增用户人脸信息
     * @param user 用户对象
     * @return 新增的结果，大于0标识成功
     */
    public static int insert(User user)
            throws SQLException, IOException, ClassNotFoundException
    {return dao.insert(user);}

    /**
     * 基于人脸标识码，进行用户次数的新增
     * @param face_id 人脸标识码
     * @return 新增后的用户全部信息
     */
    public static User count(String face_id) throws SQLException, IOException, ClassNotFoundException {
        return dao.count(face_id);
    }

    /**
     * 通过人脸标识码， 修改用户的姓名和备注信息
     * @param face_id 人脸标识码
     * @param user 用户的姓名和备注的信息对象
     * @return 修改的结果，大于0标识成功
     */
    public static int updateUserByFaceId(String face_id,User user) throws SQLException, IOException, ClassNotFoundException {
        return dao.updateUserByFaceId(face_id,user);
    }


}
