package com.kepxig.multithread.callable;
import java.util.concurrent.Callable;
import java.util.concurrent.FutureTask;

public class createThreadCallable {

    public static void main(String[] args) throws Exception {

        // �����߳�����
        Callable<Integer> call = () -> {
            System.out.println("�߳�����ʼִ����....");
            Thread.sleep(2000);
            return 1;
        };

        // �������װΪFutureTask
        FutureTask<Integer> task = new FutureTask<>(call);

        // �����̣߳�ִ���߳�����
        new Thread(task).start();

        // ====================
        // ���������߳�����֮���߳̽������֮ǰ
        System.out.println("�������Ϊ����Ϊ....");
        // ====================

        // Ϊ����Ϊ���֮���õ��̵߳�ִ�н��
        Integer result = task.get();
        System.out.println("���߳����õ��첽����ִ�еĽ��Ϊ��" + result);
    }
}
