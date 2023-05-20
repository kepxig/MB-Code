<%--
  Created by IntelliJ IDEA.
  User: kepxig
  Date: 2022/12/15
  Time: 8:53
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>$Title$</title>
</head>
<body>
学生姓名：<input type="text"></br>
学生学号：<input type="=text"></br>
<input type="buttom" value="查询成绩" onclick="query()">
<script>
    function query() {
        var stuName = $("stuName").val();
        var stuNo = $("stuNo").val();
        $.ajax(
            {
                url: "/querystu",//请求后台的地址
                type: "POST",//请求htt的类型 get post put delete
                data: {"stuName":stuName,"stuNo":stuNo},//传递到后台的参数
                dataType: "",//预期服务端返回的数据类型
                success: function (data) //请求服务端成功后执行返回的参数
                {

                }
        {

        }
    }
    )

    }

    <
    body >
    < /html>
