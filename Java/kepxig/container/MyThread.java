import java.util.concurrent.CopyOnWriteArrayList;

public class MyThread implements Runnable {
    private CopyOnWriteArrayList<String> list;

    public MyThread(CopyOnWriteArrayList<String> list) {
        this.list = list;
    }

    @Override
    public void run() {
        try {
            // 线程睡眠 1 秒
            Thread.sleep(1000);
            // 在列表中添加一个元素
            list.add("Hello World");
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

public class Main {
    public static void main(String[] args) throws InterruptedException {
        // 创建一个线程安全的 ArrayList
        CopyOnWriteArrayList<String> list = new CopyOnWriteArrayList<>();
        // 启动 10 个线程
        for (int i = 0; i < 10; i++) {
            new Thread(new MyThread(list)).start();
        }
        // 等待 2 秒
        Thread.sleep(2000);
        // 打印 ArrayList 中的所有元素
        System.out.println(list);
    }
}
