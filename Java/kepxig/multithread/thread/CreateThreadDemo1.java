package com.kepxig.multithread.thread;

public class CreateThreadDemo1 extends Thread {

    public CreateThreadDemo1() {
        // ���õ�ǰ�̵߳�����
        this.setName("MyThread");
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
        new CreateThreadDemo1().start();

        // ��ʾ���̼߳�������ִ��
        while (true) {
            printThreadInfo();
            Thread.sleep(1000);
        }
    }

    /**
     * �����ǰ�̵߳���Ϣ
     */
    private static void printThreadInfo() {
        System.out.println("��ǰ���е��߳�Ϊ�� " + Thread.currentThread().getName());
    }
}
