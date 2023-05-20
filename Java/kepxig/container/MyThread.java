import java.util.concurrent.CopyOnWriteArrayList;

public class MyThread implements Runnable {
    private CopyOnWriteArrayList<String> list;

    public MyThread(CopyOnWriteArrayList<String> list) {
        this.list = list;
    }

    @Override
    public void run() {
        try {
            // �߳�˯�� 1 ��
            Thread.sleep(1000);
            // ���б������һ��Ԫ��
            list.add("Hello World");
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

public class Main {
    public static void main(String[] args) throws InterruptedException {
        // ����һ���̰߳�ȫ�� ArrayList
        CopyOnWriteArrayList<String> list = new CopyOnWriteArrayList<>();
        // ���� 10 ���߳�
        for (int i = 0; i < 10; i++) {
            new Thread(new MyThread(list)).start();
        }
        // �ȴ� 2 ��
        Thread.sleep(2000);
        // ��ӡ ArrayList �е�����Ԫ��
        System.out.println(list);
    }
}
