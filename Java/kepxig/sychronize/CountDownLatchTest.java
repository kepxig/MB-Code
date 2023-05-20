package kepxig.sychronize;

import java.util.concurrent.CountDownLatch;

public class CountDownLatchTest {
    // �½�һ��CountDwonLatch���󲢴����������ֵ 2
    static CountDownLatch cdl = new CountDownLatch(2);

    public static void main(String[] args) throws InterruptedException {
        new Thread(new Runnable() {
            @Override
            public void run() {
                try {
                    System.out.println("thread 1: 1 ");
                    Thread.sleep(1000);
                    System.out.println("thread 1 : 2");
                    // �ڱ��ȴ����̻߳��߲���ִ����Ϻ����countDwon���������ü�������1
                    cdl.countDown();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }

            }
        }).start();
        new Thread(new Runnable() {
            @Override
            public void run() {
                try {
                    System.out.println("thread 2 : 1");
                    Thread.sleep(1000);
                    System.out.println("thread 2 : 2");
                    // �ڱ��ȴ����̻߳��߲���ִ����Ϻ����countDwon���������ü�������1
                    cdl.countDown();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }

            }
        }).start();
        // �ڵȴ������߳��е���await���������ȴ������̣߳�ֱ��������Ϊ0 ��ִ�����߳̽��������߼�
        cdl.await();
        System.out.println("thread : main");

    }
}