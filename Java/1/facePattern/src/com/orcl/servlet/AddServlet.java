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

@WebServlet("/v1/user/add")
public class AddServlet extends HttpServlet {
    @Override
    public void service(ServletRequest req, ServletResponse res) throws ServletException, IOException {
        req.setCharacterEncoding("utf-8");
        res.setCharacterEncoding("utf-8");
        System.out.println("add");
        String faceid = req.getParameter("face_id");
        String city = req.getParameter("city");
        String count = req.getParameter("count");
        User user = new User();
        user.setFace_id(faceid);
        user.setCity(city);
        user.setCount(Integer.parseInt(count));
        user.setDescription("无");
        user.setLoginTime(System.currentTimeMillis()+"");
        user.setUserName("未命名");
        int tiao=0;
        try {
            tiao=UserService.insert(user);
        } catch (SQLException e) {
            e.printStackTrace();
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
        Result result=null;
        if (tiao>0){
            result = new Result(0,"添加成功");
        }else{
            result = new Result(1,"添加失败");
        }
        //进行内容的JSON格式转换
        String json = result.toString();
        res.getWriter().append(json);
    }
}
