package com.orcl.bean;

import com.alibaba.fastjson.JSON;

public class Result {
    private Object data;
    private int status;
    private String msg;

    public Result() {
    }

    public Result(int status) {
        this.status = status;
    }

    public Result(int status, String msg) {
        this.status = status;
        this.msg = msg;
    }

    public Result(Object data, int status, String msg) {
        this.data = data;
        this.status = status;
        this.msg = msg;
    }


    @Override
    public String toString() {
        return JSON.toJSONString(this);
    }

    public Object getData() {
        return data;
    }

    public void setData(Object data) {
        this.data = data;
    }

    public int getStatus() {
        return status;
    }

    public void setStatus(int status) {
        this.status = status;
    }

    public String getMsg() {
        return msg;
    }

    public void setMsg(String msg) {
        this.msg = msg;
    }
}
