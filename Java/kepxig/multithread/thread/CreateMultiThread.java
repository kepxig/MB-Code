package com.kepxig.multithread.thread;

public class CreateMultiThread extends Thread {

    @Override
    public void run() {
        // ÿ��1s�����һ�ε�ǰ�̵߳�����
        while (true) {
            // ����̵߳����֣������߳�����������
            printThreadInfo();
            try {
                // �߳�����һ��
                Thread.sleep(2000);
            } catch (Exception e) {
                throw new RuntimeException(e);
            }
        }
    }

    public static void main(String[] args) throws Exception {
        // ע�����Ҫ����start�������������̣߳����ܵ���run����
        new CreateMultiThread().start();

        // ��������߳�ʵ����ͬʱִ��
        new CreateMultiThread().start();
        new CreateMultiThread().start();

        // ��ʾ���̼߳�������ִ��
        while (true) {
            printThreadInfo();
            Thread.sleep(2000);
        }
    }

    /**
     * �����ǰ�̵߳���Ϣ
     */
    private static void printThreadInfo() {
        System.out.println("��ǰ���е��߳�Ϊ�� " + Thread.currentThread().getName());
    }
}
