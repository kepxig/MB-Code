package com.oracle.oop;

public class Box {
    private int length;//长
    private int width;//宽
    private int high;//高

    Box(){}

    public Box(int length, int width, int high) {
        this.length = length;
        this.width = width;
        this.high = high;
    }

    public int getLength() {
        return length;
    }

    public int getWidth() {
        return width;
    }

    public int getHigh() {
        return high;
    }

    public void setLength(int length) {
        this.length = length;
    }

    public void setWidth(int width) {
        this.width = width;
    }

    public void setHigh(int high) {
        this.high = high;
    }

    /**
     * 求底面积
     * 打印输出长*宽
     */
    void findTheBottomArea(){
        System.out.println(this.length*this.width);
    }

    /**
     * 求总边长
     * @param length
     * @param width
     * @param high
     */
    void findSideLength(int length,int width,int high){
        System.out.println(4*(length+width+high));
    }

    /**
     * 求长方体的体积
     */
    void findVolume(){
        System.out.println(length*width*high);
    }



}
