package com.kepxig.multithread.runnable;


public class createThread_Task implements Runnable {

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

    /**
     * �����ǰ�̵߳���Ϣ
     */
    private static void printThreadInfo() {
        System.out.println("��ǰ���е��߳���Ϊ�� " + Thread.currentThread().getName());
    }
}
