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

@WebServlet("/v1/user/count")
public class CountServlet extends HttpServlet {
    @Override
    public void service(ServletRequest req, ServletResponse res) throws ServletException, IOException {
        req.setCharacterEncoding("utf-8");
        res.setCharacterEncoding("utf-8");
        String faceid = req.getParameter("face_id");
        System.out.println("count");
        User user=null;
        try {
           user= UserService.count(faceid);
        } catch (SQLException e) {
            e.printStackTrace();
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
        Result result=null;
        if (user!=null){
            result = new Result(user,0,"更新成功");
        }else{
            result = new Result(1,"更新失败");
        }
        //进行内容的JSON格式转换
        String json = result.toString();
        res.getWriter().append(json);
    }
}
