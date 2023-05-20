package com.kepxig.multithread.thread;

public class CreateMultiThreadDemo extends Thread {

    public CreateMultiThreadDemo(String name) {
        // ���õ�ǰ�̵߳�����
        this.setName(name);
    }

    @Override
    public void run() {
        // ÿ��1s�����һ�ε�ǰ�̵߳�����
        while (true) {
            // ����̵߳����֣������߳�����������
            printThreadInfo();
            try {
                // �߳�����һ��
                Thread.sleep(1000);
            } catch (Exception e) {
                throw new RuntimeException(e);
            }
        }
    }

    public static void main(String[] args) throws Exception {
        // ע�����Ҫ����start�������������̣߳����ܵ���run����
        new CreateMultiThreadDemo("MyThread-01").start();

        // ��������߳�ʵ����ͬʱִ��
        new CreateMultiThreadDemo("MyThread-02").start();

        // ��ʾ���̼߳�������ִ��
        while (true) {
            printThreadInfo();
            Thread.sleep(3000);
        }
    }

    /**
     * �����ǰ�̵߳���Ϣ
     */
    private static void printThreadInfo() {
        System.out.println("��ǰ���е��߳�Ϊ�� " + Thread.currentThread().getName());
    }
}
