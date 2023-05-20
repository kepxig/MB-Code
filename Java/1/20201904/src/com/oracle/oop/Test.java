package com.oracle.oop;

public class Test {
    public static void main(String[] args) {
        Box box = new Box(3,2,2);
        box.findTheBottomArea();
        box.findSideLength(box.getLength(),box.getWidth(),box.getHigh());



    }
}
