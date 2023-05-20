package com.orcl.servlet;

import com.orcl.bean.Result;
import com.orcl.bean.User;
import com.orcl.service.UserService;

import javax.servlet.ServletException;
import javax.servlet.ServletRequest;
import javax.servlet.ServletResponse;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import java.io.IOException;
import java.sql.SQLException;

@WebServlet("/v1/user/update")
public class UpdateServlet extends HttpServlet {
    @Override
    public void service(ServletRequest req, ServletResponse res) throws ServletException, IOException {
        req.setCharacterEncoding("utf-8");
        res.setCharacterEncoding("utf-8");
        String userName = req.getParameter("userName");
        String description = req.getParameter("description");
        String faceid = req.getParameter("face_id");
        User user = new User();
        user.setUserName(userName);
        user.setDescription(description);
        System.out.println("update");
        int tiao=0;
        try {
            tiao=UserService.updateUserByFaceId(faceid,user);
        } catch (SQLException e) {
            e.printStackTrace();
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
        Result result=null;
        if (tiao>0){
            result = new Result(0,"修改成功");
        }else{
            result = new Result(1,"修改失败");
        }
        //进行内容的JSON格式转换
        String json = result.toString();
        res.getWriter().append(json);

    }
}
