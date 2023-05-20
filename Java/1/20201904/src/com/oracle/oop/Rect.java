package com.oracle.oop;

public class Rect{
    private double length;
    private double width;
    private  double height;

    public Rect(double length, double width, double height) {
        this.length = length;
        this.width = width;
        this.height = height;
    }

    double getArea()
    {return  (this.length*this.width+this.length*this.height+this.width*this.height)*2;}
    double getPerimeter()
    {return  this.length+this.width+this.height;}
    double getVolume()
    {return  this.length*this.width*this.height;}

    public static void main(String[] args) {
        Rect rect=new Rect(10,10,5);
        double Area=rect.getArea();
        double Perimeter=rect.getPerimeter();
        double Volume=rect.getVolume();
        System.out.println(Area);
        System.out.println(Perimeter);
        System.out.println(Volume);

    }
}

