package com.oracle.oop;

public class Student {
    private String name;
    private boolean sex;
    private double score;

    public Student() {
    }

    public Student(String name, boolean sex, double score) {
        this.name = name;
        this.sex = sex;
        this.score = score;
    }

    public String getName() {
        return name;
    }

    public boolean isSex() {
        return sex;
    }

    public double getScore() {
        return score;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setSex(boolean sex) {
        this.sex = sex;
    }

    public void setScore(double score) {
        this.score = score;
    }
}
