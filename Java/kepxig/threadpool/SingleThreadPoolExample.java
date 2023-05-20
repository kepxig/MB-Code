
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class SingleThreadPoolExample {
    public static void main(String[] args) {
        ExecutorService executor = Executors.newSingleThreadExecutor();
        executor.execute(new Runnable() {
            public void run() {
                // ����ִ�еĴ���
                System.out.println("��������ִ�С���");
            }
        });
        executor.shutdown();
    }
}
